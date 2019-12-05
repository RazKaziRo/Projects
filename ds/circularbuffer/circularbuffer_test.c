/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Circular Buffer.
 * Date: 05.12.2019
 * Language: C
 * Reviewer: 
 */
#include <stdio.h>

#include "circularbuffer.h"

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

int main(int argc, char const *argv[])
{	
	char *buffer = "ab";
	char *buffer2 = "cd";
	char arr1[3];
	char arr2[3];

	cbuffer_t *newCBuffer = CBufferCreate(3);
	printf("actual write bytes: %lu\n", CBufferWrite(newCBuffer,buffer,3));
	printf("actual content in newbuffer %s\n",newCBuffer->arr);
	
	printf("actual write bytes2: %lu\n", CBufferWrite(newCBuffer,buffer,1));
	printf("actual read bytes2: %lu\n", CBufferRead(&arr1,newCBuffer,1));

	printf("actual write bytes3: %lu\n", CBufferWrite(newCBuffer,buffer2,2));
	printf("actual write bytes4: %lu\n", CBufferWrite(newCBuffer,buffer2,2));
	printf("actual read bytes2: %lu\n", CBufferRead(&arr2,newCBuffer,2));
	printf("actual write bytes4: %lu\n", CBufferWrite(newCBuffer,buffer2,2));

	printf("actual content in newbuffer2 %s \n",newCBuffer->arr);

	CBufferDestroy(newCBuffer);
	
	UNUSED(argv);
	UNUSED(argc);
	return 0;
}