#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "ws3head.h"

int main(int argc, char *argv[], char **envp)
{

char arr[] = "Hello";
char *str = arr;
StringToLower(str);
PrintEnv((const char **)envp);

printf("%s \n",str);


/*
char **my_envp = envp;
StringToLower(my_envp);
PrintEnv((const char**)my_envp);
*/

return 0;

}