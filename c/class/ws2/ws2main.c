#include <stdio.h>
#include <string.h>   /*for testing string origin behavoior*/
#include <strings.h>  /*for testing strcmp*/
#include "Mystring.h" /* include MyStrlen()/MyStrCmp()/MyStrCpy()*/


int main(void)
{
/* Testing strcmp*/

char str1[] = "SSs";
char str2[] = "sab";
char ch = '2';

/* Testing strchr - Return Pointer to first occurrence
printf("MyStrChr %s \n", MyStrChr(str1, ch));
printf("strchr %s \n", strchr(str1, ch));


/*test String Case Compare

printf("MyStrCaseCmp %d \n", MyStrCaseCmp(str2, str1));
printf("strcasecmp %d \n", strcasecmp(str2,str1));
/*

return 0;
}


