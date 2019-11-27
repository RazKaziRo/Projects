/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Stack.
 * Date: 26.11.2019
 * Language: C
 * Reviewer: Ben
 */
#include <stdlib.h> /*  malloc()	*/
#include <assert.h> /*	assert()	*/
#include <string.h> /*	memcpy() 	*/
#include "stack.h"

struct Stack
{
	void *start;
	void *current;
	void *end;
	size_t element_size;

};

stack_t* StackCreate(size_t element_size, size_t capacity)
{	

	stack_t *newstack = (stack_t*)malloc(sizeof(stack_t));

	if(NULL == newstack)
	{
		return 0;
	}

	newstack -> start = (void*)malloc(element_size*capacity);

	if(NULL == newstack -> start)
	{
		return 0;
	}

	newstack -> current = newstack -> start;
	newstack -> end = (char *)(newstack -> start) +(element_size*capacity);
	newstack -> element_size = element_size;

	return newstack;
}

void StackDestroy(stack_t* stack)
{	
	assert(NULL != stack -> start);
	assert(NULL != stack);

	free(stack -> start);
	free(stack);
}

int StackPush(stack_t* stack, void* data)
{
	if (stack -> current < stack -> end)
	{
		memcpy(stack -> current, data, stack -> element_size);
		stack -> current = (char *)stack -> current + stack -> element_size;

		return 1;
	}

	return 0;
}

int StackIsEmpty(stack_t* stack)
{
	return stack -> current == stack -> start;
}

size_t StackSize(stack_t* stack)
{
	return ((((char *)stack -> current) - ((char *)stack -> start)) / (stack -> element_size));
}

void *StackPeek(stack_t* stack)
{
	return((char *)stack -> current - stack -> element_size);
}

void StackPop(stack_t* stack)
{	
	if(!StackIsEmpty(stack))
	{
		stack -> current = (char *)stack -> current - stack -> element_size;
	}
}