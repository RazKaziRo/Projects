/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW2 - Pointers Strings 1-5.
 * Date: 06.11.2019
 * Language:  C
 * 
 */
#include <stdio.h>
#include <string.h>
#include "ws2head.h"


int main()

{

	char arr1[] = "  111";

	char *ptr1;
	ptr1 = arr1;

	printf("WhiteSpace Before:%s\n",arr1);

	DeleteWhiteSpace(ptr1);

	printf("WhiteSpace After:%s\n",arr1);

	return 0;
}
