/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Priority Queue.
 * Date: 12.12.2019
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/

#include "../../include/sortedlist.h" /*Sorted List API()*/
#include "../../include/priorityq.h"  /*Priority Queue API()*/

#define FREE(ptr) free(ptr); ptr = NULL;

typedef struct DLLFuncWrapper
{
	compare_func user_cmp;
	void *param;
}wrapper_t;

struct PQueue
{
	sll_t *queue;
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

pq_t *PQCreate(compare_func user_cmp_ptr, void *param)
{	
	pq_t *newPQueue = (pq_t *)malloc(sizeof(pq_t));
	assert(NULL != user_cmp_ptr);

	if (NULL != newPQueue)
	{
		newPQueue->queue = SortLLCreate(&PQCompareWrapper, &newPQueue->wrapper);
		if (NULL != newPQueue->queue)
		{
			newPQueue->wrapper.user_cmp = user_cmp_ptr;
			newPQueue->wrapper.param = param;
		}
		else
		{
			FREE(newPQueue);
		}
	}

	return newPQueue;
}

void PQDestroy(pq_t *pq)
{	
	assert(NULL != pq);

	SortLLDestroy(pq->queue);
	FREE(pq);
}

void *PQDequeue(pq_t *pq)
{	
	assert(NULL != pq);

	return(SLLPopFront(pq->queue));
}

int PQEnqueue(pq_t *pq, void *data)
{
	assert(NULL != pq);

	return !(SLLIsSameIter(SortLLInsert(pq->queue, data),SLLEnd(pq->queue)));
}

void *PQPeek(const pq_t *pq)
{	
	assert(NULL != pq);

	return (SLLGetData(SLLBegin(pq->queue)));
}

size_t PQSize(const pq_t *pq)
{	
	return (SLLSize(pq->queue));
}

int PQIsEmpty(const pq_t *pq)
{	
	assert(NULL != pq);

	return (SLLIsEmpty(pq->queue));	
}

void PQClear(pq_t *pq)
{ 
	assert(NULL != pq);

	while (!PQIsEmpty(pq))
	{
		PQDequeue(pq);
	}
}

void *PQErase(pq_t *pq, match_func m_ptr, const void *data)
{	
	void *returned_data = NULL;
	sll_iterator_t it; 
	
	assert(NULL != pq);
	assert(NULL != m_ptr);

	it = SLLFindBy(pq->queue, SLLBegin(pq->queue), SLLEnd(pq->queue), m_ptr, data);
	returned_data = SLLGetData(it);

	if (!SLLIsSameIter(it,SLLEnd(pq->queue)))
	{
		SortLLRemove(it);
	}

	return returned_data;
}