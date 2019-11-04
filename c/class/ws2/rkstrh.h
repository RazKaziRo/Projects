#include <stdio.h>


size_t MyStrlen(const char *s) /*return string length*/
{

	const char *runner = s;

	while ('\0'!=*runner){

		++runner;
	}

	return runner-s;

}


 int MyStrCmp(const char *s1, const char *s2) /*compare couple of char in string */
 {

 	char const *runner1 = s1, *runner2 = s2;
 	
 	while (*runner1 == *runner2)
 	{
		++runner1;
	 	++runner2;
 	}
 return *runner1-*runner2;
 }


char *MyStrCpy(char *dest, const char *src){ /*copy string */

size_t i = 0;

	for (i; i< MyStrlen(src) && '\0'!=src[i]; i++)
	{
		dest[i] = src[i];
	}
	for ( ;i<MyStrlen(dest); i++) /* adding all null characters to fill spaces*/
	{
		dest[i] = '\0';
	}


return dest;
}
