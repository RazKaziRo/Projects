/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW6 - Bitwise Operations.
 * Date: 17.11.2019
 * Language: C
 * Reviewer: Israel Drayfus
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

	for(; i<size; i++)
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

	num = (((num & m3) >> 1) | ((num & m1) << 1));
	num = (((num & m5) >> 2) | ((num & m2) << 2));
	num = (((num & m6) >> 4) | ((num & m4) << 4));
	num = (((num & m7) >> 8) | ((num & m8) << 8));
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
{	
	unsigned int bit_counter = n;

	bit_counter = bit_counter - ((bit_counter >> 1) & m1);
    bit_counter = (bit_counter & m2) + ((bit_counter >> 2) & m2);
    
    return (((bit_counter + (bit_counter >> 4)) & m4) * m10) >> 24;
}


int PrintBit(int a, int loc)   
{
    int buf = a & 1 << loc;

    if (buf == 0)
    {
    	return 0;
    } 
    else
    {
    	return 1;
    }  
}

void PrintFloat(float num)
{
	int i = 0;
    unsigned int  *b = (unsigned int *)(&num);

    for (i = 31; i >= 0; i--)
    {
        printf("%d",PrintBit(*b,i));
    }

}




