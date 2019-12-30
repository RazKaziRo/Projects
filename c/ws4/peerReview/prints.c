/**************************************************************************************
			Ws04 - Switch Case
			Ben Zaad
			11.11.19
			revirewer- the legendary Raz KaziRo
**************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void SwitchPrinTA(char c)
{

	switch (c)
{
	case ('A'):
		printf("A pressed\n");
		break;
	case ('T'):
		printf("T pressed\n");
		break;
	case (27):
		break;
	default :
		printf("invalid input, please try again\n");
		break;
}
}

static void Menu() 
{
	char c=0;
	printf("please enter 1 charcther\n");
	do
	{
		c= getchar();
		SwitchPrinTA(c);
	}
	while( 27 != c);
}

int main()
{
	system("stty -icanon -echo");
	Menu();
	system("stty icanon echo");

	return 0;
}

