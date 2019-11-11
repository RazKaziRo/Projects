/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW4 - Functions.
 * Date: 11.11.2019
 * Language:  C
 * Reviewer : Yonatan Zaken
 */

#include <stdio.h>
#include <stdlib.h> 			/* Import system()  */
#include <ctype.h>              /* Import toupper() */
#include "ws4head.h"

void stopBuffer()
{
	system("stty -icanon -echo");
}

void ResumeBuffer()
{
	system("stty icanon echo");
}


void MyIfLutOfFunctions()
{
	char ch = 0;

	printf("Enter T/A or ESC to quit:(IF/ELSE) \n");

	while( 27 != ch )			          /*'Esc' Character */
	{
		ch = getchar();	
		if(ch == 65 || ch==97)            /*'A' OR 'a' */
		{
			printf("A pressed\n");
		}

		else if(ch == 84 ||ch == 116)     /*'T' OR 't' */
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
	char ch = 0;

	printf("Enter T/A or ESC to quit:(Switch) \n");

	while( 27 != ch )                         /*'Esc' Character */
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
	char ch = 0;
    int i = 0;
	void (*funcarr[256])(char);

	while(i<256)
	{
		funcarr[i] = &WrongChar;
		++i;
	}

	funcarr[97] = &MyPrintChar;		/*A*/
	funcarr[65] = &MyPrintChar;		/*a*/
	funcarr[84] = &MyPrintChar;		/*t*/
	funcarr[116] = &MyPrintChar;	/*T*/

    printf("Enter T/A or ESC to quit:(LUT) \n");

	while(27 != ch)
	{
		ch = getchar();
		(*funcarr[ch])(ch);	
	}

		
}

void MyPrintChar(char ch) 
{ 
    printf("%c pressed\n", toupper(ch));
} 

void WrongChar(char ch) 
{ 
	printf("Wrong Key Pressed \n");
}

