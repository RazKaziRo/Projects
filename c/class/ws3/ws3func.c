/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW3 - Array & Pointers to Pointers.
 * Date: 06.11.2019
 * Language:  C
 * 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
	while(0!=*runner_envp)
	{
		StringToLower(*runner_envp);
		printf("%s \n",*runner_envp);
		++runner_envp;
	}

}