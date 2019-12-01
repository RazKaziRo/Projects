/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Dynamic Vector WS.
 * Date: 01.12.2019
 * Language: C
 * Reviewer: 
 */
#include <stdlib.h> /*malloc(), free()*/
#include <assert.h> /*assert()*/
#include <string.h> /*memcpy()*/

#include "vector.h"

struct Vector
{
	void *start;
	size_t size;
	size_t capacity;
	size_t element_size;
};

vector_t* VectorCreate(size_t element_size, size_t capacity)
{	
	vector_t *newVector = NULL;

	if (0 == element_size || 0 == capacity)
	{
		return NULL;
	}
	else
	{
		newVector = (vector_t *)malloc(sizeof(vector_t));
	}

	if (NULL != newVector)
	{
		newVector -> start = (void *)malloc(element_size * capacity);
		if (NULL != newVector -> start)
		{
			newVector -> size = 0;
			newVector -> capacity = capacity;
			newVector -> element_size = element_size;
			
			return newVector;
		}
		else
		{
			return NULL;
		}
		
	}
	return NULL;
}

void VectorDestroy(vector_t *vector)
{	
	assert(NULL != vector);

	free(vector -> start); vector -> start = NULL;
	free(vector); vector = NULL;
}

int VectorPushBack(vector_t *vector, const void *data)
{	
	void *current = NULL;

	assert(NULL != data);
	assert(NULL != vector);

	if (vector -> size == vector ->capacity)
	{
		VectorReserve(vector, (VectorCapacity(vector) * 2) );
	}

	current = (char *)vector -> start + (vector->size * vector -> element_size);
	memcpy(current, data, vector -> element_size);
	++(vector -> size);

	return 0;
}

void VectorPopBack(vector_t *vector)
{	
	assert(NULL != vector);

	if (VectorSize(vector) > 0)
	{	
		--(vector -> size);

		if (VectorSize(vector) == (VectorCapacity(vector) / 4))
		{
			VectorReserve(vector,(VectorCapacity(vector) / 2));
		} 
	}
}

int VectorReserve(vector_t *vector, size_t new_capacity)
{
	vector -> start = (void *)realloc(vector -> start, 
		(new_capacity * vector -> element_size));
	vector -> capacity = new_capacity;

	if (NULL == vector)
	{
		return 1;
	}
	return 0;
}

size_t VectorCapacity(const vector_t *vector)
{
	return (vector -> capacity);
}

size_t VectorSize(const vector_t *vector)
{
	return (vector -> size);
}

void* VectorGetItemAddress(const vector_t *vector, int position)
{	
	if ((size_t)position > VectorSize(vector) || 0 == position)
	{
		return NULL;
	}
	else
	{
		return ((char *)vector -> start + ((position-1)) *
		 vector -> element_size);
	}
}