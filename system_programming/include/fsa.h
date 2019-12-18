#ifndef __FSA_H__
#define __FSA_H__

#include <stddef.h> /*size_t*/

typedef struct FixedSizeAllocator fsa_t;

/*
* FSAInit() - 
* Returns pointer to the fsa_t. 
* complexity of O(1);
*/
fsa_t *FSAInit(void *allocated, const size_t segment_size, const size_t block_size); /*DONE*/

/*
* FSAAlloc() -
* Allocate memory block to the user.
* returns pointer to the block.
* complexity of O(1);                  
*/
void *FSAAlloc(fsa_t *fsa);/*DONE*/

/*
* FSAFree()-
* Gets pointer to memory block and free it.
* Returns void.
* complexity of O(1).               
*/
void FSAFree(void *block); /*DONE*/

/*
* FSACountFree()-
* Counts the number of free blocks in the segment.
* complexity of O(n)
*/
size_t FSACountFree(const fsa_t *fsa);/*DONE*/

/*
* FSASuggestSize() - 
* Gets number of blocks demanded by the user and returns the segment size suggested.
* complexity of O(1);              
*/
size_t FSASuggestSize(const size_t num_of_blocks, const size_t block_size); /*DONE*/

#endif
