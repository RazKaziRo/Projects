#include <stdio.h>
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

/* [TBD]
void DeleteWhiteSpace(char *str)
{
	char *runner_a = str;
	char *runner_b = str+1;

	while(isspace(*runner_a) && '\0'!=*runner_b)
	{
		Mystrcpy(runner_a,runner_b);
		++runner_a;
		++runner_b;
	}

	while('\0'!=*runner_a && '\0'!=*runner_b)
	{
		if(isspace(*runner_a))
		{
		Mystrcpy(runner_a,runner_b);
		}

	++runner_a;
	++runner_b;
	}
}

*/