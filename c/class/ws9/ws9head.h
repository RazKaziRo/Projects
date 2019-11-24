/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW9 - Word Boundry Optimization.
 * Date: 22.11.2019
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#ifndef _WS9HEAD_H_
#define _WS9HEAD_H_

#include <stdio.h> /*size_t*/

typedef struct 
{
	char ascii_code;
	int status;

}ascii_t;

void *MyMemSet(void *s, int c, size_t n);
void *MyMemCpy(void *dest, const void *src, size_t n);
void *MyMemMove(void *dest, const void *src, size_t num_of_chars_to_cpy);
int MyAtoi(const char *nptr);
char* MyItoa(int num, char* buffer, int base);
void CharSwap(char *x, char *y);
void isLittleEndian(int x);
void InFirstTwoArrNotThird(char *arr1, int size_arr1, char *arr2, int size_arr2, char *arr3, int size_arr3);

#endif