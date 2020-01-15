/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Single Linked List.
 * Date: 03.12.2019
 * Language: C
 * Reviewer: Itai Marienberg
 */

#include <stdio.h> /*printf()*/
#include <stdlib.h> /*free()*/

#include "slinkedlist.h" /*Single Linked List API Functions*/

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
#define FREE(ptr) free(ptr); ptr=NULL;							

static int isMatch(void *node, void *additional)
{
	node_t *check_node = (node_t*)node;

	if(*(int *)additional == (*(int *)check_node->data))
	{
		return 1;
	}
	return 0;
}

static int addOne(void *node, void *additional)
{
	node_t *node_runner = (node_t*)node;

	if(NULL != node_runner)
	{
		*(int *)node_runner->data += *(int *)additional;
	}
	return (NULL == node_runner);
}

void TestSLLCreateNode()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	int a = 10;
	int b = 20;
	n2 = SLLCreateNode(NULL,&b);
	n1 = SLLCreateNode(n2,&a);

	RUN_TEST(a == *(int *)n1->data, "FAIL: Wrong Data (10)");
	RUN_TEST(n2 == n1->next, "FAIL: n1->next(NULL)");
	RUN_TEST(b == *(int *)n2->data, "FAIL: Wrong Data (20)");
	RUN_TEST(NULL == n2->next, "FAIL: n2->next(n1)");

	FREE(n1);
	FREE(n2);

	printf("\n");
}

void TestSLLDestroy()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *head = NULL;

	int a = 10;
	int b = 20;
	int c = 30;

	n3 = SLLCreateNode(NULL,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);
	head = n1;

	RUN_TEST(n2 == n1->next, "FAIL: n2->next(n3)");
	RUN_TEST(n3 == n2->next, "FAIL: n2->next(n3)");
	RUN_TEST(NULL == n3->next, "FAIL: n3->next(NULL)");
	SLLDestroy(head);

	printf("\n");
}

void TestSLLInsert()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	n3 = SLLCreateNode(NULL,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);
	n4 = SLLCreateNode(NULL,&d);

	SLLInsert(n4,n2);

	RUN_TEST(b == *(int *)n4->data, "FAIL: Wrong Data (b)");
	RUN_TEST(d == *(int *)n2->data, "FAIL: Wrong Data (d)");
	RUN_TEST(c == *(int *)n3->data, "FAIL: Wrong Data (c)");
	RUN_TEST(a == *(int *)n1->data, "FAIL: Wrong Data (a)");
	RUN_TEST(n3 == n4->next, "FAIL: n4->next (n2)");
	RUN_TEST(NULL == n3->next, "FAIL: n3->next (NULL)");
	RUN_TEST(n4 == n2->next, "FAIL: n2->next (n3)");
	RUN_TEST(n2 == n1->next, "FAIL: n1->next (n4)");
	RUN_TEST(4 == SLLSize(n1), "FAIL: Size (4)");
	SLLDestroy(n1);

	printf("\n");

}
void TestSLLInsertAfter()
{	
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	n3 = SLLCreateNode(NULL,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);
	n4 = SLLCreateNode(NULL,&d);

	SLLInsertAfter(n4,n2);
	RUN_TEST(d == *(int *)n4->data, "FAIL: Wrong Data (d)");
	RUN_TEST(NULL == n3->next, "FAIL: n3->next (NULL)");
	RUN_TEST(n3 == n4->next, "FAIL: n4->next (n3)");
	RUN_TEST(n4 == n2->next, "FAIL: n2->next (n4)");
	RUN_TEST(n2 == n1->next, "FAIL: n1->next (n2)");
	SLLDestroy(n1);

	printf("\n");
}

void TestSLLSize()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	n3 = SLLCreateNode(NULL,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);
	RUN_TEST(3 == SLLSize(n1), "FAIL: Wrong Size (3)");

	n4 = SLLCreateNode(NULL,&d);
	n3->next = n4;
	RUN_TEST(4 == SLLSize(n1), "FAIL: Wrong Size (4)");
	RUN_TEST(NULL == n4->next, "FAIL: n4->next (NULL)");
	RUN_TEST(n4 == n3->next, "FAIL: n3->next (NULL)");
	SLLDestroy(n1);

	printf("\n");
}

void TestSLLRemoveNode()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	
	n3 = SLLCreateNode(NULL,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);

	RUN_TEST(3 == SLLSize(n1), "FAIL: Wrong Size (3)");
	SLLRemoveNode(n2);
	RUN_TEST(2 == SLLSize(n1), "FAIL: Wrong Size (2)");
	RUN_TEST(NULL == n2->next, "FAIL: n2->next (NULL)");
	RUN_TEST(n2 == n1->next, "FAIL: n1->next (n2)");
	RUN_TEST(c == *(int *)n2->data, "FAIL: Wrong Data (c)");
	RUN_TEST(a == *(int *)n1->data, "FAIL: Wrong Data (c)");

	SLLDestroy(n1);

	printf("\n");

}

void TestSLLRemoveAfter()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	n4 = SLLCreateNode(NULL,&d);
	n3 = SLLCreateNode(n4,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);

	RUN_TEST(4 == SLLSize(n1), "FAIL: Wrong Size (4)");
	RUN_TEST(n3 == n2->next, "FAIL: n2->next (n3)");
	SLLRemoveAfter(n2);
	RUN_TEST(3 == SLLSize(n1), "FAIL: Wrong Size (3)");
	RUN_TEST(n4 == n2->next, "FAIL: n2->next (n4)");
	RUN_TEST(b == *(int *)n2->data, "FAIL: n2->data (b)");
	RUN_TEST(d == *(int *)n4->data, "FAIL: n2->data (d)");

	SLLDestroy(n1);

	printf("\n");
}

void TestSLLGetNode()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;
	node_t *result = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	n4 = SLLCreateNode(NULL,&d);
	n3 = SLLCreateNode(n4,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);

	result = SLLGetNode(n1, &isMatch, &b);
	RUN_TEST(n2 == result, "FAIL: n2 == result");
	result = SLLGetNode(n1, &isMatch, &d);
	RUN_TEST(n4 == result, "FAIL: n4 == result");
	RUN_TEST(4 == SLLSize(n1), "FAIL: Wrong Size (4)");

	SLLDestroy(n1);

	printf("\n");

}

void TestSLLForEach()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int add = 5;

	n4 = SLLCreateNode(NULL,&d);
	n3 = SLLCreateNode(n4,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);

	RUN_TEST(a == *(int *)n1->data, "FAIL: n1->data (a+5)");
	RUN_TEST(b == *(int *)n2->data, "FAIL: n2->data (b+5)");
	RUN_TEST(c == *(int *)n3->data, "FAIL: n3->data (c+5)");
	RUN_TEST(d == *(int *)n4->data, "FAIL: n4->data (d+5)");

	SLLForEach(n1, &addOne, &add);

	RUN_TEST(15 == *(int *)n1->data, "FAIL: n1->data (a+5)");
	RUN_TEST(25 == *(int *)n2->data, "FAIL: n2->data (b+5)");
	RUN_TEST(35 == *(int *)n3->data, "FAIL: n3->data (c+5)");
	RUN_TEST(45 == *(int *)n4->data, "FAIL: n4->data (d+5)");

	SLLDestroy(n1);

	printf("\n");
}

void TestSLLFlip()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;
	node_t *head = n1;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	n4 = SLLCreateNode(NULL,&d);
	n3 = SLLCreateNode(n4,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);

	head = SLLFlip(n1);
	RUN_TEST(head == n4, "FAIL: head == n4");
	RUN_TEST(n3 == n4->next, "FAIL: n4->next (n3)");
	RUN_TEST(n2 == n3->next, "FAIL: n3->next (n2)");
	RUN_TEST(n1 == n2->next, "FAIL: n2->next (n1)");
	RUN_TEST(NULL == n1->next, "FAIL: n1->next (NULL)");

	SLLDestroy(n4);

	printf("\n");
}

void TestSLLRecursionFlip()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;
	node_t *n5 = NULL;
	node_t *head = n1;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;

	n5 = SLLCreateNode(NULL,&e);
	n4 = SLLCreateNode(n5,&d);
	n3 = SLLCreateNode(n4,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);

	head = SLLRecursionFlip(n1);
	RUN_TEST(head == n5, "FAIL: head == n5");
	RUN_TEST(n4 == n5->next, "FAIL: n4->next (n3)");
	RUN_TEST(n3 == n4->next, "FAIL: n4->next (n3)");
	RUN_TEST(n2 == n3->next, "FAIL: n3->next (n2)");
	RUN_TEST(n1 == n2->next, "FAIL: n2->next (nvlgd1)");
	RUN_TEST(NULL == n1->next, "FAIL: n1->next (NULL)");

	SLLDestroy(head);

	printf("\n");
}

void TestSLLHasLoop()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	n4 = SLLCreateNode(NULL,&d);
	n3 = SLLCreateNode(n4,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);
	n4->next = n2;

	RUN_TEST(1 == SLLHasLoop(n1), "FAIL: Has Loop");
	n4->next = NULL;
	RUN_TEST(0 == SLLHasLoop(n1), "FAIL: No LOOP");

	SLLDestroy(n1);

	printf("\n");
}

void TestSLLFindIntersection()
{
	node_t *n1 = NULL;
	node_t *n2 = NULL;
	node_t *n3 = NULL;
	node_t *n4 = NULL;

	node_t *n5 = NULL;
	node_t *n6 = NULL;
	node_t *n7 = NULL;
	node_t *result = NULL;

	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;
	int f = 60;
	int g = 70;

	n4 = SLLCreateNode(NULL,&d);
	n3 = SLLCreateNode(n4,&c);
	n2 = SLLCreateNode(n3,&b);
	n1 = SLLCreateNode(n2,&a);

	n7 = SLLCreateNode(n3,&g);
	n6 = SLLCreateNode(n7,&f);
	n5 = SLLCreateNode(n6,&e);

	result = SLLFindIntersection(n1,n5);

	RUN_TEST(n3 == result, "FAIL: n3 == result");
	n7->next = NULL;
	SLLDestroy(n5);
	SLLDestroy(n1);

	printf("\n");
}

int main(int argc, char const *argv[])
{

/*
	printf("TestSLLCreateNode()\n");
	TestSLLCreateNode();

	printf("TestSLLDestroy()\n");
	TestSLLDestroy();

	printf("TestSLLInsert()\n");
	TestSLLInsert();

	printf("TestSLLInsertAfter()\n");
	TestSLLInsertAfter();

	printf("TestSLLSize()\n");
	TestSLLSize();

	printf("TestSLLRemoveNode()\n");
	TestSLLRemoveNode();

	printf("TestSLLRemoveAfter()\n");
	TestSLLRemoveAfter();

	printf("TestSLLGetNode()\n");
	TestSLLGetNode();

	printf("TestSLLForEach()\n");
	TestSLLForEach();	

	printf("TestSLLFlip()\n");
	TestSLLFlip();

	printf("TestSLLHasLoop()\n");
	TestSLLHasLoop();

	printf("TestSLLFindIntersection()\n");
	TestSLLFindIntersection();
*/
	printf("TestSLLRecursionFlip()\n");
	TestSLLRecursionFlip();

	UNUSED(argc);
	UNUSED(argv);
	return 0;
}
