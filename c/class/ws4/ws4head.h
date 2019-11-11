/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW4 - Functions.
 * Date: 11.11.2019
 * Language:  C
 * Reviewer : Yonatan Zaken
 */

#ifndef _ws4func_h
#define _ws4func_h


void MyIfLutOfFunctions();				/*Print using if/else*/
void MySwitchLutOfFunctions();			/*Print using Switch*/
void MyLutOfFunctions();				/*Print using LUT*/
int CurrectCharPrint(const int ch);		/*Print the char as set */
int WrongChar(const int ch);  			/*Print if Different char then set */
void stopBuffer();						/*Stop Display User Input in terminal */
void resumeBuffer(); 				   /*Resume Display User Input in terminal */
int EscChar(const int ch);

#endif