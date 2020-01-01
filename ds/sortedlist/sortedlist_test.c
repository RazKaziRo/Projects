/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Sorted Linked List.
 * Date: 10.12.2019
 * Language: C
 * Reviewer: 
 */

#include <stdlib.h> /*free()*/
#include <stdio.h> /*printf()*/

#include "sortedlist.h"

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

int isBefore(const void *data1, const void *data2, void *param)
{
	UNUSED(param);
	return(*(int *)data1 > *(int *)data2);
}

static int FindData(void *iterator_data, void *ap)
{	
	return(*(int *)iterator_data == *(int *)ap);
}

static int AddNum(void *iterator_data, void *ap)
{	
	*(int *)iterator_data += *(int *)ap;

	return 0;
}

void TestSortLLCreate()
{	
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(1 == SortLLIsEmpty(newSll), "FAIL SLL IS EMPTY(1)");
	SortLLDestroy(newSll);
	printf("\n");
}

void TestSortLLIsEmpty()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(1 == SortLLIsEmpty(newSll), "FAIL SLL IS EMPTY(1)");

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSortLLSize()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	RUN_TEST(0 == SortLLSize(newSll), "FAIL SLL IS EMPTY(0)");

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSortLLBegin()
{
	sll_t *newSll = SortLLCreate (&isBefore, NULL);
	sll_iterator_t newSllIt;
	newSllIt = SortLLBegin(newSll);

	RUN_TEST((SortLLEnd(newSll).current) == (newSllIt.current), "FAIL SLL IS EMPTY(0)");

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSortLLEnd()
{
	sll_t *newSll = SortLLCreate(&isBefore, NULL);
	sll_iterator_t newSllIt;
	newSllIt = SortLLEnd(newSll);

	RUN_TEST((SortLLEnd(newSll).current) == (newSllIt.current), "FAIL SLL IS EMPTY(0)");

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
	newSllIt = SortLLBegin(newSll);

	RUN_TEST (0 == SortLLSize(newSll), "FAIL: WRONG SLL SIZE(0)");

	newSllIt = SortLLInsert(newSll,&a);
	RUN_TEST (1 == SortLLSize(newSll), "FAIL: WRONG SLL SIZE(1)");
	RUN_TEST(a == *(int *)SortLLGetData(newSllIt), "FAIL: Wrong Data (a)" );
	
	newSllIt = SortLLInsert(newSll,&b);
	RUN_TEST (2 == SortLLSize(newSll), "FAIL: WRONG SLL SIZE(2)");
	RUN_TEST(b == *(int *)SortLLGetData(newSllIt), "FAIL: Wrong Data (b)" );

	newSllIt = SortLLInsert(newSll,&c);
	RUN_TEST (3 == SortLLSize(newSll), "FAIL: WRONG SLL SIZE(3)");
	newSllIt = SortLLBegin(newSll);
	RUN_TEST(a == *(int *)SortLLGetData(newSllIt), "FAIL: Wrong Data (a)" );
	newSllIt = SortLLNext(newSllIt);
	RUN_TEST(c == *(int *)SortLLGetData(newSllIt), "FAIL: Wrong Data (b)" );
	newSllIt = SortLLNext(newSllIt);
	RUN_TEST(b == *(int *)SortLLGetData(newSllIt), "FAIL: Wrong Data (c)" );

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSortLLFind()
{	
	int a = 5;
	int b = 20;
	int c = 10;
	int d = 1;
	int e = 50;

	sll_t *newSll = SortLLCreate(&isBefore, NULL);
	sll_iterator_t newSllIt;
	sll_iterator_t newSllItStart;
	sll_iterator_t newSllItEnd;

	newSllIt = SortLLInsert(newSll,&a);
	newSllIt = SortLLInsert(newSll,&b);
	newSllIt = SortLLInsert(newSll,&c);
	newSllIt = SortLLBegin(newSll);

	newSllIt = SortLLFind(newSll, &b, SortLLBegin(newSll), SortLLEnd(newSll));
	RUN_TEST(b == *(int *)SortLLGetData(newSllIt), "FAIL: Wrong Data (b)" );
	newSllItStart = SortLLBegin(newSll);
	newSllItEnd = SortLLEnd(newSll);

	newSllIt = SortLLFind(newSll, &d, newSllItStart, newSllItEnd);
	RUN_TEST(1 == SortLLIsSameIter(SortLLEnd(newSll), newSllIt), "FAIL: WRONG COMPARE (it = end)" );
	newSllIt = SortLLFind(newSll, &e, newSllItStart, newSllItEnd);
	RUN_TEST(1 == SortLLIsSameIter(SortLLEnd(newSll), newSllIt), "FAIL: WRONG COMPARE (it = end)" );

	SortLLDestroy(newSll);
	printf("\n");
}	

void TestSortLLFindBy()
{
	int a = 5;
	int b = 20;
	int c = 10;
	int d = 1;
	int e = 50;

	sll_t *newSll = SortLLCreate(&isBefore, NULL);
	sll_iterator_t newSllIt;
	sll_iterator_t newSllItStart;
	sll_iterator_t newSllItEnd;

	newSllIt = SortLLInsert(newSll,&a);
	newSllIt = SortLLInsert(newSll,&b);
	newSllIt = SortLLInsert(newSll,&c);

	newSllItStart = SortLLBegin(newSll);
	newSllItEnd = SortLLEnd(newSll);

	newSllIt = SortLLFindBy(newSll, newSllItStart, newSllItEnd, &FindData, &b);
	RUN_TEST(b == *(int *)SortLLGetData(newSllIt), "FAIL: Wrong Data (b)" );
	newSllIt = SortLLFindBy(newSll, newSllItStart, newSllItEnd, &FindData, &d);
	RUN_TEST(1 == SortLLIsSameIter(SortLLEnd(newSll), newSllIt), "FAIL: WRONG COMPARE (it = end)" );
	newSllIt = SortLLFindBy(newSll, newSllItStart, newSllItEnd, &FindData, &e);
	RUN_TEST(1 == SortLLIsSameIter(SortLLEnd(newSll), newSllIt), "FAIL: WRONG COMPARE (it = end)" );

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSortLLForEach()
{
	int a = 5;
	int b = 20;
	int c = 10;
	int d = 1;

	sll_t *newSll = SortLLCreate(&isBefore, NULL);
	sll_iterator_t newSllItStart;
	sll_iterator_t newSllItEnd;

	SortLLInsert(newSll,&a);
	SortLLInsert(newSll,&b);
	SortLLInsert(newSll,&c);

	newSllItStart = SortLLBegin(newSll);
	newSllItEnd = SortLLEnd(newSll);

	RUN_TEST(0 == SortLLForEach(newSllItStart, newSllItEnd, &AddNum, &d), "FAIL: add num For Each");
	RUN_TEST(6 == *(int *)SortLLGetData(newSllItStart), "FAIL: Wrong Data (6)" );
	RUN_TEST(11 == *(int *)SortLLGetData(SortLLNext(newSllItStart)), "FAIL: Wrong Data (11)" );
	RUN_TEST(21 == *(int *)SortLLGetData(SortLLNext((SortLLNext(newSllItStart)))), "FAIL: Wrong Data (21)" );

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSortLLMerge()
{
	int a = 3;
	int b = 5;
	int c = 7;

	int d = 2;
	int e = 4;
	int f = 1;
	int g = 6;
	int h = 22;


	sll_t *newSll1 = SortLLCreate(&isBefore, NULL);
	sll_t *newSll2 = SortLLCreate(&isBefore, NULL);

	SortLLInsert(newSll1,&a);
	SortLLInsert(newSll1,&b);
	SortLLInsert(newSll1,&c);

	SortLLInsert(newSll2,&d);
	SortLLInsert(newSll2,&e);
	SortLLInsert(newSll2,&f);
	SortLLInsert(newSll2,&g);
	SortLLInsert(newSll2,&h);

	SortLLMerge(newSll1, newSll2);
	SortLLForEach(SortLLBegin(newSll1),SortLLEnd(newSll1),&AddNum, &a);

	RUN_TEST(8 == SortLLSize(newSll1), "FAIL WRONG SIZE (8)");
	RUN_TEST(f == *(int *)SortLLGetData(SortLLBegin(newSll1)), "FAIL: Wrong Data (f)");

	SortLLDestroy(newSll1);
	SortLLDestroy(newSll2);
	printf("\n");

}	
						
int main(int argc, char const *argv[])
{	

	printf("TestSortLLCreate()\n");
	TestSortLLCreate();

	printf("TestSLLIsEmpty()\n");
	TestSortLLIsEmpty();

	printf("TestSLLSize()\n");
	TestSortLLSize();

	printf("TestSLLBegin()\n");
	TestSortLLBegin();

	printf("TestSLLEnd()\n");
	TestSortLLEnd();

	printf("TestSortLLInsert()\n");
	TestSortLLInsert();

	printf("TestSLLFind()\n");
	TestSortLLFind();

	printf("TestSLLFindBy()\n");
	TestSortLLFindBy();

	printf("TestSLLForEach()\n");
	TestSortLLForEach();

	printf("TestSLLMerge()\n");
	TestSortLLMerge();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}
