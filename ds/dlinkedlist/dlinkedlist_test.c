/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Doubly Linked List.
 * Date: 08.12.2019
 * Language: C
 * Reviewer: Yonatan Zaken
 */

#include <stdio.h> /*printf()*/
#include <stdlib.h> /*free()*/
#include "dlinkedlist.h" /*DLL API Functions()*/

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

typedef struct DLLNode
{
	void *data;
	struct DLLNode *next;
	struct DLLNode *previous;
}dll_node_t;

struct DLL
{
	struct DLLNode head;
	struct DLLNode tail;
};

static int addNum(void *iterator_data, void *ap)
{
	*(int *)iterator_data += *(int *)ap;

	return 0;
}

static int findData(void *iterator_data, void *ap)
{	
	return(*(int *)iterator_data == *(int *)ap);
}

void TestDLLCreate()
{
	dll_t *newDll = DLLCreate();
	RUN_TEST(newDll->head.next == &newDll->tail, "FAIL: CREAT HEAD NEXT")
	RUN_TEST(newDll->tail.previous == &newDll->head, "FAIL: CREAT TAIL PREVIOUS")
	RUN_TEST(newDll->tail.data == NULL, "FAIL: CREAT TAIL DATA")
	RUN_TEST(newDll->head.data == NULL, "FAIL: CREAT HEAD DATA")
	FREE(newDll);
	printf("\n");
}

void TestDLLDestroy()
{
	dll_t *newDll = DLLCreate();
	DLLDestroy(newDll);
	printf("\n");
}

void TestDLLRemove()
{	
	int a = 10;
	dll_t *newDll = DLLCreate();
	iterator_t it = DLLBegin(newDll);
	DLLInsert(newDll,it, &a);
	it = DLLGetPrev(it);
	RUN_TEST(*(int *)it->data == a, "FAIL: Wrong Data (a)");
	RUN_TEST(it->next == &newDll->tail, "FAIL: Wrong NEXT (Tail)");
	RUN_TEST(it->previous == &newDll->head, "FAIL: Wrong previous (Head)");
	it = DLLRemove(it);
	RUN_TEST(it->previous == &newDll->head, "FAIL: Wrong previous (Head)");
	RUN_TEST(it->next == NULL, "FAIL: Wrong NEXT (NULL)");
	DLLDestroy(newDll);
	printf("\n");
}

void TestDLLPushBack()
{
	int a = 10;
	int b = 20;
	dll_t *newDll = DLLCreate();
	iterator_t it = DLLBegin(newDll);
	DLLInsert(newDll,it, &a);
	DLLPushBack(newDll, &b);

	RUN_TEST(* (int *)it->previous->data == b, "FAIL: Wrong DATA (b)");
	it = DLLEnd(newDll);
	it = it->previous;
	RUN_TEST(* (int *)it->previous->data == a, "FAIL: Wrong DATA (a)");
	RUN_TEST(* (int *)it->data == b, "FAIL: Wrong DATA (a)");
	RUN_TEST(it->next == &newDll->tail, "FAIL: Wrong DATA (a)");
	RUN_TEST(newDll->tail.previous == it, "FAIL: Wrong DATA (a)");
	RUN_TEST(newDll->head.next == it->previous, "FAIL: Wrong DATA (a)");
	DLLDestroy(newDll);
	printf("\n");
}

void TestDLLPushFront()
{
	int a = 10;
	int b = 20;
	dll_t *newDll = DLLCreate();
	iterator_t it = DLLBegin(newDll);
	DLLInsert(newDll,it, &a);
	DLLPushFront(newDll, &b);
	RUN_TEST(*(int *)newDll->head.next->data == b, "FAIL: Wrong Head Next Data(b)");
	RUN_TEST(*(int *)newDll->tail.previous->data == a, "FAIL: Wrong Head Next Data(b)");
	RUN_TEST(newDll->tail.previous == newDll->head.next->next, "FAIL: Wrong Head Next Data(b)");

	DLLDestroy(newDll);
	printf("\n");

}

void TestDLLPopBack()
{
	int a = 10;
	int b = 20;
	dll_t *newDll = DLLCreate();
	iterator_t it = DLLBegin(newDll);
	DLLInsert(newDll,it, &a);
	DLLInsert(newDll,it, &b);
	RUN_TEST(*(int *)newDll->head.next->data == a, "FAIL: Wrong Head Next Data(a)");
	RUN_TEST(*(int *)newDll->tail.previous->data == b, "FAIL: Wrong Head Next Data(a)");
	RUN_TEST(newDll->tail.previous == newDll->head.next->next, "FAIL: Wrong Head Next Data(a)");
	DLLPopBack(newDll);
	RUN_TEST(*(int *)newDll->tail.previous->data == a, "FAIL: Wrong Head Next Data(a)");
	RUN_TEST(*(int *)newDll->head.next->data == a, "FAIL: Wrong Head Next Data(a)");
	RUN_TEST(newDll->tail.previous->previous == &newDll->head, "FAIL: Wrong Head Next Data(a)");
	DLLPopBack(newDll);
	RUN_TEST(newDll->tail.previous == &newDll->head, "FAIL: Tail previous (head)");
	RUN_TEST(newDll->head.next == &newDll->tail, "FAIL: HEAD NEXT (tail)");

	DLLDestroy(newDll);
	printf("\n");
}


void TestDLLPopFront()
{
	int a = 10;
	int b = 20;
	dll_t *newDll = DLLCreate();
	iterator_t it = DLLBegin(newDll);
	DLLInsert(newDll,it, &a);
	DLLInsert(newDll,it, &b);

	RUN_TEST(*(int *)newDll->head.next->data == a, "FAIL: Wrong Head Next Data(a)");
	RUN_TEST(*(int *)newDll->tail.previous->data == b, "FAIL: Wrong Head Next Data(a)");
	RUN_TEST(newDll->tail.previous->previous->previous == &newDll->head, "FAIL: previous previous (head)");
	DLLPopFront(newDll);
	RUN_TEST(newDll->tail.previous->previous == &newDll->head, "FAIL: previous previous (head)");
	RUN_TEST(*(int *)newDll->head.next->data == b, "FAIL: Wrong Head Next Data(a)");
	RUN_TEST(*(int *)newDll->tail.previous->data == b, "FAIL: Wrong Head Next Data(a)");

	DLLDestroy(newDll);
	printf("\n");
}

void TestDLLSplice()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;

	dll_t *newDll1 = DLLCreate();
	dll_t *newDll2 = DLLCreate();

	iterator_t it1start = DLLBegin(newDll1);
	iterator_t it1end = DLLEnd(newDll1);
	
	iterator_t it1new = DLLEnd(newDll1);
	
	iterator_t it2start = DLLBegin(newDll2);
	iterator_t it2end = DLLEnd(newDll2);
	iterator_t it2holder = DLLBegin(newDll2);

	it1end = it1end->previous;
	it1new = it1new->previous;

	DLLInsert(newDll1,it1start, &a);
	DLLInsert(newDll1,it1start, &b);
	it1start = DLLBegin(newDll1);
	it1end = DLLEnd(newDll1);
	it1end = it1end->previous;
	DLLInsert(newDll2,it2start, &c);
	DLLInsert(newDll2,it2start, &d);
	it2holder = DLLBegin(newDll2);
	it2start = DLLBegin(newDll2);
	it2end = DLLEnd(newDll2);
	it2holder = DLLGetPrev(it2holder);

	RUN_TEST(it2start->previous == &newDll2->head, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(it2end == &newDll2->tail, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(it2holder == &newDll2->head, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(it2holder->data == NULL, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST( 2 == DLLSize(newDll1), "FAIL: WRONG SIZE DLL2 (2)");
	RUN_TEST( 2 == DLLSize(newDll2), "FAIL: WRONG SIZE DLL2 (2)");

	it1new = DLLSplice(it2start,it2end,it1end);

	RUN_TEST(it2holder->data == NULL, "FAIL: WRONG DATA HEAD (NULL)")
	RUN_TEST(*(int *)it2start->data == c, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(*(int *)it2start->next->data == d, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(it2end== &newDll2->tail, "FAIL: WRONG DATA it2node (NULL)")

	RUN_TEST(*(int *)it1new->data == b, "FAIL: WRONG DATA NEW (b)")

	RUN_TEST(*(int *)it1new->previous->data == a, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(*(int *)it1new->next->data == c, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(*(int *)it1new->next->next->data == d, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(it1new->next->next->next == &newDll1->tail, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST(it1new->previous->previous == &newDll1->head, "FAIL: WRONG DATA NEW (b)")
	RUN_TEST( 4 == DLLSize(newDll1), "FAIL: WRONG SIZE DLL2 (4)");
	RUN_TEST( 0 == DLLSize(newDll2), "FAIL: WRONG SIZE DLL2 (0)");
	RUN_TEST(it2holder->next == &newDll2->tail, "FAIL: WRONG DATA");

	DLLDestroy(newDll1);
	DLLDestroy(newDll2);

	printf("\n");
}

void TestDLLForEach()
{
	int a = 10;
	int b = 20;
	int c = 5;

	dll_t *newDll = DLLCreate();
	iterator_t it_end = DLLBegin(newDll);
	iterator_t it_start = DLLBegin(newDll);
	DLLInsert(newDll,it_start, &a);
	DLLInsert(newDll,it_start, &b);
	it_start = DLLBegin(newDll);
	it_end = DLLEnd(newDll);

	DLLForEach(it_start, it_end, &addNum, &c);
	RUN_TEST(15 == *(int *)it_start->data, "FAIL: addNum ForEach(+5)");

	DLLDestroy(newDll);
	printf("\n");
}

void TestDLLFind()
{
	int a = 10;
	int b = 20;
	int c = 5;
	dll_t *newDll = DLLCreate();
	iterator_t it = DLLBegin(newDll);
	iterator_t it_start;
	iterator_t it_end;
	iterator_t it_result;
	DLLInsert(newDll,it, &a);
	DLLInsert(newDll,it, &b);
	RUN_TEST(*(int *)it->previous->data == b, "FAIL WRONG IT RETURNED");
	RUN_TEST(*(int *)it->previous->data == b, "FAIL WRONG IT RETURNED");
	it = DLLBegin(newDll);
	RUN_TEST(*(int *)it->data == a, "FAIL WRONG IT RETURNED");

	it_start = DLLBegin(newDll);
	it_end = DLLEnd(newDll);
	it_result = DLLFind(it_start, it_end, &findData, &a);

	RUN_TEST(*(int *)it_result->data == a, "FAIL WRONG IT RETURNED");
	RUN_TEST(it_result->previous == &newDll->head, "FAIL previous (head)");
	it_result = DLLFind(it_start, it_end, &findData, &b);
	RUN_TEST(*(int *)it_result->data == b, "FAIL WRONG IT RETURNED");
	it_result = DLLFind(it_start, it_end, &findData, &c);
	RUN_TEST(it_result == &newDll->tail, "FAIL WRONG IT RETURNED");

	DLLDestroy(newDll);
	printf("\n");


}

void TestDLLSize()
{
	int a = 10;
	int b = 20;

	dll_t *newDll = DLLCreate();
	iterator_t it = DLLBegin(newDll);
	RUN_TEST(0 == DLLSize(newDll), "FAIL WRONG IT RETURNED");
	DLLInsert(newDll,it, &a);
	RUN_TEST(1 == DLLSize(newDll), "FAIL WRONG IT RETURNED");
	DLLInsert(newDll,it, &b);
	RUN_TEST(2 == DLLSize(newDll), "FAIL WRONG IT RETURNED");

	DLLDestroy(newDll);
	printf("\n");
}

int main(int argc, char const *argv[])
{

	printf("TestDLLCreate()\n");
	TestDLLCreate();

	printf("TestDLLDestroy()\n");
	TestDLLDestroy();

	printf("TestDLLRemove()\n");
	TestDLLRemove();

	printf("TestDLLPushBack()\n");
	TestDLLPushBack();

	printf("DLLPushFront()\n");
	TestDLLPushFront();

	printf("TestDLLPopBack()\n");
	TestDLLPopBack();

	printf("TestDLLPopFront()\n");
	TestDLLPopFront();

	printf("TestDLLSplice()\n");
	TestDLLSplice();

	printf("TestDLLForEach()\n");
	TestDLLForEach();

	printf("TestDLLFind()\n");
	TestDLLFind();

	printf("TestDLLSize()\n");
	TestDLLSize();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}