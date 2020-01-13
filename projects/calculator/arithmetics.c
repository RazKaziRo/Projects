/*
 * Author: Raz KaziRo
 * Purpose: Answares for Calculator.
 * Date: 13.01.2020
 * Language: C
 * Reviewer: Yonatan Zaken
 */

#include <stdlib.h> /*malloc() strtod()*/
#include <string.h> /*strlen()*/
#include <math.h> /*pow*/

#include "../../ds/include/stack.h"
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
	stack_t *nums;
	stack_t *ops;
	double *result_holder;
	calc_state_t **calc_lut;
	calc_op_t *op_lut;
};

enum Presedence
{
	LOW,
	MEDIUM,
	HIGH
};

static int OpError()
{
	return 1;
}

static int CalcCalculationHandler(calc_t *calc)
{
	double num_x = 0;
	double num_y = 0;
	double result = 0;
	char operator_holder = '\0';

	num_x = *(double *)StackPeek(calc->nums);
	StackPop(calc->nums);
	num_y = *(double *)StackPeek(calc->nums);
	StackPop(calc->nums);

	operator_holder = *(char *)StackPeek(calc->ops);
	StackPop(calc->ops);

	switch(operator_holder)
	{	

		case('-'):

		result = num_y - num_x;
		break;

		case('+'):
		result = num_y + num_x;
		break;

		case('/'):
		result = num_y / num_x;
		break;

		case('*'):
		result = num_y * num_x;
		break;

		case('^'):
		result = pow(num_y, num_x);
		break;

		default:
		break;

	}

	return(StackPush(calc->nums, &result));
}

char *CalcDummyHandler(const char *expression, calc_t *calc)
{
	return((char *)(++expression));
}

char *CalcNumberHandler(const char *expression, calc_t *calc)
{
	double num_to_push = 0;
	char *expression_holder = (char *)expression;

	num_to_push = strtod(expression, &expression_holder);
	StackPush(calc->nums, &num_to_push);

	return expression_holder;
}

char *CalcOperatorHandler(const char *expression, calc_t *calc)
{
	char *expression_holder = (char *)expression;
	char op_to_push = *expression_holder;

	if(!StackIsEmpty(calc->ops) && 
		calc->op_lut[op_to_push].presedence <= calc->op_lut[*(char *)StackPeek(calc->ops)].presedence 
		&& HIGH != calc->op_lut[op_to_push].presedence)
	{
		CalcCalculationHandler(calc);
	}

	StackPush(calc->ops, &op_to_push);

	return(++expression_holder);
}

static char *SpacesHandler(const char *expression, calc_t *calc)
{
	char *expression_holder = (char *)expression;

	while(' '== *expression_holder)
	{
		++expression_holder;
	}

	return(expression_holder);
}

char *CalcErrorHandler(const char *expression, calc_t *calc)
{

}

static char *CloseParenthesisHandler(const char *expression, calc_t *calc)
{
	while(!StackIsEmpty(calc->ops))
	{
		if('(' == *(char *)StackPeek(calc->ops))
		{
			StackPop(calc->ops);
		}

		else
		{
			CalcCalculationHandler(calc);
		}
	}

	return ((char *)(++expression));
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

		op_lut['-'].op_handler = &CalcCalculationHandler;
		op_lut['-'].presedence = LOW;

		op_lut['+'].op_handler = &CalcCalculationHandler;
		op_lut['+'].presedence = LOW;

		op_lut['*'].op_handler = &CalcCalculationHandler;
		op_lut['*'].presedence = MEDIUM;

		op_lut['/'].op_handler = &CalcCalculationHandler;
		op_lut['/'].presedence = MEDIUM;

		op_lut['^'].op_handler = &CalcCalculationHandler;
		op_lut['^'].presedence = HIGH;

		op_lut['('].op_handler = &CalcCalculationHandler;
		op_lut['('].presedence = HIGH;
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

	i = '0';

	for(; i <= '9'; ++i)
	{
		state_lut[WAIT_FOR_NUM][i].next_state = WAIT_FOR_OP;
		state_lut[WAIT_FOR_NUM][i].action = &CalcNumberHandler;
	}

	state_lut[WAIT_FOR_NUM]['+'].next_state = WAIT_FOR_OP;
	state_lut[WAIT_FOR_NUM]['+'].action = &CalcNumberHandler;

	state_lut[WAIT_FOR_NUM]['-'].next_state = WAIT_FOR_OP;
	state_lut[WAIT_FOR_NUM]['-'].action = &CalcNumberHandler;

	state_lut[WAIT_FOR_NUM]['('].next_state = WAIT_FOR_NUM;
	state_lut[WAIT_FOR_NUM]['('].action = &CalcOperatorHandler;

	state_lut[WAIT_FOR_NUM][' '].next_state = WAIT_FOR_NUM;
	state_lut[WAIT_FOR_NUM][' '].action = &SpacesHandler;
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

	state_lut[WAIT_FOR_OP][' '].next_state = WAIT_FOR_OP;
	state_lut[WAIT_FOR_OP][' '].action = &SpacesHandler;

	state_lut[WAIT_FOR_OP][')'].next_state = WAIT_FOR_OP;
	state_lut[WAIT_FOR_OP][')'].action = &CloseParenthesisHandler;

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

calc_t *CalcInit(const char *expression, double *user_result)
{
	calc_t *new_calc = (calc_t *)malloc(sizeof(calc_t));
	if(NULL != new_calc)
	{
		new_calc->nums = StackCreate(sizeof(double), strlen(expression));
		if(NULL != new_calc->nums)
		{
			new_calc->ops = StackCreate(sizeof(char), strlen(expression));
			if(NULL != new_calc->ops)
			{
				new_calc->result_holder = user_result;

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

			FREE(new_calc->nums);
		}

		FREE(new_calc);
	}

	return new_calc; 
}

state_t CalcRun(const char *expression, calc_t *calc)
{
	state_t state = WAIT_FOR_NUM;
	char *expression_runner = (char *)expression;
	char *runner_holder = expression_runner;

	while(ERROR != state && '\0'!= *expression_runner)
	{	
		runner_holder = expression_runner;

		expression_runner = calc->calc_lut[state][*expression_runner].action(expression_runner, calc);
		state = calc->calc_lut[state][*runner_holder].next_state;
	}

	while(ERROR != state && !StackIsEmpty(calc->ops))
	{
		CalcCalculationHandler(calc);
	}

	*calc->result_holder = *(double *)StackPeek(calc->nums);

	return state;
}

void CalcDestroy(calc_t *calc)
{	
	int i = 0;

	for(; i<NUM_OF_STATES; ++i)
	{
		FREE(calc->calc_lut[i]);
	}
	FREE(calc->calc_lut);

	StackDestroy(calc->nums);
	StackDestroy(calc->ops);
	FREE(calc->op_lut);
	FREE(calc);
}




