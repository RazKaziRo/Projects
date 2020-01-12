#include "calculator.h"
#include "arithmetics.h"

calc_status_t Calculator(const char *expression, double *result)
{
	calc_t *new_calc = CalcInit(expression, result);
	calc_status_t status = CalcRun(expression, new_calc);
	
	return status;
}
