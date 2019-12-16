#include <stdio.h>/*printf()*/

#include "../include/task.h"

#define RUN_TEST(test, errmsg)\
							{\
								if(test)\
								{\
									printf("SUCCESS\n");\
								}\
								else\
								{\
									printf("\033[1;31m");\
									printf("%s \n", errmsg);\
									printf("\033[0m");\
								}\
							}

#define UNUSED(x) (void)(x)
#define FREE(ptr) free(ptr); ptr = NULL;

int ToDo(void *data)
{
	printf("Hello World \n");
	return 0;
}

void TestTaskCreate()
{
	task_t *newTask = TaskCreate(&ToDo, 5, NULL);
	ilrd_uid_t TaskUid = TaskGetUid(newTask);

	RUN_TEST(1 == UIDIsSame(newTask->uid, TaskUid), "FAIL: WRONG UID");
	RUN_TEST(time(NULL) == TaskGetTimeToRun(newTask), "FAIL: TIME TO RUN");
	TaskUpdateTimeToRun(newTask);
	RUN_TEST((time(NULL) + newTask->interval) == TaskGetTimeToRun(newTask), "FAIL: TIME TO RUN");
	
	TaskDestroy(newTask);
	printf("\n");
}


void TestTaskIsMatch()
{
	task_t *newTask1 = TaskCreate(&ToDo, 5, NULL);
	task_t *newTask2 = newTask1;

	RUN_TEST(1 == TaskIsMatch(newTask2, newTask1), "FAIL: SAME TASK");
	TaskDestroy(newTask1);
	printf("\n");
}

void TestTaskRun()
{
	task_t *newTask1 = TaskCreate(&ToDo, 5, NULL);
	RUN_TEST(0 == TaskRun(newTask1), "FAIL: SAME TASK");

	TaskDestroy(newTask1);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	printf("TestTaskCreate()\n");
	TestTaskCreate();

	printf("TestTaskIsMatch()\n");
	TestTaskIsMatch();

	printf("TestTaskRun()\n");
	TestTaskRun();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}