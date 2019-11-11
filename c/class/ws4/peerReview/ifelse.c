/**************************************************************************************
			Ws04 - If/Case
			Ben Zaad
			11.11.19
			revirewer- the legendary Raz KaziRo
**************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int IFPrinTA(char c)
{	

	if ('A' == c)
	{
		printf("A pressed\n");
		return 1;
	}
	if ('T' == c)
	{
		printf("T pressed\n");
		return 1;
	}
	if (27 == c)
	{
		return 0;
	}
}

static void Menu()
{
	char c=0;
	int flag= 0;

	do
	{
		printf("please enter 1 charcther\n");
		c= getchar();
		flag= IFPrinTA(c);
	}
	while( 0 != flag);
}


int main()
{
	system("stty -icanon -echo");
	Menu();
	system("stty icanon echo");

	return 0;
}

