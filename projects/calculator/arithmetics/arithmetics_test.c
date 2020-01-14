#include <stdlib.h> /*malloc() */
#include <stdio.h> /*printf()*/

#include "arithmetics.h"

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

void TestCalcInit()
{
	char *expression = "2^3^2";
	double result = 0.0;
	calc_t *new_calc = CalcInit(expression, &result);

	printf("TestCalcInit():\n");

	RUN_TEST(NULL != new_calc, "FAIL: CALC NOT CREATED")
	CalcDestroy(new_calc);

	printf("\n");
}

state_t CalcRun(const char *expression, calc_t *calc);

void TestCalcRun()
{
	char *expression = "1+3";
	double result = 0.0;
	calc_t *new_calc = CalcInit(expression, &result);

	printf("TestCalcRun():\n");

	RUN_TEST(WAIT_FOR_OP == CalcRun(expression, new_calc),"FAIL: WRONG STATE (WAIT_FOR_OP)") 
	RUN_TEST(result == 4, "FAIL: WRONG ANSWARE(1+3)");

	CalcDestroy(new_calc);

	printf("\n");
}	


int main(int argc, char const *argv[])
{

	TestCalcInit();
	TestCalcRun();

	UNUSED(argc);
	UNUSED(argv);
	
	return 0;
}