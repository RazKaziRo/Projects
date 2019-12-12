/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Priority Queue.
 * Date: 11.12.2019
 * Language: C
 * Reviewer: 
 */
#include <stdio.h> /*printf()*/

#include "priorityq.h"

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
#define UNUSED(x) (void)(x)							

void TestPQCreate()
{
	
}


int main(int argc, char const *argv[])
{	
	printf("TestPQCreate()\n");
	TestPQCreate();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}