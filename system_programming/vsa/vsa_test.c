/*
 * Author: Raz KaziRo
 * Purpose: Answares for System Programing - Varient Size Allocator.
 * Date: 22.12.2019
 * Language: C
 * Reviewer: Yonatan Zaken
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/vsa.h"

#define MAGIC_NUMBER 0xDEADBEEF
#define LAST_HEADER (long)0xFFFFFFFFFFFFFFFF
#define HEAD_SIZE   sizeof(vsa_t)

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

struct BlockHeader
{
    long block_size;
    
    #ifndef NDEBUG
    long unique;
    #endif
};

void TestVSAInit()
{	
	size_t segment_size = 1000; 
	void *allocated = malloc(segment_size);
	vsa_t *new_vsa = VSAInit(allocated, segment_size);

	#ifdef NDEBUG
	RUN_TEST (976 == new_vsa->block_size, "FAIL: WRONG SIZE (968)");
	#endif

	#ifndef NDEBUG
	RUN_TEST (MAGIC_NUMBER == new_vsa->unique, "FAIL: WRONG SIZE (MAGIC_NUMBER)");
	RUN_TEST (968 == new_vsa->block_size, "FAIL: WRONG SIZE (968)");
	RUN_TEST(952 == VSALargestChunkSize(new_vsa), "FAIL:LARGEST SIZE (952)"); 
	#endif

	FREE(allocated);

	printf("\n");
}

void TestVSAAlloc()
{
	size_t segment_size = 1000; 
	void *allocated = malloc(segment_size);
	void *block1 = NULL;
	void *block2 = NULL;

	vsa_t *new_vsa = VSAInit(allocated, segment_size);
	char *vsa_runner = (char *)new_vsa;

	#ifndef NDEBUG
	RUN_TEST (MAGIC_NUMBER == new_vsa->unique, "FAIL: WRONG SIZE (MAGIC_NUMBER)");
	RUN_TEST (968 == new_vsa->block_size, "FAIL: WRONG SIZE (968)");
	#endif

	block1 = VSAAlloc(new_vsa, 100);
	#ifndef NDEBUG
	RUN_TEST (MAGIC_NUMBER == new_vsa->unique, "FAIL: WRONG SIZE (MAGIC_NUMBER)");
	RUN_TEST (-100 == new_vsa->block_size, "FAIL: WRONG SIZE (968)");
	#endif

	vsa_runner += sizeof(vsa_t)+ 100;

	#ifndef NDEBUG
	RUN_TEST (MAGIC_NUMBER == ((vsa_t*)vsa_runner)->unique, "FAIL: WRONG SIZE (MAGIC_NUMBER)");
	RUN_TEST (852 == ((vsa_t*)vsa_runner)->block_size, "FAIL: WRONG SIZE (852)");
	#endif

	block2 = VSAAlloc(new_vsa, VSALargestChunkSize(new_vsa)); 

	vsa_runner += sizeof(vsa_t) + 852;

	#ifndef NDEBUG
	RUN_TEST (MAGIC_NUMBER == ((vsa_t*)vsa_runner)->unique, "FAIL: WRONG SIZE (MAGIC_NUMBER)");
	RUN_TEST (LAST_HEADER == ((vsa_t*)vsa_runner)->block_size, "FAIL: WRONG SIZE (852)");
	RUN_TEST (0 == VSALargestChunkSize(new_vsa), "FAIL: WRONG SIZE (0)");
	#endif

	UNUSED(block1);
	UNUSED(block2);
	
	FREE(allocated);

	printf("\n");

}

void TestVSAFree()
{
	size_t segment_size = 1000; 
	void *allocated = malloc(segment_size);
	void *block1 = NULL;
	void *block2 = NULL;
	vsa_t *new_vsa = VSAInit(allocated, segment_size);
	char *vsa_runner = (char *)new_vsa;

	RUN_TEST (952 == VSALargestChunkSize(new_vsa), "FAIL: WRONG SIZE (0)");

	block1 = VSAAlloc(new_vsa, 100);
	vsa_runner = block1;
	vsa_runner -= sizeof(vsa_t);
	RUN_TEST (-100 == ((vsa_t *)vsa_runner)->block_size, "FAIL: BLOCK SIZE (-100)");
	RUN_TEST (836 == VSALargestChunkSize(new_vsa), "FAIL: WRONG SIZE (836)");

	block2 = VSAAlloc(new_vsa, 100);
	vsa_runner = block2;
	vsa_runner -= sizeof(vsa_t);
	RUN_TEST (-100 == ((vsa_t *)vsa_runner)->block_size, "FAIL: BLOCK SIZE (-100)");
	RUN_TEST (720 == VSALargestChunkSize(new_vsa), "FAIL: WRONG SIZE (952)");

	VSAFree(block1);
	RUN_TEST (720 == VSALargestChunkSize(new_vsa), "FAIL: WRONG SIZE (952)");

	FREE(allocated);

	printf("\n");
}


void TestVSALargestChunkSize()
{
	size_t segment_size = 1000; 
	void *allocated = malloc(segment_size);

	vsa_t *new_vsa = VSAInit(allocated, segment_size);

	#ifdef NDEBUG
	RUN_TEST(968 == VSALargestChunkSize(new_vsa), "FAIL: WRONG LARGEST (968)");
	#endif

	#ifndef NDEBUG
	RUN_TEST(952 == VSALargestChunkSize(new_vsa), "FAIL: WRONG LARGEST (952)");
	#endif

	FREE(allocated);

	printf("\n");
}

int main(int argc, char const *argv[])
{

	printf("TestVSAInit()\n");
	TestVSAInit();

	printf("TestVSALargestChunkSize()\n");
	TestVSALargestChunkSize();

	printf("TestVSAAlloc()\n");
	TestVSAAlloc();

	printf("TestVSAFree()\n");
	TestVSAFree();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}