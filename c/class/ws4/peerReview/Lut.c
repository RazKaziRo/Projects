/**************************************************************************************
			Ws04 - LUT
			Ben Zaad
			11.11.19
			revirewer- the legendary Raz KaziRo
**************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int Printchar(char ch)
{
	printf("%c pressed \n", ch);
	return 1;

}

int Terminate(char ch)
{
	return 0;
}

int Invalid(char ch)
{
	printf("Invalid key entered. please try again\n");
	return 1;
}

/*Initiation and setting up of the look up table*/
void LutInit( int (*LUT[])(char) )
{
	int i=0;

	for (i=0; i <= 256; i++)
	{
		LUT[i]= &Invalid;
	}
	LUT[65]= &Printchar;
	LUT[84]= &Printchar;
	LUT[27]= &Terminate;
}
 
/*keep geting char values from stdin and sending them to the LUT*/ 
int LutMenu( int (*LUT[])(char))
{
	char c= 1;	
	
	printf("please enter a char\n");
	do
	{
		c= getchar();
	}
	while ((*LUT[c])(c));
	
}

int main()
{
	int (*LUT[256])(char);

	system("stty -icanon -echo");
	LutInit(LUT);
	LutMenu(LUT);
	system("stty icanon echo");

return 0;
}