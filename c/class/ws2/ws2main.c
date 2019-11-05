/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW2 - Pointers Strings 1-5.
 * Date: 05.11.2019
 * Language:  C
 * Reviewer: Shye
 */
#include <stdlib.h> /* to use free()*/
#include <stdio.h>
#include <string.h>   /*for testing string origin behavoior*/
#include <strings.h>  /*for testing strcmp*/
#include "Mystring.h" /* include MyStrlen()/MyStrCmp()/MyStrCpy()*/

char *strdup(const char *s);

int main(void)
{
    
/* -Testing Mystrlen - Return String Length >  NOT ACCEPT '\0' */

/* < [REMOVE HERE]

char str1[] = "Hello World!";

printf("Mystrlen: %ld \n", Mystrlen(str1)); 
printf("strlen: %ld \n", strlen(str1));

[REMOVE HERE] */

/* Testing Mystrcmp - Compare 2 Strings > NOT ACCEPT '\0'*/ 

/* < [REMOVE HERE]

char str1[] = "H!";
char str2[] = "Hed!";

char str3[] = "H!";
char str4[] = "Hed!";


printf("Mystrcmp: %d \n", Mystrcmp(str1,str2)); 
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

/* < [REMOVE HERE]

char str1[] = "SSs";
char str2[] = "sab";

char str3[] = "SSs";
char str4[] = "sab";

printf("MyStrcasecmp %d \n", Mystrcasecmp(str1, str2));
printf("strcasecmp %d \n", strcasecmp(str3,str4));

[REMOVE HERE] > */

/* Testing Mystrcpy - Copy string from (dest,src) > NOT ACCEPT '\0'*/ 

/* < [REMOVE HERE]

char str1[] = "111";
char str2[] = "2222";

char str3[] = "111";
char str4[] = "2222";

printf("Mystrcpy: %s \n", Mystrcpy(str1,str2)); 
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

/* printf("Mystrdup: %s \n", Mystrdup(str1)); */

/* < [REMOVE HERE]

char *pt1 , *pt2;

char str1[] = "ma kores";
char str2[] = "ma kores";


pt1 = Mystrdup(str1);
pt2 = strdup(str2);

printf("Mystrdup: %s \n", pt1);
printf("strdup: %s \n", pt2);

[REMOVE HERE] > */

/* Testing Mystrcat - adding to string  (dest,src) >
 NOT ACCEPT '\0'*/ 

/* < [REMOVE HERE]

char str1[] = "123";
char str2[] = "45 ";

char str3[] = "123";
char str4[] = "45";


printf("Mystrcat: %s \n", Mystrcat(str1, str2));
printf("strcat: %s \n", strcat(str3,str4));

[REMOVE HERE] > */

/* Testing IsPolindrom - adding to string  (dest,src) >
 NOT ACCEPT '\0'*/ 

/* < [REMOVE HERE]


char str1[] = "222";

printf("IsPalindrome: %d \n", MyIsPalindrome(str1));

[REMOVE HERE] > */
My7boom(0, 100);

return 0;
}


