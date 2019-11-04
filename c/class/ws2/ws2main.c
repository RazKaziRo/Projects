#include <stdio.h>
#include <string.h>
#include <strings.h> 
#include "Mystring.h" /* include MyStrlen()/MyStrCmp()/MyStrCpy()*/


int main(void)
{
/* Testing strcmp*/

char str1[] = "abc";
/*char str2[] = "shyeor";*/
char ch = '2';


printf("MyStrChr %s \n", MyStrChr(str1, ch));
printf("strchr %s \n", strchr(str1, ch));
ks
/*printf("MyStrNCpy %d \n", MyStrCaseCmp(str1, str2));*/
/*printf("strcasecmp %d", strcasecmp(str1,str2));*/

return 0;
}


