#include <stdlib.h> /*malloc(), free()*/
#include "../../include/task.h"

#define FREE(ptr) free(ptr); ptr = NULL;

task_t *TaskCreate(task_func to_do, time_t interval, void *param)
{
	task_t *newTask = malloc(sizeof(task_t));
	if (NULL != newTask)
	{
		newTask->uid = UIDCreate();
		if(!UIDIsBad(newTask->uid))
		{
			newTask->to_do = to_do;
			newTask->run_time = time(NULL);
			newTask->interval = interval;
			newTask->param = param;
		}
		else
		{
			FREE(newTask);
		}
	}

	return newTask;
}

void TaskDestroy(task_t *t)
{
	FREE(t);
}

ilrd_uid_t TaskGetUid(task_t *t)
{
	return(t->uid);
}

int TaskIsMatch(const task_t *t1, const task_t *t2)
{
	return(UIDIsSame(t1->uid, t2->uid));
}

time_t TaskGetTimeToRun(const task_t *t)
{
	return(t->run_time);
}

void TaskUpdateTimeToRun(task_t *t)
{
	t->run_time += t->interval;
}

int TaskRun(const task_t *t)
{	
	return(t->to_do(t->param));
}



