#include <stdio.h>
#include <stdlib.h>

void foo()
{
	char str1[20];
	char *str2 = malloc(sizeof(*str2)*20);
	char *str3 = "whatever";
	char str4[] = "whatever"; 
	str3[1] = 'a';

	printf("%s", str3);
}

int main()
{	
	foo();
	return 0;
}
