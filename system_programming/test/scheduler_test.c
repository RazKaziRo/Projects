#include <stdio.h>/*printf()*/
#include <unistd.h> /*sleep()*/

#include "../include/scheduler.h"

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

static int ToDo1Sec(void *data)
{
	printf("Every 1 Seconds \n");
	UNUSED(data);
	return 0;
}

static int ToDo5Sec(void *data)
{
	printf("Every 5 Seconds \n");
	UNUSED(data);
	return 0;
}

static int StopScheduler(void *data)
{
	SchedulerStop(data);
}

void TestSchedulerCreate()
{
	scheduler_t *newScheduler = SchedulerCreate();
	RUN_TEST(0 == SchedulerSize(newScheduler), "FAIL: WRONG CREATE SIZE (0)");
	RUN_TEST(1 == SchedulerIsEmpty(newScheduler), "FAIL: WRONG CREATE SIZE (0)");

	SchedulerDestroy(newScheduler);
	printf("\n");
	
}

void TestSchedulerAddTask()
{
	scheduler_t *newScheduler = SchedulerCreate();
	RUN_TEST(0 == SchedulerSize(newScheduler), "FAIL: WRONG CREATE SIZE (0)");
	RUN_TEST(1 == SchedulerIsEmpty(newScheduler), "FAIL: WRONG CREATE SIZE (0)");
	SchedulerAddTask(newScheduler, &ToDo1Sec,1, NULL);
	RUN_TEST(1 == SchedulerSize(newScheduler), "FAIL: WRONG CREATE SIZE (0)");
	RUN_TEST(0 == SchedulerIsEmpty(newScheduler), "FAIL: WRONG CREATE SIZE (0)");
	SchedulerAddTask(newScheduler, &ToDo5Sec,5, NULL);
	RUN_TEST(2 == SchedulerSize(newScheduler), "FAIL: WRONG SIZE (2)");

	SchedulerDestroy(newScheduler);
	printf("\n");
	
}

void TestSchedulerRemoveTask()
{
	scheduler_t *newScheduler = SchedulerCreate();
	ilrd_uid_t newUid;

	RUN_TEST(0 == SchedulerSize(newScheduler), "FAIL: WRONG CREATE SIZE (0)");
	RUN_TEST(1 == SchedulerIsEmpty(newScheduler), "FAIL: WRONG IS EMPTY (1)");
	
	newUid = SchedulerAddTask(newScheduler, &ToDo1Sec,1, NULL);
	RUN_TEST(0 == SchedulerIsEmpty(newScheduler), "FAIL: WRONG IS EMPTY (1)");
	RUN_TEST(1 == SchedulerSize(newScheduler), "FAIL: WRONG CREATE SIZE (0)");

	SchedulerRemoveTask(newScheduler,newUid);
	RUN_TEST(0 == SchedulerSize(newScheduler), "FAIL: WRONG CREATE SIZE (0)");
	RUN_TEST(1 == SchedulerIsEmpty(newScheduler), "FAIL: WRONG IS EMPTY (1)");

	SchedulerDestroy(newScheduler);
	printf("\n");
}

void TestSchedulerClear()
{
	scheduler_t *newScheduler = SchedulerCreate();
	SchedulerAddTask(newScheduler, &ToDo1Sec,1, NULL);
	SchedulerAddTask(newScheduler, &ToDo5Sec,5, NULL);
	SchedulerClear(newScheduler);
	RUN_TEST(1 == SchedulerIsEmpty(newScheduler), "FAIL: EMPTY AFTER CLEAR (1)");
	RUN_TEST(0 == SchedulerSize(newScheduler), "FAIL: WRONG CREATE SIZE (0)");

	SchedulerDestroy(newScheduler);
	printf("\n");

}

void TestSchedulerRun()
{
	scheduler_t *newScheduler = SchedulerCreate();
	ilrd_uid_t newUid;
	SchedulerAddTask(newScheduler, &ToDo5Sec,5, NULL);
	SchedulerAddTask(newScheduler, &ToDo1Sec,1, NULL);
	/*SchedulerAddTask(newScheduler, &StopScheduler,15, newScheduler);*/

	RUN_TEST(3 == SchedulerSize(newScheduler), "FAIL: WRONG CREATE SIZE (0)");

	SchedulerRun(newScheduler);
	printf("stop");
	SchedulerRun(newScheduler);

	SchedulerDestroy(newScheduler);
	printf("\n");

}

int main(int argc, char const *argv[])
{	
	printf("TestSchedulerCreate()\n");
	TestSchedulerCreate();

	printf("TestSchedulerAddTask()\n");
	TestSchedulerAddTask();

	printf("TestSchedulerRemoveTask()\n");
	TestSchedulerRemoveTask();

	printf("TestSchedulerRun()\n");
	TestSchedulerRun();

	/*printf("TestSchedulerClear()\n");
	TestSchedulerClear();*/
	
	UNUSED(argv);
	UNUSED(argc);
	return 0;
}