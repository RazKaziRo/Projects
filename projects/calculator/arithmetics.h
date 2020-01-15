#ifndef __ARITHMETICS_H__
#define __ARITMETICS_H__

typedef struct Calc calc_t;

typedef char *(*func_state_t)(const char *expression, calc_t *calc);
typedef int (*func_op_t)(calc_t *calculator);

typedef enum
{
	WAIT_FOR_OP,
	WAIT_FOR_NUM,
	ERROR
} state_t;

/* Initiates LUT of all ASCII table 
	pointer to calculator struct or NULL for memory fail */
calc_t *CalcInit(const char *expression, double *result);

/* free all resorces in use */ 
void CalcDestroy(calc_t *calc);

state_t CalcRun(const char *expression, calc_t *calc);

char *CalcNumberHandler(const char *expression, calc_t *calc);

char *CalcOperatorHandler(const char *expression, calc_t *calc);

char *CalcErrorHandler(const char *expression, calc_t *calc);

char *CalcDummyHandler(const char *expression, calc_t *calc);

#endif
