#include <stdio.h> /* size_t */

#include "ws9head.h"

#define WORD_SIZE 8

void *MyMemset(void *original_str, int intput_char, size_t times_to_fill)
{	
	char *str_ptr = original_str;

	while(times_to_fill>=WORD_SIZE)
	{	
		*(size_t*)str_ptr= FillChunk (intput_char);
		str_ptr+=WORD_SIZE;
		times_to_fill-=WORD_SIZE;
	}

	if(times_to_fill<WORD_SIZE)
	{
		FillLessThenChunk(str_ptr,intput_char, times_to_fill);
	}

	return original_str;
}

void FillLessThenChunk(char *str_ptr,int intput_char, size_t times_to_fill)
{
		while(times_to_fill > 0)
		{
			*(char *)str_ptr = intput_char;
			++str_ptr;
			--times_to_fill;
		}
}

size_t FillChunk (int intput_char)
{
	size_t chunk = 0;
	int i = 0;

	while(i<WORD_SIZE)
	{
		chunk |= intput_char;
		chunk <<= WORD_SIZE;
		++i;
	}
	chunk |= intput_char;

return chunk;	
}

void AddressAlignment (void *s)
{

}

