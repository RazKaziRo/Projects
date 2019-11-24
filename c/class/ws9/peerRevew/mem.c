#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define WORD 8
#define BYTE 8

/*#include "mem.h"*/

/*creates a word that holds "word" times the bit seq of c*/
static size_t CharToWord(char c)
{
	int i=0;
	size_t char_expander = c;

	for (;WORD-1 > i; ++i)
	{
		char_expander <<= BYTE;
		char_expander |= c;
	}
    return char_expander;
}

static size_t StringToWord(char *st)
{
	int i=0;
	size_t string_holder = *(st+BYTE-1);
	char *runner = (st+BYTE-1);

	for (;WORD > i;++i)
	{
		string_holder <<= BYTE;
		string_holder |= *runner;
		--runner;
	}
    return string_holder;
}

/*copies the char val of c, n times into str*/
void *MyMemSet(void *str, int c, size_t n)
{
	size_t adress_holder = (size_t)str;
	size_t char_expander= 0;
	char *runner= (char*)str;

	assert(NULL != str);

	while ((adress_holder % WORD) != 0)
	{
		*runner = (char)c;
		++runner;
		--n;
	}

	char_expander = CharToWord((char)c);

	while (WORD <= n)
	{
		 *(size_t*)runner= char_expander;
		 n -= WORD;
		 runner += WORD;
	}

	while (0 < n)
	{
		*runner = (char)c;
		++runner;
		--n;
	}
 	
	return str;
}

void *MyMemCpy(void *dest, const void *source, size_t n)
{
	size_t dest_adress_holder = (size_t)dest;
	size_t string_holder= 0;
	char *dest_runner= (char*)dest;
	char *source_runner= (char*)source;

	assert(NULL != dest);
	assert(NULL != source);

	while (dest_adress_holder % WORD != 0)
	{
		*dest_runner= *source_runner;
		--n;
		++dest_runner;
		++source_runner;
		dest_adress_holder = (size_t)dest_runner;
	}	

	while (WORD <= n)
	{
		string_holder= StringToWord(source_runner);
		*(size_t*)dest_runner= string_holder;
		n -= WORD;
		dest_runner += WORD;
		source_runner += WORD;
	}

	while (0 < n)
	{
		*dest_runner= *source_runner;
		--n;
		++dest_runner;
		++source_runner;
	}	

	return dest;
}

void *MyMemMoveReverse(void *dest, const void *source, size_t n)
{
        char *dest_ptr = (char*) dest;
        char *source_ptr = (char*) source;
        const char *src_ptr = source;

        dest_ptr += n-1;
        source_ptr += n-1;

        while(0 < n)
        {
                *dest_ptr = *source_ptr;
                --dest_ptr;
                --source_ptr;
                --n;
        }
        return dest;	
}

void *MyMemMove(void *dest, const void *source, size_t n)
{
	if ((((char*)dest > (char*)source + n)) || ((char*)dest+strlen(dest) < (char*)source))
	{
		MyMemCpy(dest, source, n);
	}
	else 
	{
		MyMemMoveReverse(dest, source, n);
	}
}

void Test(int condition, const char *msg)
{
	if (condition)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("\033[1;31m");
		printf("%s \n",msg);
		 printf("\033[0m");
	}
}

int main()
{
   char *st1 = (char*)malloc(66);
   char *st3 = (char*)malloc(66);
   char *st2 = (char*)malloc(66);
   char *st4 = (char*)malloc(66);

	strcpy(st1,"Segmentation fault (core dumped)");
	strcpy(st3,"Segmentation fault (core dumped)");
	strcpy(st2,"Segmentation fault (core dumped)");
	strcpy(st4,"Segmentation fault (core dumped)");

	puts(st1);
	MyMemMove(st1+2, st3, 1);
	puts(st1);
	/*MyMemMove(st2+2, st4,1);*/

/*
	Test(0 == strcmp(memmove(st1+2, st3,1),MyMemMove(st2+2, st4,1)), "FAILED: 10 Times ");
*/
    	return 0;
}
