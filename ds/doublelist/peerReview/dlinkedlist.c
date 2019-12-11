/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Doubly Linked List.
 * Date: 08.12.2019
 * Language: C
 * Reviewer: Yonatan Zaken
 */

#include <stdlib.h>		 /*free(), malloc()*/
#include <assert.h> 	 /*assert()*/
#include "dlinkedlist.h" /*DLL API Functions()*/

#define UNUSED(x) (void)(x)
#define FREE(ptr) free(ptr); ptr=NULL;

typedef struct DLLNode
{
	void *data;
	struct DLLNode *next;
	struct DLLNode *previous;
}dll_node_t;

struct DLL
{
	struct DLLNode head;
	struct DLLNode tail;
};

dll_t *DLLCreate()
{	
	dll_t *newDll = NULL;

	newDll = malloc(sizeof(dll_t));
	if (NULL != newDll)
	{
		newDll->head.next = &newDll->tail;
		newDll->head.previous = NULL;
		newDll->head.data = NULL;
		newDll->tail.previous =  &newDll->head;
		newDll->tail.next = NULL;
		newDll->tail.data = NULL;

		return newDll;	
	}

	return newDll;	
}

void DLLDestroy(dll_t *dll)
{	
	dll_node_t *next_node = dll->head.next;
	dll_node_t *current_node = NULL;

	assert(NULL != dll);

    while (NULL != next_node->next)
    {
    	current_node = next_node;
    	next_node = next_node->next;
    	FREE(current_node);
    }

    FREE(dll);
}


iterator_t DLLGetNext(iterator_t it)
{
	it = it->next;

	return it;
}

iterator_t DLLGetPrev(iterator_t it)
{
	it = it->previous;
	
	return it;
}

iterator_t DLLInsert(dll_t *dll, iterator_t it, void *data)
{	
	dll_node_t *newNode = NULL;

	assert(NULL != dll);
	assert(NULL != data);

	newNode = malloc(sizeof(dll_node_t));
	if(NULL != newNode)
	{
		newNode->data = data;
		newNode->next = it;
		newNode->previous = it->previous;
		it->previous->next = newNode;
		it->previous = newNode;
		it = it->previous;

		return it;
	}

	UNUSED(dll);
	return DLLEnd(dll);
}

iterator_t DLLBegin(const dll_t *dll)
{	
	iterator_t it;

	assert(NULL != dll);

	it =  dll->head.next;

	return it;
}

iterator_t DLLEnd(dll_t *dll)
{	
	iterator_t it = NULL;

	assert(NULL != dll);

	it =  &dll->tail;

	return it;
}

int DLLIsEmpty(const dll_t *dll)
{
	assert(NULL != dll);
	return (dll->head.next == &dll->tail);
}

void *DLLGetData(iterator_t it)
{
	return (it->data);
}

size_t DLLSize(const dll_t *dll)
{
	size_t count = 0;
	iterator_t it = NULL;

	assert(NULL != dll);

	it = DLLBegin(dll);

	while (NULL != it && NULL != it->next)
	{
		++count;
		it = it->next;
	}

	return count;
}

int DLLIsSameIter(const iterator_t it1, const iterator_t it2)
{
	return (it1 == it2);
}

iterator_t DLLRemove(iterator_t it)
{	
	dll_node_t *node_holder = it->next;
	if (NULL != it->next && NULL != it->previous)
	{
		it->previous->next = it->next;
		it->next->previous = it->previous;
		FREE(it);
	}
	it = node_holder;
	return it;
}

iterator_t DLLPushBack(dll_t *dll, void *data)
{	
	iterator_t newIt = NULL;

	assert(NULL != dll);
	assert(NULL != data);

	newIt = DLLEnd(dll);
	newIt = DLLInsert(dll, newIt, data);

	return newIt;
}	

iterator_t DLLPushFront(dll_t *dll, void *data)
{
	iterator_t newIt = NULL;

	assert(NULL != dll);

	newIt = DLLBegin(dll);
	newIt = DLLInsert(dll, newIt, data);

	return newIt;
}

void *DLLPopBack(dll_t *dll)
{
	 iterator_t newIt = NULL;
	 void *data_hodlder = dll->tail.previous->data;
	 assert(NULL != dll);

	 newIt = DLLEnd(dll);
	 newIt = newIt->previous;

	 newIt = DLLRemove(newIt);

	 return data_hodlder;
}

void *DLLPopFront(dll_t *dll)
{	
	iterator_t newIt = NULL;
	void *data_hodlder = dll->head.next->data;

	assert(NULL != dll);

	newIt = DLLBegin(dll);
	newIt = DLLRemove(newIt);

	return data_hodlder;
}

iterator_t DLLSplice(iterator_t start, iterator_t end, iterator_t where)
{	
	start->previous->next = end;
	end->previous->next = where->next;
	where->next->previous = end->previous;
	end->previous = start->previous;
	where->next = start;
	start->previous = where;

	return where;
}

int DLLForEach(iterator_t start, iterator_t end, action_func a_ptr, void *ap)
{	
	iterator_t it_runner = start;
	int res = 1;

	assert(NULL != ap);

	while (!DLLIsSameIter(it_runner,end) && 0 != res)
	{
		res = a_ptr(it_runner->data, ap);
		it_runner = it_runner->next;
	}

	return res;
}

iterator_t DLLFind(iterator_t start, iterator_t end, match_func m_ptr, void *ap)
{	
	iterator_t it_runner = start;

	assert(NULL != ap);

	while ((0 == DLLIsSameIter(it_runner, end)) 
		&& 0 == m_ptr(it_runner->data, ap))
	{
		it_runner = it_runner->next;
	}

	return it_runner;
}



