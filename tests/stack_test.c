/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Stack.
 * Date: 26.11.2019
 * Language: C
 * Reviewer: Ben Step
 */

#include <stdio.h>

#include "stack.h"

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
struct Stack
{
	void *start;
	void *current;
	void *end;
	size_t element_size;

};

void TestStackCreate()
{	
	stack_t *s1 = StackCreate(10,3);
	stack_t *s2 = StackCreate(3,10);
	stack_t *s3 = StackCreate(1,1);

	RUN_TEST(10 == s1->element_size, "FAIL: RIGHT ELEMNT SIZE");
	RUN_TEST(3 == s2->element_size, "FAIL: RIGHT ELEMNT SIZE");
	RUN_TEST(1 == s3->element_size, "FAIL: RIGHT ELEMNT SIZE");
	StackDestroy(s1);
	StackDestroy(s2);
	StackDestroy(s3);
	printf("\n");
}

void TestStackDestroy()
{	
	stack_t *s1 = StackCreate(10,3);

	StackDestroy(s1);
	RUN_TEST(NULL != s1, "FAIL: STACK DESTROYD");

	printf("\n");
}

void TestStackPush()
{
	int x = 4;
	int *ptr = &x;
	stack_t *s1 = StackCreate(4,1);
	RUN_TEST(1 == StackPush(s1, ptr), "FAIL: STACK DESTROYD");
	StackDestroy(s1);
	printf("\n");
}

void TestStackIsEmpty()
{	
	int x = 1;
	stack_t *s1 = StackCreate(4,3);
	StackPush(s1,&x);
	RUN_TEST(!(1 == StackIsEmpty(s1)),"FAIL: STACK IS NOT EMPTY");
	RUN_TEST(0 == StackIsEmpty(s1),"FAIL: STACK IS EMPTY");
	StackPop(s1);
	RUN_TEST(1 == StackIsEmpty(s1),"FAIL: STACK IS EMPTY");
	StackDestroy(s1);
	printf("\n");
}

void TestStackSize()
{	
	int x = 1;
	int y = 2;
	int z = 3;
	stack_t *s1 = StackCreate(4,3);

	StackPush(s1,&x);
	StackPush(s1,&y);
	StackPush(s1,&z);

	RUN_TEST(3 == StackSize(s1),"FAIL STACK SIZE 1");
	RUN_TEST(!(4 == StackSize(s1)),"FAIL WRONG STACK SIZE");
	StackDestroy(s1);
	printf("\n");
}

void TestStackPeek()
{
	int x = 9;
	int y = 4;
	stack_t *s1 = StackCreate(4,3);
	StackPush(s1,&x);
	StackPush(s1,&y);
	
	RUN_TEST(4 == *(int*)StackPeek(s1),"FAIL: WRONG PEEK (4)");
	StackPop(s1);
	RUN_TEST(9 == *(int*)StackPeek(s1),"FAIL: WRONG PEEK (9)");
	StackPop(s1);
	RUN_TEST(NULL == StackPeek(s1),"FAIL: WRONG PEEK (9)");
	StackDestroy(s1);
	printf("\n");
}

void TestStackPop()
{
	int x = 9;
	int y = 4;
	stack_t *s1 = StackCreate(4,3);
	StackPush(s1,&x);
	StackPush(s1,&y);

	StackPop(s1);
	RUN_TEST(9 == (*(int*)StackPeek(s1)),"FAIL: WRONG PEEK (4)");
	StackPop(s1);
	RUN_TEST(NULL == StackPeek(s1),"FAIL: WRONG PEEK (9)");
	StackPop(s1);
	StackDestroy(s1);
	printf("\n");
}

void  TestStackRecursiveSort()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	stack_t *s1 = StackCreate(4,4);

	StackPush(s1,&d);		
	StackPush(s1,&c);
	StackPush(s1,&b);
	StackPush(s1,&a);

	while(!StackIsEmpty(s1))
	{
		printf("before: %d\n", *(int *)StackPopWithData(s1));
	}

	StackPush(s1,&d);		
	StackPush(s1,&c);
	StackPush(s1,&b);
	StackPush(s1,&a);

	StackRecursiveSort(s1);

	while(!StackIsEmpty(s1))
	{
		printf("after: %d\n",*(int *)StackPopWithData(s1));
	}

}

int main(int argc, char const *argv[])
{

	printf("TestStackCreate()\n");
	TestStackCreate();
	
	printf("TestStackDestroy()\n");
	TestStackDestroy();

	printf("TestStackPush()\n");
	TestStackPush();

	printf("TestStackIsEmpty()\n");
	TestStackIsEmpty();

	printf("TestStackIsEmpty()\n");
	TestStackSize();

	printf("TestStackPeek()\n");
	TestStackPeek();

	printf("TestStackPeek()\n");
	TestStackPop();

	printf("TestStackRecursiveSort()\n");
	TestStackRecursiveSort();

	UNUSED(argc);
	UNUSED(argv);

	return 0;
}