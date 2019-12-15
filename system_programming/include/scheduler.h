#ifndef __SHCEDULER_H__
#define __SHCEDULER_H__

#include <stddef.h>/*size_t*/
#include <time.h>/*time_t*/

#include "uid.h" /*uid functions*/

typedef struct Scheduler scheduler_t;
typedef int (*task_func)(void *param);

/*
* 
*
*
*/

scheduler_t *SchedulerCreate();



void SchedulerDestroy(scheduler_t *s);
int SchedulerAddTask(scheduler_t *s, task_func, time_t interval, void *param);
void SchedulerRemoveTask(scheduler_t *s, ilrd_uid_t uid);
void SchedulerRun(const scheduler_t *s);
void SchedulerStop(const scheduler_t *s);
size_t SchedulerSize(const scheduler_t *s);
int SchedulerIsEmpty(const scheduler_t *s);
void SchedulerClear(scheduler_t *s);

#endif
