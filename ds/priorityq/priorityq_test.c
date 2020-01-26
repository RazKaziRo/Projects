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

void TestPQCreate()
{	
	size_t element_size = 4;
	pq_t *new_pq = PQCreate(&MyCompare, &element_size);
	RUN_TEST(0 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(0)");
	PQDestroy(new_pq);
	printf("\n");
}


void TestPQEnqueue()
{	
	int a = 5;
	int b = 15;
	int c = 20;
	int d = 25;

	pq_t *new_pq = PQCreate(&MyCompare, NULL);

	RUN_TEST(0 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(0)");
	PQEnqueue(new_pq,&a);
	RUN_TEST(1 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(1)");
	PQEnqueue(new_pq,&b);
	RUN_TEST(2 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(2)");
	PQEnqueue(new_pq,&c);
	PQEnqueue(new_pq,&d);

	PQClear(new_pq);
	RUN_TEST(0 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(0)");
	

	PQDestroy(new_pq);
	printf("\n");
}


void TestPQDequeue()
{
	int a = 5;
	int b = 15;
	int c = 20;
	int d = 25;

	pq_t *new_pq = PQCreate(&MyCompare, NULL);

	RUN_TEST(0 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(0)");
	PQEnqueue(new_pq,&a);
	RUN_TEST(1 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(1)");
	PQEnqueue(new_pq,&b);
	RUN_TEST(2 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(2)");
	PQEnqueue(new_pq,&c);
	PQEnqueue(new_pq,&d);

	PQDequeue(new_pq);
	PQClear(new_pq);

	RUN_TEST(0 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(0)");
	

	PQDestroy(new_pq);
	printf("\n");

}
/*
void TestPQPeek()
{
	int a = 10;
	int b = 20;

	pq_t *new_pq = PQCreate(&MyCompare, NULL);
	PQEnqueue(new_pq,&b);
	PQEnqueue(new_pq,&a);
 	RUN_TEST(a == *(int *)PQPeek(new_pq), "FAIL: WRONG DATA ON PEEK (a)");

	PQDestroy(new_pq);
	printf("\n");
}

void TestPQErase()
{
	int a = 10;
	int b = 20;

	pq_t *new_pq = PQCreate(&MyCompare, NULL);
	PQEnqueue(new_pq,&a);
	PQEnqueue(new_pq,&b);
	RUN_TEST(2 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(2)");
	RUN_TEST(a == *(int *)PQErase(new_pq, &FindData, &a), "FAIL: WRONG DATA (a)");
	RUN_TEST(NULL == PQErase(new_pq, &FindData, &a), "FAIL: WRONG DATA (a)");
	RUN_TEST(1 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(1)");

	PQDestroy(new_pq);
	printf("\n");

}

void TestPQSize()
{
	int a = 10;
	int b = 20;

	pq_t *new_pq = PQCreate(&MyCompare, NULL);
	PQEnqueue(new_pq,&a);
	PQEnqueue(new_pq,&b);
	RUN_TEST(2 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(2)");

	PQDestroy(new_pq);
	printf("\n");
}

void TestPQClear()
{
	int a = 10;
	int b = 20;

	pq_t *new_pq = PQCreate(&MyCompare, NULL);
	PQEnqueue(new_pq,&a);
	PQEnqueue(new_pq,&b);
	RUN_TEST(2 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(2)");
	PQClear(new_pq);
	RUN_TEST(0 == PQSize(new_pq), "FAIL: WRONG CREATE SIZE(0)");

	PQDestroy(new_pq);
	printf("\n");

}
*/
int main(int argc, char const *argv[])
{	
	printf("TestPQCreate()\n");
	TestPQCreate();

	printf("TestPQEnqueue()\n");
	TestPQEnqueue();

	printf("TestPQDequeue()\n");
	TestPQDequeue();
/*
	printf("TestPQPeek()\n");
	TestPQPeek();

	printf("TestPQErase()\n");
	TestPQErase();

	printf("TestPQSize()\n");
	TestPQSize();

	printf("TestPQClear()\n");
	TestPQClear();
*/
	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}