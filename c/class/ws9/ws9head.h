#include <stdio.h> /*size_t*/

#ifndef _WS9HEAD_H_
#define _WS9HEAD_H_

void *MyMemset(void *s, int c, size_t n);
size_t FillChunk (int c);
void FillLessThenChunk(char *str_ptr,int intput_char, size_t times_to_fill);
int MyAtoi(const char *nptr);
char* MyItoa(int num, char* buffer, int base);


#endif