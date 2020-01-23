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
#include "../include/heapify.h"


#define FREE(ptr) free(ptr); ptr = NULL;
#define INIT_SIZE 1
#define ELEMENT_SIZE sizeof(void *)

typedef struct DLLFuncWrapper
{
	pq_compare_func user_cmp;
	void *param;
}wrapper_t;

struct PQueue
{
	vector_t *queue;
	wrapper_t wrapper;
};

static int PQCompareWrapper(const void *data1, const void *data2, void *param)
{	
	wrapper_t *wrapper = NULL;

	assert(NULL != data1);
	assert(NULL != data2);

	wrapper = (wrapper_t *)param;

	return !(0 <= (wrapper->user_cmp(data1, data2, wrapper->param)));
}

pq_t *PQCreate(pq_compare_func user_cmp_ptr, void *param)
{	
	pq_t *new_pq = malloc(sizeof(*new_pq));
	if (NULL != new_pq)
	{
		new_pq->queue = VectorCreate(ELEMENT_SIZE, INIT_SIZE);
		if(NULL != new_pq->queue)
		{
			new_pq->wrapper.user_cmp = user_cmp_ptr;
			new_pq->wrapper.param = param;
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
	VectorDestroy(pq->queue);
	FREE(pq);
}

size_t PQSize(const pq_t *pq)
{
	return(VectorSize(pq->queue));
}

int PQEnqueue(pq_t *pq, void *data)
{	
	VectorPushBack(pq->queue, &data);
	HeapifyUp(pq->queue, PQSize(pq), (PQSize(pq) - 1), ELEMENT_SIZE, pq->wrapper.user_cmp,pq->wrapper.param);
}

int PQIsEmpty(const pq_t *pq)
{
	return(0 == VectorSize(pq->queue));
}

void PQClear(pq_t *pq)
{
	while(!PQIsEmpty(pq))
	{
		VectorPopBack(pq->queue);
	}
}





