#include <stdio.h>
/*insertion_sort.h file*/
#ifndef _Mystring_h
#define _Mystring_h

size_t Mystrlen(const char *str);

int Mystrcmp(const char *s1, const char *s2);

char *Mystrcpy(char *dest, const char *src);

char *Mystrncpy(char *dest, const char *src, size_t n);

int Mystrcasecmp(const char *s1, const char *s2); 

char *Mystrchr(const char *s, int c);

char *Mystrdup(const char *s);

char *Mystrcat(char *dest, const char *src);


#endif


