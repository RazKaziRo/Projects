/*
 * Author: Raz KaziRo
 * Purpose: Answares for System Programing - Task.
 * Date: 17.12.2019
 * Language: C
 * Reviewer: Shye Shapira 
 */

#include <assert.h> /*assert()*/
#include <stdlib.h> /*malloc(), free()*/

#include "../../include/task.h" /*Task API Functions()*/

#define FREE(ptr) free(ptr); ptr = NULL;

task_t *TaskCreate(task_func to_do, time_t interval, void *param)
{
	task_t *new_task = malloc(sizeof(task_t));
	if (NULL != new_task)
	{
		new_task->uid = UIDCreate();
		if (!UIDIsBad(new_task->uid))
		{
			new_task->to_do = to_do;
			new_task->run_time = time(NULL) + interval;
			new_task->interval = interval;
			new_task->param = param;
		}
		else
		{
			FREE(new_task);
		}
	}

	return new_task;
}

void TaskDestroy(task_t *t)
{	
	assert(NULL != t);
	
	FREE(t);
}

ilrd_uid_t TaskGetUid(task_t *t)
{
	assert(NULL != t);

	return(t->uid);
}

int TaskIsMatch(const task_t *t1, const task_t *t2)
{	
	assert(NULL != t1);
	assert(NULL != t2);

	return (UIDIsSame(t1->uid, t2->uid));
}

time_t TaskGetTimeToRun(const task_t *t)
{	
	assert(NULL != t);

	return (t->run_time);
}

void TaskUpdateTimeToRun(task_t *t)
{	
	assert(NULL != t);

	t->run_time += t->interval;
}

int TaskRun(const task_t *t)
{		
	assert(NULL != t);

	return (t->to_do(t->param));
}



