#include <stdio.h>
#include <string.h> 			/*need to be replaced with my header*/

char *MyStrCpy(char *dest, const char *src){
size_t i = 0;

	for (i; i< strlen(src) && '\0'!=src[i]; i++)
	{
		dest[i] = src[i];
	}
	for ( ;i<strlen(dest); i++) /* adding all null characters to fill spaces*/
	{
		dest[i] = '\0';
	}


return dest;
}


