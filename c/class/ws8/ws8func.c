/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW8 - Structs.
 * Date: 20.11.2019
 * Language: C
 * Reviewer: Shye Shapira
 */

#include <stdio.h>
#include <stdlib.h> /*malloc()*/
#include <string.h> /*strlen()*/

#include "ws8head.h"

int InitializeStruct(Struct s[])
{
	char str[] = "aaa";

	*((int *)&(s[0].data)) = 1;
	s[0].print_ptr = PrintInt;
	s[0].add_ptr = AddToInt;
	s[0].clean_ptr = NULL;

	*((float *)&(s[1].data)) = 2.25;
	s[1].print_ptr = PrintFloat;
	s[1].add_ptr = AddToFloat;
	s[1].clean_ptr = NULL;

	s[2].data = (void *)malloc(strlen(str)+1);

	if(NULL == s[2].data) /*Check For Malloc() Failed */
	{
		return 1;
	}

	strcpy(s[2].data, str);
	s[2].print_ptr = PrintChar;
	s[2].add_ptr = AddToChar;
	s[2].clean_ptr = CleanUpChar;

	return 0;
}

int StructInfrastructure()
{	
    int input_num = 0;
	Struct s[NUM_OF_STRUCT];
	InitializeStruct(s);


	PrintAll(s);

    printf("Enter Number To add: ");
    scanf("%d", &input_num);
	AddIntToAll(s, input_num);
	PrintAll(s);

	CleanAll(s);

	return 0;
}

void CleanAll(Struct s[])
{
	int i = 0;

	for (; i < NUM_OF_STRUCT; i++)
	{
		if(NULL != s[i].clean_ptr)
		{
			s[i].clean_ptr(s[i].data);
		}
	}
}

void AddIntToAll(Struct s[], int num_to_add)
{
	int i = 0;

	for (; i < NUM_OF_STRUCT; i++)
	{
		s[i].add_ptr(&s[i].data, num_to_add);
	}
}

void PrintAll(Struct s[])
{
	int i = 0;

	for (; i < NUM_OF_STRUCT; i++)
	{
		s[i].print_ptr(s[i].data);
	}
}


void PrintInt(void *data)
{
	 printf("%d\n", *((int *)(&data)));
}

void PrintFloat(void *data)
{
	 printf("%f\n", *((float *)(&data)));
}

void PrintChar(void *data)
{
	 printf("%s\n", (char *)data);
}


int AddToInt(void *data, int int_to_add)
{
	*((int *)(data)) += int_to_add;

	return 0;
}

int AddToFloat(void *data, int int_to_add)
{
	*((float *)(data)) += int_to_add;

	return 0;
}

int AddToChar(void *data, int int_to_add)
{	

	int num_to_add = CountDigitsOfInt(int_to_add);
	char *str_to_concat = IntToString(int_to_add, CountDigitsOfInt(int_to_add));
	*(char **)data = (void *)realloc(*(char **)data,strlen(*(char **)data)+num_to_add+1);

	if (NULL == *(char **)data) /*Check For Malloc() Failed */
	{
		return 1;
	}

	strcat(*(char **)data,str_to_concat);

	free(str_to_concat);
	str_to_concat = NULL;

	return 0;
}

int CleanUpChar(void *data)
{
	free(data);
	data = NULL;

	return 0;
}

int CountDigitsOfInt(int num_to_count)
{
	int counter = 0;
	while (0 != num_to_count)
	{
		num_to_count = num_to_count/10;
		++counter;	
	}

	return counter;
}

char *IntToString(int num_to_convert, int size)
{	
	char *converted_int = (char *)malloc(size+1);
	sprintf(converted_int, "%d", num_to_convert);

    return converted_int;
}