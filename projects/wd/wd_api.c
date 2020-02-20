#include <signal.h> /*sigaction*/
#include <fcntl.h>	/**/          
#include <sys/stat.h>       
#include <semaphore.h>/*sem_open*()*/

#include "wd_api.h"
#include "../../system_programming/include/scheduler.h"

/*
*   '0x0100' or S_IRUSR - Permits the creator of the named semaphore to open the semaphore in read mode.
*   '0x0080' or S_IWUSR - Permits the creator of the named semaphore to open the semaphore in write mode.
*   '0x0020' or S_IRGRP - Permits the group associated with the named semaphore to open the semaphore in read mode.
*   '0x0010' or S_IWGRP - Permits the group associated with the named semaphore to open the semaphore in write mode.
*   '0x0004' or S_IROTH - Permits others to open the named semaphore in read mode.
*   '0x0002' or S_IWOTH - Permits others to open the named semaphore in write mode.
*/

#define SEM_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)
#define INITIAL_VALUE 0

struct WATCHDOG
{
	scheduler_t *scheduler;

}
int g_Is_Breathing = 0;
sem_t *sem_wd_ready = NULL;
sem_t *sem_ps_ready = NULL;

void SIGUSR1Handler(int sig)
{
	++g_Is_Breathing;
}

void SIGUSR2Handler(int sig)
{

}

 static int Task1ImAlive(void *param)
{
	return 0;
}

 static int Task2IsAlive(void *param)
{
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

static scheduler_t *IMPWDSchedulerInit()
{

	scheduler_t *scheduler = SchedulerCreate();
	if(NULL != scheduler)
	{
		SchedulerAddTask(scheduler, &Task1ImAlive, 1, NULL);
		/*SchedulerAddTask(scheduler, &Task2IsAlive, 3, NULL);*/
	}

	return scheduler;
}

static sem_t *IMPWDSemaphoreInit()
{

/*
	sem_wd_ready = sem_open(SEM_PING_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	sem_ps_ready = sem_open(SEM_PONG_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
*/

}

static wd_status_t WDInit(wd_t wd)
{
	int sighandlers_init_status = 0;
	scheduler_t *wd_scheduler = NULL;

	wd_scheduler =  IMPWDSchedulerInit();
	if(NULL != wd_scheduler)
	{
		sighandlers_init_status = IMPWDSigHandlersInit();

		if(0 == sighandlers_init_status)
		{
			if (SEM_FAILED != IMPWDSemaphoreInit())
			{
				return SUCCESS;
			}
		}

		SchedulerDestroy(wd_scheduler);
	}

	return MEMORY_ALOC_FAIL;

}	


wd_t *WDStart(const char *filename, wd_status_t status)
{
	wd_status_t wd_start_status = WDInit();
	if(SUCCESS == wd_start_status)
	{
		/*ptrehad create*/
	}


}
