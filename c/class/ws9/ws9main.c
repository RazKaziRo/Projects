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
   char str[50] = "This is string.h library function";
   char *ptr_str = str;

   puts(str);
   memset(str,'s',18);
   puts(str);

/* EX 1.1 Memset */

	Test(*(char*)(memset(str,'1',7)) == *(char*)(MyMemset(str,'1',7)), "FAILED: Not Equal '1'");
	Test(*(char*)(memset(str,'0',8)) == *(char*)(MyMemset(str,'0',8)), "FAILED: Not Equal '0' 1");
	Test(*(char*)(memset(str,'s',0)) == *(char*)(MyMemset(str,'s',0)), "FAILED: Not Equal 's' 0");
	Test(*(char*)(memset(str,'s',18)) == *(char*)(MyMemset(str,'s',18)), "FAILED: Not Equal 's' 18");

return 0;

}