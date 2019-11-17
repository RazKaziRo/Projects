/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW6 - Bitwise Operations.
 * Date: 13.11.2019
 * Language: C
 * Reviewer: 
 */

#ifndef _ws6func_h
#define _ws6func_h
#include <stdio.h>


long BitWisePow2(unsigned int x, unsigned int y);
int IsPowOf2NoLoop(unsigned int n);
int IsPowOf2Loop(unsigned int n);
int AddOneToInt(int n);
void ThreeBitsOn(unsigned int n[], int size);
int TwoANDSixON(const unsigned char ch);
int TwoORSixON(const unsigned char ch);
unsigned int ClosestDivideBySixteen(const unsigned int n);
void SwapTwoVariables(unsigned int *x,unsigned int *y);
int CountSetOfBitsLoop(unsigned int n);
int CountSetOfBitsNOLoop(unsigned int n);


#endif