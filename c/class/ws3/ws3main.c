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

int i = 0;
char soldier_list[10] = {'L','L','L','L','L','L','L','L','L','L'};
char *ptr_sl = soldier_list;
char *sw_ptr = soldier_list+2; /*Send 1*/

Jospehus(soldier_list,sw_ptr);

for(;i<10;i++)
{
	printf("Soldier %d: %c\n", i+1, soldier_list[i]);
}
printf("Live Solders: %d \n", LiveCounter(ptr_sl));

return 0;

}