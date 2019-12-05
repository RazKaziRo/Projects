/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Circular Buffer.
 * Date: 05.12.2019
 * Language: C
 * Reviewer: 
 */

#include <stddef.h> /*size_t, offsetoff*/
#include <stdlib.h> /*malloc()*/
#include <string.h> /*memcpy*/

#include "circularbuffer.h" /*Circular Buffer API Functions*/

#define START_POSITION 1
#define FREE(ptr) free(ptr); ptr = NULL;

typedef char byte_t;

struct CBuffer
{
	size_t read_index;
	size_t size;
	size_t capacity;
	byte_t arr[START_POSITION];
};

cbuffer_t *CBufferCreate(size_t capacity)
{
	cbuffer_t *newCBuffer = (cbuffer_t*)malloc(offsetof(cbuffer_t, arr) + capacity);
	if (NULL != newCBuffer)
	{
		newCBuffer->read_index = 0;
		newCBuffer->size = 0;
		newCBuffer->capacity = capacity;

		return newCBuffer;
	}

	return NULL;
}

void CBufferDestroy(cbuffer_t *cb)
{
	FREE(cb);
}

ssize_t CBufferRead(void *buffer, cbuffer_t *cb, size_t count)
{	
	size_t remain_to_read = 0;

	if(count > cb->size)
	{
		count = cb->size;
	}
	remain_to_read = count;

	if (count + cb->size > cb->capacity)
	{
		remain_to_read = cb->capacity - cb->read_index;
		memcpy(buffer, &cb->arr[cb->read_index], remain_to_read);
		buffer = (byte_t *)buffer + remain_to_read;
		cb->size -= remain_to_read;
		cb->read_index = 0;
	}

	memcpy(buffer, &cb->arr[cb->read_index], remain_to_read);
	cb->read_index += remain_to_read;
	cb->size -= remain_to_read;

	return count;
}

ssize_t CBufferWrite(cbuffer_t *cb ,const void *buffer, size_t count)
{	
	size_t max_count = 0;

	if(CBufferFreeSpace(cb) < count)
	{
		count = CBufferFreeSpace(cb);
	}

	max_count = count;

	if (max_count + cb->size > cb->capacity)
	{	
		max_count = cb->capacity - (cb->read_index + cb->size);
		memcpy(&cb->arr[cb->size+cb->read_index%cb->capacity], buffer, max_count);
		cb->size += max_count;
	    buffer = (byte_t *)buffer + max_count;
		max_count = cb->capacity - cb->size;
	}
	memcpy(&cb->arr[(cb->size+cb->read_index)%cb->capacity], buffer, max_count);
	cb->size += max_count;

	return count;
}

size_t CBufferCapacity(const cbuffer_t *cb)
{
	return cb->capacity;
}

int CBufferIsEmpty(const cbuffer_t *cb)
{
	return(0 == cb->size);
}

size_t CBufferFreeSpace(const cbuffer_t *cb)
{
	return(cb->capacity-cb->size);
}