/**************************************************************************************
			Ws09 
			Ben Zaad
			24.11.19
			revirewer- Raz
**************************************************************************************/
#include "mem.h"

void TwoGoodToBeThree(char *a, char *b, char *c)
{
	char **abc = NULL;
	int  i = 0;

	abc = (char**)calloc(3,1);
	
	for (i=0;i<3;i++)
	{
    abc[i] = (char *)calloc(128, 1);
	}

	while (('\0' != *a) || ('\0' != *b) || ('\0' != *c))
	{
		++abc[0][(int)*a];
		++abc[1][(int)*b];
		++abc[2][(int)*c];
		if (*a != '\0')
		{
			++a;
		}
		if (*b != '\0')
		{
			++b;
		}
		if (*c != '\0')
		{
			++c;
		} 
	}

	for (i = 0 ; i < 128 ; ++i)
	{
		if ((abc[0][i]  > 0) && ((abc[1][i]) > 0) && ((abc[2][i] == 0)))
		{
			printf("%c\n",i);
		}
	}
	free(abc);
}