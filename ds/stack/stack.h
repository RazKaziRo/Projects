/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Stack.
 * Date: 26.11.2019
 * Language: C
 * Reviewer: Ben
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <stddef.h> /*size_t*/

typedef struct Stack stack_t;

/* This function creates new Stack */
stack_t* StackCreate(size_t element_size, size_t capacity); /*DONE*/

/* This function destroy the Stack */
void StackDestroy(stack_t* mystack);/* DONE */

/* This function push given element to the top of the Stack */
int StackPush(stack_t* mystack, void* data);/* DONE */

/* This function pop the element that is on the top of the Stack and remove it */
void StackPop(stack_t* mystack);/* DONE */

/* This function checkes if the Stack is empty */
int StackIsEmpty(stack_t* mystack); /* DONE */

/* This function return the number of elements in the stack */
size_t StackSize(stack_t* mystack); /* DONE */

/* This function returns the top most elemet on the Stack */
void* StackPeek(stack_t* mystack);

#endif
