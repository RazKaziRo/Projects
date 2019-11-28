/*********************************/
/*    Data Structures            */
/*    Bits Arrays                */
/*    Author :   Daniel Ifrah    */
/*    Reviewed By:               */
/*    Date:    26/11/2019        */
/*                               */
/*********************************/

#include <stddef.h>  /* size_t data type */
#include <stdlib.h>  /* malloc */
#include <assert.h>  /* assert */
#include <string.h>  /* memcpy */
#include <stdio.h>   /* printf */
#include "stack.h"   /* stack data structure functions */

struct Stack
{
	void *start;
	void *current;
	void *end;
	size_t data_size;
};


stack_t* StackCreate(size_t element_size, size_t capacity)
{
	stack_t *new_stack = (stack_t*)malloc(sizeof(stack_t));
	if (NULL == new_stack)
	{
		return NULL;
	}

	new_stack->start = (void*)malloc(element_size * capacity);
	if (NULL == new_stack->start)
	{
		return NULL;
	}

	new_stack->data_size = element_size;
	new_stack->current = new_stack->start;
	new_stack->end = ((char*)new_stack->start + element_size * (capacity - 1));

	return new_stack;
}

void StackDestroy(stack_t* mystack)
{
	assert(NULL != mystack);
	assert(NULL != mystack->start);

	free(mystack->start);
	mystack->start = NULL;
	free(mystack);
	mystack = NULL;
}

int StackPush(stack_t* mystack, void* data)
{
	assert(NULL != mystack);
	assert(NULL != data);

	if (mystack->current > mystack->end)
	{
		return 0;
	}

	memcpy(mystack->current, data, mystack->data_size);
	mystack->current = (char*)mystack->current + mystack->data_size;

	return 1;
}

void StackPop(stack_t* mystack)
{

	mystack->current = (char*)mystack->current - mystack->data_size;
}

int StackIsEmpty(const stack_t* mystack)
{
	
	return (0 == (char*)mystack->current - (char*)mystack->start);
}

size_t StackSize(const stack_t* mystack)
{
	return (((char*)mystack->current - 
		     (char*)mystack->start)/(mystack->data_size));
}

void* StackPeek(const stack_t* mystack)
{
	if (mystack->current == mystack->start)
	{
		return NULL;
	}

	return ((char*)mystack->current - mystack->data_size);
}