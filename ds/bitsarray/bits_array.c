#include <assert.h>

#include "bits_array.h"

#define  m0   0x0000000000000000 /* binary: 0000...*/
#define  m1   0x5555555555555555 /* binary: 0101 0101...*/
#define  m2   0x3333333333333333 /* binary: 00110011..*/
#define  m4   0x0f0f0f0f0f0f0f0f /* binary: 4 zeros,  4 ones ...*/
#define  m8   0x00ff00ff00ff00ff /* binary: 8 zeros,  8 ones ...*/
#define  m16  0x0000ffff0000ffff /* binary: 16 zeros, 16 ones ...*/
#define  m32  0x00000000ffffffff /* binary: 32 zeros, 32 ones  */
#define  m64  0xffffffffffffffff /* binary: 31 ones first 1... */

#define BITS_IN_WORD 64

typedef size_t bitsarr_t;

bitsarr_t BArrSetAllBits(bitsarr_t bits)
{
	return bits |= m64;
}

bitsarr_t BArrResetAllBits(bitsarr_t bits)

{
	return (bits &= m0);
}

int BArrIsOn(bitsarr_t bits, int position)
{
	size_t flag = 1;
	flag = flag << (position-1); 

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
	flag = flag << (position-1); 

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
 	bits = BArrCountOn(~bits);

 	return bits;
 }

 bitsarr_t BArrSetOn(bitsarr_t bits, int position)
 {
 	size_t flag = 1;
	flag = flag << (position-1); 

	return (bits | flag);
 }

  bitsarr_t BArrSetOff(bitsarr_t bits, int position)
 {
 	size_t flag = 1;
	flag = flag << (position-1); 

	return (bits & ~flag);
 }

 bitsarr_t BArrSetBit(bitsarr_t bits, int position, int status)
 {
 	switch(status)
 	{
 		case 1:
 		bits = BArrSetOn(bits,position);
 		break;

 		case 0:
 		bits = BArrSetOff(bits,position);
 		break;
 	}	
 	return bits;
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
		bits = BArrSetOff(bits, position);
	}
	else
	{
		bits = BArrSetOn(bits, position);
	}

	return bits;
}


bitsarr_t BArrMirror(bitsarr_t bits)
{
	bits = ((bits << 32) | (bits >> 32));
	bits = (((bits & m16) << 16) | ((bits & ~m16) >> 16));
	bits = (((bits & m8) << 8) | ((bits & ~m8) >> 8));
	bits = (((bits & m4) << 4) | ((bits & ~m4) >> 4));
	bits = (((bits & m2) << 2) | ((bits & ~m2) >> 2));
	bits = (((bits & m1) << 1) | ((bits & ~m1) >> 1));

	return bits;
}

char *BArrToString(bitsarr_t bits, char *buffer)
{
	int i = 0;
	bits = BArrMirror(bits);

	assert(NULL != buffer);

	for(; i < BITS_IN_WORD; ++i)
	{
	    *buffer = ((bits&1)+48);
	    ++buffer;
	    bits>>= 1;
	}
	*buffer = '\0';

	return buffer;
}