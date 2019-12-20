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

struct BlockHeader
{
    long block_size;
    
    #ifndef NDEBUG
    long unique;
    #endif
};



vsa_t *VSAInit(void *allocated, size_t segment_size)
{


}
