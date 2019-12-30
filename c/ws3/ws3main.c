#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ws3head.h"

int main(int argc, char *argv[], char **envp)
{

/*
char **envp_copy = CopyEnv((const char **)envp);
PrintEnv((const char **)envp_copy);
/*if(envp_copy)
{
}
CleanEnvCopy(envp_copy);
*/

int n = 0;
int i =0;
int *arr = NULL;
printf("How Many Soldiers: ");
scanf("%d", &n);
arr = (int *)malloc(n*sizeof(int));



while(i<n-1)
{
	arr[i] = i+1;
	++i;
}
arr[i] = 0;

printf("Sword Location: ");
scanf("%d", &i);

while(arr[i] != i)
{
	arr[i] = arr[arr[i]];
	i = arr[i];
}

printf("lucky Soldier: %d \n", i);

/*
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


while( i<1000)
{
	printf("Soldier %d: %c \n", i+1,*soldier_list);
	++soldier_list;
	++i;
}

while(i>0)
{
	--sl_runner;
	--i;
}


/*
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
	printf("The Winnder No# %d: %c \n", ++i,*soldier_list++);
	}

++i;
++soldier_list;
}
*/



/*
int i = 0;
char arr[1000];
char *soldier_list = arr;
char *sw_location = arr;

for(i = 0; i<1000; i++)
	arr[i] = 'L';



Jospehus(soldier_list,sw_location);
*/

return 0;

}