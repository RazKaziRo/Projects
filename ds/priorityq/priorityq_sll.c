/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Priority Queue.
 * Date: 12.12.2019
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/

#include "sortedlist.h" /*Sorted List API()*/
#include "priorityq_sll.h"  /*Priority Queue API()*/

#define FREE(ptr) free(ptr); ptr = NULL;

typedef struct DLLFuncWrapper
{
	compare_func user_cmp;
	void *param;
}wrapper_t;

struct SLLPQueue
{
	sll_t *queue;
	wrapper_t wrapper;
};

static int SLLPQCompareWrapper(const void *data1, const void *data2, void *param)
{	
	wrapper_t *wrapper = NULL;

	assert(NULL != data1);
	assert(NULL != data2);

	wrapper = (wrapper_t *)param;

	return !(0 <= (wrapper->user_cmp(data1, data2, wrapper->param)));
}

SLLPQ_t *SLLPQCreate(compare_func user_cmp_ptr, void *param)
{	
	SLLPQ_t *newSLLPQueue = (SLLPQ_t *)malloc(sizeof(SLLPQ_t));
	assert(NULL != user_cmp_ptr);

	if (NULL != newSLLPQueue)
	{
		newSLLPQueue->queue = SortLLCreate(&SLLPQCompareWrapper, &newSLLPQueue->wrapper);
		if (NULL != newSLLPQueue->queue)
		{
			newSLLPQueue->wrapper.user_cmp = user_cmp_ptr;
			newSLLPQueue->wrapper.param = param;
		}
		else
		{
			FREE(newSLLPQueue);
		}
	}

	return newSLLPQueue;
}

void SLLPQDestroy(SLLPQ_t *SLLPQ)
{	
	assert(NULL != SLLPQ);

	SortLLDestroy(SLLPQ->queue);
	FREE(SLLPQ);
}

void *SLLPQDequeue(SLLPQ_t *SLLPQ)
{	
	assert(NULL != SLLPQ);

	return(SortLLPopFront(SLLPQ->queue));
}

int SLLPQEnqueue(SLLPQ_t *SLLPQ, void *data)
{
	assert(NULL != SLLPQ);

	return !(SortLLIsSameIter(SortLLInsert(SLLPQ->queue, data),SortLLEnd(SLLPQ->queue)));
}

void *SLLPQPeek(const SLLPQ_t *SLLPQ)
{	
	assert(NULL != SLLPQ);

	return (SortLLGetData(SortLLBegin(SLLPQ->queue)));
}

size_t SLLPQSize(const SLLPQ_t *SLLPQ)
{	
	return (SortLLSize(SLLPQ->queue));
}

int SLLPQIsEmpty(const SLLPQ_t *SLLPQ)
{	
	assert(NULL != SLLPQ);

	return (SortLLIsEmpty(SLLPQ->queue));	
}

void SLLPQClear(SLLPQ_t *SLLPQ)
{ 
	assert(NULL != SLLPQ);

	while (!SLLPQIsEmpty(SLLPQ))
	{
		SLLPQDequeue(SLLPQ);
	}
}

void *SLLPQErase(SLLPQ_t *SLLPQ, match_func m_ptr, const void *data)
{	
	void *returned_data = NULL;
	sll_iterator_t it; 
	
	assert(NULL != SLLPQ);
	assert(NULL != m_ptr);

	it = SortLLFindBy(SLLPQ->queue, SortLLBegin(SLLPQ->queue), SortLLEnd(SLLPQ->queue), m_ptr, data);
	returned_data = SortLLGetData(it);

	if (!SortLLIsSameIter(it,SortLLEnd(SLLPQ->queue)))
	{
		SortLLRemove(it);
	}

	return returned_data;
}
