#ifndef _WS8HEAD_H
#define _WS8HEAD_H

#define NUM_OF_STRUCT 3

typedef void (*ptr_to_print) (void *ptr);
typedef int (*ptr_to_add) (void *ptr, int input_int);
typedef int (*ptr_to_clean)(void *ptr);

typedef struct 
{
	void *data;
	ptr_to_print print_ptr;
	ptr_to_add add_ptr;
	ptr_to_clean clean_ptr;
	

}Struct;

void PrintChar(void *data);
void PrintInt(void *data);
void PrintFloat(void *data);

int AddToInt(void *data , int int_to_add);
int AddToFloat(void *data, int int_to_add);
int AddToChar(void *data, int int_to_add);

int CleanUpChar(void *address_to_data);

void AddIntToAll(Struct s[], int num_to_add);
void PrintAll(Struct s[]);
void CleanAll(Struct s[]);

int InitializeStruct(Struct s[]);
int StructInfrastructure();

int CountDigitsOfInt(int num_to_count);

#endif