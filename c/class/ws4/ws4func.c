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
	int ch = 0;

	printf("Enter T/A or ESC to quit:(If) \n");

	while( 27 != ch )			/*Esc Character */
	{
		ch = getchar();	
		if(ch == 65 || ch==97)
		{
			printf("A pressed\n");
		}

		else if(ch == 84 ||ch == 116)
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

	while( 27 != ch )
	{
		ch = getchar();
		switch(ch)
		{
			case 65 : case 97:
			
				printf("A pressed\n");
				break;

			case 84: case 116:
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
