#include <stdlib.h> /*malloc(), free()*/
#include <assert.h> /*assert()*/

#include "../../include/scheduler.h"
#include "../../include/uid.h"
#include "../../include/task.h"
#include "../../../ds/include/priorityq.h"

#define FREE(ptr) free(ptr); ptr = NULL;

struct Scheduler
{
	pq_t *queue;
	int remove_current;
	int stop;
	task_t *current_task;
};

static int TimeCompare(const void *data1,const void *data2, void *param)
{

}

scheduler_t *SchedulerCreate()
{	
	void *data = NULL;

	pq_t *newQueue = PQCreate(&TimeCompare, data);
}

void SchedulerDestroy(scheduler_t *s)
{
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
	PQClear(s->queue);
}