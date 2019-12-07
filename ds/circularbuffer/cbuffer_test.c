/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Circular Buffer.
 * Date: 05.12.2019
 * Language: C
 * Reviewer: 
 */

#include <stdio.h>
#include <stdlib.h> /*free()*/
#include <string.h> /*strcmp()*/

#include "cbuffer.h"

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



typedef char byte_t;

struct CBuffer
{
	size_t read_index;
	size_t size;
	size_t capacity;
	byte_t arr[1];
};

void TestCBufferCreate()
{
	cbuffer_t *newCBuffer = CBufferCreate(3);
	RUN_TEST(0 == newCBuffer->size, "FAIL WRONG SIZE (0)")
	RUN_TEST(3 == newCBuffer->capacity, "FAIL WRONG CAPACITY (3)")
	RUN_TEST(0 == newCBuffer->read_index, "FAIL WRONG READ INDEX (0)")
	FREE(newCBuffer);
	printf("\n");

}

void TestCBufferDestroy()
{
	cbuffer_t *newCBuffer = CBufferCreate(10);
	CBufferDestroy(newCBuffer);
	printf("\n");
}

void TestCBufferWrite()
{
	cbuffer_t *newCBuffer = CBufferCreate(10);
	char *writebuffer = "Hello1234";

	RUN_TEST(6 == CBufferWrite(newCBuffer, writebuffer, 6), "FAIL: WRONG WRITE (6)");
	RUN_TEST(0 == strcmp("Hello1",newCBuffer->arr), "FAIL: WRONG WRITE (Hello)");
	RUN_TEST(6 == newCBuffer->size, "FAIL: WRONG SIZE (6)");
	RUN_TEST(10 == newCBuffer->capacity, "FAIL: WRONG CAPACITY (10)");
	RUN_TEST(4 == CBufferWrite(newCBuffer, writebuffer, 6), "FAIL: WRONG WRITE (4)");
	RUN_TEST(10 == newCBuffer->size, "FAIL: WRONG SIZE (10)");
	RUN_TEST(0 == CBufferWrite(newCBuffer, writebuffer, 1), "FAIL: WRONG WRITE (4)");
	RUN_TEST(0 == strcmp("Hello1Hell",newCBuffer->arr), "FAIL: WRONG WRITE (HelloHello)");

	CBufferDestroy(newCBuffer);
	printf("\n");
}

void TestCBufferRead()
{
	cbuffer_t *newCBuffer = CBufferCreate(10);
	char *writebuffer = "Hello1234";
	char readBuffer1[7];
	char readBuffer2[3];


	CBufferWrite(newCBuffer,writebuffer,9);

	RUN_TEST(7 == CBufferRead(readBuffer1,newCBuffer,7), "FAIL TO Read (10)");
	RUN_TEST(0 == strcmp(readBuffer1, "Hello12"), "FAIL Wrong String (Hello12)");
	RUN_TEST(2 == CBufferRead(readBuffer2,newCBuffer,7), "FAIL TO Read (10)");
	CBufferDestroy(newCBuffer);
	printf("\n");
}

int main(int argc, char const *argv[])
{	
	
	printf("TestCBufferCreate()\n");
	TestCBufferCreate();

	printf("TestCBufferDestroy()\n");
	TestCBufferDestroy();

	printf("TestCBufferWrite()\n");
	TestCBufferWrite();

	printf("TestCBufferWrite()\n");
	TestCBufferRead();


	UNUSED(argv);
	UNUSED(argc);
	return 0;
}

