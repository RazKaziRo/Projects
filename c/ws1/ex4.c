#include<stdio.h>

double pow_to10 (int inputnum)
{

	double result = 1.0;
	float base=10;
	int i;

	if(inputnum <0)
	{
	base = 1/base;
	inputnum = inputnum * (-1);
	}

	for(i = 0; i < inputnum; i ++)
	{
	result *= base;
	}
	
return result;

}
