#ifndef __WD_H__
#define __WD_H__

#include <semaphore.h> /*sem_t()*/
#include <pthread.h>
#include "../../system_programming/include/scheduler.h"

typedef struct WATCHDOGPACK wd_t;

typedef enum WDSTATUS
{
	SUCCESS,
	MEMORY_ALOC_FAIL

} wd_status_t;

struct WATCHDOGPACK
{
	scheduler_t *scheduler;
	pthread_t thread;
	pid_t app_id_to_watch;
	const char *path_to_app;
	sem_t *sem_stop_app;
};


wd_t *WDInit(wd_status_t *status);

void *WDSchedulerRun(void *wd_pack);


#endif