/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Sorted Linked List.
 * Date: 10.12.2019
 * Language: C
 * Reviewer: Shye Shapira
 */
#include <stdlib.h> /*malloc()*/

#include "sortedlist.h" /*Sorted List API()*/
#include "priorityq.h"

#define FREE(ptr) free(ptr); ptr = NULL;

struct PQueue
{
	sll_t *queue;
	compare_func_ptr cmp_ptr;
};

pq_t *PQCreate(compare_func_ptr cmp_ptr, void *param)
{	
	pq_t *newQueue = (pq_t *)malloc(sizeof(pq_t));
	if (NULL != newQueue)
	{
		newQueue->queue = SortLLCreate(cmp_ptr, param);
		newQueue->cmp_ptr = cmp_ptr;
	}
	return newQueue;
}

void PQDestroy(pq_t *pq)
{
	SortLLDestroy(pq->queue);
	FREE(pq);
}

void *PQDequeue(pq_t *pq)
{
	return(SLLPopFront(pq->queue));
}

int PQEnqueue(pq_t *pq, void *data)
{	
	SortLLInsert(pq->queue, data);
	return 0;
}

void *PQPeek(const pq_t *pq)
{
	return(SLLGetData(SLLBegin(pq->queue)));
}

size_t PQSize(const pq_t *pq)
{
	return (SLLSize(pq->queue));
}

int PQIsEmpty(const pq_t *pq)
{
	return(SLLIsEmpty(pq->queue));	
}

void PQClear(pq_t *pq)
{
	while(!PQIsEmpty(pq))
	{
		PQDequeue(pq);
	}
}





