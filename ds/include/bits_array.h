/*
 * Author: Raz KaziRo
 * Purpose: Answares for DSWS1 - Bits Array.
 * Date: 25.11.2019
 * Language: C
 * Reviewer: 
 */
typedef enum 
{
	TURN_ON,
	TURN_OFF
} BIT_SET_T;

#ifndef __BITS_ARRAY_H__
#define __BITS_ARRAY_H__

#include <stdio.h> /* size_t */

void SetAll(size_t *bits_arr);
void ResetAll(size_t *bits_arr);

int IsOn(size_t *bits_arr, int bit_position);
int IsOff(size_t *bits_arr, int bit_position);

int CountOff(size_t *bits_arr);
int CountOn(size_t *bits_arr);

void SetOn(size_t *bits_arr, int bit_position);
void SetOff(size_t *bits_arr, int bit_position);
void SetBit(size_t *bits_arr, int bit_position, BIT_SET_T state);

void FlipBit(size_t *bits_arr, int bit_position);

void RotateLeft(size_t *bits_arr, int times_to_rotate);
void RotateRight(size_t *bits_arr, int times_to_rotate);

char *ToString(size_t *bits_arr);

void Mirror(size_t *bits_arr);

#endif