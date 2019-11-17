/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW6 - Bitwise Operations.
 * Date: 14.11.2019
 * Language: C
 * Reviewer: 
 */

#include "ws6head.h"

long BitWisePow2(unsigned int x, unsigned int y)
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
	if ((n&(n-1)) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int AddOneToInt(int n)
{
    int m = 1; 
      
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

long int ByteMirror(unsigned int n)
{
		/*TBD*/
}

int TwoANDSixON(const unsigned char ch)
{
	int result_two = 0;
	int result_six = 0;

	result_two = ch << 1;
	result_six = ch << 5;


return(result_two & result_six);

}

/*
int TwoORSixON(const unsigned char ch)
{
	 - - - TBD  - - -

	int result_two = 0;
	int result_six = 0;

	result_two = ch << 1;
	result_six = ch << 5;


return(result_two | result_six);

}

*/

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

int CountSetOfBitsLoop(unsigned int n) 
{
	int count = 0;

	while(n) 
	{ 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
}

int CountSetOfBitsNOLoop(unsigned int n)
{
	/*TBD*/
}




