/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Priority Queue.
 * Date: 11.12.2019
 * Language: C
 * Reviewer: 
 */
#include <stdio.h> /*printf()*/

#include "../include/priorityq.h"

#define UNUSED(x) (void)(x)
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

static int MyCompare(const void *data1, const void *data2, void *param)
{
	return 1;
}						

void TestPQCreate()
{	
	pq_t *newPQ = PQCreate(&MyCompare, NULL);
	RUN_TEST(0 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(0)");
	PQDestroy(newPQ);
	printf("\n");
}

void TestPQEnqueue()
{	
	int a = 10;
	int b = 20;

	pq_t *newPQ = PQCreate(&MyCompare, NULL);
	RUN_TEST(0 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(0)");
	PQEnqueue(newPQ,&a);
	RUN_TEST(1 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(1)");
	PQEnqueue(newPQ,&b);
	RUN_TEST(2 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(2)");
	PQDestroy(newPQ);
	printf("\n");
}


int main(int argc, char const *argv[])
{	
	printf("TestPQCreate()\n");
	TestPQCreate();

	printf("TestPQEnqueue()\n");
	TestPQEnqueue();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}