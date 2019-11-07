#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ws3head.h"

int main(int argc, char *argv[], char **envp)
{

char **envp_copy = CopyEnv((const char **)envp);


PrintEnv((const char **)envp_copy);

/*printf("envp_copy size: %d",EnvpSize((const char **)envp_copy));*/
CleanEnvCopy(envp_copy);

/*printf("envp_size %d \n", EnvpSize((const char **)envp));*/


/*
char **my_envp = envp;
StringToLower(my_envp);
PrintEnv((const char**)my_envp);
*/

return 0;

}