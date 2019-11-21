#include <stdio.h> /* size_t */

#include "ws9head.h"

#define WORD_SIZE 8

void *MyMemset(void *original_str, int intput_char, size_t times_to_fill)
{	
	size_t chunk = FillChunk (intput_char);
	char *str_ptr = original_str;

	while(times_to_fill>=WORD_SIZE)
	{
		*(size_t*)str_ptr = chunk;
		times_to_fill-=WORD_SIZE;
	}


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
	size_t num = 0;
	int i = 0;

	while(i<WORD_SIZE)
	{
		num |= intput_char;
		num<<=WORD_SIZE;
		++i;
	}
	num |= intput_char;

return num;	
}

void AddressAlignment (void *s)
{

}

