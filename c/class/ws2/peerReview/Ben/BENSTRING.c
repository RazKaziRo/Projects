#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<assert.h>
#include<ctype.h>
#include <stdlib.h>
#include "BENSTRING.h"

/*recives a string of unknown length and return its length
****Codezila will not be responible for crushes due to null pointer insertion */
size_t MtStrLen( const char *ar ) 
{
    	const char *runner = ar;	
    	assert(NULL != ar);
	
	while('\0'!=*runner)
	{
		++runner;
	}
	
	return (runner-ar); 
}


/*recives 2 char arrays and return 0 if they equal, pos val if the 1st diff char 
is on the 1st string and neg val if the 1st diff char is on the 2nd string 
****Codezila will not be responible for crushes due to null pointer insertion */
int MyStrCmp(const char *ar1 ,const char *ar2 )
{
	const char *runner1 = ar1, *runner2 = ar2;		
	assert( NULL != ar1 && NULL != ar2);

	while ((*runner1 == *runner2)  && ('\0' != *runner1))
	{
		++runner1;
        ++runner2; 
	 }
	return  ( *runner1 - *runner2 );
}

/*copys the string from source to the string in target
****Codezila will not be responible for crushes due to null pointer insertion */
char *MyStrCopy(char *target, const char *source)
{    
	char *rt = target;
	assert(( NULL != target) && ( NULL != source) );

        while( '\0' != *source)
        {         
            *target= *source;          
            ++source;
            ++target;
        }
        *target = '\0' ;
	return rt; 
} 

/*recives an int n and 2 strings, copies n number of lines from the string from 
the right to the one in the left 
****Codezila will not be responible for crushes due to null pointer insertion */
char *MyStrNCopy (char *dest, const char *src, int size)
{	
	char *dest_start = dest;
	assert( NULL != dest && NULL != src);
	
	for ( ; 1 <= size; size--)
	{
		if ( '\0' == *src )
		{
			*dest = '\0';
		}
		else 
		{
			*dest = *src;
		}
		++src;
		++dest;
	}
return dest_start;
}

/* recives 2 strings and compares each char ignoring upper/lower cases 
***Codezila will not be responible for crushes due to null pointer insertion */
int MyStrCaseCmp( const char *s1, const char *s2)
{
	assert( NULL != s1 && NULL != s2);

	char *runner1 = s1, *runner2= s2;

	while (( '\0' != *runner1) || ( '\0' != *runner2))
	{
		if (tolower(*runner1) != tolower(*runner2))
		{
		    return (tolower(*runner1) - tolower(*runner2));
		}
		else 
		{
		    ++runner1;
		    ++runner2;
		}
    }
	return (tolower(*runner1) - tolower(*runner2));
}

/* recives a string and look up in it for a said char- returns its adress or a
 null if if it is not there
****Codezila will not be responible for crushes due to null pointer insertion */
char *MyStrChr( const char *str, int c)
{
	assert( NULL != str);

	while ( '\0' != *str )
	{
		if ( *str == c )
		{
			return (char *)str;
		}
		else
		{
		++str;
		}
	}
	return (char *)str;
}


char *MyStrDup(const char *s)
{
	char *stemp, *st;
	
	stemp= (char *) malloc (strlen(s)*sizeof(char));
	st=stemp;
	while ('\0' != *s)
	{
	*stemp= *s;
	++s;
	++stemp;
	}
	return (char *) st;
}

char *MyStrDup(const char *s)
{
	char *stemp, *st;
	
	stemp= (char *) malloc (strlen(s)*sizeof(char));
	st=stemp;
	while ('\0' != *s)
	{
	*stemp= *s;
	++s;
	++stemp;
	}
	return (char *) st;
}

char *MyStrCat (char *dest, const char *src)
{
	char *dest1st = dest;

	while ( '\0' != *dest)
	{
		++dest;
	}
	while ( '\0' != *src )
	{
		*dest = *src;
		++dest;
		++src;
	}
	return dest1st;
}

char *MyStrNCat (char *dest, const char *src, int n)
{
	char *dest1st = dest;
	int i=0;

	while ( '\0' != *dest)
	{
		++dest;
	}
	for ( i=0; i <= n ; i++ )
	{
		*dest = *src;
		++dest;
		++src;
	}
	return dest1st;
}


/* int main()
{
	const char ar1[]="shalom";
	char *st1, *st2;

    st1=strdup(ar1);
    st2=MyStrDup(ar1);
	printf("strdup produced string : %s\n", st1 );
	printf("My produced string : %s\n", st2 );
	free(st1);
	free(st2);
	return 0; */
}
