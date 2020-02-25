/*
 * Author: Raz KaziRo
 * Purpose: Answares for Project - Watch Dog.
 * Date: 25.02.2020
 * Language: C
 * Reviewer: Shye Shapira 
 */

#include <signal.h> 	/*sigaction*/
#include <fcntl.h>		/*SEM_PERMS*/ 
#include <sys/stat.h> 	/*O_CREAT*/      
#include <semaphore.h>	/*sem_open*()*/
#include <stdlib.h> 	/*malloc()*/
#include "stdio.h" 		/*printf()*/
#include <sys/types.h> 	/*getpid()*/
#include <unistd.h>		/*getpid()*/

#include "wd.h"

int g_im_alive = 0;

sem_t *sem_stop_app = NULL;

static void SIGUSR1Handler(int sig)
{	
	printf("SIGUSR1 - app_id: %d  g_im_alive value: %d\n",getpid(), g_im_alive);
	++g_im_alive;

	UNUSED(sig);

}

static void SIGUSR2Handler(int sig)
{
	int sem_stop_value = 0;
	printf("sem post recived!");

	sem_post(sem_stop_app);

	sem_getvalue(sem_stop_app, &sem_stop_value);
	printf("My Id: %d, sem_stop_value: %d \n", getpid(), sem_stop_value);

	UNUSED(sig);
}

static int Task1ImAlive(void *param)
{
	wd_t *wd_pack_holder = (wd_t *)param;
	int sem_stop_value = 0;

	sem_getvalue(sem_stop_app, &sem_stop_value);

	if (0 == sem_stop_value)
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

	if (0 == g_im_alive)
	{	
		printf("I am: %d I need to Revive: %d \n",  getpid(), wd_pack_holder->app_id_to_watch);
		app_id = fork();

		if (app_id == 0)
		{
			printf("PROCESS NEED TO REVIVE: %s", wd_pack_holder->path_app_to_watch);
			execl(wd_pack_holder->path_app_to_watch, wd_pack_holder->path_app_to_watch, wd_pack_holder->path_to_app, NULL);
		}

		wd_pack_holder->app_id_to_watch = app_id;
		SchedulerStop(wd_pack_holder->scheduler);
	}

	printf("I am %d PROCESS ALIVE \n", getpid());
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
	if (NULL != scheduler)
	{
		if (!UIDIsBad(SchedulerAddTask(scheduler, &Task1ImAlive, 1, wd_pack))
			&& !UIDIsBad(SchedulerAddTask(scheduler, &Task2IsAlive, 3, wd_pack)))
		{
			return scheduler;
		}
		else
		{
			SchedulerDestroy(scheduler);
		}
	}

	return NULL;
}

static int IMPWDSemaphoreInit()
{
	int sem_open_status = 0;

	sem_stop_app = sem_open(SEM_STOP_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	if (SEM_FAILED == sem_stop_app)
	{
		sem_open_status  = 1;
	}

	return sem_open_status;
}

wd_t *WDInit(wd_status_t *status)
{
	int sighandlers_init_status = 0;

	wd_t *wd_pack = malloc(sizeof(*wd_pack));
	if (NULL != wd_pack)
	{
		wd_pack->scheduler =  IMPWDSchedulerInit(wd_pack);
		if (NULL != wd_pack->scheduler)
		{
			sighandlers_init_status = IMPWDSigHandlersInit();
			if (0 == sighandlers_init_status)
			{
				if (0 == IMPWDSemaphoreInit())
				{
					*status = SUCCESS;
					return wd_pack;
				}

				WDCleanup(wd_pack);
			}

			SchedulerDestroy(wd_pack->scheduler);
		}

		*status = MEMORY_ALOC_FAIL;
		FREE(wd_pack);
	}

	return wd_pack;	
}

void *WDSchedulerRun(void *wd_pack)
{	
	wd_t *wd_pack_holder = (wd_t *)wd_pack;
	int sem_stop_value = 0;

	sem_getvalue(sem_stop_app, &sem_stop_value);
	printf("Inside %d Before Scheduler Run: sem_stop_value %d \n",getpid(), sem_stop_value);

	while(0 == sem_stop_value)
	{
		sem_post(wd_pack_holder->sem_to_ready);
		sem_wait(wd_pack_holder->sem_to_wait);

		SchedulerRun(((wd_t *)wd_pack)->scheduler);

		sem_getvalue(sem_stop_app, &sem_stop_value);
	}

	printf("Inside %d After Scheduler Run: sem_stop_value %d \n",getpid(), sem_stop_value);

	WDCleanup(wd_pack_holder);

	return NULL;
}

void WDCleanup(wd_t *wd_pack)
{
	SchedulerDestroy(wd_pack->scheduler);
	wd_pack->status = SUCCESS;

	if (0 != sem_close(sem_stop_app) || 
		(0 != sem_close(wd_pack->sem_to_ready)) || (0 != sem_close(wd_pack->sem_to_wait)))
	{
		wd_pack->status = SEM_CLOSE_FAIL;
	}

	if (0 != sem_unlink(SEM_APP_TO_WAIT_NAME) || 
		(0 != sem_unlink(SEM_APP_IS_READY_NAME)) || (0 != sem_unlink(SEM_STOP_NAME)))
	{
		wd_pack->status = SEM_UNLINK_FAIL;
	}

	if (wd_pack->status == SEM_UNLINK_FAIL || wd_pack->status ==  SEM_CLOSE_FAIL)
	{
		wd_pack->status = WD_CLEAN_FAIL;
	}	
}
