#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ws3head.h"

int main(int argc, char *argv[], char **envp)
{

/* ENV TEST
char **envp_copy = CopyEnv((const char **)envp);
PrintEnv((const char **)envp_copy);
CleanEnvCopy(envp_copy);
*/
char *ptr = "int";

printSizeOfType(ptr);


return 0;

}