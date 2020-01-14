#include <stdlib.h> /*malloc() */
#include <stdio.h> /*printf()*/

#include "calculator.h"

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

void TestCalculator()
{	

 	double result = 0.0;
 	char *expression = "10+(2+4*3)*2-5-2*3";
 	int status = 0;

 	status = Calculator(expression, &result);

	printf("result: %f \n", result);
	printf("status %d \n", status);
}						

int main(int argc, char const *argv[])
{

	TestCalculator();

	UNUSED(argc);
	UNUSED(argv);

	return 0;
}