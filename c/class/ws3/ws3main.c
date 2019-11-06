#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "ws3head.h"

int main(int argc, char *argv[], char **envp)
{

char *str[1][3] = {"One", "Two", "Threes"};
char **ptr = *str;

while(*ptr != 0)
{
	while(**ptr != '\0')
	{
	printf("%c \n",**ptr);
	++(**ptr);
	}
	
	++*ptr;
}
/*
char **my_envp = envp;
StringToLower(my_envp);
PrintEnv((const char**)my_envp);
*/

return 0;

}