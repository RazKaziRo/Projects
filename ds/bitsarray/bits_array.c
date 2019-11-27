/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - BitsArray.
 * Date: 26.11.2019
 * Language: C
 * Reviewer: Eliya Goldfisher
 */

#include <assert.h> 	/*assert()*/

#include "bits_array.h" /*bits arr functions ()*/

#define  M0   0x0000000000000000 /* binary: 0000...*/
#define  M1   0x5555555555555555 /* binary: 0101 0101...*/
#define  M2   0x3333333333333333 /* binary: 00110011..*/
#define  M4   0x0f0f0f0f0f0f0f0f /* binary: 4 zeros,  4 ones ...*/
#define  M8   0x00ff00ff00ff00ff /* binary: 8 zeros,  8 ones ...*/
#define  M16  0x0000ffff0000ffff /* binary: 16 zeros, 16 ones ...*/
#define  M32  0x00000000ffffffff /* binary: 32 zeros, 32 ones  */
#define  M64  0xffffffffffffffff /* binary: 31 ones first 1... */

#define BITS_IN_WORD 64

bitsarr_t BArrSetAllBits(bitsarr_t bits)
{
	return bits |= M64;
}

bitsarr_t BArrResetAllBits(bitsarr_t bits)

{
	return (bits &= M0);
}

int BArrIsOn(bitsarr_t bits, int position)
{
	size_t flag = 1;

	flag <<= (position-1); 

	if(flag == (bits & flag))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BArrIsOff(bitsarr_t bits, int position)
{
	size_t flag = 1;

	flag <<= (position-1); 

	if (flag != (bits & flag))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

 size_t BArrCountOn(bitsarr_t bits)
 {
 	size_t count = 0;

	while (0 != bits) 
	{ 
        count += bits & 1; 
        bits >>= 1; 
    } 

    return count; 
 }

 size_t BArrCountOff(bitsarr_t bits)
 {
 	return BArrCountOn(~bits);
 }

 bitsarr_t BArrSetOn(bitsarr_t bits, int position)
 {
 	size_t flag = 1;

	flag <<= (position-1); 

	return (bits | flag);
 }

 bitsarr_t BArrSetOff(bitsarr_t bits, int position)
 {
 	size_t flag = 1;
 	
	flag <<= (position-1); 

	return (bits & ~flag);
 }

 bitsarr_t BArrSetBit(bitsarr_t bits, int position, int status)
 {
 	switch (status)
 	{
 		case 1:
 		return BArrSetOn(bits,position);
 		break;

 		case 0:
 		return BArrSetOff(bits,position);
 		break;
 	}	
 }

 bitsarr_t BArrRotateRight(bitsarr_t bits, int num_of_rotations)
 {
 	 return (bits >> num_of_rotations)|(bits << (BITS_IN_WORD - num_of_rotations)); 
 }

 bitsarr_t BArrRotateLeft(bitsarr_t bits, int num_of_rotations)
 {
 	return (bits << num_of_rotations)|(bits >> (BITS_IN_WORD - num_of_rotations)); 
 }
 
bitsarr_t BArrFlipBit(bitsarr_t bits, int position)
{
	if (1 == BArrIsOn(bits, position))
	{
		return BArrSetOff(bits, position);
	}

	return BArrSetOn(bits, position);
}


bitsarr_t BArrMirror(bitsarr_t bits)
{
	bits = ((bits << 32) | (bits >> 32));
	bits = (((bits & M16) << 16) | ((bits & ~M16) >> 16));
	bits = (((bits & M8) << 8) | ((bits & ~M8) >> 8));
	bits = (((bits & M4) << 4) | ((bits & ~M4) >> 4));
	bits = (((bits & M2) << 2) | ((bits & ~M2) >> 2));
	bits = (((bits & M1) << 1) | ((bits & ~M1) >> 1));

	return bits;
}

char *BArrToString(bitsarr_t bits, char *buffer)
{
	int i = 0;
    char *buff_runner = NULL;

	assert(NULL != buffer);
    
    bits = BArrMirror(bits);
    buff_runner = buffer;

	for(; i < BITS_IN_WORD; ++i)
	{
	    *buff_runner = ((bits & 1) + 48);
	    ++buff_runner;
	    bits >>= 1;
	}
	
	*buff_runner = '\0';

	return buffer;
}