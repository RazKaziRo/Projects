/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW6 - Bitwise Operations.
 * Date: 14.11.2019
 * Language: C
 * Reviewer: 
 */

#include "ws6head.h"

long Pow2(unsigned int x, unsigned int y)
{
	return x<<y;;
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


