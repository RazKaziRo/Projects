/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW2 - Pointers Strings 1-5.
 * Date: 06.11.2019
 * Language:  C
 * 
 */
#include <stdio.h>
#include "ws2head.h"

int main()
{
	int* p = (int*) 17;
	printf("%d",(int)(long)(p+4));
	return 0;
}

