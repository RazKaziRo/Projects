/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Vector Priority Queue.
 * Date: 22.01.2020
 * Language: C
 * Reviewer: 
 */

#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/

#include "../include/vector.h" 
#include "../include/priorityq_vector.h" 

#define FREE(ptr) free(ptr); ptr = NULL;
#define START_POSITION 1
#define ELEMENT_SIZE sizeof(void *)

struct PQueue
{
	vector_t *vector;
	compare_func user_cmp;
	void *param;
};

pq_t *PQCreate(compare_func user_cmp_ptr, void *param)
{	
	pq_t *new_pq = malloc(sizeof(*new_pq));
	if (NULL != new_pq)
	{
		new_pq->vector = VectorCreate(ELEMENT_SIZE, START_POSITION);
		if (NULL != new_pq->vector)
		{
			new_pq->user_cmp = user_cmp_ptr;
			new_pq->param = param;
		}
		else
		{
			FREE(new_pq);
		}
	}

	return new_pq;
}

void PQDestroy(pq_t *pq)
{
	VectorDestroy(pq->vector);
	FREE(pq);
}

size_t PQSize(const pq_t *pq)
{
	return(VectorSize(pq->vector));
}


static void SwapPointers(void **parent, void **child)
{
	void *data_holder = *parent;
	*parent = *child;
	*child = data_holder;
}

void PQHeapifyUp(void *vector, size_t size, size_t index, size_t element_size, compare_func cmp, void *param)
{	
	size_t parent_index =  ((index - 1) / 2);

	void **parent_value = NULL;
	void **child_value = NULL ; 

	if (index > 1 && size > (2 * index))
	{
		parent_value = VectorGetItemAddress((vector_t *)vector, parent_index + 1);
		child_value = VectorGetItemAddress((vector_t *)vector, index + 1);

		if ((0 > cmp(*parent_value, *child_value, param)))
		{
			SwapPointers(parent_value, child_value);
		}

		else
		{
			return;
		}

		index = parent_index;
		PQHeapifyUp(vector, size, index, element_size, cmp, param);
	}
}

int PQEnqueue(pq_t *pq, void *data)
{	
	int result = VectorPushBack(pq->vector, &data);

	if (0 == result)
	{	
		PQHeapifyUp(pq->vector,PQSize(pq), (PQSize(pq)-1), ELEMENT_SIZE, pq->user_cmp, pq->param);
	}

	return !result;
}

void PQHeapifyDown(void *vector, size_t size, size_t index, size_t element_size, compare_func cmp, void *param)
{
	void **left_child = NULL;
	void **right_child = NULL;
	void **replacment_child = NULL;
	void **parent = NULL;

	size_t parent_index = index;
	size_t left_child_idx = 2 * index + 1;
	size_t right_child_idx = 2 * index + 2;
	int res = 0;

	parent = VectorGetItemAddress((vector_t*)vector, parent_index + 1);

	if (right_child_idx < size)
	{
		right_child = VectorGetItemAddress((vector_t*)vector, right_child_idx + 1);
		left_child = VectorGetItemAddress((vector_t*)vector, left_child_idx + 1);
		if (0 < cmp(*right_child, *left_child, param) &&  0 < cmp(*right_child, *parent, param))
		{
			SwapPointers(right_child, parent);
			parent_index = right_child_idx;
		}
		else if (0 < cmp(*left_child, *parent, param))
		{
			SwapPointers(left_child, parent);
			parent_index = left_child_idx;
		}
	}

	else if ((left_child_idx < size))
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
		PQHeapifyDown(vector, size, parent_index, element_size, cmp, param);
	}
	else
	{
		return;
	}
}

void *PQDequeue(pq_t *pq)
{	
	void **root_value = VectorGetItemAddress(pq->vector, START_POSITION);
	void **replacer_value = VectorGetItemAddress(pq->vector, PQSize(pq));
	void *data_holder = *root_value;

	SwapPointers(root_value, replacer_value);
	VectorPopBack(pq->vector);

	PQHeapifyDown(pq->vector, PQSize(pq), 0, ELEMENT_SIZE, pq->user_cmp, pq->param);

	return data_holder;
}

int PQIsEmpty(const pq_t *pq)
{
	return(0 == VectorSize(pq->vector));
}

void PQClear(pq_t *pq)
{
	while(!PQIsEmpty(pq))
	{
		VectorPopBack(pq->vector);
	}
}

void *PQPeek(const pq_t *pq)
{
	void **peek_data = VectorGetItemAddress(pq->vector, START_POSITION);
	return(*peek_data);
}

void *PQErase(pq_t *pq, match_func m_ptr, const void *data)
{	
	size_t i = 0;
	size_t size = PQSize(pq);
	void **last_value = VectorGetItemAddress(pq->vector, PQSize(pq));
	void **replacer_value = NULL;
	void *data_holder = NULL;

	for(; i < size; ++i)
	{	
		replacer_value = VectorGetItemAddress(pq->vector, i + 1);
		if (1 == m_ptr(*replacer_value, (void *)data))
		{
			data_holder = *replacer_value;
			SwapPointers(replacer_value, last_value);
			VectorPopBack(pq->vector);
			PQHeapifyUp(pq->vector, PQSize(pq), i, ELEMENT_SIZE, pq->user_cmp, pq->param);
			PQHeapifyDown(pq->vector, PQSize(pq), i, ELEMENT_SIZE, pq->user_cmp, pq->param);
			break;
		}
	}

	return data_holder;
}
