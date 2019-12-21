/*
 * Author: Raz KaziRo
 * Purpose: Answares for System Programing - Varient Size Allocator.
 * Date: 22.12.2019
 * Language: C
 * Reviewer: Yonatan Zaken
 */
#include <assert.h> /* assert */

#include "../../include/vsa.h" /* API functions */

#define MAGIC_NUMBER 0xDEADBEEF
#define LAST_HEADER 0x8000000000000000

typedef char byte_t;

struct BlockHeader
{
    long block_size;
    
    #ifndef NDEBUG
    long unique;
    #endif
};

vsa_t *VSAInit(void *allocated, size_t segment_size)
{
	vsa_t start_block_header = {0};
	vsa_t end_block_header = {0};

	byte_t *vsa_runner = allocated;
	vsa_t *new_vsa = allocated;

	assert(NULL != allocated);

	start_block_header.block_size = segment_size - sizeof(vsa_t)*2;
	end_block_header.block_size = LAST_HEADER;

	#ifndef NDEBUG
	start_block_header.unique = MAGIC_NUMBER;
	end_block_header.unique = MAGIC_NUMBER;
	 #endif

	*(vsa_t *)vsa_runner = start_block_header;
	vsa_runner += segment_size - sizeof(vsa_t);
	*(vsa_t *)vsa_runner = end_block_header;

	return new_vsa;
}

static long AbsoluteNUmber (long num)
{
	return num *-1;
}

void *VSAAlloc(vsa_t *vsa, size_t requested_block_size)
{
	long block_size_holder = 0;
	vsa_t new_block_header = {0};

	block_size_holder = vsa->block_size;
	byte_t *vsa_runner = (byte_t *)vsa;

	while(block_size_holder < 0 && block_size_holder != LAST_HEADER)
	{
		vsa_runner += AbsoluteNUmber(block_size_holder);
		block_size_holder = ((vsa_t*)vsa_runner)->block_size;
	}

	if(block_size_holder != LAST_HEADER && 
		((vsa_t*)vsa_runner)->block_size >= requested_block_size)
	{	
		((vsa_t*)vsa_runner)->block_size = block_size_holder -requested_block_size;
		((vsa_t*)vsa_runner)->unique = MAGIC_NUMBER;
	}
	vsa_runner += sizeof(vsa_t);
	
	return vsa_runner;
}
