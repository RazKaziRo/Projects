/*
 * Author: Raz KaziRo
 * Purpose: Answares for Recursion.
 * Date: 14.01.2020
 * Language: C
 * Reviewer: 
 */

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

	if('\0' == *src)
	{	
		*(dest + strlen(dest)) = *src;
		return dest;
	}

	*(dest + (RecursiveStrLen(dest))) = *src;
	RecursiveStrCat(dest + RecursiveStrLen(dest), src + 1);
	

	return (dest);
}

char *RecursiveStrStr(const char *haystack, const char *needle)
{
	if ('\0' == *haystack)
	{
		return NULL;
	}

	if (*haystack != *needle && '\0' != *needle)
	{
		return(RecursiveStrStr((haystack + 1), (needle)));
	}

	RecursiveStrStr((haystack + 1), (needle + 1));
	
	return(char *)haystack;
}

int recMultiply(int num, int times){

    if(times == 0)
    {
    	return 0;
    }
    
    num += recMultiply(num, times - 1);

	return num;
}

int recDivision(int num, int dividor){

	int count = 0;

	if(num == 0 || dividor == 0)
	{
		return 0;
	}

	++ count;
	count += recDivision(num - dividor, dividor);

	return count;

}

unsigned int BitWiseAddition(unsigned int x, unsigned y)
{	

	unsigned int carry = x & y;

	if(y == 0)
	{
		return x;
	}

	BitWiseAddition(x ^ y , carry << 1);

}
