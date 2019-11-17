/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW6 - Bitwise Operations.
 * Date: 14.11.2019
 * Language: C
 * Reviewer: 
 */

#include "ws6head.h"

unsigned long BitWisePow2(unsigned int x, unsigned int y)
{
	return x<<y;
}

int IsPowOf2Loop(unsigned int n)
{
	unsigned int x = 1;

	while(x <= n)
	{
		if(x == n)
		{
			return 1;
		}

		x = x<<1;

	}

	return 0;
}

int IsPowOf2NoLoop(unsigned int n)
{
	if (0 ==(n&(n-1)))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

unsigned int AddOneToInt(unsigned int n)
{
    unsigned int m = 1; 
      
    while( n & m ) 
    { 
        n = n ^ m; 
        m <<= 1; 
    } 
      
    n = n ^ m; 
    return n; 
}

void ThreeBitsOn(unsigned int n[], int size)
{
	int count = 0, i = 0;
	unsigned int tmp = 0;

	for(; i<size-1; i++)
	{	
	tmp = n[i];

	while(n[i] > 0)
	{
		count += n[i] & 1;
		n[i] >>= 1;
	}
	if(count == 3)
	{
		printf("Number with 3 bits on: %d \n", tmp);
	}
	count = 0;
}

}	

unsigned int ByteMirrorLoop(unsigned const int num)
{	
    unsigned int  NO_OF_BITS = sizeof(num) * 8; 
    unsigned int reverse_num = 0; 
    unsigned int i = 0; 

    for (; i < NO_OF_BITS; i++) 
    { 
       if((num & (1 << i)))
       {
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);   
       }
    } 

   return reverse_num; 
} 



unsigned int ByteMirrorNOLoop(unsigned int num)
{	

	num = (((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1));
	num = (((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2));
	num = (((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4));
	num = (((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8));
	num = ((num >> 16) | (num << 16));

	return num;

}


unsigned int TwoANDSixBitON(const unsigned char input_ch)
{
	unsigned int hold_6bit = (input_ch >> 5) & 1;
	unsigned int hold_2bit = (input_ch >> 1) & 1;

	return(hold_2bit & hold_6bit);

}


unsigned int TwoORSixBitON(const unsigned char input_ch)
{

	unsigned int hold_6bit = (input_ch >> 5) & 1;
	unsigned int hold_2bit = (input_ch >> 1) & 1;

	return(hold_2bit | hold_6bit);

}


unsigned int SwapThreeAndFiveBits(unsigned int input_num)
{	
	unsigned int hold_3bit = (input_num>>2) & 1;
	unsigned int hold_5bit = (input_num>>4) & 1;
	unsigned int tmp_num = hold_3bit^hold_5bit;

	hold_3bit = tmp_num << 2;
	hold_5bit = tmp_num << 4;

	return input_num^(hold_5bit | hold_3bit);
}


unsigned int ClosestDivideBySixteen(const unsigned int n)
{
	unsigned int closest_num = n>>4;
	closest_num <<= 4;

	return closest_num;
}

void SwapTwoVariables(unsigned int *x,unsigned int *y)
{
	*x = *x^*y;
	*y = *x^*y;
	*x = *x^*y;
}

unsigned int CountSetOfBitsLoop(unsigned int n) 
{
	unsigned int count = 0;

	while(n) 
	{ 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
}


unsigned int CountSetOfBitsNOLoop(unsigned const int n)

{	unsigned int bit_counter = n;
    bit_counter = bit_counter - ((bit_counter >> 1) & 0x55555555);
    bit_counter = (bit_counter & 0x33333333) + ((bit_counter >> 2) & 0x33333333);
    return ((bit_counter + (bit_counter >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}




