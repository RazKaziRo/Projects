/*
 * Author: Raz KaziRo
 * Purpose: Answares for System Programing - Varient Size Allocator.
 * Date: 22.12.2019
 * Language: C
 * Reviewer: Yonatan Zaken
 */

#include <assert.h> /* assert */

#include "vsa.h"

#define MAGIC_NUMBER 0xDEADBEEF
#define LAST_HEADER (long)0xFFFFFFFFFFFFFFFF
#define HEAD_SIZE   sizeof(vsa_t)

typedef char byte_t;

struct BlockHeader
{
    long block_size;
    
    #ifndef NDEBUG
    long unique;
    #endif
};

static long AbsNum (long block_size)
{
	return block_size *-1;
}

static void BlockDefragmentation(vsa_t *vsa)
{	
	byte_t *vsa_start_runner = (byte_t *)vsa;
	byte_t *vsa_runner = (byte_t *)vsa;

	long chunk_collector = 0;
	size_t head_count = 0; 

	while (((vsa_t*)vsa_runner)->block_size != LAST_HEADER)
	{	
		chunk_collector = 0;
		head_count = 0; 

		while (((vsa_t*)vsa_runner)->block_size < 0 && 
			LAST_HEADER != ((vsa_t*)vsa_runner)->block_size) 
		{
			vsa_runner += AbsNum(((vsa_t*)vsa_runner)->block_size) + HEAD_SIZE;
		}

		vsa_start_runner = vsa_runner;

		while (((vsa_t*)vsa_runner)->block_size >= 0 && 
			LAST_HEADER != ((vsa_t*)vsa_runner)->block_size)
		{
			chunk_collector += ((vsa_t*)vsa_runner)->block_size;
			vsa_runner += ((vsa_t*)vsa_runner)->block_size + HEAD_SIZE;
			++head_count;
		}
	}

	((vsa_t*)vsa_start_runner)->block_size = chunk_collector
	 + HEAD_SIZE * (head_count - 1);
}

vsa_t *VSAInit(void *allocated, size_t segment_size)
{
	vsa_t start_block_header = {0};
	vsa_t end_block_header = {0};

	byte_t *vsa_runner = allocated;
	vsa_t *new_vsa = allocated;

	assert(NULL != allocated);

	start_block_header.block_size = segment_size - HEAD_SIZE * 2;
	end_block_header.block_size = LAST_HEADER;

	#ifndef NDEBUG
	start_block_header.unique = MAGIC_NUMBER;
	end_block_header.unique = MAGIC_NUMBER;
	#endif

	*(vsa_t *)vsa_runner = start_block_header;
	vsa_runner += segment_size - HEAD_SIZE;
	*(vsa_t *)vsa_runner = end_block_header;

	return new_vsa;
}

size_t VSALargestChunkSize(vsa_t *vsa)
{	
	byte_t *vsa_runner = (byte_t *)vsa;
	long largest_chunk = 0;

	BlockDefragmentation(vsa);

	while (((vsa_t*)vsa_runner)->block_size != LAST_HEADER)
	{	

		while (((vsa_t*)vsa_runner)->block_size < 0 && 
			LAST_HEADER != ((vsa_t*)vsa_runner)->block_size) 
		{
			vsa_runner += AbsNum(((vsa_t*)vsa_runner)->block_size) + HEAD_SIZE;
		}

		if (largest_chunk < ((vsa_t*)vsa_runner)->block_size)
		{
			largest_chunk = ((vsa_t*)vsa_runner)->block_size - HEAD_SIZE;
		}

		vsa_runner += ((vsa_t*)vsa_runner)->block_size + HEAD_SIZE;
	}
	return largest_chunk;
}

void *VSAAlloc(vsa_t *vsa, size_t requested_block_size)
{
	long block_size_holder = 0;
	byte_t *vsa_runner = (byte_t *)vsa;

	block_size_holder = vsa->block_size;

	BlockDefragmentation(vsa);

	while (((vsa_t*)vsa_runner)->block_size < 0 && 
		((vsa_t*)vsa_runner)->block_size != LAST_HEADER)
	{
		vsa_runner += AbsNum(((vsa_t*)vsa_runner)->block_size) + HEAD_SIZE;
	}

	while (((vsa_t*)vsa_runner)->block_size > 0 && 
		((vsa_t*)vsa_runner)->block_size != LAST_HEADER)
	{
		if (((vsa_t*)vsa_runner)->block_size >= (long)requested_block_size)
		{
			block_size_holder = ((vsa_t*)vsa_runner)->block_size;
			((vsa_t*)vsa_runner)->block_size = -requested_block_size;
			vsa_runner += requested_block_size + HEAD_SIZE;
			((vsa_t*)vsa_runner)->block_size = 
			block_size_holder - requested_block_size - HEAD_SIZE;

			#ifndef NDEBUG
			((vsa_t*)vsa_runner)->unique = MAGIC_NUMBER;
			#endif
			vsa_runner -= requested_block_size;

			return vsa_runner;
		}

		else
		{
			vsa_runner += ((vsa_t*)vsa_runner)->block_size + HEAD_SIZE;
		}
	}

	return NULL;
}

void VSAFree(void *block)
{
	byte_t *block_runner = block;

	assert(NULL != block);

	block_runner -= HEAD_SIZE;

	assert(MAGIC_NUMBER == ((vsa_t*)block_runner)->unique);

	((vsa_t*)block_runner)->block_size = 
	AbsNum(((vsa_t*)block_runner)->block_size);
}