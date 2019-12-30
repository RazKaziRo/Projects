/**************************************************************************************
			Ws09 
			Ben Zaad
			24.11.19
			revirewer- Raz
**************************************************************************************/
#include "mem.h"

void LittleEndian()
{
	size_t num = 1;
	size_t *p_num = &num;

	if (1 == *(char*)p_num)
	{
		printf("Little Endian\n");
	}
	else 
	{
		printf("BIG Endian\n");	
	}
}