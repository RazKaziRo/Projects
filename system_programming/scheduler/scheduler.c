/*
 * Author: Raz KaziRo
 * Purpose: Answares for System Programing - Scheduler.
 * Date: 17.12.2019
 * Language: C
 * Reviewer: Shye Shapira 
 */

#include <stdlib.h> /*malloc(), free()*/
#include <assert.h> /*assert()*/
#include <unistd.h> /*sleep()*/

#include "scheduler.h"  	   /*Scheduler API Functions*/
#include "uid.h"			   /*UID API Functions*/
#include "task.h"		 	   /*Task API Functions*/
#include "priorityq_sll.h" /*Priority Queue API Functions*/

#define FREE(ptr) free(ptr); ptr = NULL;
#define UNUSED(x) (void)(x)
#define FLAG_ON 1
#define FLAG_OFF 0

struct Scheduler
{
	SLLPQ_t *queue;
	int remove_current;
	int stop;
	task_t *current_task;
};

static int TimeCompare(const void *data1,const void *data2, void *param)
{
	task_t *t1 = (task_t *)data1;
	task_t *t2 = (task_t *)data2;

	assert(NULL != data1);
	assert(NULL != data2);

	UNUSED(param);

	return(TaskGetTimeToRun(t2) - TaskGetTimeToRun(t1));
}

scheduler_t *SchedulerCreate()
{	
	scheduler_t *new_scheduler = malloc(sizeof(scheduler_t));
	if (NULL != new_scheduler)
	{
		new_scheduler->queue = SLLPQCreate(&TimeCompare, NULL);
		if (NULL != new_scheduler->queue)
		{
			new_scheduler->remove_current = 0;
			new_scheduler->stop = 0;
			new_scheduler->current_task = NULL;
		}
		else
		{
			FREE(new_scheduler);
		}
	}

	return new_scheduler;
}

void SchedulerRun(scheduler_t *s)
{	
	task_t *task_to_run = NULL;

	assert(NULL != s);
	
	s->stop = FLAG_OFF;

	while (!s->stop)
	{
		task_to_run = SLLPQDequeue(s->queue);
		s->current_task = task_to_run;

		if (time(NULL) < TaskGetTimeToRun(task_to_run))
		{
			while (sleep(TaskGetTimeToRun(task_to_run) - time(NULL)));
		}

		if (0 == TaskRun(task_to_run) && 0 == s->remove_current)
		{
			TaskUpdateTimeToRun(task_to_run);
			SLLPQEnqueue(s->queue,task_to_run); /*suppose no need to check if failed*/
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
	task_t *new_task = TaskCreate(to_do, interval, param);
	ilrd_uid_t bad_uid = {0};

	assert(NULL != s);

	if (NULL != new_task)
	{
		if (SLLPQEnqueue(s->queue, new_task))
		{
			return (TaskGetUid(new_task));
		}
	}

	return bad_uid;
}

static int IsSame(void *data1, void *data2)
{
	task_t *t1 = (task_t *)data1;

	assert(NULL != data1);
	assert(NULL != data2);

	return (UIDIsSame(TaskGetUid(t1),*(ilrd_uid_t *)data2));
}

void SchedulerRemoveTask(scheduler_t *s, ilrd_uid_t uid)
{	
	task_t *task_holder = NULL;

	assert(NULL != s);

	if (NULL == s->current_task || !UIDIsSame(uid,TaskGetUid(s->current_task)))
	{
		task_holder = SLLPQErase(s->queue, &IsSame, &uid);
		TaskDestroy(task_holder);
	}
	else
	{
		s->remove_current = FLAG_ON;
	}
}

void SchedulerDestroy(scheduler_t *s)
{	
	assert(NULL != s);

	SchedulerClear(s);
	SLLPQDestroy(s->queue);
	FREE(s);
}

size_t SchedulerSize(const scheduler_t *s)
{
	assert(NULL != s);

	return(SLLPQSize(s->queue));
}

int SchedulerIsEmpty(const scheduler_t *s)
{
	assert(NULL != s);

	return(SLLPQIsEmpty(s->queue));
}

void SchedulerClear(scheduler_t *s)
{
	assert(NULL != s);

	while (!SLLPQIsEmpty(s->queue))
	{
		TaskDestroy(SLLPQDequeue(s->queue));
	}
}

void SchedulerStop(scheduler_t *s)
{
	assert(NULL != s);

	s->stop = FLAG_ON;
}
