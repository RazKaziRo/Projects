/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Priority Queue.
 * Date: 12.12.2019
 * Language: C
 * Reviewer: Guy Cohen Zedek
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
	UNUSED(param);
	return(*(int *)data2 - *(int *)data1);
}	

static int FindData(void *iterator_data, void *ap)
{	
	return(*(int *)iterator_data == *(int *)ap);
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

void TestPQDequeue()
{
	int a = 10;
	int b = 20;

	pq_t *newPQ = PQCreate(&MyCompare, NULL);
	PQEnqueue(newPQ,&a);
	PQEnqueue(newPQ,&b);
	RUN_TEST(2 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(2)");
	RUN_TEST(a == *(int *)PQPeek(newPQ), "FAIL: WRONG DATA ON PEEK (a)");
	PQDequeue(newPQ);
	RUN_TEST(1 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(2)");
	RUN_TEST(b == *(int *)PQPeek(newPQ), "FAIL: WRONG DATA ON PEEK (a)");

	PQDestroy(newPQ);
	printf("\n");

}

void TestPQPeek()
{
	int a = 10;
	int b = 20;

	pq_t *newPQ = PQCreate(&MyCompare, NULL);
	PQEnqueue(newPQ,&b);
	PQEnqueue(newPQ,&a);
 	RUN_TEST(a == *(int *)PQPeek(newPQ), "FAIL: WRONG DATA ON PEEK (a)");

	PQDestroy(newPQ);
	printf("\n");
}

void TestPQErase()
{
	int a = 10;
	int b = 20;

	pq_t *newPQ = PQCreate(&MyCompare, NULL);
	PQEnqueue(newPQ,&a);
	PQEnqueue(newPQ,&b);
	RUN_TEST(2 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(2)");
	RUN_TEST(a == *(int *)PQErase(newPQ, &FindData, &a), "FAIL: WRONG DATA (a)");
	RUN_TEST(NULL == PQErase(newPQ, &FindData, &a), "FAIL: WRONG DATA (a)");
	RUN_TEST(1 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(1)");

	PQDestroy(newPQ);
	printf("\n");

}

void TestPQSize()
{
	int a = 10;
	int b = 20;

	pq_t *newPQ = PQCreate(&MyCompare, NULL);
	PQEnqueue(newPQ,&a);
	PQEnqueue(newPQ,&b);
	RUN_TEST(2 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(2)");

	PQDestroy(newPQ);
	printf("\n");
}

void TestPQClear()
{
	int a = 10;
	int b = 20;

	pq_t *newPQ = PQCreate(&MyCompare, NULL);
	PQEnqueue(newPQ,&a);
	PQEnqueue(newPQ,&b);
	RUN_TEST(2 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(2)");
	PQClear(newPQ);
	RUN_TEST(0 == PQSize(newPQ), "FAIL: WRONG CREATE SIZE(0)");

	PQDestroy(newPQ);
	printf("\n");

}

int main(int argc, char const *argv[])
{	
	printf("TestPQCreate()\n");
	TestPQCreate();

	printf("TestPQEnqueue()\n");
	TestPQEnqueue();

	printf("TestPQDequeue()\n");
	TestPQDequeue();

	printf("TestPQPeek()\n");
	TestPQPeek();

	printf("TestPQErase()\n");
	TestPQErase();

	printf("TestPQSize()\n");
	TestPQSize();

	printf("TestPQClear()\n");
	TestPQClear();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}