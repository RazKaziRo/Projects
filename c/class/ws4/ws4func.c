/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW4 - Functions.
 * Date: 11.11.2019
 * Language:  C
 * 
 */

#include <stdio.h>
#include <stdlib.h> 			/*Import system() */
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
	int ch;

	printf("Enter T/A or ESC to quit:(If) \n");
	ch = getchar();

	while( 27 != ch )			/*Esc Character */
	{

		if(ch == 65 || ch==97)
		{
			printf("A pressed\n");
			ch = getchar();
		}

		else if(ch == 84 ||ch == 116)
		{
			printf("T pressed\n");
			ch = getchar();
		}	
		else
		{
			printf("Wrong Key Pressed\n");
			ch = getchar();
		}
	} 
	
}

void MySwitchLutOfFunctions()
{
	int ch;

	printf("Enter T/A or ESC to quit:(Switch) \n");
	ch = getchar();

	while( 27 != ch )
	{
		switch(ch)
		{
			case 65 : case 97:
			
				printf("A pressed\n");
				ch = getchar();
				break;

			case 84: case 116:
			{
				printf("T pressed\n");
				ch = getchar();
				break;
			}

			default:
			{
				printf("Wrong Key Pressed\n");
				ch = getchar();
				break;
			}
		}
	}

	
}
