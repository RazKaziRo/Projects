/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW2 - Pointers Strings 1-5.
 * Date: 05.11.2019
 * Language:  C
 * Reviewer: Shye
 */

#include "BENSTRING.h" /*BENS HEADER*/
#include <stdio.h>
#include <string.h>   /*for testing string origin behavoior*/
#include <strings.h>  /*for testing strcmp*/
/* #include "Mystring.h" include MyStrlen()/MyStrCmp()/MyStrCpy()*/


char *strdup(const char *s);

int main(void)
{
    
/* -Testing Mystrlen - Return String Length >  NOT ACCEPT '\0' */

/* < [REMOVE HERE]

char str1[] = "+*";
char str2[] = "+*";

printf("Strln: %ld \n", Strln(str1)); 
printf("strlen: %ld \n", strlen(str2));

[REMOVE HERE] */

/* Testing Mystrcmp - Compare 2 Strings > NOT ACCEPT '\0'*/ 

/* < [REMOVE HERE]

char str1[] = " ";
char str2[] = " ";

char str3[] = " ";
char str4[] = " ";


printf("Strcp: %d \n", Strcp(str1,str2)); 
printf("strcmp: %d \n", strcmp(str3,str4));

[REMOVE HERE] */

/* Testing Mystrchr - Return Pointer to first occurrence > NOT ACCEPT '\0'*/ 


/* < [REMOVE HERE]


char str1[] = "Sasas";
char ch1 = 'm';

char str2[] = "Sasas";
char ch2 = 'm';

printf("MyStrChr %s \n", Mystrchr(str1, ch1));
printf("strchr %s \n", strchr(str2, ch2));

 [REMOVE HERE] > */

/* Testing Mystrcasecmp - Compare char in string ignore case > NOT ACCEPT '\0'*/ 


char str1[] = "Dd";
char str2[] = "Dd ";

char str3[] = "Dd";
char str4[] = "Dd ";

printf("StrCasCmp %d \n", StrCasCmp(str1, str2));
printf("strcasecmp %d \n", strcasecmp(str3,str4));


/* Testing Mystrcpy - Copy string from (dest,src) > NOT ACCEPT '\0'*/ 

/* < [REMOVE HERE]

char str1[] = "hELLO ";
char str2[] = " WorD ";

char str3[] = "hELLO ";
char str4[] = " WorD ";

printf("StrCopy: %s \n", StrCopy(str1,str2)); 
printf("strcpy: %s \n", strcpy(str3,str4));

[REMOVE HERE] > */

/* Testing Mystrncpy - return pointer from the n string (dest,src) >
 NOT ACCEPT '\0'*/ 

/* < [REMOVE HERE]

char str1[] = "Hello";
char str2[] = "World";

char str3[] = "Hello";
char str4[] = "World";

printf("Mystrcpy: %s \n", Mystrncpy(str1,str2, 10)); 
printf("strcpy: %s \n", strncpy(str3,str4, 10));

[REMOVE HERE] > */

/* Testing Mystrncpy - return pointer from the n string (dest,src) >
 NOT ACCEPT '\0'*/ 

/* < [REMOVE HERE]

char *pt1 , *pt2;

char str1[] = "Hello";
char str3[] = "Hello";

pt1 = strdup(str1);
pt2 = strdup(str3);


printf("Mystrdup: %s \n", Mystrdup(str1)); 
printf("strdup: %s \n", pt1);

[REMOVE HERE] > */

return 0;
}


