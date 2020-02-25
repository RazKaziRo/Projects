/*
 * Author: Raz KaziRo
 * Purpose: Answares for Project - Watch Dog.
 * Date: 25.02.2020
 * Language: C
 * Reviewer: Shye Shapira 
 */

#include <signal.h> 	/*kill()*/
#include <sys/types.h>	/*fork()*/
#include <unistd.h>		/*getppid()*/
#include <time.h>

#include "wd_api_func.h"

sem_t *is_wd_up = NULL;
sem_t *wd_sem_stop_app = NULL;

static int IMPWDSemInitHelper(wd_t *wd_pack)
{
	int sem_open_status = 0;

	wd_pack->sem_to_wait = sem_open(SEM_APP_IS_READY_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	if (SEM_FAILED == wd_pack->sem_to_wait)
	{
		sem_open_status  = 1;
	}

	wd_pack->sem_to_ready = sem_open(SEM_APP_TO_WAIT_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	if (SEM_FAILED == wd_pack->sem_to_ready)
	{
		sem_open_status  = 1;
	}

	is_wd_up = sem_open(SEM_IS_WD_UP_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	if (SEM_FAILED == is_wd_up)
	{
		sem_open_status  = 1;
	}

	wd_sem_stop_app = sem_open(SEM_STOP_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
	if (SEM_FAILED == wd_sem_stop_app)
	{
		sem_open_status  = 1;
	}

	return sem_open_status;
}

wd_t *WDStart(const char *path_to_app, wd_status_t *status)
{	
	pid_t app_id = 0;
	int is_wd_up_value = 0;

	wd_t *wd_pack = WDInit(status);
	
	if (NULL == wd_pack)
	{	
		*status = WD_INIT_FAIL;
		return NULL;
	}	

	if(0 != IMPWDSemInitHelper(wd_pack))
	{
		WDCleanup(wd_pack);
		*status = SEM_OPEN_FAIL;
		FREE(wd_pack);

		return NULL; 
	}

	sem_getvalue(is_wd_up, &is_wd_up_value);

	wd_pack->path_app_to_watch = WD_APP_PATH;
	wd_pack->path_to_app = path_to_app;

	printf("is_wd_up_value %d", is_wd_up_value);

	if (0 == is_wd_up_value)
	{	
		app_id = fork();
		
		if (0 == app_id)
		{	
			printf("Start WD APP: \n");

			sem_post(is_wd_up);
			execl(WD_APP_PATH, wd_pack->path_app_to_watch, wd_pack->path_to_app, NULL);
		}
		else
		{
			wd_pack->app_id_to_watch = app_id;
			printf("app-> patch to wd %s \n", wd_pack->path_app_to_watch);
		}
	}

	else
	{	
		wd_pack->app_id_to_watch = getppid();
	}

	if (0 != pthread_create(&wd_pack->thread, NULL, &WDSchedulerRun, wd_pack))
	{
		WDCleanup(wd_pack);
		*status = THREAD_CREATE_FAIL;
		return NULL;
	}
	
	printf("is_wd_up_value %d \n", is_wd_up_value);
	sem_close(is_wd_up);

	*status = SUCCESS;

	return wd_pack;
}

wd_status_t WDStop(wd_t *wd_pack)
{
	int sem_stop_value = 0;
	time_t start = clock();
	wd_status_t status_holder = 0;

	printf("STOP SEM_STOP_VALUE befor %d \n", sem_stop_value);

	while (0 == sem_stop_value && ((clock() - start)/CLOCKS_PER_SEC) < 3)
	{
		sem_getvalue(wd_sem_stop_app, &sem_stop_value);
		kill(wd_pack->app_id_to_watch, SIGUSR2);
	}

	if (0 == sem_stop_value)
	{
		sem_post(wd_sem_stop_app);
		kill(wd_pack->app_id_to_watch, SIGKILL);
	}

	printf("STOP SEM_STOP_VALUE after kill %d \n", sem_stop_value);

	pthread_join(wd_pack->thread, NULL);

	sem_close(wd_sem_stop_app);
	sem_unlink(SEM_IS_WD_UP_NAME);

	status_holder = wd_pack->status;

	FREE(wd_pack);

	return status_holder;
}
