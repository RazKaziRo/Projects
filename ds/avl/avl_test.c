#include <stdio.h> /*printf()*/

#include "avl.h"

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

static int NodeDataCmp(const void *data_x, const void *data_y)
{
	int result = (*(int *)data_x - *(int *)data_y);

	if(result > 0)
	{
		return 1;
	}
	else if(result < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

static int AddIntToNode(void *data, void *param)
{
	*(int *)data += *(int *)param;

	return 0;
}

static int PrintNodeData(void *data, void *param)
{
	printf("Data: %d \n", *(int *)data);

	UNUSED(param);

	return 0;
}


void TestAVLCreate()
{
	avl_t *new_tree = AVLCreate(&NodeDataCmp);

	printf("TestAVLCreate(): \n");
	RUN_TEST(NULL != new_tree, "FAIL: NEW TREE = NULL");

	AVLDestroy(new_tree);

	printf("\n");
}

void TestAVLInsert()
{	
	avl_t *new_tree = AVLCreate(&NodeDataCmp);
	int a = 20;
	int b = 10;
	int c = 8;

	printf("TestAVLInsert(): \n");
	RUN_TEST(0 == AVLSize(new_tree), "FAIL: SIZE(0) AFTER CREATE");

	AVLInsert(new_tree, &a);
	RUN_TEST(1 == AVLSize(new_tree), "FAIL: SIZE(1) AFTER 1 INSERT");
	RUN_TEST(0 == AVLGetHeight(new_tree), "FAIL: WRONG HEIGHT (0)");

	AVLInsert(new_tree, &b);
	RUN_TEST(2 == AVLSize(new_tree), "FAIL: SIZE(2) AFTER 2 INSERT");

	AVLInsert(new_tree, &c);
	RUN_TEST(1 == AVLGetHeight(new_tree), "FAIL: WRONG HEIGHT (1)");
	RUN_TEST(3 == AVLSize(new_tree), "FAIL: SIZE(3) AFTER 2 INSERT");

	AVLDestroy(new_tree);

	printf("\n");
}

void TestAVLForeach()
{
	avl_t *new_tree = AVLCreate(&NodeDataCmp);
	int a = 10;
	int b = 20;
	int c = 8;
	int e = 1;

	int param = 5;

	AVLInsert(new_tree, &a);
	AVLInsert(new_tree, &b);
	AVLInsert(new_tree, &c);

	printf("TestAVLForeach(): \n");
	RUN_TEST(0 == AVLForeach(new_tree, &PrintNodeData, &param), "FAIL: WRONG VALUE FROM FOREACH(0)");
	RUN_TEST(0 == AVLForeach(new_tree, &AddIntToNode, &param), "FAIL: WRONG VALUE FROM FOREACH(0)");
	RUN_TEST(a == *(int *)AVLFind(new_tree, &a), "FAIL: WRONG FIND (a)");
	RUN_TEST(NULL == AVLFind(new_tree, &e), "FAIL: WRONG FIND (e)");
	RUN_TEST(0 == AVLForeach(new_tree, &PrintNodeData, &param), "FAIL: WRONG VALUE FROM FOREACH(0)");

	AVLDestroy(new_tree);

	printf("\n");

}

void TestAVLRemove()
{
	avl_t *new_tree = AVLCreate(&NodeDataCmp);
	int a = 10;
	int b = 20;
	int c = 8;

	AVLInsert(new_tree, &a);
	AVLInsert(new_tree, &b);
	AVLInsert(new_tree, &c);

	RUN_TEST(3 == AVLSize(new_tree), "FAIL: SIZE(3) AFTER 3 INSERT");

	AVLRemove(new_tree, &a);

	RUN_TEST(2 == AVLSize(new_tree), "FAIL: SIZE(2) AFTER 1 REMOVE");

	AVLDestroy(new_tree);

}

void TestAVLRotation()
{
	avl_t *new_tree = AVLCreate(&NodeDataCmp);

	int a = 10;
	int b = 8;
	int c = 6;

	AVLInsert(new_tree, &a);
	AVLInsert(new_tree, &b);
	AVLInsert(new_tree, &c);
}

int main(int argc, char const *argv[])
{	
	
	TestAVLInsert();

	/*TestAVLCreate();
	TestAVLForeach();
	TestAVLRemove();
	TestAVLRotation();*/

	UNUSED(argc);
	UNUSED(argv);
	return 0;
}


