#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "ws2head.h"

int MyIsPalindrome (const char *str)
{
	const char *ptrhead = str, *ptrtail = str;

	while('\0'!= *ptrtail)
	{
		++ptrtail;
	}
	--ptrtail;

	while(ptrhead < ptrtail)
	{
		if(*ptrhead!=*ptrtail)
		{
			return 0;
		}
		++ptrhead;
		--ptrtail;
	}
return 1;

}

void My7boom (int start, int end)
{
	int i = start;
	for (; i<end; i++)
	{
		if(i%7 == 0 || My7boomHelper(i,7))
		{
			printf("BOOM \n");
			continue;
		}
		printf("%d\n", i);
	}
}

int My7boomHelper(int i, int j) /*Helper Function to 7BOOM*/
{
	while(i != 0)
	{
		if(i%10 == j)
		{
			return 1;
		}
		i = i/10;
	}
return 0;
}

void Myswap(int **a, int **b)
{
	int *tmp = *a;
	*a = *b;
	*b = tmp;
}



void DeleteWhiteSpace(char *str)
{
	char *runner_a = str;
	char *runner_b = str+1;

	while(isspace(*runner_a) && '\0'!=*runner_b)
	{
		strcpy(runner_a,runner_b);
		++runner_a;
		++runner_b;
	}

	while('\0'!=*runner_a && '\0'!=*runner_b)
	{
		if(isspace(*runner_a))
		{
		strcpy(runner_a,runner_b);
		}

	++runner_a;
	++runner_b;
	}
}



char *SumStringsAsNum(const char *a, const char *b, char *c)
{
	const char *runner_a =  a, *runner_b =b;
	int sizedifference = 0;

	if(strlen(a)>strlen(b))
	{
		sizedifference = strlen(a)-strlen(b);
	}
	else
	{
		sizedifference = strlen(a)-strlen(b);
	}

	if(strlen(a)>strlen(b) && sizedifference>0)
	{
		*c = *runner_a;
		++c;
		++runner_a;
		--sizedifference;
	} 
	else
	{
		*c = *runner_b;
		++c;
		++runner_b;
		--sizedifference;
	}
	

	while(*runner_a != '\0' && *runner_b != '\0')
	{
		if(*runner_a + *runner_b >= 106)
		{
			*c ='1';
			*(c+1) = *runner_a + *runner_b - 48 -10;

		}
		else
		{
			*c =*runner_a + *runner_b - 48;
		}
		++c;
		++runner_a;
		++runner_b;
	}

return c;
}

int NewNumsize(char *num1, char *num2)
{
	int x = (strlen(num1) + strlen(num2));
	if(*num1+*num2 >= 106)
	{
		return x/2+1;
	}
	else
	{
		return x/2;
	}
}



