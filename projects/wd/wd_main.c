/*
 * Author: Raz KaziRo
 * Purpose: Answares for Project - Watch Dog.
 * Date: 25.02.2020
 * Language: C
 * Reviewer: Guy Cohen Zedek 
 */

#include <sys/types.h> 	/*getpid()*/
#include <unistd.h> 	/*getpid()*/

#include "wd.h"

static int SemOpenInit(wd_t *wd)
{
	int sem_open_status = 0;

	wd->sem_to_wait = sem_open(SEM_APP_TO_WAIT_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	if(SEM_FAILED == wd->sem_to_wait)
	{
		sem_open_status  = 1;
	}

	wd->sem_to_ready = sem_open(SEM_APP_IS_READY_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	if(SEM_FAILED == wd->sem_to_ready)
	{
		sem_open_status  = 1;
	}

	return sem_open_status;
}

int main(int argc, char const *argv[])
{
	wd_status_t wd_init_status = SUCCESS;
	wd_t *wd = NULL;

	wd = WDInit(&wd_init_status);
	if (NULL == wd)
	{
		return wd_init_status;
	}

	wd->app_id_to_watch = getppid();

	wd->path_app_to_watch = argv[1];
	wd->path_to_app = argv[0];

	printf("WD ARGV[0]: %s", argv[0]);
	printf("WD ARGV[1]: %s", argv[1]);

	printf("inside wd path to app: %s \n", wd->path_app_to_watch);
	printf("WD PID: %d \n", getpid());

	if (0 == SemOpenInit(wd))
	{
		WDSchedulerRun(&wd->scheduler);
	}
	else
	{
		WDCleanup(wd);
		wd_init_status =  FAIL_START_WD;
	}

	FREE(wd);
	UNUSED(argc);

	return wd_init_status;
}