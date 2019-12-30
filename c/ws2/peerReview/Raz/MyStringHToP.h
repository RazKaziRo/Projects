#include <stdio.h>
/*insertion_sort.h file*/
#ifndef _MyStringToP_h
#define _MyStringToP_h

size_t MyStrLen(const char *str);

int MyStrCmp(const char *s1, const char *s2);

char *MyStrCpy(char *dest, const char *src);

char *MyStrNCpy(char *dest, const char *src, size_t n);

int MyStrCaseCmp(const char *s1, const char *s2); 

char *MyStrChr(const char *s, int c);

#endif


