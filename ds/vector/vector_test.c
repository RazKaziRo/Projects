/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Dynamic Vector WS.
 * Date: 01.12.2019
 * Language: C
 * Reviewer: Israel Drayfus
 */
#include <stdio.h> 	/*printf(), sizeof()*/
#include <stdlib.h> /*free()*/
#include "vector.h"

#define UNUSED(x)	(void)(x)
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
struct Vector
{
	void *start;
	size_t size;
	size_t capacity;
	size_t element_size;
};

void TestVectorCreate()
{	/*VectorCreate(size_t element_size, size_t capacity)*/
	vector_t *v = VectorCreate(4,1);
	vector_t *v2 = VectorCreate(0,1);
	vector_t *v3 = VectorCreate(1,0);

	RUN_TEST(NULL != v, "FAIL: Creat Vector 4,1");
	RUN_TEST(1 == v -> capacity, "FAIL: Creat Vector Size 1");
	RUN_TEST(4 == v -> element_size, "FAIL: Element Size 4");
	RUN_TEST(0 == v -> size, "FAIL: Element Size 4");
	RUN_TEST(NULL == v2, "FAIL: Creat Vector 0,1");
	RUN_TEST(NULL == v3, "FAIL: Creat Vector 0,1");
	free(v -> start); v->start = NULL;
	free(v); v =NULL;
	printf("\n");
}

void TestVectorDestroy()
{
	vector_t *v = VectorCreate(4,1);
	VectorDestroy(v);
	printf("\n");
}	

void TestVectorPushBack()
{	
	int a = 10;
	int b = 20;
	int c = 30;

	/*VectorCreate(size_t element_size, size_t capacity)*/
	vector_t *v = VectorCreate(4,2);
	VectorPushBack(v, &a);
	RUN_TEST(1 == v -> size, "FAIL: After 1 Push Size = 1");
	RUN_TEST(2 == v -> capacity, "FAIL: After 1 Push Capacity = 10");
	RUN_TEST(4 == v -> element_size, "FAIL: After 1 Push element_size = 4");
	VectorPushBack(v, &b);
	RUN_TEST(2 == v -> size, "FAIL: After 2 Push Size = 2");
	RUN_TEST(2 == v -> capacity, "FAIL: After 2 Capacity +Size = 2");
	VectorPushBack(v, &c);
	RUN_TEST(4 == v -> capacity, "FAIL: After 3 Push +Capacity = 4");
	RUN_TEST(3 == v -> size, "FAIL: After 3 Push Size = 3");
	VectorDestroy(v);
	printf("\n");
}

void TestVectorPopBack()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	/*VectorCreate(size_t element_size, size_t capacity)*/
	vector_t *v = VectorCreate(4,10);
	VectorPushBack(v, &a);
	VectorPushBack(v, &b);
	VectorPushBack(v, &c);
	VectorPushBack(v, &d);
	RUN_TEST(4 == v -> size, "FAIL: After 3 Push Size = 4");
	RUN_TEST(10 == v -> capacity, "FAIL: After 3 Push Size = 3");
	
	VectorPopBack(v);

	RUN_TEST(3 == v -> size, "FAIL: After 1 POP Size = 3");
	RUN_TEST(10 == v -> capacity, "FAIL: After 1 POP Capacity = 10");
	
	VectorPopBack(v);

	RUN_TEST(2 == v -> size, "FAIL: After 2 POP Size = 2");
	RUN_TEST(5 == v -> capacity, "FAIL: After 2 POP Capacity = 5");
	
	VectorPopBack(v);

	RUN_TEST(1 == v -> size, "FAIL: After 3 POP Size = 1");
	RUN_TEST(2 == v -> capacity, "FAIL: After 3 POP Capacity = 2");
	
	VectorPopBack(v);

	RUN_TEST(0 == v -> size, "FAIL: After 4 POP Size = 0");
	RUN_TEST(1 == v -> capacity, "FAIL: After 3 POP Capacity = 2");
	
	VectorPopBack(v); /*Extra */

	RUN_TEST(0 == v -> size, "FAIL: After 5 POP Size = 0");
	RUN_TEST(1 == v -> capacity, "FAIL: After 5 POP Capacity = 1");

	VectorDestroy(v);

	printf("\n");

}

void TestVectorReserve()
{
	/*(vector_t *vector, size_t new_capacity)*/
	vector_t *v = VectorCreate(4,10);
	RUN_TEST(10 == v -> capacity, "FAIL: Before Reserve Capacity = 10");	
	VectorReserve(v,5);
	RUN_TEST(5 == v -> capacity, "FAIL: After Reserve 5 Capacity = 5");
	VectorReserve(v,0);
	RUN_TEST(5 == v -> capacity, "FAIL: After Reserve 0 Capacity = 5");
	VectorDestroy(v);
	printf("\n");
}

void TestVectorCapacity()
{
	vector_t *v = VectorCreate(4,10);
	
	RUN_TEST(10 == VectorCapacity(v), "FAIL: Capacity = 10");
	VectorReserve(v,5);
	RUN_TEST(5 == VectorCapacity(v), "FAIL: After Reserve Capacity = 5");
	VectorPopBack(v);
	RUN_TEST(5 == VectorCapacity(v), "FAIL: After NULL POP Capacity = 5");
	VectorDestroy(v);
	printf("\n");
}

void TestVectorSize()
{
	vector_t *v = VectorCreate(4,10);
	int a = 10;

	RUN_TEST(0 == VectorSize(v), "FAIL: Size = 0");
	VectorPushBack(v, &a);
	RUN_TEST(1 == VectorSize(v), "FAIL: After PUSH Size = 1");
	VectorPopBack(v);	
	RUN_TEST(0 == VectorSize(v), "FAIL: After POP Size = 0");
	VectorPopBack(v);	
	RUN_TEST(0 == VectorSize(v), "FAIL: After EXTRA POP Size = 0");
	VectorDestroy(v);
	printf("\n");
}

void TestVectorGetItemAddress()
{
	/*const vector_t *vector, int position*/
	vector_t *v = VectorCreate(4,10);
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;

	VectorPushBack(v, &a);
	VectorPushBack(v, &b);
	VectorPushBack(v, &c);
	VectorPushBack(v, &d);
	VectorPushBack(v, &e);

	RUN_TEST(10 == *(int *)(VectorGetItemAddress(v,1)), "FAIL: Value Index 1 = 10");
	RUN_TEST(20 == *(int *)(VectorGetItemAddress(v,2)), "FAIL: Value Index 1 = 20");
	RUN_TEST(30 == *(int *)(VectorGetItemAddress(v,3)), "FAIL: Value Index 1 = 30");
	RUN_TEST(40 == *(int *)(VectorGetItemAddress(v,4)), "FAIL: Value Index 1 = 40");
	RUN_TEST(50 == *(int *)(VectorGetItemAddress(v,5)), "FAIL: Value Index 1 = 50");
	
	VectorPopBack(v);

	RUN_TEST(NULL == (VectorGetItemAddress(v,5)), "FAIL: Value Index 1 after POP = 10");
	RUN_TEST(10 == *(int *)(VectorGetItemAddress(v,1)), "FAIL: Value Index 1 after POP = 10");
	RUN_TEST(40 == *(int *)(VectorGetItemAddress(v,4)), "FAIL: Value Index 1 after POP = 10");
	RUN_TEST(NULL == (VectorGetItemAddress(v,0)), "FAIL: Value Index 0 after POP = NULL");
	
	VectorDestroy(v);
	
	printf("\n");

}

int main(int argc, char const *argv[])
{

	printf("TestVectorCreate()\n");
	TestVectorCreate();

	printf("TestVectorDestroy()\n");
	TestVectorDestroy();

	printf("TestVectorPushBack()\n");
	TestVectorPushBack();

	printf("TestVectorPopBack()\n");
	TestVectorPopBack();

	printf("TestVectorReserve()\n");
	TestVectorReserve();

	printf("TestVectorCapacity()\n");
	TestVectorCapacity();

	printf("TestVectorSize()\n");
	TestVectorSize();

	printf("TestVectorGetItemAddress()\n");
	TestVectorGetItemAddress();

	UNUSED(argv);
	UNUSED(argc);

	return 0;
}