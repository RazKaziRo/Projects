#include "recursion.h"

size_t RecursiveFibonacci(size_t n)
{
	if (0 == n)
	{
		return 0;
	}

	if (1 == n)
	{
		return 1;
	}

	return (RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2));
}

size_t IterativeFibonacci(size_t n)
{
    size_t previousPreviousNumber, previousNumber = 0, currentNumber = 1, i = 1;

	for(; (double)i < n; ++i)
	{
		previousPreviousNumber = previousNumber;
		previousNumber = currentNumber;
		currentNumber = previousPreviousNumber + previousNumber;

	}

	return currentNumber;
}

size_t RecursiveStrLen(const char *str)
{
	if(*str == '\0')
	{
		return 0;
	}

	return(RecursiveStrLen(str +1) + 1);
}

int RecursiveStrCmp(const char *s1, const char *s2)
{	
	if(*s1 != *s2 || '\0' == *s1 || '\0' == *s2)
	{
		return *s1 - *s2;
	}

	return(RecursiveStrCmp((s1+1), (s2+1)));
}

char *RecursiveStrCpy(char *dest, const char *src)
{
	if ('\0' == *src)
	{	
		*dest = *src;
		return dest;
	}

	RecursiveStrCpy((dest + 1), (src + 1));
	*dest = *src;

	return (dest);
}

char *RecursiveStrCat(char *dest, const char *src)
{
	
}