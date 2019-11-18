/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW6 - Bitwise Operations.
 * Date: 17.11.2019
 * Language: C
 * Reviewer: Israel Drayfus
 */

#ifndef _ws6func_h
#define _ws6func_h
#include <stdio.h>

#define NO_OF_BITS sizeof(num) * 8
#define  m1   0x55555555 /* binary: 0101...*/
#define  m2   0x33333333 /* binary: 0011...*/
#define  m3	  0xaaaaaaaa /* binary: 1010 1010...*/
#define  m4   0x0f0f0f0f /*binary:  0000 1111 ...*/
#define  m5	  0xcccccccc /* binary: 1100 1100...*/
#define  m6   0xf0f0f0f0 /*binary:  1111 0000 ...*/
#define  m7   0xff00ff00 /*binary:  1111 1111 0000 0000  ...*/
#define  m8   0x00ff00ff /*binary:  8 zeros,  8 ones ...*/
#define  m9   0x10101010 /*binary:  8 zeros,  8 ones ...*/
#define  m10  0x01010101 /*binary:  8 zeros,  8 ones ...*/
#define  m16  0x0000ffff /*binary: 16 zeros, 16 ones ...*/

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
void PrintFloat(float num);
int PrintBit(int a, int loc);



#endif