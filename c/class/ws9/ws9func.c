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
	int tmp_num = num;
	
	assert(NULL != buffer);

	UNUSED(base);

	if (0 == num)
	{
		*buff_runner = (num%10)+48;
		++buff_runner;
	}

	if (0 > num)
	{
		*buff_runner = '-';
		++buff_runner;
		num *=-1;
	}

	while (0 != tmp_num)
	{
		++buff_runner;
		tmp_num /= 10;
	}

	*buff_runner = '\0';
	--buff_runner;

	while (num != 0)
	{
		*buff_runner = (num%10)+48;
		--buff_runner;
		num /=10;
	}

	return buffer;
}



