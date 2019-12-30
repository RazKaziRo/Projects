#include <stdio.h>
#include <assert.h>
#include <ctype.h>	  /*for using tolower/toupper	*/
#include "MyStringHToP.h" /* mystring.c file*/

size_t MyStrLen(const char *str) 				/*  string length */
{
	const char *runner = str;

    assert ( 0 != str);

	while ('\0'!=*runner)
	{
		++runner;
	}

return runner-str;

}


 int MyStrCmp(const char *s1, const char *s2)   /* compare couple of char in 
 string */
 {

    char const *runner1 = s1, *runner2 = s2;

    assert ( 0 != s1 && 0 != s2);   

    while (*runner1 == *runner2 && '\0' != *runner1)
    {
        ++runner1;
        ++runner2;
    }

 return *runner1-*runner2;

 }


char *MyStrCpy(char *dest, const char *src)
{   /* copy string */

    const char *runnersrc = src;
    char *runnerdest = dest;

    assert (0!= runnersrc);

    while('\0' != *runnersrc)
    {
        *runnerdest = *runnersrc;
        ++runnersrc;
        ++runnerdest;
    }

    *runnerdest = '\0'; /*initi last place to null*/

return dest;

}



char *MyStrNCpy(char *dest, const char *src, size_t n)
{  
    const char *runnersrc = src;
    char *runnerdest = dest;
    size_t i;

        assert ( 0 != dest && 0 != src && '\0' != n);   

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

int MyStrCaseCmp(const char *s1, const char *s2)
{
    char const *runner1 = s1, *runner2 = s2;

    assert (0 != s1 && 0 != s2);

    while(tolower(*runner1)== tolower(*runner2) && '\0'!=*s1 )
    {
        ++runner1;
        ++runner2;
    }

return(tolower(*runner1)- tolower(*runner2));
}


char *MyStrChr(const char *s, int c)  /*return pointer to first accurence of c*/
{
    const char *runner_s = s;

    assert(0 != s);

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