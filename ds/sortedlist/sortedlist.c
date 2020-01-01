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

static sll_iterator_t SortLLRequierdIterator(sll_t *sll, 
	sll_iterator_t start, sll_iterator_t end, void *data)
{
	sll_iterator_t sll_runner_it;

	assert(NULL != sll);
	assert(NULL != data);

	sll_runner_it = start;

	while ((!SortLLIsEmpty(sll)) && (!SortLLIsSameIter(sll_runner_it, end)) && 
		(0 == sll-> cmp_func(SortLLGetData(sll_runner_it),data, sll->param)))
	{
		sll_runner_it = SortLLNext(sll_runner_it);
	}

	return sll_runner_it;
}

sll_iterator_t SortLLFind(const sll_t *sll, const void *data,
 sll_iterator_t start, sll_iterator_t end)
{
	sll_iterator_t sll_returned_iterator;

	assert(NULL != sll);
	assert(NULL != data);

	sll_returned_iterator = 
	SortLLRequierdIterator((sll_t *)sll, start, end, (void *)data);
	
	sll_returned_iterator.current = DLLGetPrev(sll_returned_iterator.current);

	if (!SortLLIsSameIter(sll_returned_iterator,SortLLPrev(SortLLBegin(sll))) 
		&& (0 == sll->cmp_func(data,SortLLGetData(sll_returned_iterator),sll->param)))
	{
		return sll_returned_iterator;
	}

	return end;
}

sll_iterator_t SortLLFindBy(const sll_t *sll, sll_iterator_t start,
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

int SortLLForEach(sll_iterator_t start, sll_iterator_t end, action_func_ptr a_ptr,
 void *ap)
{	
	return (DLLForEach(start.current, end.current, a_ptr, ap));
}

sll_iterator_t SortLLInsert(sll_t *sll, void *data)
{	
	sll_iterator_t sll_returned_iterator;

	assert(NULL != sll);
	assert(NULL != data);

	sll_returned_iterator = 
	SortLLRequierdIterator(sll,SortLLBegin(sll),SortLLEnd(sll), data);

	sll_returned_iterator.current = 
	DLLInsert(sll->list,sll_returned_iterator.current, data);

	return sll_returned_iterator;
}

int SortLLIsEmpty(const sll_t *sll)
{	
	assert(NULL != sll);

	return (DLLIsEmpty(sll->list));
}

size_t SortLLSize(const sll_t *sll)
{	
	assert(NULL != sll);

	return (DLLSize(sll->list));
}

sll_iterator_t SortLLBegin(const sll_t *sll)
{
	sll_iterator_t sll_it;

	assert(NULL != sll);

	sll_it.current = DLLBegin(sll->list);

	return (sll_it);
}

sll_iterator_t SortLLEnd(const sll_t *sll)
{
	sll_iterator_t sll_it;

	assert(NULL != sll);

	sll_it.current = DLLEnd(sll->list);

	return (sll_it);
}

sll_iterator_t SortLLNext(sll_iterator_t sll_it)
{	
	sll_it.current = DLLGetNext(sll_it.current);

	return (sll_it);
}

sll_iterator_t SortLLPrev(sll_iterator_t sll_it)
{
	sll_it.current = DLLGetPrev(sll_it.current);

	return (sll_it);
}

sll_iterator_t SortLLRemove(sll_iterator_t sll_it)
{
	sll_it.current = DLLRemove(sll_it.current);

	return (sll_it);
}

void *SortLLGetData(sll_iterator_t sll_it)
{
	return (DLLGetData(sll_it.current));
}

int SortLLIsSameIter(const sll_iterator_t sll_it1, const sll_iterator_t sll_it2)
{
	return (DLLIsSameIter(sll_it1.current, sll_it2.current));
}

void *SortLLPopBack(sll_t *sll)
{
	return (DLLPopBack(sll->list));
}

void *SortLLPopFront(sll_t *sll)
{
	return (DLLPopFront(sll->list));
}

void SortLLMerge(sll_t *dest, sll_t *src)
{	
	sll_iterator_t sll_src_start_runner, sll_src_end_runner, sll_src_end,
	 sll_dest_end, sll_dest_start, sll_dest_where_runner;

	assert(NULL != src);
	assert(NULL != dest);

	sll_src_start_runner = SortLLBegin(src);
	sll_dest_start = SortLLBegin(dest);
	sll_dest_end = SortLLEnd(dest);
	sll_src_end = SortLLEnd(src);

	while (!SortLLIsSameIter(sll_src_start_runner, sll_src_end))
	{	
		sll_dest_where_runner = 
		SortLLRequierdIterator(dest,sll_dest_start,sll_dest_end, 
			SortLLGetData(sll_src_start_runner));

		sll_dest_start = sll_dest_where_runner;
		sll_dest_where_runner = SortLLPrev(sll_dest_where_runner);

		if (SortLLIsSameIter(sll_dest_start, sll_dest_end))
		{
			sll_src_end_runner = SortLLNext(sll_src_end_runner);
		}
		else
		{
			sll_src_end_runner = 
			SortLLRequierdIterator(src,sll_src_start_runner, sll_src_end, 
				SortLLGetData(sll_dest_start));
		}

		sll_dest_where_runner.current =
		DLLSplice(sll_src_start_runner.current, sll_src_end_runner.current,
		 sll_dest_where_runner.current);

		sll_src_start_runner = sll_src_end_runner;
	}
}
