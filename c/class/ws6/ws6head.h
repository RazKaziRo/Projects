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


unsigned long BitWisePow2(unsigned int x, unsigned int y);
int IsPowOf2NoLoop(unsigned int n);
int IsPowOf2Loop(unsigned int n);
unsigned int AddOneToInt(unsigned int n);
void ThreeBitsOn(unsigned int n[], int size);
unsigned int ByteMirrorLoop(unsigned const int n);
unsigned int ByteMirrorNOLoop(unsigned const int n);
unsigned int SwapThreeAndFiveBits(unsigned int num);
unsigned int TwoANDSixBitON(const unsigned char ch);
unsigned int TwoORSixBitON(const unsigned char ch);
unsigned int ClosestDivideBySixteen(const unsigned int n);
void SwapTwoVariables(unsigned int *x,unsigned int *y);
unsigned int CountSetOfBitsLoop(unsigned int n);
unsigned int CountSetOfBitsNOLoop(unsigned const int n);


#endif