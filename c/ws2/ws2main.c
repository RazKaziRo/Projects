/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW2 - Pointers Strings 1-5.
 * Date: 06.11.2019
 * Language:  C
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ws2head.h"

int main()
{
    /*
	char arr1[] = "  111";

	char *ptr1;
	ptr1 = arr1;

	printf("WhiteSpace Before:%s\n",arr1);

	DeleteWhiteSpace(ptr1);

	printf("WhiteSpace After:%s\n",arr1);
    */


    char arr1[] = "100";
    char arr2[] = "1";
    char *ptr1 = arr1;
    char *ptr2 = arr2;

    int size = NewNumsize(arr1,arr2);

    char *ptr3 = (char *)malloc(size*sizeof(char));

    SumStringsAsNum(ptr1, ptr2, ptr3);

    printf("%s+%s = %s\n",ptr1,ptr2,ptr3);
    free(ptr3);


	return (0);
}
