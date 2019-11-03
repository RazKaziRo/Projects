#include <stdio.h>
#include <string.h>
int MyStrCmp(const char *s1, const char *s2);

int main(void)
{

int x;

/* Testing strcmp*/

char str1[20]="hello";
char str2[20]="hello";

/*printf("str2-vs-str1 %s \n", strcpy(dest,src));*/
printf("str2-vs-str1 %d \n", strcmp(str1, str2));

}

 int MyStrCmp(const char *s1, const char *s2)
 {

 	char const *runner1 = s1, *runner2 = s2;
 	
 	while (*runner1 == *runner2)
 	{
		++runner1;
	 	++runner2;
 	}
 return *runner1-*runner2;
 }


