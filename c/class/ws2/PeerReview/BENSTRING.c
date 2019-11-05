#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include "BENSTRING.h"

 int strcasecmp(const char *s1, const char *s2);

/*recives a string of unknown length and return its length
****Codezila will not be responible for crushes due to null pointer insertion */
size_t Strln( const char *ar ) /*R.K - CHECK*/
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
int Strcp(const char *ar1 ,const char *ar2 ) /*R.K - CHECK*/
{
	const char *runner1 = ar1, *runner2 = ar2;		
	assert( NULL != ar1);
    	assert( NULL != ar2);

	while ((*runner1 == *runner2)  && ('\0' != *runner1))
	{
         printf("ar1= %d  ar2=%d\n", *runner1, *runner2);
		++runner1;
        ++runner2; 
	 }
	return  ( *runner1 - *runner2 );
}

/*copys the string from source to the string in target
****Codezila will not be responible for crushes due to null pointer insertion */
char *StrCopy(char *target, const char *source) /*R.K - CHECK*/
{    
	char *rt = target;
	assert( NULL != target);
	assert( NULL != source);

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
char *StrnCpy (char *dest, const char *src, int size) /*R.K - CHECK*/
{	
	char *dest_start = dest;
	assert( NULL != dest);
	assert( NULL != src);
	
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
		printf("the loop will run %d \n",size);
		++src;
		++dest;
	}
return dest_start;
}

/* recives 2 strings and compares each char ignoring upper/lower cases 
***Codezila will not be responible for crushes due to null pointer insertion */
int StrCasCmp( const char *s1, const char *s2) /*R.K - CHECK*/
{
	assert( NULL != s1);
	assert( NULL != s2);

	while (( '\0' != *s1) && ( '\0' != *s2))
	{
		if (tolower(*s1) != tolower(*s2))
		{
		    return (tolower(*s1) - tolower(*s2));
		}
		else 
		{
		    ++s1;
		    ++s2;
		}
    }
        printf(" *s1 = %d\n*s2 = %d\n",tolower(*s1),tolower(*s2));
	return (tolower(*s1) - tolower(*s2));
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

