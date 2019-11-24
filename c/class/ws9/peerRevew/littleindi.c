#include<stdio.h>

#define LilEndi(num) *(char*)(&num) == (num & 0xff) 

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

int main()
{
	int x = 40;

	LittleEndian();

	printf("%d\n",LilEndi(x));

	return 0;
}