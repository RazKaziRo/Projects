#include <stdlib.h> /*malloc(), free()*/
#include <assert.h> /*assert()*/
#include <unistd.h> /*sleep()*/

#include "../../include/scheduler.h"
#include "../../include/uid.h"
#include "../../include/task.h"
#include "../../../ds/include/priorityq.h"

#define FREE(ptr) free(ptr); ptr = NULL;
#define UNUSED(x) (void)(x)
#define FLAG_ON 1
#define FLAG_OFF 0
struct Scheduler
{
	pq_t *queue;
	int remove_current;
	int stop;
	task_t *current_task;
};

static int TimeCompare(const void *data1,const void *data2, void *param)
{
	task_t *t1 = (task_t *)data1;
	task_t *t2 = (task_t *)data2;

	UNUSED(param);

	return(TaskGetTimeToRun(t2) - TaskGetTimeToRun(t1));
}

scheduler_t *SchedulerCreate()
{	
	scheduler_t *newScheduler = malloc(sizeof(scheduler_t));
	if(NULL != newScheduler)
	{
		newScheduler->queue = PQCreate(&TimeCompare, NULL);
		if(NULL != newScheduler->queue)
		{
			newScheduler->remove_current = 0;
			newScheduler->stop = 0;
			newScheduler->current_task = NULL;
		}
		else
		{
			FREE(newScheduler);
		}
	}

	return newScheduler;
}

void SchedulerRun(scheduler_t *s)
{
	task_t *task_to_run;

	while(!s->stop)
	{
		task_to_run = PQDequeue(s->queue);
		s->current_task = task_to_run;

		if (time(NULL) < TaskGetTimeToRun(task_to_run))
		{
			while (sleep(TaskGetTimeToRun(task_to_run) - time(NULL)));
		}

		if(0 == TaskRun(task_to_run) && 0 == s->remove_current)
		{
			TaskUpdateTimeToRun(task_to_run);
			PQEnqueue(s->queue,task_to_run); /*what to do if failed?*/
		}
		else
		{
			TaskDestroy(task_to_run);
			s->remove_current = FLAG_OFF;
		}
	}
}

ilrd_uid_t SchedulerAddTask(scheduler_t *s, task_func to_do, time_t interval, void *param)
{
	task_t *newTask = TaskCreate(to_do, interval, param);
	ilrd_uid_t bad_uid = {0};

	if (NULL != newTask)
	{
		if(PQEnqueue(s->queue, newTask))
		{
			return(TaskGetUid(newTask));
		}
	}

	return bad_uid;
}

static int IsSame(void *data1, void *data2)
{
	task_t *t1 = (task_t *)data1;

	return(UIDIsSame(TaskGetUid(t1),*(ilrd_uid_t *)data2));
}

void SchedulerRemoveTask(scheduler_t *s, ilrd_uid_t uid)
{	
	task_t *task_holder = NULL;

	if(NULL == s->current_task || !UIDIsSame(uid,TaskGetUid(s->current_task)))
	{
		task_holder = PQErase(s->queue, &IsSame, &uid);
		TaskDestroy(task_holder);
	}
	else
	{
		s->remove_current = FLAG_ON;
	}
}

void SchedulerDestroy(scheduler_t *s)
{	
	SchedulerClear(s);
	PQDestroy(s->queue);
	FREE(s);
}

size_t SchedulerSize(const scheduler_t *s)
{
	return(PQSize(s->queue));
}

int SchedulerIsEmpty(const scheduler_t *s)
{
	return(PQIsEmpty(s->queue));
}

void SchedulerClear(scheduler_t *s)
{
	while(!PQIsEmpty(s->queue))
	{
		TaskDestroy(PQDequeue(s->queue));
	}
}

void SchedulerStop(scheduler_t *s)
{
	s->stop = FLAG_ON;
}