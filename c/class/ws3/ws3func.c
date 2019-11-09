/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW3 - Array & Pointers to Pointers.
 * Date: 07.11.2019
 * Language:  C
 * 
 */

#include <stdio.h>
#include <string.h>		/* import for strlen() use */
#include <ctype.h> 		/* import for tolower() use */
#include <stdlib.h> 	/* import for calloc use  */
#include <assert.h>		/* import for assert user */
#include "ws3head.h"						/* import for MyStrDup() user */

char *MyStrDup(const char *s) 		/*copy Strings*/
{
	int s_size = strlen(s)+1;

	char *runner_s = (char *)s;
	char *new_ptr =(char*) malloc(s_size * sizeof(char));
	char *runner_h = new_ptr;

    assert(0 != s);

    if(new_ptr) 					/*Test malloc allocation*/
    {
		while('\0' != *runner_s)
		{
			*new_ptr = *runner_s;
			++runner_s;
			++new_ptr;
		}
    }
    else
    {
    	/*TBD malloc failed*/
    }

	*new_ptr = '\0';

return runner_h;
}

void *StringToLower(char *my_strenvp)
{
	char *runner_envp = my_strenvp;

	assert (my_strenvp !=0);

	while(*runner_envp)
	{
		*runner_envp = tolower(*runner_envp);
		++runner_envp;
	}
}

void *PrintEnv(const char **my_envp)
{
	char **runner_envp = (char **)my_envp;

	assert (0 != my_envp);

	while(0 != *runner_envp)
	{
		StringToLower(*runner_envp);
		printf("%s \n",*runner_envp);
		++runner_envp;
	}
}

long int EnvpSize(const char **envp)
{	
	char const **runner_envp =envp ;
	while(NULL != *runner_envp)
	{
	++runner_envp;
	}
return runner_envp - envp;
}


char **CopyEnv(const char **envp)
{
	char const **runner_envp = envp ;

	long int size = EnvpSize(envp);
	char **envp_copy = (char **)calloc((size+1),sizeof(*runner_envp)); 
	char **runner_copy = envp_copy;


	if(envp_copy != NULL) 			/*check calloc memory allocation*/
	{
		while(0 != *runner_envp)
		{
			*runner_copy=MyStrDup(*runner_envp);
			++runner_envp;
			++runner_copy;
		}
	}
	else
	{
		/*TBD malloc failed */
	}

return envp_copy;
}



void CleanEnvCopy(char **envp_copy)
{	
	char **free_runner = envp_copy;

	while(*free_runner != 0)
	{
		free(*free_runner);
		*free_runner = NULL;
		++free_runner;
	}

free(envp_copy);	
}

int LiveCounter(const char *soldierlist)
{
	char *sl_runner = (char *)soldierlist;

	int alive = 0;

	while('\0'!= *sl_runner)
		{
			if('D'!= *sl_runner)
			{
				++alive;
			}
		++sl_runner;
		}


return alive;
}

void *killsoldier(const char *soldierlist, char *sw_ptr)
{
	char *soldiers_runner = (char *)soldierlist;
	
	
}

void *Jospehus(const char *soldierlist, char *sw_ptr)
{
	char *sw_runner = (char *)sw_ptr;
	char *soldiers_runner = (char *)soldierlist;
	int size = LiveCounter(soldierlist);

	while(LiveCounter(soldierlist)>1)
	{
		if( '\0' == *sw_runner)
		{
			sw_runner = soldiers_runner;
		}
		killsoldier(soldiers_runner,sw_runner);
		size =LiveCounter(soldierlist);
	}
}






