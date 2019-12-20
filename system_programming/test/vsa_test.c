/*
 * Author: Raz KaziRo
 * Purpose: Answares for System Programing - Varient Size Allocator.
 * Date: 22.12.2019
 * Language: C
 * Reviewer: Yonatan Zaken
 */

#include "../include/vsa.h"

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

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}