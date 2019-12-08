/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Doubly Linked List.
 * Date: 08.12.2019
 * Language: C
 * Reviewer: 
 */

#include <stdlib.h>		 /*free(), malloc()*/
#include <assert.h> 	 /*assert()*/
#include "dlinkedlist.h" /*API Functions()*/

#define UNUSED(x) (void)(x)
#define FREE(ptr) free(ptr); ptr=NULL;
#define NUM_OF_DUMMYS 1

typedef struct DLLNODE
{
	void *data;
	struct DLLNODE *next;
	struct DLLNODE *previous;
}dll_node_t;

struct DLL
{
	struct DLLNODE head;
	struct DLLNODE tail;
};

struct ITERATOR
{
	struct DLLNODE *node;
};

dll_t *DLLCreate()
{
	dll_t *newDll = malloc(sizeof(dll_t));
	newDll->head.next = &newDll->tail;
	newDll->head.previous = NULL;
	newDll->head.data = NULL;

	newDll->tail.next = NULL;
	newDll->tail.data = NULL;	
	newDll->tail.previous =  &newDll->head;	

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
	it.node = it.node->next;

	return it;
}

iterator_t DLLGetPrev(iterator_t it)
{
	it.node = it.node->previous;
	
	return it;
}

int DLLInsert(dll_t *dll, iterator_t it, void *data)
{	
	dll_node_t *newNode = malloc(sizeof(dll_node_t));

	assert(NULL != dll);
	assert(NULL != data);

	if(NULL != newNode)
	{
		newNode->data = data;
		newNode->next = it.node;
		newNode->previous = it.node->previous;
		it.node->previous->next = newNode;
		it.node->previous = newNode;

		return 1;
	}

	UNUSED(dll);
	return 0;
}

iterator_t DLLBegin(const dll_t *dll)
{	
	iterator_t it;

	assert(NULL != dll);

	it.node =  dll->head.next;

	return it;
}

iterator_t DLLEnd(dll_t *dll)
{	
	iterator_t it;

	assert(NULL != dll);

	it.node =  dll->tail.previous;

	return it;
}

int DLLIsEmpty(const dll_t *dll)
{
	assert(NULL != dll);
	return (dll->head.next == &dll->tail);
}

void *GetData(iterator_t it)
{
	return(it.node->data);
}

size_t DLLSize(const dll_t *dll)
{
	size_t count = 0;
	iterator_t it = DLLBegin(dll);

	while(NULL != it.node && NULL != it.node->next)
	{
		++count;
		it.node = it.node->next;
	}

	return count;
}

int DLLIsSameIter(const iterator_t it1, const iterator_t it2)
{
	return(it1.node == it2.node);
}

iterator_t DLLRemove(iterator_t it)
{	
	dll_node_t *node_holder = it.node->next;
	if(NULL != it.node->next && NULL != it.node->previous)
	{
		it.node->previous->next = it.node->next;
		it.node->previous->previous = it.node->previous;
		FREE(it.node);
	}
	it.node = node_holder;
	return it;
}
