#include <stdio.h>
#include "rkstrh.h" /* include MyStrlen()/MyStrCmp()/MyStrCpy()*/

int main(void)
{
/* Testing strcmp*/

char str1[20]="123";
char str2[20]="456";
printf("stcpy %s \n", MyStrCpy(str2, str1));

return 0;
}


