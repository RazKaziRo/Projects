/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Dynamic Vector WS.
 * Date: 01.12.2019
 * Language: C
 * Reviewer: Israel Drayfus
 */

#include <stdlib.h> /*malloc(), free()*/
#include <assert.h> /*assert()*/
#include <string.h> /*memcpy()*/

#include "vector.h" /*API FUNCTIONS()*/

#define SHRINK_FACTOR 4
#define GROWTH_FACTOR 2

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
	}

	return NULL;		 /* newVector malloc() FAIL */
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

	if (vector -> size == vector -> capacity)
	{
		VectorReserve(vector, (vector -> capacity * GROWTH_FACTOR));
	}

	current = (char *)vector -> start + (vector->size * vector -> element_size);
	memcpy(current, data, vector -> element_size);
	++(vector -> size);

	return 0;
}

void VectorPopBack(vector_t *vector)
{	
	assert(NULL != vector);

	if (vector -> size > 0)
	{	
		--(vector -> size);

		if (vector -> size == (vector -> capacity / SHRINK_FACTOR))
		{
			VectorReserve(vector, (vector -> capacity / GROWTH_FACTOR));
		} 
	}
}

int VectorReserve(vector_t *vector, size_t new_capacity)
{   
    if (0 < new_capacity)
    {
        vector -> start = (void *)realloc(vector -> start, 
        	(new_capacity * vector -> element_size));
       
        vector -> capacity = new_capacity; 

        return (NULL == vector); /* vector -> start realloc fail*/
    }
    else
    {
        return 1;      /* new_capacity <= 0 */
    }
}

size_t VectorCapacity(const vector_t *vector)
{	
	assert(NULL != vector);

	return (vector -> capacity);
}

size_t VectorSize(const vector_t *vector)
{	
	assert(NULL != vector);

	return (vector -> size);
}

void* VectorGetItemAddress(const vector_t *vector, size_t position)
{	
	assert(NULL != vector);

	if ((size_t)position > vector -> size || 0 == position)
	{
		return NULL;
	}
	else
	{
		return ((char *)vector -> start + (position-1)/* pos 1 = 0 = first */
        * vector -> element_size);
	}
}