#ifndef __RECURSION_H__
#define __RECURSION_H__

#include <stddef.h> /*size_t*/

size_t RecursiveFibonacci(size_t n);
size_t IterativeFibonacci(size_t n);

size_t RecursiveStrLen(const char *);
int RecursiveStrCmp(const char *s1, const char *s2);
char *RecursiveStrCpy(char *dest, const char *src);
char *RecursiveStrCat(char *dest, const char *src);
char *RecursiveStrStr(const char *haystack, const char *needle);
int recMultiply(int num, int times);
int recDivision(int num, int times);
unsigned int BitWiseAddition(unsigned int x, unsigned y);


#endif
