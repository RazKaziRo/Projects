/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW4 - Functions.
 * Date: 11.11.2019
 * Language: C
 * Reviewer: Yonatan Zaken
 */

#include <stdio.h>
#include <stdlib.h> 			/* Import system()  */
#include <ctype.h>              /* Import toupper() */
#include "ws4head.h"

void stopBuffer()
{
	system("stty -icanon -echo");
}

void resumeBuffer()
{
	system("stty icanon echo");
}


void MyIfLutOfFunctions()
{
	int ch = 0;

	printf("Enter T/A or ESC to quit:(IF/ELSE) \n");

	while( 27 != ch )			          /*'Esc' Character */
	{
		ch = getchar();	
		if(ch == 65 || ch == 97)           /*'A' OR 'a' */
		{
			printf("A pressed\n");
		}

		else if(ch == 84 ||ch == 116)       /*'T' OR 't' */
		{
			printf("T pressed\n");
		}	
		else
		{
			printf("Wrong Key Pressed\n");
		}
	} 
	
}

void MySwitchLutOfFunctions()
{
	int ch = 0;

	printf("Enter T/A or ESC to quit:(Switch) \n");

	while( 27 != ch )                        /*'Esc' Character */
	{
		ch = getchar();
		switch(ch)
		{
			case 65 : case 97:               /*'A' OR 'a' */
			{
				printf("A pressed\n");
				break;
			}

			case 84: case 116:               /*'T' OR 't' */
			{
				printf("T pressed\n");
				break;
			}

			default:
			{
				printf("Wrong Key Pressed\n");
				break;
			}
		}
	}

	
}

void MyLutOfFunctions()
{
	int ch = 0;
    int i = 0;
	int (*funcarr[256])(int);

	while(i<256)
	{
		funcarr[i] = &WrongChar;    		/*Set wrong char result */
		++i;
	}

	funcarr[27] = &EscChar;					/*Esc*/
	funcarr[97] = &CurrectCharPrint;		/*A*/
	funcarr[65] = &CurrectCharPrint;		/*a*/
	funcarr[84] = &CurrectCharPrint;		/*t*/
	funcarr[116] = &CurrectCharPrint;		/*T*/
			

    printf("Enter T/A or ESC to quit:(LUT) \n");
	ch = getchar();

	while ((*funcarr[ch])(ch))
	{
		ch = getchar();
	}

}

int CurrectCharPrint(const int ch) 
{ 
    printf("%c pressed\n", toupper(ch));

return 1;
} 

int WrongChar(const int ch) 
{ 
	printf("Wrong Key Pressed \n");
	
	return 1;
}

int EscChar(const int ch) 
{ 
    return 0;
} 

