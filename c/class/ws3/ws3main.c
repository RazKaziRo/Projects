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



int num_of_soldiers = 0;
int sw_location = 0;
char *soldier_list = NULL;
char *ptr_sl = NULL;
char *sl_runner;
char *sw_ptr = NULL;
char *sw_runner = NULL;
int i = 0;

printf("How Many Soldiers: ");
scanf("%d", &num_of_soldiers);

soldier_list = (char *)malloc(num_of_soldiers*sizeof(char));
sl_runner = soldier_list;

while(num_of_soldiers>0)
{
	*sl_runner = 'L';
	++sl_runner;
	--num_of_soldiers;
}
ptr_sl = soldier_list;

printf("Sword Location: ");
scanf("%d", &sw_location);
sw_runner = soldier_list;

while(sw_location-1>0)
{
++sw_runner;
--sw_location;
}
sw_ptr = sw_runner;

Jospehus(ptr_sl,sw_ptr);

while(*soldier_list)
{
	if(*soldier_list == 'L')
	{
	printf("Soldiers %d: %c \n", ++i,*soldier_list++);
	}

++i;
++soldier_list;
}

/*
int i = 0;
char arr[13] = {'1','2','3','4','5','6','7','8','9','T','E','T','T'};
char *soldier_list = arr;
char *sw_location = arr;

Jospehus(soldier_list,sw_location );

for(;i<13; i++)
{
	printf("Soldier %d: %c\n", i+1,arr[i]);
}
*/

return 0;

}