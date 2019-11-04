#include <stdio.h>
#include "rkstrh.h" /* include MyStrlen()/MyStrCmp()/MyStrCpy()*/



int main(void)
{

int x;

/* Testing strcmp*/

char str1[20]="ma";
char str2[2]="ko";
printf("stcpy %s \n", MyStrCpy(str1, str2));

}


