/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Sorted Linked List.
 * Date: 10.12.2019
 * Language: C
 * Reviewer: Shye Shapira
 */

#include <stdlib.h> /* malloc() */
#include <assert.h> /* assert() */

#include "sortedlist.h" /* SLL API Functions() */

#define FREE(ptr) free(ptr); ptr=NULL;
#define UNUSED(x) (void)(x)

struct SLL
{
	dll_t *list;
	is_before cmp_func;
	void *param;
};

sll_t *SortLLCreate(is_before func, void *param)
{
	sll_t *newSll = (sll_t *)malloc(sizeof(sll_t));
	if (NULL != newSll)
	{
		newSll->list = DLLCreate();
		newSll->cmp_func = func;
		newSll->param = param;
	}

	return newSll;
}

void SortLLDestroy(sll_t *sll)
{
	DLLDestroy(sll->list);
	FREE(sll);
}

static sll_iterator_t SLLRequierdIterator(sll_t *sll, 
	sll_iterator_t start, sll_iterator_t end, void *data)
{
	sll_iterator_t sll_runner_it;

	assert(NULL != sll);
	assert(NULL != data);

	sll_runner_it = start;

	while ((!SLLIsEmpty(sll)) && (!SLLIsSameIter(sll_runner_it, end)) && 
		(0 == sll-> cmp_func(SLLGetData(sll_runner_it),data, NULL)))
	{
		sll_runner_it = SLLNext(sll_runner_it);
	}

	return sll_runner_it;
}

sll_iterator_t SLLFind(const sll_t *sll, const void *data,
 sll_iterator_t start, sll_iterator_t end)
{
	sll_iterator_t sll_returned_iterator;

	assert(NULL != sll);
	assert(NULL != data);

	sll_returned_iterator = 
	SLLRequierdIterator((sll_t *)sll, start, end, (void *)data);
	
	sll_returned_iterator.current = DLLGetPrev(sll_returned_iterator.current);

	if (!SLLIsSameIter(sll_returned_iterator,SLLPrev(SLLBegin(sll))) 
		&& (0 == sll->cmp_func(data,SLLGetData(sll_returned_iterator),NULL)))
	{
		return sll_returned_iterator;
	}

	return end;
}

sll_iterator_t SLLFindBy(const sll_t *sll, sll_iterator_t start,
 sll_iterator_t end, match_func_ptr m_ptr ,const void *data)
{
	sll_iterator_t sll_returned_iterator;

	assert(NULL != sll);
	assert(NULL != data);

	sll_returned_iterator.current = 
	DLLFind(start.current, end.current, m_ptr, (void *)data);

	UNUSED(sll);

	return (sll_returned_iterator);
}

int SLLForEach(sll_iterator_t start, sll_iterator_t end, action_func_ptr a_ptr,
 void *ap)
{	
	assert(NULL != ap);

	return (DLLForEach(start.current, end.current, a_ptr, ap));
}

sll_iterator_t SortLLInsert(sll_t *sll, void *data)
{	
	sll_iterator_t sll_returned_iterator;

	assert(NULL != sll);
	assert(NULL != data);

	sll_returned_iterator = 
	SLLRequierdIterator(sll,SLLBegin(sll),SLLEnd(sll), data);

	sll_returned_iterator.current = 
	DLLInsert(sll->list,sll_returned_iterator.current, data);

	return sll_returned_iterator;
}

int SLLIsEmpty(const sll_t *sll)
{	
	assert(NULL != sll);

	return (DLLIsEmpty(sll->list));
}

size_t SLLSize(const sll_t *sll)
{	
	assert(NULL != sll);

	return (DLLSize(sll->list));
}

sll_iterator_t SLLBegin(const sll_t *sll)
{
	sll_iterator_t sll_it;

	assert(NULL != sll);

	sll_it.current = DLLBegin(sll->list);

	return (sll_it);
}

sll_iterator_t SLLEnd(const sll_t *sll)
{
	sll_iterator_t sll_it;

	assert(NULL != sll);

	sll_it.current = DLLEnd(sll->list);

	return (sll_it);
}

sll_iterator_t SLLNext(sll_iterator_t sll_it)
{	
	sll_it.current = DLLGetNext(sll_it.current);

	return (sll_it);
}

sll_iterator_t SLLPrev(sll_iterator_t sll_it)
{
	sll_it.current = DLLGetPrev(sll_it.current);

	return (sll_it);
}

sll_iterator_t SortLLRemove(sll_iterator_t sll_it)
{
	sll_it.current = DLLRemove(sll_it.current);

	return (sll_it);
}

void *SLLGetData(sll_iterator_t sll_it)
{
	return (DLLGetData(sll_it.current));
}

int SLLIsSameIter(const sll_iterator_t sll_it1, const sll_iterator_t sll_it2)
{
	return (DLLIsSameIter(sll_it1.current, sll_it2.current));
}

void *SLLPopBack(sll_t *sll)
{
	return (DLLPopBack(sll->list));
}

void *SLLPopFront(sll_t *sll)
{
	return (DLLPopFront(sll->list));
}

void SLLMerge(sll_t *dest, sll_t *src)
{	
	sll_iterator_t sll_src_start_runner, sll_src_end_runner, sll_src_end,
	 sll_dest_end, sll_dest_start, sll_dest_where_runner;

	assert(NULL != src);
	assert(NULL != dest);

	sll_src_start_runner = SLLBegin(src);
	sll_dest_start = SLLBegin(dest);
	sll_dest_end = SLLEnd(dest);
	sll_src_end = SLLEnd(src);

	while (!SLLIsSameIter(sll_src_start_runner, sll_src_end))
	{	
		sll_dest_where_runner = 
		SLLRequierdIterator(dest,sll_dest_start,sll_dest_end, 
			SLLGetData(sll_src_start_runner));

		sll_dest_start = sll_dest_where_runner;
		sll_dest_where_runner = SLLPrev(sll_dest_where_runner);

		if (SLLIsSameIter(sll_dest_start, sll_dest_end))
		{
			sll_src_end_runner = SLLNext(sll_src_end_runner);
		}
		else
		{
			sll_src_end_runner = 
			SLLRequierdIterator(src,sll_src_start_runner, sll_src_end, 
				SLLGetData(sll_dest_start));
		}

		sll_dest_where_runner.current =
		DLLSplice(sll_src_start_runner.current, sll_src_end_runner.current,
		 sll_dest_where_runner.current);

		sll_src_start_runner = sll_src_end_runner;
	}
}