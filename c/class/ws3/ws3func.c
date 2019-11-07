/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW3 - Array & Pointers to Pointers.
 * Date: 06.11.2019
 * Language:  C
 * 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h> /*For tolower use */
#include <stdlib.h>
#include <assert.h>
#include "ws3head.h"

void *StringToLower(char *my_strenvp)
{	
	char *runner_envp = my_strenvp;
	while(*runner_envp)
	{
		*runner_envp = tolower(*runner_envp);
		++runner_envp;
	}
}

void *PrintEnv(const char **my_envp)
{
	char **runner_envp = (char **)my_envp;
	while(0 != *runner_envp)
	{
		StringToLower(*runner_envp);
		printf("%s \n",*runner_envp);
		++runner_envp;
	}
}

char **CopyEnv(const char **envp)
{
	char const **runner_envp = envp ;

	int size = EnvpSize(envp);
	char **envp_copy = (char **)calloc((size+1),sizeof(*runner_envp)); /*Size ptr size*/
	char **runner_copy = envp_copy;


	if(**envp_copy) /*check if malloc not able to get memory*/
	{
		/*free*/
	}

	while(0 != *runner_envp)
	{
		*runner_copy=MyStrDup(*runner_envp);
		++runner_envp;
		++runner_copy;
	}

return envp_copy;
}



int EnvpSize(const char **envp)
{	
	int counter = 0;
	char const **runner_envp =envp ;
	while(NULL != *runner_envp)
	{
	++counter;
	++runner_envp;
	}
return counter;
}

char *MyStrDup(const char *s)
{
	int s_size = strlen(s)+1;

	char *runner_s = (char *)s;
	char *new_ptr =(char*) malloc(s_size * sizeof(char));
	char *runner_h = new_ptr;

    assert(0 != s);

		while('\0' != *runner_s)
		{
			*new_ptr = *runner_s;
			++runner_s;
			++new_ptr;

		}
	*new_ptr = '\0';

	return runner_h;
}

void CleanEnvCopy(char **envp_copy)
{	
	char **free_runner = envp_copy;
	int size = EnvpSize((const char**)envp_copy);
	while(size > 0)
	{
		free(*free_runner);
		*free_runner = NULL;
		++free_runner;
		--size;
	}
free(envp_copy);	
}