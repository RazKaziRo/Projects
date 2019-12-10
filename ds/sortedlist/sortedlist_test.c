/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Sorted Linked List.
 * Date: 10.12.2019
 * Language: C
 * Reviewer: 
 */

#include <stdio.h>
#include <stdlib.h> /*free()*/

#include "sortedlist.h" /* Queue API Functions*/

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

int isBefore(const void *data1, const void *data2, void *param)
{
	UNUSED(param);
	return(*(int *)data1 > *(int *)data2);
}

void TestSortLLCreate()
{	

	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(1 == SLLIsEmpty(newSll), "FAIL SLL IS EMPTY(1)");
	SortLLDestroy(newSll);
	printf("\n");
}

void TestSLLIsEmpty()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(1 == SLLIsEmpty(newSll), "FAIL SLL IS EMPTY(1)");

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSLLSize()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(0 == SLLSize(newSll), "FAIL SLL IS EMPTY(0)");

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSLLBegin()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	sll_iterator_t newSllIt;
	newSllIt = SLLBegin(newSll);

	RUN_TEST((SLLEnd(newSll).current) == (newSllIt.current), "FAIL SLL IS EMPTY(0)");

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSLLEnd()
{
	sll_t *newSll = SortLLCreate(&isBefore, NULL);
	sll_iterator_t newSllIt;
	newSllIt = SLLEnd(newSll);

	RUN_TEST((SLLEnd(newSll).current) == (newSllIt.current), "FAIL SLL IS EMPTY(0)");

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSortLLInsert()
{	
	int a = 5;
	int b = 20;
	int c = 10;

	sll_t *newSll = SortLLCreate(&isBefore, NULL);
	sll_iterator_t newSllIt;
	newSllIt = SLLBegin(newSll);

	RUN_TEST (0 == SLLSize(newSll), "FAIL: WRONG SLL SIZE(0)");

	newSllIt = SortLLInsert(newSll,&a);
	RUN_TEST (1 == SLLSize(newSll), "FAIL: WRONG SLL SIZE(1)");
	RUN_TEST(a == *(int *)SLLGetData(newSllIt), "FAIL: Wrong Data (a)" );
	
	newSllIt = SortLLInsert(newSll,&b);
	RUN_TEST (2 == SLLSize(newSll), "FAIL: WRONG SLL SIZE(2)");
	RUN_TEST(b == *(int *)SLLGetData(newSllIt), "FAIL: Wrong Data (b)" );

	newSllIt = SortLLInsert(newSll,&c);
	RUN_TEST (3 == SLLSize(newSll), "FAIL: WRONG SLL SIZE(3)");
	newSllIt = SLLBegin(newSll);
	RUN_TEST(a == *(int *)SLLGetData(newSllIt), "FAIL: Wrong Data (a)" );
	newSllIt = SLLNext(newSllIt);
	RUN_TEST(c == *(int *)SLLGetData(newSllIt), "FAIL: Wrong Data (b)" );
	newSllIt = SLLNext(newSllIt);
	RUN_TEST(b == *(int *)SLLGetData(newSllIt), "FAIL: Wrong Data (c)" );

	SortLLDestroy(newSll);
	printf("\n");
}
						
int main(int argc, char const *argv[])
{	

	printf("TestSortLLCreate()\n");
	TestSortLLCreate();

	printf("TestSLLIsEmpty()\n");
	TestSLLIsEmpty();

	printf("TestSLLSize()\n");
	TestSLLSize();

	printf("TestSLLBegin()\n");
	TestSLLBegin();

	printf("TestSLLEnd()\n");
	TestSLLEnd();

	printf("TestSortLLInsert()\n");
	TestSortLLInsert();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}