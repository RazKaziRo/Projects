#include <stdio.h>
#include <stdlib.h> /*for using Malloc/Calloc/Realock*/
#include <assert.h>
#include <ctype.h>	  /*for using tolower/toupper	*/
#include "Mystring.h" /* mystring.c file*/

size_t Mystrlen(const char *str) 				/*  string length */
{

	const char *runner = str;

	assert ( '\0' != *str);	


	while ('\0'!=*runner)
	{
		++runner;
	}

	return runner-str;

}


 int Mystrcmp(const char *s1, const char *s2)  	/* compare couple of char in 
 string */
 {

 char const *runner1 = s1, *runner2 = s2;

 	assert ( '\0' != *s1 && '\0' != *s2);	

 	while (*runner1 == *runner2 && '\0' != *runner1)
 	{
		++runner1;
	 	++runner2;
 	}

 return *runner1-*runner2;

 }


char *Mystrcpy(char *dest, const char *src){  	/* copy string */

const char *runnersrc = src;
char *runnerdest = dest;

    assert ('\0' != *runnersrc);

	while('\0' != *runnersrc)
	{
		*runnerdest = *runnersrc;
		++runnersrc;
		++runnerdest;
	}

*runnerdest = '\0';

return dest;

}


char *Mystrncpy(char *dest, const char *src, size_t n)
{  
	const char *runnersrc = src;
	char *runnerdest = dest;
    size_t i;

    	assert ( '\0' != *dest && '\0' != *src && '\0' != n);	

		for (i = 0; i < n && '\0' != *runnersrc; i++)
		{
			*runnerdest = *runnersrc;
			++runnerdest;
			++runnersrc;
		}
	         
	    for ( ; i<n  && '\0' != *runnerdest; i++)
	    {
	    	*runnerdest = '\0';
	    	++runnerdest;
	    }
    

   return dest;

}

int Mystrcasecmp(const char *s1, const char *s2)
{
	char const *runner1 = s1, *runner2 = s2;

	assert ('\0' != *s1 && '\0' != *s2);

	while(tolower(*runner1)== tolower(*runner2))
	{
 		++runner1;
 		++runner2;
	}

return(tolower(*runner1)- tolower(*runner2));
}


char *Mystrchr(const char *s, int c)  /*return pointer to first accurence of c*/
{
	const char *runner_s = s;

	assert('\0'!=*s);

	while (*runner_s != c &&  '\0'!=* runner_s)
	{	
		++runner_s;
	}

	if(*runner_s == '\0' && c != '\0')
	{
		return NULL;
	}

	return (char *)runner_s;

}

char *Mystrdup(const char *s)
{
	int s_size = Mystrlen(s)+1;

	char *runner_s = (char *)s;
	char *new_ptr =(char*) malloc(s_size * sizeof(char));
	char *runner_h = new_ptr;

		while('\0' != *runner_s)
		{
			*new_ptr = *runner_s;
			++runner_s;
			++new_ptr;

		}
	*new_ptr = '\0';

	return runner_h;
}

char *Mystrcat(char *dest, const char *src)
{
	char *runnerdest = dest;
	const char *runnersrc = src;

	while('\0' != *runnerdest)
	{
		++runnerdest;
	}
	while('\0' != *runnersrc)
	{
		*runnerdest = *runnersrc;
		++runnersrc;
		++runnerdest;
	}

	*runnerdest = '\0';

return dest;
}

int MyIsPalindrome (const char *str)
{
	const char *ptrhead = str, *ptrtail = str;

	while('\0'!= *ptrtail)
	{
		++ptrtail;
	}
	--ptrtail;

	while(ptrhead < ptrtail)
	{
		if(*ptrhead!=*ptrtail)
		{
			return 0;
		}
		++ptrhead;
		--ptrtail;
	}
return 1;

}

void My7boom (int start, int end)
{
	int i = start;
	for (; i<end; i++)
	{
		if(i%7 == 0 || My7boomHelper(i,7))
		{
			printf("BOOM \n");
			continue;
		}
		printf("%d\n", i);
	}
}

int My7boomHelper(int i, int j) /*Helper Function to 7BOOM*/
{
	while(i != 0)
	{
		if(i%10 == j)
		{
			return 1;
		}
		i = i/10;
	}
return 0;
}
