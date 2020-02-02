/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Binary Search Tree.
 * Date: 08.01.2020
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#include <stdio.h> /*printf()*/

#include "bst.h"

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

static int DataCmp(const void *user_data, const void *node_data, void *param)
{	
	UNUSED(param);
	return (*(int *)user_data > *(int *)node_data ? 1 : 0);
}

static int AddIntToNode(void *data, void *param)
{
	*(int *)data += *(int *)param;
	return 0;

}

void TestBSTCreate()
{	
	
	bst_t *new_tree = BSTCreate(&DataCmp, NULL);

	printf("TestBSTCreate()\n");
	RUN_TEST(1 == BSTIsEmpty(new_tree), "FAIL: TREE IS EMPTY");
	BSTDestroy(new_tree);
	printf("\n");
}

void TestBSTInsert()
{
	bst_t *new_tree = BSTCreate(&DataCmp, NULL);
	bst_itr_t new_it = NULL;

	int a = 10;
	int b = 20;
	int c = 15;

	printf("TestBSTInsert()\n");
	RUN_TEST(1 == BSTIsEmpty(new_tree), "FAIL: TREE IS EMPTY");

	RUN_TEST(0 == BSTInsert(new_tree, &a),"FAIL: INSERT (a)");
	RUN_TEST(0 == BSTIsEmpty(new_tree), "FAIL: TREE IS EMPTY");
	RUN_TEST(a == *(int *)(BSTGetData(BSTBegin(new_tree))), "FAIL: DATA IS (a)");

	RUN_TEST(0 == BSTInsert(new_tree, &b),"FAIL: INSERT (b)");

	RUN_TEST(0 == BSTInsert(new_tree, &c),"FAIL: INSERT (c)");

	new_it = BSTBegin(new_tree);/*10*/
	RUN_TEST(c == *(int *)(BSTGetData(BSTNext(new_it))), "FAIL: DATA IS (c)");
	new_it = BSTNext(new_it); /*15*/
	new_it = BSTNext(new_it); /*20*/
	RUN_TEST(b == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (b)");

	BSTDestroy(new_tree);

	printf("\n");
}

void TestBSTPrev()
{
	bst_t *new_tree = BSTCreate(&DataCmp, NULL);
	bst_itr_t new_it = NULL;

	int a = 10;
	int b = 20;
	int c = 15;

	printf("TestBSTPrev()\n");

	BSTInsert(new_tree, &a);
	BSTInsert(new_tree, &b);
	BSTInsert(new_tree, &c);

	new_it = BSTBegin(new_tree);
	new_it = BSTNext(new_it); /*15*/
	new_it = BSTNext(new_it); /*20*/

	RUN_TEST(c == *(int *)BSTGetData(BSTPrev(new_it)),"FAIL: WRONG DATA (c)");
	
	new_it = BSTBegin(new_tree);
	RUN_TEST(BSTIsSameItr((BSTPrev(new_it)), BSTEnd(new_tree)),"FAIL: PREV OF BEGIN");
	BSTDestroy(new_tree);

	printf("\n");


}	

void TestBSTSize()
{
	bst_t *new_tree = BSTCreate(&DataCmp, NULL);
	bst_itr_t new_it = NULL;

	int a = 10;
	int b = 20;
	int c = 15;
	int d = 9;

	printf("TestBSTSize()\n");

	RUN_TEST(0 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(1)");
	RUN_TEST(1 == BSTIsEmpty(new_tree), "FAIL: TREE IS EMPTY");
	BSTInsert(new_tree, &a);
	RUN_TEST(1 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(1)");
	BSTInsert(new_tree, &b);
	RUN_TEST(2 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(2)");

	BSTInsert(new_tree, &c);
	RUN_TEST(0 == BSTIsEmpty(new_tree), "FAIL: TREE IS EMPTY");
	RUN_TEST(3 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(3)");
	BSTInsert(new_tree, &d);
	RUN_TEST(4 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(4)");
	new_it = BSTBegin(new_tree);
	RUN_TEST(d == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (d)");
	new_it = BSTNext(new_it);
	RUN_TEST(a == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (a)");
	new_it = BSTNext(new_it);
	RUN_TEST(c == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (c)");
	new_it = BSTNext(new_it);
	RUN_TEST(b == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (b)");

	BSTDestroy(new_tree);

	printf("\n");

}

void TestBSTRemove()
{
	bst_t *new_tree = BSTCreate(&DataCmp, NULL);
	bst_itr_t new_it = NULL;

	int a = 10;
	int b = 20;
	int c = 15;

	printf("TestBSTRemove()\n");

	BSTInsert(new_tree, &a);
	BSTInsert(new_tree, &b);
	BSTInsert(new_tree, &c);

	new_it = BSTBegin(new_tree);
	RUN_TEST(3 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(3)");
	RUN_TEST(a == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (a)");
	BSTRemove(new_it);
	RUN_TEST(2 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(2)");
	new_it = BSTBegin(new_tree);
	RUN_TEST(c == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (c)");
	BSTRemove(new_it);
	RUN_TEST(1 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(1)");
	new_it = BSTBegin(new_tree);
	RUN_TEST(b == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (b)");
	BSTRemove(new_it);
	RUN_TEST(0 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(0)");

	BSTInsert(new_tree, &b);
	new_it = BSTBegin(new_tree);
	RUN_TEST(b == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (b)");
	BSTInsert(new_tree, &a);
	new_it = BSTBegin(new_tree);
	new_it = BSTNext(new_it);
	RUN_TEST(b == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (b)");
	BSTRemove(new_it);
	new_it = BSTBegin(new_tree);
	RUN_TEST(a == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (a)");
	RUN_TEST(1 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(1)");
	BSTRemove(new_it);
	RUN_TEST(0 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(1)");
	BSTInsert(new_tree, &a);
	RUN_TEST(1 == BSTSize(new_tree), "FAIL: WRONG BST SIZE(1)");

	BSTDestroy(new_tree);

	printf("\n");
}


void TestBSTFind()
{
	bst_t *new_tree = BSTCreate(&DataCmp, NULL);
	bst_itr_t new_it = NULL;

	int a = 10;
	int b = 20;
	int c = 15;
	int d = 9;
	int e = 0;

	printf("TestBSTFind()\n");

	BSTInsert(new_tree, &a);
	BSTInsert(new_tree, &b);
	BSTInsert(new_tree, &c);
	BSTInsert(new_tree, &d);

	new_it = BSTFind(new_tree, &b);
	RUN_TEST(b == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (b)");
	new_it = BSTFind(new_tree, &d);
	RUN_TEST(d == *(int *)(BSTGetData(new_it)), "FAIL: DATA IS (d)");
	new_it = BSTFind(new_tree, &e);
	RUN_TEST(1 == BSTIsSameItr(new_it,BSTEnd(new_tree)), "FAIL: NO FIND RETURN END");

	BSTDestroy(new_tree);

	printf("\n");
}

void TestBSTForeach()
{
	bst_t *new_tree = BSTCreate(&DataCmp, NULL);
	bst_itr_t start_it = NULL;
	bst_itr_t end_it = NULL;

	int a = 10;
	int b = 20;
	int c = 15;
	int int_to_add = 1;

	printf("TestBSTForeach()\n");

	BSTInsert(new_tree, &a);
	BSTInsert(new_tree, &b);
	BSTInsert(new_tree, &c);

	start_it = BSTBegin(new_tree);
	end_it = BSTEnd(new_tree);

	
	RUN_TEST(0 == (BSTForeach(start_it, end_it, &AddIntToNode, &int_to_add)), "FAIL:action func failed");
	RUN_TEST(11 == *(int *)(BSTGetData(start_it)), "FAIL: DATA NOT int_to_add (a)");

	BSTDestroy(new_tree);
}


int main(int argc, char const *argv[])
{

	TestBSTCreate();

	TestBSTInsert();

	TestBSTPrev();

	TestBSTSize();

 	TestBSTRemove();

	TestBSTSize();

	TestBSTFind();

	TestBSTForeach();

	UNUSED(argc);
	UNUSED(argv);
	return 0;
}


