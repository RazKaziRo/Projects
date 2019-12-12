/*********************************/
/*    Data Structures            */
/*    SortSLL                    */
/*    Author :Daniel I.          */
/*    Reviewed By:               */
/*    Date:     11/12/2019       */
/*********************************/

#include <assert.h> /* assert */ 
#include <stdlib.h>	/* malloc */ 

#include "priorityqueue.h" /* API */
#include "sortedlist.h" /* API */ 

#define UNUSE(x) (void)(x)
#define FREE(ptr) free(ptr); ptr = NULL;

struct pack
{
	compare_func_ptr cmp_func;
	void *param;
};

struct PQueue
{
	sll_t *queue;
	pack_t pack;
};


int IsBefore(const void *data1, const void *data2, void *param)
{
	pack_t *p = (pack_t *)param;
	return (0 < p->cmp_func(data1, data2,p->param));
}

pq_t *PQCreate(compare_func_ptr cmp_ptr, void *param)
{
	pq_t *new_pq = (pq_t *)malloc(sizeof(pq_t));
	if (NULL != new_pq)
	{
		new_pq->pack.cmp_func = cmp_ptr;
		new_pq->pack.param = param;
		new_pq->queue = SortLLCreate(IsBefore, &new_pq->pack);
		if (NULL == new_pq)
		{
			FREE(new_pq);

			return NULL;
		}
	}

	return new_pq;
}

void PQDestroy(pq_t *pq)
{
	SortLLDestroy(pq->queue);
	FREE(pq);
}

void *PQDequeue(pq_t *pq)
{
	return SLLPopFront(pq->queue);
}

int PQEnqueue(pq_t *pq, void *data)
{
	SortLLInsert(pq->queue,data);
	return 0;
}

void *PQPeek(const pq_t *pq)
{
	return SLLGetData(SLLBegin(pq->queue));
}

size_t PQSize(const pq_t *pq)
{
	return SLLSize(pq->queue);
}

int PQIsEmpty(const pq_t *pq)
{
	return SLLIsEmpty(pq->queue);
}

void PQClear(pq_t *pq)
{
	size_t size = PQSize(pq);

	while (0 < size)
	{
		PQDequeue(pq);
		--size;
	}
}

void *PQErase(pq_t *pq, match_func_ptr m_ptr, void *param)
{
	void *data = NULL;
	sll_iterator_t it;

	it = SLLFindBy(pq->queue, SLLBegin(pq->queue),
                      SLLEnd(pq->queue), m_ptr, param);


	if (!SLLIsSameIter(it,SLLEnd(pq->queue)))
	{
		data = SLLGetData(it);
		SortLLRemove(it);
	}

	return data;
	
}