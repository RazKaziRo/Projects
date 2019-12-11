/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Sorted Linked List.
 * Date: 10.12.2019
 * Language: C
 * Reviewer: 
 */

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

void TestSLLFind()
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
	newSllIt = SLLBegin(newSll);

	newSllIt = SLLFind(newSll, &b, SLLBegin(newSll), SLLEnd(newSll));
	RUN_TEST(b == *(int *)SLLGetData(newSllIt), "FAIL: Wrong Data (b)" );
	newSllItStart = SLLBegin(newSll);
	newSllItEnd = SLLEnd(newSll);

	newSllIt = SLLFind(newSll, &d, newSllItStart, newSllItEnd);
	RUN_TEST(1 == SLLIsSameIter(SLLEnd(newSll), newSllIt), "FAIL: WRONG COMPARE (it = end)" );
	newSllIt = SLLFind(newSll, &e, newSllItStart, newSllItEnd);
	RUN_TEST(1 == SLLIsSameIter(SLLEnd(newSll), newSllIt), "FAIL: WRONG COMPARE (it = end)" );

	SortLLDestroy(newSll);
	printf("\n");
}	

void TestSLLFindBy()
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

	newSllItStart = SLLBegin(newSll);
	newSllItEnd = SLLEnd(newSll);

	newSllIt = SLLFindBy(newSll, newSllItStart, newSllItEnd, &FindData, &b);
	RUN_TEST(b == *(int *)SLLGetData(newSllIt), "FAIL: Wrong Data (b)" );
	newSllIt = SLLFindBy(newSll, newSllItStart, newSllItEnd, &FindData, &d);
	RUN_TEST(1 == SLLIsSameIter(SLLEnd(newSll), newSllIt), "FAIL: WRONG COMPARE (it = end)" );
	newSllIt = SLLFindBy(newSll, newSllItStart, newSllItEnd, &FindData, &e);
	RUN_TEST(1 == SLLIsSameIter(SLLEnd(newSll), newSllIt), "FAIL: WRONG COMPARE (it = end)" );

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSLLForEach()
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

	newSllItStart = SLLBegin(newSll);
	newSllItEnd = SLLEnd(newSll);

	RUN_TEST(0 == SLLForEach(newSllItStart, newSllItEnd, &AddNum, &d), "FAIL: add num For Each");
	RUN_TEST(6 == *(int *)SLLGetData(newSllItStart), "FAIL: Wrong Data (6)" );
	RUN_TEST(11 == *(int *)SLLGetData(SLLNext(newSllItStart)), "FAIL: Wrong Data (11)" );
	RUN_TEST(21 == *(int *)SLLGetData(SLLNext((SLLNext(newSllItStart)))), "FAIL: Wrong Data (21)" );

	SortLLDestroy(newSll);
	printf("\n");
}

void TestSLLMerge()
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

	SLLMerge(newSll1, newSll2);
	SLLForEach(SLLBegin(newSll1),SLLEnd(newSll1),&AddNum, &a);

	RUN_TEST(8 == SLLSize(newSll1), "FAIL WRONG SIZE (8)");
	RUN_TEST(f == *(int *)SLLGetData(SLLBegin(newSll1)), "FAIL: Wrong Data (f)");

	SortLLDestroy(newSll1);
	SortLLDestroy(newSll2);
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

	printf("TestSLLFind()\n");
	TestSLLFind();

	printf("TestSLLFindBy()\n");
	TestSLLFindBy();

	printf("TestSLLForEach()\n");
	TestSLLForEach();

	printf("TestSLLMerge()\n");
	TestSLLMerge();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}