#include <stdio.h> /* size_t */
#include <string.h> /*strlen()*/
#include <assert.h> /*assert()*/

#include "ws9head.h"

#define WORD_SIZE 8
#define UNUSED(x) (void)(x)

void *MyMemset(void *original_str, int intput_char, size_t times_to_fill)
{	
	char *str_ptr = original_str;

	assert(NULL != original_str);

	while (times_to_fill>=WORD_SIZE)
	{	
		*(size_t*)str_ptr= FillChunk (intput_char);
		str_ptr+=WORD_SIZE;
		times_to_fill-=WORD_SIZE;
	}

	if (times_to_fill<WORD_SIZE)
	{
		FillLessThenChunk(str_ptr,intput_char, times_to_fill);
	}

	return original_str;
}

void FillLessThenChunk(char *str_ptr,int intput_char, size_t times_to_fill)
{
	assert(NULL != str_ptr);

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

	while (i < WORD_SIZE)
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

int MyAtoi(const char *nptr)
{
	int new_int = 0;
	int sign = 1;

	assert(NULL != nptr);

	if ('-' == *nptr)
	{
		sign =-1;
		++nptr;
	}

	while ( '\0'!= *nptr)
	{
		new_int = (new_int*10 + *nptr) - 48;
		++nptr;
	}

	return sign * new_int;
}

char* MyItoa(int num, char* buffer, int base)
{	

	char *buff_runner = buffer;
	int reminder = 0;
	int abs_num = num;
	int num_length = 0;

	assert(NULL != buffer);

	if (base < 2 || base > 32)
	{
		return buffer;	
	}

	if (num < 0 && 10 == base)
	{
		*buff_runner = '-';
		++buff_runner;
	}

	if (abs_num < 0)
	{
		abs_num *= -1;
	}

	while(0 != abs_num)
	{
		reminder = abs_num%base;

		if(reminder >=10)
		{
			*buff_runner = 65 + (reminder-10); 
		}
		else
		{
			*buff_runner = reminder+48;
		}

		++buff_runner;
		++num_length;
		abs_num /= base;
	}

	++buff_runner;
	buff_runner = '\0';

	ReverseNum(buffer, num_length);

	return buffer;
}

void ReverseNum(char *buffer, int num_length)
{	
	int j = 0;
	char *buffer_next_char = buffer;
	++buffer_next_char;

	while(num_length > j)
	{
		CharSwap(buffer, buffer_next_char);
		++j;
	}
}	

void CharSwap(char *x, char *y) 
{
	char tmp_char = *x; 
	*x = *y; 
	*y = tmp_char;
}



