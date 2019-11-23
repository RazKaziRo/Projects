#include <stdio.h>
#include <string.h>

#include "ws9head.h"

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


/* EX 2.2 Itoa */
/*
	Test(0 == strcmp(MyItoa(10, buff_ptr, 10),"10"), "FAILED: Not Equal 10");
	Test(0 == strcmp(MyItoa(123456, buff_ptr, 10),"123456"), "FAILED: Not Equal 123456");
	Test(0 == strcmp(MyItoa(-1, buff_ptr, 10),"-1"), "FAILED: Not Equal -1");
	Test(0 == strcmp(MyItoa(0, buff_ptr, 10),"0"), "FAILED: Not Equal 0");

*/
   /* EX 2.1 atoi */
/*
	Test(1 == MyAtoi("1"), "FAILED: Not Equal 1");
	Test(-1 == MyAtoi("-1"), "FAILED: Not Equal -1");
	Test(0 == MyAtoi("0"), "FAILED: Not Equal 0");
	Test(987654 == MyAtoi("987654"), "FAILED: Not Equal 987654");
	Test(1 == MyAtoi("01"), "FAILED: Not Equal 01");

*/

/* EX 1.1 Memset */
/*
	Test(*(char*)(memset(str,'1',7)) == *(char*)(MyMemset(str,'1',7)), "FAILED: Not Equal '1'");
	Test(*(char*)(memset(str,'0',8)) == *(char*)(MyMemset(str,'0',8)), "FAILED: Not Equal '0' 1");
	Test(*(char*)(memset(str,'s',0)) == *(char*)(MyMemset(str,'s',0)), "FAILED: Not Equal 's' 0");
	Test(*(char*)(memset(str,'s',18)) == *(char*)(MyMemset(str,'s',18)), "FAILED: Not Equal 's' 18");
*/

return 0;

}