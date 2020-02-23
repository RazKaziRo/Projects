#include <signal.h> /*kill()*/
#include <sys/types.h> /*fork()*/
#include <unistd.h>

#include "wd_api_func.h"

wd_t *WDStart(const char *path_to_app, wd_status_t *status)
{	
	pid_t app_id = 0;
	wd_t *wd_pack = WDInit(status);
	if(NULL != wd_pack)
	{
		if(0 == pthread_create(&wd_pack->thread, NULL, &WDSchedulerRun, wd_pack))
		{	
			
			app_id = fork();
			/*SEM*/
			if(0 == app_id)
			{
				execl(WD_APP_PATH, path_to_app, NULL);
			}
			else
			{
				wd_pack->app_id_to_watch = app_id;
				wd_pack->path_to_app = WD_APP_PATH;
				printf("app-> patch to wd %s \n", wd_pack->path_to_app);
			}
			/*SEM POST*/
		}

	}

	return wd_pack;
}

void WDStop(wd_t *wd_pack)
{
	int sem_stop_value = 0;
	sem_getvalue(wd_pack->sem_stop_app, &sem_stop_value);

	printf("WD STOP SEM STOP VALUE: %d", sem_stop_value);
	while(0 == sem_stop_value)
	{
		kill(wd_pack->app_id_to_watch, SIGUSR2);
	}
	
	pthread_join(wd_pack->thread, NULL);
}
