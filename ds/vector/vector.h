/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Dynamic Vector WS.
 * Date: 01.12.2019
 * Language: C
 * Reviewer: 
 */

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stddef.h> /* size_t */

typedef struct Vector vector_t;

/* This function creates the vector */
vector_t* VectorCreate(size_t element_size, size_t capacity); /*DONE*/

/* This function destroy the vector */
/* Warning: the function doesn't get NULL pointer */
void VectorDestroy(vector_t *vector); /*DONE*/

/* This function push new item at the end of the vector */
/* 0 - success , 1- failure */
/* Warning: Could resize the capacity in an unpredictable manner */
/* Warning: the function doesn't get NULL pointer */
int VectorPushBack(vector_t *vector, const void *data); /*DONE*/

/* This function pops the last item in the vector */
/* Warning: the function doesn't get NULL pointer */
void VectorPopBack(vector_t *vector); /*DONE*/

/* This function resizing the vector size as needed with extra space */
/* 0 - success , 1- failure */
/* Warning: the function doesn't get NULL pointer */
int VectorReserve(vector_t *vector, size_t new_capacity); /*DONE*/

/* This function return the total size of the vetor */
/* Warning: the function doesn't get NULL pointer */
size_t VectorCapacity(const vector_t *vector); /*DONE*/

/* This function return the current number of elements in the vetor */
/* Warning: the function doesn't get NULL pointer */
size_t VectorSize(const vector_t *vector); /*DONE*/

/* This function return specific item address to the user */
/* Warning: the address is valid until using PopBack/PushBack over the limit */
/* Warning: the function doesn't get NULL pointer */
void* VectorGetItemAddress(const vector_t *vector, int position); /*DONE*/

#endif