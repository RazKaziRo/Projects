/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW9 - Word Boundry Optimization.
 * Date: 22.11.2019
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#include <stdio.h>
#include <string.h>	/*strcmp()*/
#include <stdlib.h> 	/*malloc()*/
#include "ws9head.h"

#define IS_LITTLE_ENDIAN(a) (*(char*)&a) == (0xff&a) ? printf("Little Endian\n") : printf("Big Endian\n")  	

void Test(int condition, const char *msg)
{
	if (condition)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("\033[1;31m");
		printf("%s \n",msg);
		 printf("\033[0m");
	}
}

int main () 
{

/* EX 3 - 3 Arrays */

/*
char arr1[] = "12345671189";
char arr2[] = "13579135";
char arr3[] = "012583";

char *ptr_arr1 = arr1;
char *ptr_arr2 = arr2;
char *ptr_arr3 = arr3;

InFirstTwoArrNotThird(ptr_arr1, sizeof(arr1), ptr_arr2, sizeof(arr2), ptr_arr3, sizeof(arr3));
*/

/* EX 2.2 itoa -   Run Each Test Individually */

/*
	char *buff_ptr = malloc(12);
	
	free(buff_ptr); buff_ptr=NULL;
*/

/*
	Test(0 == strcmp(MyItoa(10, buff_ptr, 10),"10"), "FAILED: Not Equal 10");
	Test(0 == strcmp(MyItoa(123456, buff_ptr, 10),"123456"), "FAILED: Not Equal 123456");
	Test(0 == strcmp(MyItoa(-1, buff_ptr, 10),"-1"), "FAILED: Not Equal -1");
	Test(0 == strcmp(MyItoa(0, buff_ptr, 10),"0"), "FAILED: Not Equal 0");
	Test(0 == strcmp(MyItoa(0, buff_ptr, 12),"0"), "FAILED: Not Equal 0");
	Test(0 == strcmp(MyItoa(0, buff_ptr, 36),"0"), "FAILED: Not Equal 0");
	Test(0 == strcmp(MyItoa(10, buff_ptr, 16),"A"), "FAILED: Not Equal A");
	Test(0 == strcmp(MyItoa(123, buff_ptr, 2),"1111011"), "FAILED: Not Equal 1111011");
	Test(0 == strcmp(MyItoa(123, buff_ptr, 16),"7B"), "FAILED: 7B");
*/

   /* EX 2.1 atoi */
/*
	Test(1 == MyAtoi("1"), "FAILED: Not Equal 1");
	Test(-1 == MyAtoi("-1"), "FAILED: Not Equal -1");
	Test(0 == MyAtoi("0"), "FAILED: Not Equal 0");
	Test(987654 == MyAtoi("987654"), "FAILED: Not Equal 987654");
	Test(1 == MyAtoi("01"), "FAILED: Not Equal 01");
*/

/* EX 1.3 memmove - Run Each Test Individually */

/*
	char arr1[] = "AAAAAAAAAAAAAAAAA";
	char arr2[] = "BBBBBBBBBBBBBBBBB";
	char arr3[] = "AAAAAAAAAAAAAAAAA";
	char arr4[] = "BBBBBBBBBBBBBBBBB";

	char *buff_ptr1 = (char *)malloc(strlen(arr1)+1);
	char *buff_ptr2 = (char *)malloc(strlen(arr2)+1);
	char *buff_ptr3 = (char *)malloc(strlen(arr1)+1);
	char *buff_ptr4 = (char *)malloc(strlen(arr2)+1);

	buff_ptr1 = arr1;
	buff_ptr2 = arr2;
	buff_ptr3 = arr3;
	buff_ptr4 = arr4;

	++buff_ptr2;

	puts(buff_ptr3);
	MyMemMove(buff_ptr3, buff_ptr4,10);
	puts(buff_ptr3);

	free(buff_ptr1); buff_ptr1 = NULL;
	free(buff_ptr2); buff_ptr2 = NULL;
	free(buff_ptr3); buff_ptr3 = NULL;
	free(buff_ptr4); buff_ptr4 = NULL;
*/

/*
	Test(0 == strcmp(memmove(buff_ptr1, buff_ptr2,10),MyMemMove(buff_ptr3, buff_ptr4,10)), "FAILED: 10 Times ");
	Test(0 == strcmp(memmove(buff_ptr1+3, buff_ptr1,5),MyMemMove(buff_ptr3+3, buff_ptr3,5)), "FAILED: OverLap ");
	Test(0 == strcmp(memmove(buff_ptr1, buff_ptr2,0),MyMemMove(buff_ptr3, buff_ptr4,0)), "FAILED: 0 Times ");

*/

/* EX 1.2 memcpy -  Run Each Test Individually! */

/*
	char arr1[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	char arr2[] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
	char arr3[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	char arr4[] = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";

	char *buff_ptr1 = (char *)malloc(strlen(arr1)+1);
	char *buff_ptr2 = (char *)malloc(strlen(arr2)+1);
	char *buff_ptr3 = (char *)malloc(strlen(arr1)+1);
	char *buff_ptr4 = (char *)malloc(strlen(arr2)+1);

	buff_ptr1 = arr1;
	buff_ptr2 = arr2;
	buff_ptr3 = arr3;
	buff_ptr4 = arr4;

	++buff_ptr2;
	puts(arr1);

	free(buff_ptr1); buff_ptr1 = NULL;
	free(buff_ptr2); buff_ptr2 = NULL;
	free(buff_ptr3); buff_ptr3 = NULL;
	free(buff_ptr4); buff_ptr4 = NULL;
*/

/*
	Test(0 == strcmp(memcpy(buff_ptr1, buff_ptr2,10),MyMemCpy(buff_ptr3, buff_ptr4,10)), "FAILED: 10 Times ");
	Test(0 == strcmp(memcpy(buff_ptr1, buff_ptr2,1),MyMemCpy(buff_ptr3, buff_ptr4,1)), "FAILED: 1 Times ");
	Test(0 == strcmp(memcpy(buff_ptr1, buff_ptr2,0),MyMemCpy(buff_ptr3, buff_ptr4,0)), "FAILED: 1 Times ");
*/
	
/* EX 1.1 Memset -  Run Each Test Individually! */

/*
	char *buff_ptr1 = (char *)malloc(32);
	char *buff_ptr2 = (char *)malloc(32);

	++buff_ptr1;
	++buff_ptr2;

	Test(0 == strcmp(memset(buff_ptr1,'0',1),MyMemSet(buff_ptr2,'0',1)), "FAILED: 1 Times ");

	free(buff_ptr1); buff_ptr1 = NULL;
	free(buff_ptr2); buff_ptr2 = NULL;
*/

/*	Test(0 == strcmp(memset(buff_ptr1,'1',31),MyMemSet(buff_ptr2,'1',31)), "FAILED: 31 Times ");
	Test(0 == strcmp(memset(buff_ptr1,'s',8),MyMemSet(buff_ptr2,'s',8)), "FAILED: 8 Times ");
	Test(0 == strcmp(memset(buff_ptr1,'0',1),MyMemSet(buff_ptr2,'0',1)), "FAILED: 1 Times ");
	Test(0 == !strcmp(memset(buff_ptr1,'1',16),MyMemSet(buff_ptr2,'1',17)), "FAILED:  Equal 's' 16/17");
*/



return 0;

}
