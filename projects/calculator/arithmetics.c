#include <stdlib.h> /*malloc() strtod()*/
#include <string.h> /*strlen()*/

#include "stack.h"
#include "arithmetics.h"

#define FREE(ptr) free(ptr); ptr = NULL;

#define NUM_OF_STATES 3
#define NUM_OF_OPERATIONS 5
#define NUM_OF_ASCII_CHARS 256

typedef struct State
{
	state_t next_state;
	func_state_t action;
} calc_state_t;

typedef struct Operator
{
	func_op_t op_handler;
	int presedence;
} calc_op_t;

struct Calc
{
	stack_t *num;
	stack_t *ops;
	double *result;
	calc_state_t **calc_lut;
	calc_op_t *op_lut;
};

enum OpPresedence
{
	LOW,
	MEDIUM,
	HIGH
};

static int Addition(calc_t *calc)
{

}

static int Subtraction(calc_t *calc)
{

}

static int Multiplication(calc_t *calc)
{

}

static int Division(calc_t *calc)
{

}

static int Power(calc_t *calc)
{

}

static int OpError()
{
	return 1;
}

char *CalcDummyHandler(const char *expression, calc_t *calc)
{
	
}

char *CalcNumberHandler(const char *expression, calc_t *calc)
{
	double num_to_push = 0;
	char *expression_holder = (char *)expression;
	char **expression_leftovers = &expression_holder;

	num_to_push = strtod(expression, expression_leftovers);
	StackPush(calc->num, &num_to_push);

	return expression_holder;
}

char *CalcOperatorHandler(const char *expression, calc_t *calc)
{
	char op_to_push = *expression;
	StackPush(calc->ops, &op_to_push);

}

char *CalcErrorHandler(const char *expression, calc_t *calc)
{

}


calc_op_t * CalcOpLutInit()
{
	calc_op_t *op_lut = (calc_op_t *)malloc(sizeof(calc_op_t) * NUM_OF_ASCII_CHARS);
	if(NULL != op_lut)
	{	
		int i = 0;

		for(;i<NUM_OF_ASCII_CHARS; ++i)
		{
			op_lut[i].op_handler = &OpError;
			op_lut[i].presedence = -1;
		}

		op_lut['-'].op_handler = &Subtraction;
		op_lut['-'].presedence = LOW;

		op_lut['+'].op_handler = &Addition;
		op_lut['+'].presedence = LOW;

		op_lut['*'].op_handler = &Multiplication;
		op_lut['*'].presedence = MEDIUM;

		op_lut['/'].op_handler = &Division;
		op_lut['/'].presedence = MEDIUM;

		op_lut['^'].op_handler = &Power;
		op_lut['^'].presedence = HIGH;
	}

	return op_lut;
}

static void WaitForNumStateInit(calc_state_t *state_lut[])
{	
	int i = 0;

	for(; i < NUM_OF_ASCII_CHARS; ++i)
	{
		state_lut[WAIT_FOR_NUM][i].next_state = ERROR;
		state_lut[WAIT_FOR_NUM][i].action = &CalcErrorHandler;
	}

	i = 0;

	for(; i <= 9; ++i)
	{
		state_lut[WAIT_FOR_NUM][i].next_state = WAIT_FOR_OP;
		state_lut[WAIT_FOR_NUM][i].action = &CalcNumberHandler;
	}

	state_lut[WAIT_FOR_NUM]['+'].next_state = WAIT_FOR_OP;
	state_lut[WAIT_FOR_NUM]['+'].action = &CalcNumberHandler;

	state_lut[WAIT_FOR_NUM]['-'].next_state = WAIT_FOR_OP;
	state_lut[WAIT_FOR_NUM]['-'].action = &CalcNumberHandler;

	state_lut[WAIT_FOR_NUM]['('].next_state = WAIT_FOR_NUM;
	state_lut[WAIT_FOR_NUM]['('].action = &CalcDummyHandler;
}

static void WaitForOpStateInit(calc_state_t *state_lut[])
{
	int j = 0;

	for(; j < NUM_OF_ASCII_CHARS; ++j)
	{
		state_lut[WAIT_FOR_OP][j].next_state = ERROR;
		state_lut[WAIT_FOR_OP][j].action = &CalcErrorHandler;
	}

	state_lut[WAIT_FOR_OP]['+'].next_state = WAIT_FOR_NUM;
	state_lut[WAIT_FOR_OP]['+'].action = &CalcOperatorHandler;

	state_lut[WAIT_FOR_OP]['-'].next_state = WAIT_FOR_NUM;
	state_lut[WAIT_FOR_OP]['-'].action = &CalcOperatorHandler;

	state_lut[WAIT_FOR_OP]['*'].next_state = WAIT_FOR_NUM;
	state_lut[WAIT_FOR_OP]['*'].action = &CalcOperatorHandler;

	state_lut[WAIT_FOR_OP]['/'].next_state = WAIT_FOR_NUM;
	state_lut[WAIT_FOR_OP]['/'].action = &CalcOperatorHandler;

	state_lut[WAIT_FOR_OP]['^'].next_state = WAIT_FOR_NUM;
	state_lut[WAIT_FOR_OP]['^'].action = &CalcOperatorHandler;

}	

static void ErrorStateInit(calc_state_t *state_lut[])
{	
	int k = 0;

	for(; k < NUM_OF_ASCII_CHARS; ++k)
	{
		state_lut[ERROR][k].next_state = ERROR;
		state_lut[ERROR][k].action = &CalcErrorHandler;
	}
}

static calc_state_t **CalcStateLutInite()
{
	calc_state_t **state_lut = (calc_state_t **)malloc(NUM_OF_STATES  * sizeof(calc_state_t *));

	state_lut[WAIT_FOR_NUM] = (calc_state_t *)malloc(sizeof(calc_state_t) * NUM_OF_ASCII_CHARS);
	if (NULL != state_lut[WAIT_FOR_NUM])
	{
		WaitForNumStateInit(state_lut);

		state_lut[WAIT_FOR_OP] = (calc_state_t *)malloc(sizeof(calc_state_t) * NUM_OF_ASCII_CHARS);
		if (NULL != state_lut[WAIT_FOR_OP])
		{

			WaitForOpStateInit(state_lut);

			state_lut[ERROR] = (calc_state_t *)malloc(sizeof(calc_state_t) * NUM_OF_ASCII_CHARS);
			if (NULL != state_lut[ERROR])
			{
				ErrorStateInit(state_lut);
				return state_lut;
			}

			FREE(state_lut[WAIT_FOR_OP]);
		}

		FREE(state_lut[WAIT_FOR_NUM]);
	}

	FREE(state_lut);
	return state_lut;
}

calc_t *CalcInit(const char *expression, double *result)
{
	calc_t *new_calc = (calc_t *)malloc(sizeof(calc_t));
	if(NULL != new_calc)
	{
		new_calc->num = StackCreate(sizeof(double), strlen(expression));
		if(NULL != new_calc->num)
		{
			new_calc->ops = StackCreate(sizeof(char), strlen(expression));
			if(NULL != new_calc->ops)
			{
				new_calc->result = result;

				new_calc->calc_lut = CalcStateLutInite();
				if(NULL != new_calc->calc_lut)
				{
					new_calc->op_lut = CalcOpLutInit();
					if(NULL != new_calc->op_lut)
					{
						return new_calc; 
					}

					FREE(new_calc->calc_lut);
				}

				FREE(new_calc->ops)
			}

			FREE(new_calc->num);
		}

		FREE(new_calc);
	}

	return new_calc; 
}

state_t CalcRun(const char *expression, calc_t *calc)
{
	int state = WAIT_FOR_NUM;
	char *expression_runner = (char *)expression;

	while(ERROR != state && '\0'!= *expression_runner)
	{	
		expression_runner = calc->calc_lut[state][*expression_runner].action(expression_runner, calc);
		state = calc->calc_lut[state][*expression_runner].next_state;
	}

	return state;
}



