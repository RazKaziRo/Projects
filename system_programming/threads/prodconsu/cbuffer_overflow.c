#include <stddef.h> /*size_t, offsetoff*/
#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/
#include <string.h> /*memcpy*/

#include "cbuffer_overflow.h" /*Circular Buffer API Functions*/


#define START_POSITION 1
#define FREE(ptr) free(ptr); ptr = NULL;

struct CBufferOverFlow
{
	size_t read_index;
	size_t write_index;
	size_t capacity;
	int arr[START_POSITION];
};

cbuffer_t *CBufferCreate(size_t capacity)
{
	cbuffer_t *newCBuffer = malloc(offsetof(cbuffer_t, arr) + capacity * sizeof(int));
	if (NULL != newCBuffer)
	{
		newCBuffer->read_index = 0;
		newCBuffer->write_index = 0;
		newCBuffer->capacity = capacity;

		return newCBuffer;
	}

	return NULL;
}

void CBufferDestroy(cbuffer_t *cb)
{	
	assert(NULL != cb);

	FREE(cb);
}

int CBufferRead(cbuffer_t *cb)
{	
	int num_holder = 0;

	assert(NULL != cb);

	num_holder = cb->arr[cb->read_index % cb->capacity];
	cb->read_index = (cb->read_index + 1) % cb->capacity;

	return num_holder;
}

void CBufferWrite(cbuffer_t *cb ,int num_to_insert)
{	
	assert(NULL != cb);

	cb->arr[(cb->write_index + cb->read_index) % cb->capacity] = num_to_insert;
}

size_t CBufferFreeSpace(const cbuffer_t *cb)
{
	assert(NULL != cb);
	
	return(cb->capacity - (cb->write_index - cb->read_index));
}
