/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Queue.
 * Date: 04.12.2019
 * Language: C
 * Reviewer: Eliya Goldfisher
 */
#include <stdio.h>
#include <stdlib.h> /*free()*/

#include "queue.h" /* Queue API Functions*/

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

struct Queue
{
	node_t *front;
	node_t *rear;
};

void TestQCreate()
{

	queue_t *newQueue = QCreate();
	RUN_TEST(1 == (newQueue->front->next == newQueue->rear), "FAIL: QF->NEXT = QR");

	SLLDestroy(newQueue->front);
	FREE(newQueue);
	printf("\n");

}	

void TestQEnqueue()
{
	int a = 10;

	queue_t *newQueue = QCreate();
	QEnqueue(newQueue, &a);
	RUN_TEST(a == *(int *)(newQueue->front->next->data), "FAIL: QF->NEXT->DT = 10");

	SLLDestroy(newQueue->front);
	FREE(newQueue);
	printf("\n");
}

void TestQDequeue()
{
	int a = 10;
	int b = 20;
	int c = 30;

	queue_t *newQueue = QCreate();
	QEnqueue(newQueue, &a);
	QEnqueue(newQueue, &b);
	QEnqueue(newQueue, &c);

	RUN_TEST(a == *(int *)(newQueue->front->next->data), "FAIL: QF->NEXT->DT = 10");
	QDequeue(newQueue);
	RUN_TEST(b == *(int *)(newQueue->front->next->data), "FAIL: QF->NEXT->DT = 20");
	QDequeue(newQueue);
	RUN_TEST(c == *(int *)(newQueue->front->next->data), "FAIL: QF->NEXT->DT = 30");

	SLLDestroy(newQueue->front);
	FREE(newQueue);
	printf("\n");
}

void TestQSize()
{
	int a = 10;
	int b = 20;
	int c = 30;

	queue_t *newQueue = QCreate();
	QEnqueue(newQueue, &a);
	QEnqueue(newQueue, &b);
	QEnqueue(newQueue, &c);

	RUN_TEST(3 == QSize(newQueue), "FAIL: Wrong Size (3)");
	QDequeue(newQueue);
	RUN_TEST(2 == QSize(newQueue), "FAIL: Wrong Size (2)");

	SLLDestroy(newQueue->front);
	FREE(newQueue);
	printf("\n");
}

void TestQPeek()
{
	int a = 10;
	int b = 20;
	int c = 30;

	queue_t *newQueue = QCreate();
	QEnqueue(newQueue, &a);
	QEnqueue(newQueue, &b);
	QEnqueue(newQueue, &c);

	RUN_TEST(a == *(int *)QPeek(newQueue), "FAIL Peek a");
	QDequeue(newQueue);
	RUN_TEST(b == *(int *)QPeek(newQueue), "FAIL Peek b");

	SLLDestroy(newQueue->front);
	FREE(newQueue);
	printf("\n");
}

void TestQIsEmpty()
{
	int a = 10;

	queue_t *newQueue = QCreate();
	RUN_TEST(1 == QIsEmpty(newQueue), "FAIL QIsEmpty 1");
	QEnqueue(newQueue, &a);
	RUN_TEST(0 == QIsEmpty(newQueue), "FAIL QIsEmpty 0");

	SLLDestroy(newQueue->front);
	FREE(newQueue);
	printf("\n");
}

void TestQDestroy()
{
	queue_t *newQueue = QCreate();
	QDestroy(newQueue);
	printf("\n");
}

void TestQAppend()
{
	int a = 10;
	int b = 20;
	int c = 30;

	int d = 40;
	int e = 50;
	int f = 60;

	queue_t *newQueue1 = QCreate();
	queue_t *newQueue2 = QCreate();

	QEnqueue(newQueue1, &a);
	QEnqueue(newQueue1, &b);
	QEnqueue(newQueue1, &c);

	QEnqueue(newQueue2, &d);
	QEnqueue(newQueue2, &e);
	QEnqueue(newQueue2, &f);

	QAppend(newQueue1, newQueue2);
	RUN_TEST(6 == QSize(newQueue1), "FAIL: Wrong Size (6)");
	QDequeue(newQueue1);
	QDequeue(newQueue1);
	RUN_TEST(30 == *(int *)QPeek(newQueue1), "FAIL Peek c");
	RUN_TEST(4 == QSize(newQueue1), "FAIL: Wrong Size (4)");
	QDequeue(newQueue1);
	RUN_TEST(40 == *(int *)QPeek(newQueue1), "FAIL Peek d");
	RUN_TEST(3 == QSize(newQueue1), "FAIL: Wrong Size (3)");

	QDestroy(newQueue1);
}

							
int main(int argc, char const *argv[])
{

	printf("TestQCreate()\n");
	TestQCreate();

	printf("TestQEnqueue()\n");
	TestQEnqueue();

	printf("TestQDequeue()\n");
	TestQDequeue();

	printf("TestQSize()\n");
	TestQSize();

	printf("TestQPeek()\n");
	TestQPeek();

	printf("TestQIsEmpty()\n");
	TestQIsEmpty();

	printf("TestQDestroy()\n");
	TestQDestroy();

	printf("TestQAppend()\n");
	TestQAppend();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}