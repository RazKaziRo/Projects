#include <signal.h> /*sigaction*/
#include <fcntl.h>	/**/          
#include <sys/stat.h>       
#include <semaphore.h>/*sem_open*()*/
#include <stdlib.h> /*malloc()*/
#include "stdio.h" /*printf()*/
#include <sys/types.h> /*getpud()*/
#include <unistd.h>

#include "wd.h"

#define SEM_STOP_NAME "/stop_app"
#define SEM_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
/*
*   '0x0100' or S_IRUSR - Permits the creator of the named semaphore to open the semaphore in read mode.
*   '0x0080' or S_IWUSR - Permits the creator of the named semaphore to open the semaphore in write mode.
*   '0x0020' or S_IRGRP - Permits the group associated with the named semaphore to open the semaphore in read mode.
*   '0x0010' or S_IWGRP - Permits the group associated with the named semaphore to open the semaphore in write mode.
*   '0x0004' or S_IROTH - Permits others to open the named semaphore in read mode.
*   '0x0002' or S_IWOTH - Permits others to open the named semaphore in write mode.
*/

#define INITIAL_VALUE 0
#define FREE(ptr) free(ptr); ptr = NULL;

int g_im_alive = 0;
sem_t *sem_wd_ready = NULL;
sem_t *sem_ps_ready = NULL;
sem_t *sem_stop_app = NULL;

static void SIGUSR1Handler(int sig)
{	
	printf("SIGUSR1 HANDLER: %d \n", g_im_alive);
	++g_im_alive;
}

static void SIGUSR2Handler(int sig)
{
	sem_post(sem_stop_app);
}

 static int Task1ImAlive(void *param)
{
	wd_t *wd_pack_holder = (wd_t *)param;
	int sem_stop_value = 0;

	sem_getvalue(sem_stop_app, &sem_stop_value);

	if(0 == sem_stop_value)
	{
		printf("My Id: %d, App Id: %d \n", getpid(), wd_pack_holder->app_id_to_watch);
		kill(wd_pack_holder->app_id_to_watch, SIGUSR1);
	}
	else
	{
		SchedulerStop(wd_pack_holder->scheduler);
	}

	return 0;
}

 static int Task2IsAlive(void *param)
{
	wd_t *wd_pack_holder = (wd_t *)param;
	pid_t app_id = 0;

	if(0 == g_im_alive)
	{	
		kill(wd_pack_holder->app_id_to_watch, SIGKILL);
		app_id = fork();

		if(app_id == 0)
		{
			execl(wd_pack_holder->path_to_app, wd_pack_holder->path_to_app, NULL);
		}
		else
		{
			wd_pack_holder->app_id_to_watch = app_id;
		}
		
	}

	g_im_alive = 0;

	return 0;
}


static int IMPWDSigHandlersInit()
{
	int status_sig_1 = 0, status_sig_2 = 0;

	struct sigaction sigusr1_act;
	struct sigaction sigusr2_act;

	sigusr1_act.sa_handler = SIGUSR1Handler;
    sigusr1_act.sa_flags = 0;

	sigusr2_act.sa_handler = SIGUSR2Handler;
    sigusr2_act.sa_flags = 0;

	status_sig_1 = sigaction(SIGUSR1, &sigusr1_act, NULL);
	status_sig_2 = sigaction(SIGUSR2, &sigusr2_act, NULL);

	return (status_sig_1 + status_sig_2);
}

static scheduler_t *IMPWDSchedulerInit(wd_t *wd_pack)
{
	scheduler_t *scheduler = SchedulerCreate();
	if(NULL != scheduler)
	{
		SchedulerAddTask(scheduler, &Task1ImAlive, 1, wd_pack);
		SchedulerAddTask(scheduler, &Task2IsAlive, 3, wd_pack);
	}

	return scheduler;
}

static sem_t *IMPWDSemaphoreInit(wd_t *wd_pack)
{

	sem_stop_app = sem_open(SEM_STOP_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	wd_pack->sem_stop_app = sem_stop_app;
/*
	sem_wd_ready = sem_open(SEM_PING_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	sem_ps_ready = sem_open(SEM_PONG_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);

	
	*/

	return sem_stop_app;
}

wd_t *WDInit(wd_status_t *status)
{
	int sighandlers_init_status = 0;

	wd_t *wd_pack = malloc(sizeof(*wd_pack));
	if(NULL != wd_pack)
	{
		wd_pack->scheduler =  IMPWDSchedulerInit(wd_pack);
		if(NULL != wd_pack->scheduler)
		{
			sighandlers_init_status = IMPWDSigHandlersInit();
			if(0 == sighandlers_init_status)
			{
				if (SEM_FAILED != IMPWDSemaphoreInit(wd_pack))
				{
					*status = SUCCESS;

					return wd_pack;
				}
			}

			SchedulerDestroy(wd_pack->scheduler);
		}

		*status = MEMORY_ALOC_FAIL;
		FREE(wd_pack);
	}

	return wd_pack;	
}

static void WDCleanup(wd_t *wd_pack)
{
	SchedulerDestroy(wd_pack->scheduler);
	FREE(wd_pack);
	sem_unlink(SEM_STOP_NAME);
}

void *WDSchedulerRun(void *wd_pack)
{	
	int sem_value = 0;
	sem_getvalue(sem_stop_app, &sem_value);

	printf("sem_value %d \n", sem_value);

	while(0 == sem_value)
	{
		SchedulerRun(((wd_t *)wd_pack)->scheduler);
	}

	WDCleanup(wd_pack);
}
