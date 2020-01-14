/*
 * Author: Raz KaziRo
 * Purpose: Answares for Calculator.
 * Date: 13.01.2020
 * Language: C
 * Reviewer: Yonatan Zaken
 */
#include <stdlib.h>/*NULL*/

#include "calculator.h"
#include "arithmetics.h"

calc_status_t Calculator(const char *expression, double *result)
{
	calc_status_t status = MEMORY_FAIL;

	calc_t *new_calc = CalcInit(expression, result);
	if (NULL != new_calc)
	{
		status = CalcRun(expression, new_calc);
		CalcDestroy(new_calc);
	}

	return status;
}
