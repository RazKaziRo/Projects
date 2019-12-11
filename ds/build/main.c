/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS.
 * Date: 10.12.2019
 * Language: C
 * Reviewer: 
 */

#include <stdio.h>
#include <stdlib.h> /*free()*/

#include "sortedlist.h" /* Queue API Functions*/

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
#define FREE(ptr) free(ptr); ptr = NULL;


							
int main(int argc, char const *argv[])
{
	printf("(test)\n");

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}