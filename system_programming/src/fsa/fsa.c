#include <stdio.h> /*printf()*/

#include "../../include/fsa.h"

#define WORD_SIZE 8
#define BYTE (char *)

struct FixedSizeAllocator
{
	size_t next_available_index;
	size_t block_size;
	size_t segment_size;
};

typedef struct BlockHeader
{
	size_t next_free_index;
}block_header_t;


size_t FSASuggestBlockSize(const size_t block_size)
{	
	if (0 == block_size % WORD_SIZE)
	{
		return block_size;
	}
	return (block_size + (WORD_SIZE - (block_size % WORD_SIZE)));
}

static void FSAInitFillHelper(fsa_t *fsa)
{	
	size_t next_available = fsa->next_available_index;
	char *fsa_runner = (char *)fsa;

	while(next_available < fsa->segment_size)
	{	
		block_header_t new_header = {0};

		fsa_runner += next_available;
		new_header.next_free_index = next_available + fsa->block_size
		+ sizeof(block_header_t);
		next_available = new_header.next_free_index;
		*(block_header_t*)fsa_runner = new_header;
		fsa_runner = (char *)fsa;
	}

}

fsa_t *FSAInit(void *allocated, const size_t segment_size, const size_t block_size)
{
	fsa_t *fsa_ptr_location = NULL;
	fsa_ptr_location = allocated;

	while(0 != (size_t)fsa_ptr_location % WORD_SIZE)
	{
		++fsa_ptr_location;
	}

	fsa_ptr_location->next_available_index = (sizeof(fsa_t));
	fsa_ptr_location->block_size = FSASuggestBlockSize(block_size) ;
	fsa_ptr_location->segment_size = segment_size;

	FSAInitFillHelper(fsa_ptr_location);

	return (fsa_ptr_location);
}

size_t FSASuggestSize(const size_t num_of_blocks, const size_t block_size)
{
	 return (sizeof(fsa_t) + num_of_blocks 
	 	* (sizeof(block_header_t) + FSASuggestBlockSize(block_size)));
}

void *FSAAlloc(fsa_t *fsa)
{
	size_t next_available = 0;
	char *returned_pointer = NULL;
	char *fsa_runner = (char *)fsa;

	next_available = fsa->next_available_index;

	if(fsa->segment_size > fsa->next_available_index)
	{
		fsa_runner += next_available;
		fsa->next_available_index = 
		((block_header_t*)fsa_runner)->next_free_index;
		((block_header_t*)fsa_runner)->next_free_index = next_available;
		returned_pointer = fsa_runner + sizeof(block_header_t);
	}

	return returned_pointer;
}

size_t FSACountFree(const fsa_t *fsa)
{	
	char *fsa_runner = (char *)fsa;
	size_t next_available = fsa->next_available_index;
	size_t counter = 0;

	while(next_available < fsa->segment_size)
	{	
		fsa_runner += next_available;
		next_available = ((block_header_t*)fsa_runner)->next_free_index;
		++counter;
		fsa_runner = (char *)fsa;
	}

	return counter;
}

void FSAFree(void *block)
{
	char *fsa_runner = (char *)block;
	size_t head_next_available_holder = 0;
	size_t fsa_next_available_holder = 0;

	fsa_runner -= sizeof(block_header_t);
	head_next_available_holder = ((block_header_t*)fsa_runner)->next_free_index;
	fsa_runner -= head_next_available_holder;
	fsa_next_available_holder = ((fsa_t *)fsa_runner)->next_available_index;
	((fsa_t *)fsa_runner)->next_available_index = head_next_available_holder;
	fsa_runner += head_next_available_holder;
	((block_header_t*)fsa_runner)->next_free_index = fsa_next_available_holder;
}