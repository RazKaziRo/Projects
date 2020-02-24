#ifndef __WD_H__
#define __WD_H__

#include <fcntl.h>	/*SEM_PERMS*/ 
#include <sys/stat.h>       
#include <semaphore.h>/*sem_open*()*/
#include <pthread.h>
#include "../../system_programming/include/scheduler.h"

#define SEM_STOP_NAME "/stop_app"
#define SEM_IS_WD_UP_NAME "/wd_up"
#define SEM_APP_IS_READY_NAME "/app_is_ready"
#define SEM_APP_TO_WAIT_NAME "/wd_is_ready"

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
	sem_t *sem_to_wait;
	sem_t *sem_to_ready;
};


wd_t *WDInit(wd_status_t *status);

void *WDSchedulerRun(void *wd_pack);


#endif