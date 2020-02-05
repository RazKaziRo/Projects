/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Vector Priority Queue.
 * Date: 22.01.2020
 * Language: C
 * Reviewer: 
 */

#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/

#include "vector.h" 
#include "priorityq_vector.h" 

#define FREE(ptr) free(ptr); ptr = NULL;
#define START_POSITION 1
#define ELEMENT_SIZE sizeof(void *)

struct VECPQueue
{
	vector_t *vector;
	compare_func user_cmp;
	void *param;
};

static void SwapPointers(void **parent, void **child)
{
	void *data_holder = *parent;
	*parent = *child;
	*child = data_holder;
}

vecpq_t *VECPQCreate(compare_func user_cmp_ptr, void *param)
{	
	vecpq_t *new_vecpq = malloc(sizeof(*new_vecpq));
	if (NULL != new_vecpq)
	{
		new_vecpq->vector = VectorCreate(ELEMENT_SIZE, START_POSITION);
		if (NULL != new_vecpq->vector)
		{
			assert(NULL != user_cmp_ptr);

			new_vecpq->user_cmp = user_cmp_ptr;
			new_vecpq->param = param;
		}
		else
		{
			FREE(new_vecpq);
		}
	}

	return new_vecpq;
}

void VECPQDestroy(vecpq_t *vecpq)
{
	assert(NULL != vecpq);

	VectorDestroy(vecpq->vector);
	FREE(vecpq);
}

size_t VECPQSize(const vecpq_t *vecpq)
{
	assert(NULL != vecpq);

	return (VectorSize(vecpq->vector));
}

int VECPQEnqueue(vecpq_t *vecpq, void *data)
{	
	int result = 0;

	assert(NULL != vecpq);

	result = VectorPushBack(vecpq->vector, &data);

	if (0 == result)
	{	
		VECPQHeapifyUp(vecpq->vector,VECPQSize(vecpq), 
			(VECPQSize(vecpq) - 1), ELEMENT_SIZE, vecpq->user_cmp, vecpq->param);
	}

	return !result;
}

void *VECPQDequeue(vecpq_t *vecpq)
{	
	void **root_value = NULL;
	void **replacer_value = NULL;
	void *data_holder = NULL;

	assert(NULL != vecpq);

	root_value = VectorGetItemAddress(vecpq->vector, START_POSITION);
	replacer_value = VectorGetItemAddress(vecpq->vector, VECPQSize(vecpq));
	data_holder = *root_value;

	SwapPointers(root_value, replacer_value);
	VectorPopBack(vecpq->vector);

	VECPQHeapifyDown(vecpq->vector, VECPQSize(vecpq), 0, 
		ELEMENT_SIZE, vecpq->user_cmp, vecpq->param);

	return data_holder;
}

int VECPQIsEmpty(const vecpq_t *vecpq)
{
	assert(NULL != vecpq);

	return (0 == VectorSize(vecpq->vector));
}

void VECPQClear(vecpq_t *vecpq)
{
	assert(NULL != vecpq);

	while(!VECPQIsEmpty(vecpq))
	{
		VectorPopBack(vecpq->vector);
	}
}

void *VECPQPeek(const vecpq_t *vecpq)
{	
	assert(NULL != vecpq);
	return (VectorGetItemAddress(vecpq->vector, START_POSITION));
}

void *VECPQErase(vecpq_t *vecpq, match_func m_ptr, const void *data)
{	
	size_t i = 0;
	size_t size = 0;
	void **last_value = NULL;
	void **replacer_value = NULL;
	void *data_holder = NULL;

	assert(NULL != vecpq);

	size = VECPQSize(vecpq);
	last_value = VectorGetItemAddress(vecpq->vector, VECPQSize(vecpq));

	for(; i < size; ++i)
	{	
		replacer_value = VectorGetItemAddress(vecpq->vector, i + 1);
		if (1 == m_ptr(*replacer_value, (void *)data))
		{
			data_holder = *replacer_value;
			SwapPointers(replacer_value, last_value);
			VectorPopBack(vecpq->vector);
			VECPQHeapifyUp(vecpq->vector, VECPQSize(vecpq), i, 
				ELEMENT_SIZE, vecpq->user_cmp, vecpq->param);

			VECPQHeapifyDown(vecpq->vector, VECPQSize(vecpq), i, 
				ELEMENT_SIZE, vecpq->user_cmp, vecpq->param);

			break;
		}
	}

	return data_holder;
}

void VECPQHeapifyDown(void *vector, size_t size, size_t index, 
	size_t element_size, compare_func cmp, void *param)
{
	void **left_child = NULL, **right_child = NULL, **parent = NULL;
	
	size_t parent_index = index;
	size_t left_child_idx = 2 * index + 1;
	size_t right_child_idx = 2 * index + 2;

	assert(NULL != vector);
	assert(NULL != cmp);

	parent = VectorGetItemAddress((vector_t*)vector, parent_index + 1);

	if (right_child_idx < size)
	{
		right_child = VectorGetItemAddress((vector_t*)vector, right_child_idx + 1);
		left_child = VectorGetItemAddress((vector_t*)vector, left_child_idx + 1);

		if (0 < cmp(*right_child, *left_child, param))
		{
			if( (0 < cmp(*right_child, *parent, param)))
			{
				SwapPointers(right_child, parent);
				parent_index = right_child_idx;
			}
		}

		else if (0 < cmp(*left_child, *parent, param))
		{
			SwapPointers(left_child, parent);
			parent_index = left_child_idx;
		}
	}

	else if (left_child_idx < size)
	{
		left_child = VectorGetItemAddress((vector_t*)vector, left_child_idx + 1);

		if ((0 < cmp(*left_child, *parent, param)))
		{
			SwapPointers(left_child, parent);
			parent_index = left_child_idx;
		}
	}

	if (parent_index != index)
	{
		VECPQHeapifyDown(vector, size, parent_index, element_size, cmp, param);
	}
}

void VECPQHeapifyUp(void *vector, size_t size, size_t index, 
	size_t element_size, compare_func cmp, void *param)
{	
	size_t parent_index =  ((index - 1) / 2);

	void **parent_value = NULL;
	void **child_value = NULL ; 

	assert(NULL != vector);
	assert(NULL != cmp);

	if (index > 1 && size > (2 * index))
	{
		parent_value = VectorGetItemAddress((vector_t *)vector, parent_index + 1);
		child_value = VectorGetItemAddress((vector_t *)vector, index + 1);

		if ((0 > cmp(*parent_value, *child_value, param)))
		{
			SwapPointers(parent_value, child_value);
			index = parent_index;
			VECPQHeapifyUp(vector, size, index, element_size, cmp, param);
		}
	}
}