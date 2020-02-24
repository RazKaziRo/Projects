#include <stdio.h>
#include <sys/types.h> /*getpid()*/
#include <unistd.h>

#include "wd.h"

int main(int argc, char const *argv[])
{
	int sem_open_status = 0;
	wd_status_t wd_init_status;
	wd_t *wd = NULL;

	wd = WDInit(&wd_init_status);
	wd->app_id_to_watch = getppid();

	wd->path_app_to_revive = argv[0];
	wd->path_app_being_revive_by = argv[1];

	
	printf("WD ARGV[1]: %s", argv[1]);
	printf("WD ARGV[0]: %s", argv[0]);

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

	printf("inside wd path to app: %s \n", wd->path_app_to_revive);
	printf("WD PID: %d \n", getpid());

	WDSchedulerRun(&wd->scheduler);

	return 0;
}