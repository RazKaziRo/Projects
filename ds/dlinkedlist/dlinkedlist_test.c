/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Doubly Linked List.
 * Date: 08.12.2019
 * Language: C
 * Reviewer: 
 */

#include <stdio.h> /*printf()*/
#include <stdlib.h> /*free()*/

#include "dlinkedlist.h"

#define RUN_TEST(test, errmsg)\
							{\
								if(test)\
								{\
									printf("SUCCESS\n");\
								}\
								else\
								{\
									printf("\033[1;31m");\
									printf("%s \n", errmsg);\
									printf("\033[0m");\
								}\
							}
#define UNUSED(x) (void)(x)
#define FREE(ptr) free(ptr); ptr=NULL;	

struct ITERATOR
{
	struct DLLNODE *node;
};
typedef struct DLLNODE
{
	void *data;
	struct DLLNODE *next;
	struct DLLNODE *previous;
}dll_node_t;

void TestDLLCreate()
{
	dll_t *newDll = DLLCreate();
	FREE(newDll);
	printf("\n");
}

int main(int argc, char const *argv[])
{

	printf("TestDLLCreate()");
	TestDLLCreate();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}