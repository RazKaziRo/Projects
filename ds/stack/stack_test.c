/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Stack.
 * Date: 26.11.2019
 * Language: C
 * Reviewer: Ben
 */

#include <stdio.h>

#include "stack.h"

#define UNUSED(x) (void)(x)
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

struct Stack
{
	void *start;
	void *current;
	void *end;
	size_t element_size;

};

int main(int argc, char const *argv[])
{


	/*element size, capacity*/
	stack_t *s = StackCreate(10,3);
	size_t size = s->element_size;
	
	printf("%ld \n", size);

	UNUSED(argc);
	UNUSED(argv);

	return 0;
}