#include <stdio.h>

long unsigned int MyStrlen (const char *);
#define MAX_LIMIT 100
int main (void)

{

	char input[MAX_LIMIT];
	printf("Enter String: \n");
	fgets(input,MAX_LIMIT, stdin);
	printf("The String Lengthss is: %ld \n", MyStrlen(input));

}


long unsigned int MyStrlen(const char *s)
{

	long unsigned int  c = 0; 					/* Count the chars*/

	while (*s != '\0')
	{
		s++;
		c++;
	}

	return c;

}