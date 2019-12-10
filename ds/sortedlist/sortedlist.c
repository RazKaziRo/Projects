#include <stdlib.h> /*malloc()*/

#include "sortedlist.h"

#define FREE(ptr) free(ptr); ptr=NULL;

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

int SLLIsEmpty(const sll_t *sll)
{
	return(DLLIsEmpty(sll->list));
}

size_t SLLSize(const sll_t *sll)
{
	return(DLLSize(sll->list));
}

sll_iterator_t SLLBegin(const sll_t *sll)
{
	sll_iterator_t sll_it;
	sll_it.current = DLLBegin(sll->list);

	return(sll_it);
}

sll_iterator_t SLLEnd(sll_t *sll) /*UT*/
{
	sll_iterator_t sll_it;
	sll_it.current = DLLEnd(sll->list);

	return(sll_it);
}

sll_iterator_t SLLNext(sll_iterator_t sll_it) /*UT*/
{	
	sll_it.current = DLLGetNext(sll_it.current);

	return(sll_it);
}

sll_iterator_t SLLPrev(sll_iterator_t sll_it)
{
	sll_it.current = DLLGetPrev(sll_it.current);

	return(sll_it);
}

sll_iterator_t SortLLRemove(sll_iterator_t sll_it)
{
	sll_it.current = DLLRemove(sll_it.current);

	return (sll_it);
}

void *SLLGetData(sll_iterator_t sll_it)
{
	return(DLLGetData(sll_it.current));
}

int SLLIsSameIter(const sll_iterator_t sll_it1, const sll_iterator_t sll_it2)
{
	return(DLLIsSameIter(sll_it1.current, sll_it2.current));
}

void *SLLPopBack(sll_t *sll)
{
	return(DLLPopBack(sll->list));
}

void *SLLPopFront(sll_t *sll)
{
	return(DLLPopFront(sll->list));
}

sll_iterator_t SLLFind(const sll_t *sll, const void *data, sll_iterator_t start, sll_iterator_t end)
{

}



