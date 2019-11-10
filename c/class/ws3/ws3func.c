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

void *MyMalloc(size_t size, int flag)
{
	if(flag == 1)
	{
	return (void *)malloc(size);
	}

	else
	{
	return NULL;
	}
	
}

char *MyStrDup(const char *s) 			/*My String Copy*/
{
	int s_size = strlen(s)+1;
	char *runner_s = (char *)s;
	char *new_ptr =(char*) MyMalloc((s_size * sizeof(char)),0); 
	/* - 1 - Memory Suscsess 0 - Memory Allocation Failed */
	char *runner_h = new_ptr;

    assert(0 != s);

    if(new_ptr) 					/*Test malloc allocation*/
    {
		while('\0' != *runner_s)
		{
			*new_ptr = tolower(*runner_s);
			++runner_s;
			++new_ptr;
		}
	*new_ptr = '\0';

    }
    else
    {
        	return new_ptr; /*As Null*/
    }

return runner_h;
}


void *PrintEnv(const char **my_envp)
{
	char **runner_envp = (char **)my_envp;

	assert (0 != my_envp);

	while(0 != *runner_envp)
	{
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
	/* - 1 - Memory Suscsess 0 - Memory Allocation Failed */

	char **runner_copy = envp_copy;


	if(envp_copy != NULL) 			/*check calloc memory allocation*/
	{
		while(0 != *runner_envp)
		{
			*runner_copy = MyStrDup(*runner_envp);
			if(NULL==runner_copy)
			{
				CleanEnvCopy(envp_copy);
			}

		++runner_envp;
		++runner_copy;
		}
	}
	else
	{
		/*printf("Memory For Envp Copy Allocation Failed \n");*/
		CleanEnvCopy(envp_copy);
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
	int result = 0;
	char *sl_runner = (char *)soldierlist;

	while('\0'!= *sl_runner )
	{
		if('0'!=*sl_runner)
		{
			++result;
		}
	++sl_runner;
	}
	return result;
}

char *NextAlive(const char *soldierlist, char *sw_ptr) /* Point To The Next Alive*/
{
	char *sl_runner = (char *)soldierlist;

	if(*sw_ptr != '0')
	{
		++sw_ptr;
	}

	while(*sw_ptr == '0' && *sw_ptr != '\0')
	{
		++sw_ptr;
	}

	if(*sw_ptr =='\0')
	{
	sw_ptr = sl_runner;

		while(*sw_ptr == '0' && *sw_ptr != '\0')
		{
			++sw_ptr;
		}
	}

return sw_ptr;
}

void *Killlive(const char *soldierlist, char *sw_ptr) 	/*Kill The current Soldier*/
{	

	char *sl_runner = (char *)soldierlist;
	*sw_ptr = '0';
	
}


void *Jospehus(const char *soldierlist, char *sw_ptr) 
{
	char *sl_runner = (char *)soldierlist;

	while(LiveCounter(soldierlist)>1)
	{
		sw_ptr = NextAlive(sl_runner,sw_ptr);
		Killlive(sl_runner,sw_ptr);
		sw_ptr = NextAlive(sl_runner,sw_ptr);

	}
}







