/**************************************************************************************
            Ws09 
            Ben Zaad
            24.11.19
            revirewer- Raz
**************************************************************************************/
#include "mem.h"

#define BITS_IN_BYTE 8

#define INT_SIZE 4
#define ZERO 48
#define A_IN_ASCII 55

#define DIGITS 10

/*gets a string and return an int presentation of it- returns zero for
unint values, undefined over 9 digits */
int MyAtoI(const char *str, int base)
{
    int convertion_res = 0, sign = 0;

    if ('-' == *str)
    {
        ++str;
        sign = 1;
    }
    puts(str);

    if ((1 == strlen(str)) && ( 9+ZERO >= (int)*str))
    {
        return ((int)*str-ZERO);
    }
    else if ((1 == strlen(str)) && ( 9+ZERO <= (int)*str))
    {
        return ((int)*str-A_IN_ASCII);
    }

    while (*(str+1) != '\0')
    {
        convertion_res += (int)*str;
        printf("%d\n", convertion_res);
        if ( 9+ZERO >= (int)*str) 
        {
            convertion_res -= ZERO;
            convertion_res *= base;
        }
        else if ( 9+ZERO <= (int)*str) 
        {
            printf("%d\n", convertion_res);
            convertion_res -= A_IN_ASCII;
            convertion_res *= base;
        }

        printf("%d\n", convertion_res);
        ++str;
    }
    if ( 9+ZERO >= (int)*str)
    {
        convertion_res += (int)*str - ZERO;
    }
    else if (9+ZERO <= (int)*str)
    {
        convertion_res += (int)*str - A_IN_ASCII;
    }
    if (1 == sign)
    {
        return -convertion_res;
    }

    return convertion_res;
}

char* MyItoA(int num, char* buffer, int base)
{
    int counter = 0, sign = 0, len = 0;
    char *buffer_runner = buffer, *header =  buffer;
    char temp = 0;

    if ( 0 > num)
    {
        num= -num;
        sign = 1;
    }

    while (1 <= num)
    {
        if (9 >= num%base)
        {
            *buffer_runner = num%base + ZERO;
        }
        else
        {
            *buffer_runner = num%base + A_IN_ASCII;
        }
        ++buffer_runner;
        num /= base;
        ++counter;
    }
    len = counter;
    *buffer_runner= '\0';
    --buffer_runner;

    while ( 0 < (counter/2))
    {
        temp = *buffer_runner;
        *buffer_runner = *buffer;
        *buffer = temp;
        ++buffer;
        --buffer_runner;
        --counter;
    }
    if (1 == sign)
    {
        memmove(header+1, header, len);
        *header = '-';
    }
    return header;
}