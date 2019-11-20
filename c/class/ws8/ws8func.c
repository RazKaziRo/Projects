#include <stdio.h>
#include <stdlib.h> /*malloc()*/
#include <string.h> /*strlen()*/

#include "ws8head.h"

#define MYPRINT(a,b)           printf("%s%d\n",a,b);

int InitializeStruct(Struct s[])
{
	*((int *)&(s[0].data)) = 1;
	s[0].print_ptr = PrintInt;
	s[0].add_ptr = AddToInt;
	s[0].clean_ptr = NULL;

	*((float *)&(s[1].data)) = 2.25;
	s[1].print_ptr = PrintFloat;
	s[1].add_ptr = AddToFloat;
	s[1].clean_ptr = NULL;

	s[2].data = "Hello World";
	s[2].print_ptr = PrintChar;
	s[2].add_ptr = AddToChar;
	s[2].clean_ptr = CleanUpChar;

}

int StructInfrastructure()
{	
	int i = 0;
	Struct s[NUM_OF_STRUCT];
	InitializeStruct(s);

	PrintAll(s);
	AddIntToAll(s, 10);
	PrintAll(s);
	

}

void CleanAll(Struct s[])
{
	int i = 0;

	for (i = 0 ; i < NUM_OF_STRUCT; i++)
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

	for (i = 0 ; i < NUM_OF_STRUCT; i++)
	{
			s[i].add_ptr(&s[i].data, num_to_add);
	}
}

void PrintAll(Struct s[])
{
	int i = 0;

	for (i = 0 ; i < NUM_OF_STRUCT; i++)
	{
			s[i].print_ptr(s[i].data);
	}
}


void PrintInt(void *data)
{
	 printf("%d \n", *((int *)(&data)));
}

void PrintFloat(void *data)
{
	 printf("%f \n", *((float *)(&data)));
}

void PrintChar(void *data)
{
	 printf("%s \n", (char *)data);
}


int AddToInt(void *address_to_data, int int_to_add)
{
	*((int *)(address_to_data)) += int_to_add;

	return 0;
}

int AddToFloat(void *address_to_data, int int_to_add)
{
	*((float *)(address_to_data)) += int_to_add;

	return 0;
}

int AddToChar(void *address_to_data, int int_to_add)
{	

	int num_to_add = 0;
	*(char *)address_to_data = CountDigitsOfInt(int_to_add);
	address_to_data = (char *)realloc(address_to_data, 
		strlen(address_to_data)+num_to_add); 
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
	while(num_to_count != 0)
	{
		num_to_count = num_to_count/10;
		++counter;	
	}

	return counter;
}