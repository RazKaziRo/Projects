/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW9 - Word Boundry Optimization.
 * Date: 22.11.2019
 * Language: C
 * Reviewer: 
 */

#include <stdio.h>  /* size_t */
#include <string.h> /*strlen()*/
#include <assert.h> /*assert()*/
#include "ws9head.h"

#define WORD_SIZE 8
#define ASCII_COUNT 256

#define UNUSED(x) (void)(x)

static size_t FillChunk (int intput_char)
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

void *MyMemSet(void *original_str, int intput_char, size_t times_to_fill)
{	
	char *str_ptr = original_str;
	assert(NULL != original_str);

	while (0 != (size_t)str_ptr % WORD_SIZE && 0 < times_to_fill) 		/*Address Aligment*/
	{
		*(char *)str_ptr = intput_char;
		--times_to_fill;
		++str_ptr;
	}

	while (times_to_fill >= WORD_SIZE)
	{	
		*(size_t*)str_ptr = FillChunk(intput_char);
		str_ptr += WORD_SIZE;
		times_to_fill -= WORD_SIZE;
	}


	while (times_to_fill<WORD_SIZE && 0 < times_to_fill)
	{
		*(char *)str_ptr = intput_char;
		++str_ptr;
		--times_to_fill;
	}
	
	return original_str;
}

void *MyMemCpy(void *dest, const void *src, size_t num_of_chars_to_cpy)
{
	char *dest_ptr = dest;
	const char *src_ptr = src;

    assert(NULL != src);
    assert(NULL != dest);

	while (0 != (size_t )dest_ptr%WORD_SIZE && 0 < num_of_chars_to_cpy) 		/*Address Aligment*/
	{
		*dest_ptr = *src_ptr;
		--num_of_chars_to_cpy;
		++dest_ptr;
		++src_ptr;
	}

	while (num_of_chars_to_cpy >= WORD_SIZE)
	{	
		*(size_t*)dest_ptr = *(size_t*)src_ptr;
		src_ptr += WORD_SIZE;
		dest_ptr += WORD_SIZE;
		num_of_chars_to_cpy -= WORD_SIZE;
	}

	while (0 < num_of_chars_to_cpy)
	{
		*dest_ptr = *src_ptr;
		++dest_ptr;
		++src_ptr;
		--num_of_chars_to_cpy;
	}

	return dest;
}

static void *MyMemMoveReverse(void *dest, const void *src, size_t num_of_chars_to_cpy)
{
    char *dest_ptr = dest;
    const char *src_ptr = src;

    assert(NULL != src);
    assert(NULL != dest);

    dest_ptr += num_of_chars_to_cpy-1;
    src_ptr += num_of_chars_to_cpy-1;

    while (0 < num_of_chars_to_cpy)
    {
        *dest_ptr = *src_ptr;
        --dest_ptr;
        --src_ptr;
        --num_of_chars_to_cpy;
    }
    return dest;
}

void *MyMemMove(void *dest, const void *src, size_t num_of_chars_to_cpy)
{
	char *dest_ptr = dest;
	const char *src_ptr = src;

    assert(NULL != src);
    assert(NULL != dest);

	if (src >= dest)
	{
		MyMemCpy(dest_ptr, src_ptr, num_of_chars_to_cpy);
	}
	else
	{
		MyMemMoveReverse(dest_ptr, src_ptr, num_of_chars_to_cpy);
	}
	
	return dest;
}

void isLittleEndian(int x)
{

	int x_first_byte = (0xff&x);

	if (x_first_byte == (*(char *)&x))
	{
		printf("Machine is Little Endian \n");
	}
	else
	{
		printf("Machine is Big Endian \n");
	}
}

int MyAtoi(const char *nptr) /*Base 10*/
{
	int new_int = 0;
	int sign = 1;

	assert(NULL != nptr);

	if ('-' == *nptr)
	{
		sign =-1;
		++nptr;
	}

	while ( '\0' != *nptr)
	{
		new_int = (new_int*10 + *nptr) - 48;
		++nptr;
	}

	return sign * new_int;
}

static void ReverseNum(char *buffer, char *end_of_buffer, int num_length)
{   
    int j = 0;

    assert (NULL != buffer);
    assert (NULL != end_of_buffer);

    --end_of_buffer;    /* Skip The '\0' */

    while(num_length/2 > j)
    {
        CharSwap(buffer, end_of_buffer);
        --end_of_buffer;
        ++buffer;
        ++j;
    }
}   

char* MyItoa(int num, char* buffer, int base)
{	
	char *buff_runner = buffer;
	int reminder = 0;
	int num_length = 0;
	int abs_num = num;

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

	if (0 > num)
	{
		abs_num *= -1;
	}

	do  						/*Take care of the 0 case */
	{
	reminder = abs_num%base; 

	if (reminder >= 10)
	{
		*buff_runner = 65 + (reminder - 10); 
	}
	else
	{
		*buff_runner = reminder + 48;
	}

	++buff_runner;
	++num_length;
	abs_num /= base;

	}while(0 != abs_num);
	
	*buff_runner = '\0';
	
	ReverseNum(buffer, buff_runner, num_length);

	return buffer;
}

void CharSwap(char *x, char *y) 
{
	char tmp_char = *x; 

    assert (NULL != x);
    assert (NULL != y);

	*x = *y; 
	*y = tmp_char;
}

void InitAsciiStructArray(ascii_t asciiArr[])
{

	int i = 0;

	for(; i< ASCII_COUNT; ++i)
	{
		asciiArr[i].ascii_code = (char)i;
		asciiArr[i].status = 0;
	}
}

void InFirstTwoArrNotThird(char *arr1,int size_arr1, char *arr2,int size_arr2, char *arr3, int size_arr3 )
{	
	int i = 0;
	ascii_t asciiArr[ASCII_COUNT];

    assert (NULL != arr1);
    assert (NULL != arr2);
    assert (NULL != arr3);

	InitAsciiStructArray(asciiArr);

	while (size_arr1 > 0)
	{
		if (1 == asciiArr[*arr1 % ASCII_COUNT].status)
		{
			--size_arr1;
			++arr1;
			continue;
		}

		asciiArr[*arr1 % ASCII_COUNT].status +=1;
		--size_arr1;
		++arr1;
	}

	while (size_arr2 > 0)
	{
		if(2 == asciiArr[*arr2 % ASCII_COUNT].status)
		{
			--size_arr2;
			++arr2;
			continue;
		}

		asciiArr[*arr2 % ASCII_COUNT].status +=1;
		--size_arr2;
		++arr2;
	}

	while (size_arr3 > 0)
	{
		asciiArr[*arr3 % ASCII_COUNT].status =-1;
		--size_arr3;
		++arr3;
	}

	while (i < ASCII_COUNT)
	{
		if (2 == asciiArr[i].status)
		{
			printf("%c\n", asciiArr[i].ascii_code);
		}
		++i;
	}
}



