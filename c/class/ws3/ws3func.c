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

void *StringToLower(char **my_envp)
{		
		while(0 != *my_envp)
		{
		while('\0' != **my_envp)
		{
		if(islower(**my_envp))
		{
			*(++*my_envp);
		}
		else
		{
		**my_envp = tolower(**my_envp);
		*(++*my_envp);
		}

		}
		++*my_envp;
		}

}

void *PrintEnv(const char **my_envp)
{
	while(0!=*my_envp)
	{
		printf("%s \n",*my_envp);
		++my_envp;
	}

}