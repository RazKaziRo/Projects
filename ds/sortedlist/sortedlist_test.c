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
	return(*(int *)data1 < *(int *)data2);
}

void TestSortLLCreate()
{	

	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(1 == SLLIsEmpty(newSll), "FAIL SLL IS EMPTY(1)");
	printf("\n");
}

void TestSLLIsEmpty()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(1 == SLLIsEmpty(newSll), "FAIL SLL IS EMPTY(1)");

	printf("\n");
}

void TestSLLSize()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(0 == SLLSize(newSll), "FAIL SLL IS EMPTY(0)");

	printf("\n");
}

void TestSLLBegin()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	sll_iterator_t newSllIt;
	newSllIt = SLLBegin(newSll);

	RUN_TEST((SLLEnd(newSll).current) == (newSllIt.current), "FAIL SLL IS EMPTY(0)");

	printf("\n");
}

void TestSLLEnd()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	sll_iterator_t newSllIt;
	newSllIt = SLLEnd(newSll);

	RUN_TEST((SLLEnd(newSll).current) == (newSllIt.current), "FAIL SLL IS EMPTY(0)");

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

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}