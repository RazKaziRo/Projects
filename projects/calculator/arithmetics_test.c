#include <stdlib.h> /*malloc() */
#include <stdio.h> /*printf()*/

#include "arithmetics.h"

int main(int argc, char const *argv[])
{
	char *expression = "1+1";
	double *result = (double *)malloc(80);

	calc_t *new_calc = CalcInit(expression, result);
	CalcRun(expression, new_calc);

	printf("%f", *result);
	
	return 0;
}