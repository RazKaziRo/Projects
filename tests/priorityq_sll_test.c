/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Priority Queue.
 * Date: 12.12.2019
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#include <stdio.h> /*printf()*/

#include "../include/priorityq_sll.h"

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
	return(*(int *)data1 - *(int *)data2);
}	

static int FindData(void *iterator_data, void *ap)
{	
	return(*(int *)iterator_data == *(int *)ap);
}					

void TestSLLPQCreate()
{	
	size_t element_size = 4;
	SLLPQ_t *new_SLLPQ = SLLPQCreate(&MyCompare, &element_size);
	RUN_TEST(0 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(0)");
	SLLPQDestroy(new_SLLPQ);
	printf("\n");
}


void TestSLLPQEnqueue()
{	
	int a = 5;
	int b = 15;
	int c = 20;
	int d = 25;

	SLLPQ_t *new_SLLPQ = SLLPQCreate(&MyCompare, NULL);

	RUN_TEST(0 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(0)");
	SLLPQEnqueue(new_SLLPQ,&a);
	RUN_TEST(1 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(1)");
	SLLPQEnqueue(new_SLLPQ,&b);
	RUN_TEST(2 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(2)");
	SLLPQEnqueue(new_SLLPQ,&c);
	SLLPQEnqueue(new_SLLPQ,&d);

	SLLPQClear(new_SLLPQ);
	RUN_TEST(0 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(0)");
	

	SLLPQDestroy(new_SLLPQ);
	printf("\n");
}


void TestSLLPQDequeue()
{
	int a = 5;
	int b = 15;
	int c = 20;
	int d = 25;
	int e = 30;

	SLLPQ_t *new_SLLPQ = SLLPQCreate(&MyCompare, NULL);

	RUN_TEST(0 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(0)");
	SLLPQEnqueue(new_SLLPQ,&a);
	RUN_TEST(1 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(1)");
	SLLPQEnqueue(new_SLLPQ,&b);
	RUN_TEST(2 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(2)");
	SLLPQEnqueue(new_SLLPQ,&c);
	SLLPQEnqueue(new_SLLPQ,&d);

	SLLPQDequeue(new_SLLPQ);
	SLLPQEnqueue(new_SLLPQ,&e);
	SLLPQClear(new_SLLPQ);

	RUN_TEST(0 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(0)");
	
	SLLPQDestroy(new_SLLPQ);
	printf("\n");

}


void TestSLLPQPeek()
{
	int a = 10;
	int b = 20;

	SLLPQ_t *new_SLLPQ = SLLPQCreate(&MyCompare, NULL);
	SLLPQEnqueue(new_SLLPQ,&b);
	SLLPQEnqueue(new_SLLPQ,&a);
 	RUN_TEST(b == *(int *)SLLPQPeek(new_SLLPQ), "FAIL: WRONG DATA ON PEEK (b)");

	SLLPQDestroy(new_SLLPQ);
	printf("\n");
}


void TestSLLPQErase()
{
	int a = 10;
	int b = 20;

	SLLPQ_t *new_SLLPQ = SLLPQCreate(&MyCompare, NULL);
	SLLPQEnqueue(new_SLLPQ,&a);
	SLLPQEnqueue(new_SLLPQ,&b);
	RUN_TEST(2 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(2)");
	RUN_TEST(a == *(int *)SLLPQErase(new_SLLPQ, &FindData, &a), "FAIL: WRONG DATA (a)");
	RUN_TEST(NULL == SLLPQErase(new_SLLPQ, &FindData, &a), "FAIL: WRONG DATA (a)");
	RUN_TEST(1 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(1)");

	SLLPQDestroy(new_SLLPQ);
	printf("\n");

}

void TestSLLPQSize()
{
	int a = 10;
	int b = 20;

	SLLPQ_t *new_SLLPQ = SLLPQCreate(&MyCompare, NULL);
	SLLPQEnqueue(new_SLLPQ,&a);
	SLLPQEnqueue(new_SLLPQ,&b);
	RUN_TEST(2 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(2)");

	SLLPQDestroy(new_SLLPQ);
	printf("\n");
}

void TestSLLPQClear()
{
	int a = 10;
	int b = 20;

	SLLPQ_t *new_SLLPQ = SLLPQCreate(&MyCompare, NULL);
	SLLPQEnqueue(new_SLLPQ,&a);
	SLLPQEnqueue(new_SLLPQ,&b);
	RUN_TEST(2 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(2)");
	SLLPQClear(new_SLLPQ);
	RUN_TEST(0 == SLLPQSize(new_SLLPQ), "FAIL: WRONG CREATE SIZE(0)");

	SLLPQDestroy(new_SLLPQ);
	printf("\n");

}

int main(int argc, char const *argv[])
{	
	printf("TestSLLPQCreate()\n");
	TestSLLPQCreate();

	printf("TestSLLPQEnqueue()\n");
	TestSLLPQEnqueue();

	printf("TestSLLPQDequeue()\n");
	TestSLLPQDequeue();

	printf("TestSLLPQPeek()\n");
	TestSLLPQPeek();

	printf("TestSLLPQErase()\n");
	TestSLLPQErase();

	printf("TestSLLPQSize()\n");
	TestSLLPQSize();

	printf("TestSLLPQClear()\n");
	TestSLLPQClear();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}