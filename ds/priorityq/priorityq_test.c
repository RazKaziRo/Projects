/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Priority Queue.
 * Date: 12.12.2019
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#include <stdio.h> /*printf()*/

#include "../include/priorityq_vector.h"

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

void TestVECPQCreate()
{	
	size_t element_size = 4;
	VECPQ_t *new_VECPQ = VECPQCreate(&MyCompare, &element_size);
	RUN_TEST(0 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(0)");
	VECPQDestroy(new_VECPQ);
	printf("\n");
}


void TestVECPQEnqueue()
{	
	int a = 5;
	int b = 15;
	int c = 20;
	int d = 25;

	VECPQ_t *new_VECPQ = VECPQCreate(&MyCompare, NULL);

	RUN_TEST(0 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(0)");
	VECPQEnqueue(new_VECPQ,&a);
	RUN_TEST(1 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(1)");
	VECPQEnqueue(new_VECPQ,&b);
	RUN_TEST(2 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(2)");
	VECPQEnqueue(new_VECPQ,&c);
	VECPQEnqueue(new_VECPQ,&d);

	VECPQClear(new_VECPQ);
	RUN_TEST(0 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(0)");
	

	VECPQDestroy(new_VECPQ);
	printf("\n");
}


void TestVECPQDequeue()
{
	int a = 5;
	int b = 15;
	int c = 20;
	int d = 25;
	int e = 30;

	VECPQ_t *new_VECPQ = VECPQCreate(&MyCompare, NULL);

	RUN_TEST(0 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(0)");
	VECPQEnqueue(new_VECPQ,&a);
	RUN_TEST(1 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(1)");
	VECPQEnqueue(new_VECPQ,&b);
	RUN_TEST(2 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(2)");
	VECPQEnqueue(new_VECPQ,&c);
	VECPQEnqueue(new_VECPQ,&d);

	VECPQDequeue(new_VECPQ);
	VECPQEnqueue(new_VECPQ,&e);
	VECPQClear(new_VECPQ);

	RUN_TEST(0 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(0)");
	
	VECPQDestroy(new_VECPQ);
	printf("\n");

}


void TestVECPQPeek()
{
	int a = 10;
	int b = 20;

	VECPQ_t *new_VECPQ = VECPQCreate(&MyCompare, NULL);
	VECPQEnqueue(new_VECPQ,&b);
	VECPQEnqueue(new_VECPQ,&a);
 	RUN_TEST(b == *(int *)VECPQPeek(new_VECPQ), "FAIL: WRONG DATA ON PEEK (b)");

	VECPQDestroy(new_VECPQ);
	printf("\n");
}


void TestVECPQErase()
{
	int a = 10;
	int b = 20;

	VECPQ_t *new_VECPQ = VECPQCreate(&MyCompare, NULL);
	VECPQEnqueue(new_VECPQ,&a);
	VECPQEnqueue(new_VECPQ,&b);
	RUN_TEST(2 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(2)");
	RUN_TEST(a == *(int *)VECPQErase(new_VECPQ, &FindData, &a), "FAIL: WRONG DATA (a)");
	RUN_TEST(NULL == VECPQErase(new_VECPQ, &FindData, &a), "FAIL: WRONG DATA (a)");
	RUN_TEST(1 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(1)");

	VECPQDestroy(new_VECPQ);
	printf("\n");

}

void TestVECPQSize()
{
	int a = 10;
	int b = 20;

	VECPQ_t *new_VECPQ = VECPQCreate(&MyCompare, NULL);
	VECPQEnqueue(new_VECPQ,&a);
	VECPQEnqueue(new_VECPQ,&b);
	RUN_TEST(2 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(2)");

	VECPQDestroy(new_VECPQ);
	printf("\n");
}

void TestVECPQClear()
{
	int a = 10;
	int b = 20;

	VECPQ_t *new_VECPQ = VECPQCreate(&MyCompare, NULL);
	VECPQEnqueue(new_VECPQ,&a);
	VECPQEnqueue(new_VECPQ,&b);
	RUN_TEST(2 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(2)");
	VECPQClear(new_VECPQ);
	RUN_TEST(0 == VECPQSize(new_VECPQ), "FAIL: WRONG CREATE SIZE(0)");

	VECPQDestroy(new_VECPQ);
	printf("\n");

}

int main(int argc, char const *argv[])
{	
	printf("TestVECPQCreate()\n");
	TestVECPQCreate();

	printf("TestVECPQEnqueue()\n");
	TestVECPQEnqueue();

	printf("TestVECPQDequeue()\n");
	TestVECPQDequeue();

	printf("TestVECPQPeek()\n");
	TestVECPQPeek();

	printf("TestVECPQErase()\n");
	TestVECPQErase();

	printf("TestVECPQSize()\n");
	TestVECPQSize();

	printf("TestVECPQClear()\n");
	TestVECPQClear();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}