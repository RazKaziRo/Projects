#ifndef __BENSTRING_H__
#define __BENSTRING_H__

#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<assert.h>
#include<ctype.h>

/*recives a string of unknown length and return its length
****Codezila will not be responible for crushes due to null pointer insertion */
size_t Strln( const char *ar );



/*recives 2 char arrays and return 0 if they equal, pos val if the 1st diff char 
is on the 1st string and neg val if the 1st diff char is on the 2nd string 
****Codezila will not be responible for crushes due to null pointer insertion */
int Strcp(const char *ar1 ,const char *ar2 );

/*copys the string from source to the string in target
****Codezila will not be responible for crushes due to null pointer insertion */
char *StrCopy(char *target, const char *source);
 

/*recives an int n and 2 strings, copies n number of lines from the string from 
the right to the one in the left 
****Codezila will not be responible for crushes due to null pointer insertion */
char *StrnCpy (char *dest, const char *src, int size);


/* recives 2 strings and compares each char ignoring upper/lower cases 
***Codezila will not be responible for crushes due to null pointer insertion */
int StrCasCmp( const char *s1, const char *s2);


/* recives a string and look up in it for a said char- returns its adress or a
 null if if it is not there
****Codezila will not be responible for crushes due to null pointer insertion */
char *MyStrChr( const char *str, int c);

#endif
