#include "bits_array.h"

#define  m0   0x0000000000000000 /* binary: 0101...*/
#define  m1   0x5555555555555555 /* binary: 0101...*/
#define  m2   0x3333333333333333 /* binary: 0011...*/
#define  m3   0xaaaaaaaaaaaaaaaa /* binary: 1010 1010...*/
#define  m4   0x0f0f0f0f /*binary:  0000 1111 ...*/
#define  m5   0xcccccccc /* binary: 1100 1100...*/
#define  m6   0xf0f0f0f0 /*binary:  1111 0000 ...*/
#define  m7   0xff00ff00 /*binary:  1111 1111 0000 0000  ...*/
#define  m8   0x00ff00ff /*binary:  8 zeros,  8 ones ...*/
#define  m9   0x10101010 /*binary:  8 zeros,  8 ones ...*/
#define  m10  0x01010101 /*binary:  8 zeros,  8 ones ...*/
#define  m16  0x0000ffff /*binary: 16 zeros, 16 ones ...*/
#define  m732 0x7fffffffffffffff /*binary: 31 ones first 1...*/
#define  m32  0xffffffffffffffff /*binary: 32 ones ...*/

#define BITS_IN_WORD 64

size_t BArrSetAllBits(size_t bits)
{
	return bits |= m732;
}

size_t BArrResetAllBits(size_t bits)

{
	return (bits &= m0);
}

int BArrIsOn(size_t bits, int position)
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

int BArrIsOff(size_t bits, int position)
{
	size_t flag = 1;
	flag = flag << (position-1); 

	if(flag != (bits & flag))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

 size_t BArrCountOn(size_t bits)
 {
 	size_t count = 0;

	while(bits) 
	{ 
        count += bits & 1; 
        bits >>= 1; 
    } 
    return count; 
 }

 size_t BArrCountOff(size_t bits)
 {
 	BArrCountOn(~bits);
 }

 size_t BArrSetOn(size_t bits, int position)
 {
 	size_t flag = 1;
	flag = flag << (position-1); 

	return (bits | flag);
 }

  size_t BArrSetOff(size_t bits, int position)
 {
 	size_t flag = 1;
	flag = flag << (position-1); 

	return (bits ^ flag);
 }

 size_t BArrSetBit(size_t bits, int position, int status)
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
 
/*****************************************/

static size_t PrintBits(size_t a, int loc)   
{
    size_t buf = a & 1 << loc;

    if (buf == 0)
    {
    	return 0;
    } 
    else
    {
    	return 1;
    }  
}

void PrintSize_t(size_t bits)
{
	int i = 0, c = 0;

    for (i = BITS_IN_WORD; i > 0; --i)
    {
        printf("%ld",PrintBits(bits,i));
        ++c;

    }
     printf("\n");
}
