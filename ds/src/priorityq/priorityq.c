/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Sorted Linked List.
 * Date: 10.12.2019
 * Language: C
 * Reviewer: Shye Shapira
 */
#include <stdlib.h> /*malloc()*/

#include "../../include/sortedlist.h" /*Sorted List API()*/
#include "../../include/priorityq.h"

#define FREE(ptr) free(ptr); ptr = NULL;



typedef struct DLLFuncWrapper
{
	compare_func user_cmp_ptr;
	void *data;
}u_func_wrapper_t;

struct PQueue
{
	sll_t *queue;
	u_func_wrapper_t *dll_func_w;
	compare_func my_cmp_ptr;
	void *param;
};

static int PQCompareWrapper(const void *data1,const void *data2, void *param)
{	
	int res = 0;

	u_func_wrapper_t *wrapper = (u_func_wrapper_t *)data1;
	res = wrapper->user_cmp_ptr(wrapper->data, data2, param);

	return (0 > res);
}

pq_t *PQCreate(compare_func user_cmp_ptr, void *param)
{	
	pq_t *newPQueue = (pq_t *)malloc(sizeof(pq_t));

	u_func_wrapper_t *newFuncWrapper = malloc(sizeof(u_func_wrapper_t));
	if(NULL != newFuncWrapper)
	{
		newFuncWrapper->user_cmp_ptr = user_cmp_ptr;
		newFuncWrapper->data = NULL;
	}

	if (NULL != newPQueue)
	{
		newPQueue->queue = SortLLCreate(&PQCompareWrapper, param);
		newPQueue->my_cmp_ptr = &PQCompareWrapper;
		newPQueue->param = param;
		newPQueue->dll_func_w = newFuncWrapper;
	}
	return newPQueue;
}

void PQDestroy(pq_t *pq)
{
	SortLLDestroy(pq->queue);
	FREE(pq->dll_func_w);
	FREE(pq);
}

void *PQDequeue(pq_t *pq)
{
	return(SLLPopFront(pq->queue));
}

int PQEnqueue(pq_t *pq, void *data)
{	
	pq->dll_func_w->data = data;
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





