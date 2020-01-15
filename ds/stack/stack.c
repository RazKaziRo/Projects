/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Stack.
 * Date: 26.11.2019
 * Language: C
 * Reviewer: Ben Step
 */

#include <stdlib.h> /*  malloc() */
#include <assert.h> /*	assert() */
#include <string.h> /*	memcpy() */
#include "stack.h"  /*	Stack()  */

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

	if (NULL == newstack)
	{
		return 0;
	}

	newstack -> start = (void *)malloc(element_size*capacity);

	if (NULL == newstack -> start) 
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

	free(stack -> start); stack -> start = NULL;
	free(stack);stack = NULL;
}

int StackPush(stack_t* stack, void* data)
{
    assert(NULL != stack);
    assert(NULL != data);

	if (stack -> current < stack -> end)
	{
		memcpy(stack -> current, data, stack -> element_size);
		stack -> current = (char *)stack -> current + stack -> element_size;

		return 1;
	}
    
	return 0;
}

int StackIsEmpty(const stack_t* stack)
{
    assert(NULL != stack);

	return stack -> current == stack -> start;
}

size_t StackSize(const stack_t* stack)
{
    assert(NULL != stack);

	return ((((char *)(stack -> current) - (char *)(stack -> start)) / stack -> element_size));
}

void *StackPeek(const stack_t* stack)
{
    assert(NULL != stack);

	if (!StackIsEmpty(stack))
	{
	   return((char *)(stack -> current) - stack -> element_size);
	}

	return NULL;
}

void StackPop(stack_t* stack)
{	
    assert(NULL != stack);

	if (!StackIsEmpty(stack))
	{
		stack -> current = (char *)stack -> current - stack -> element_size;
	}
}

void *StackPopWithData(stack_t* stack)
{	
	void *data = NULL;
    assert(NULL != stack);

	if (!StackIsEmpty(stack))
	{	
		data = StackPeek(stack);
		stack->current = (char *)stack->current - stack -> element_size;
	}

	return data;
}

void StackRecursiveSort(stack_t* mystack)
{	
	int top_holder = 0;
	int buttom_holder = 0;
	size_t stack_size = StackSize(mystack);

	if (2 > stack_size)
	{
		return;
	}

	if (2 == stack_size)
	{
		top_holder = *(int *)StackPopWithData(mystack);

		if(top_holder < *(int *)StackPeek(mystack))
		{
			buttom_holder = *(int *)StackPopWithData(mystack);
			StackPush(mystack, &top_holder);
			StackPush(mystack, &buttom_holder);
		}
		else
		{
			StackPush(mystack, &top_holder);
		}

		return;
	}

	top_holder = *(int *)StackPopWithData(mystack);
	StackRecursiveSort(mystack);

	if(top_holder < *(int *)StackPeek(mystack))
	{
		buttom_holder = *(int *)StackPopWithData(mystack);
		StackPush(mystack, &top_holder);
		StackRecursiveSort(mystack);
		StackPush(mystack, &buttom_holder);
	}
	else
	{
		StackPush(mystack, &top_holder);
	}
}
