#include <stdlib.h>

#include "utilities.h" /* RUN_TEST */
#include "calculator.h"

static void TestAdd()
{
    char add[] = ".2+3";
    double result = 0;
    
    printf("Add:\n");
    RUN_TEST(0 == Calculator(add, &result));
    RUN_TEST(3.200000 == result);
}

static void TestSub()
{
    char sub[] = "100-30-20";
    double result = 0;
    
    printf("\nSub:\n");
    RUN_TEST(0 == Calculator(sub, &result));
    RUN_TEST(50.000000 == result);
}

static void TestMult()
{
    char mult[] = "8*4";
    double result = 0;
    
    printf("\nMult:\n");
    RUN_TEST(0 == Calculator(mult, &result));
    RUN_TEST(32.000000 == result);
}

static void TestDiv()
{
    char div[] = "1/4/2";
    double result = 0;
    
    printf("\nDiv:\n");
    RUN_TEST(0 == Calculator(div, &result));
    RUN_TEST(0.125000 == result);
}

static void TestPower()
{
    char pow[] = "2^3^2+2+3";
    double result = 0;
    
    printf("\nPow:\n");
    RUN_TEST(0 == Calculator(pow, &result));
    RUN_TEST(517.000000 == result);
}

static void TestComplex()
{
    char complex1[] = "(2+7)*6+5";
    double result = 0;
    
    printf("\nComplex:\n");
    RUN_TEST(0 == Calculator(complex1, &result));
    RUN_TEST(59.000000 == result);
}

static void TestSpaces()
{
    char spaces[] = "  2+5";
    double result = 0;
    
    printf("\nSpaces:\n");
    RUN_TEST(0 == Calculator(spaces, &result));
    RUN_TEST(7.000000 == result);
}

static void TestSyntaxError()
{
    char invalid1[] = "24*/8", invalid2[] = "5-", invalid3[] = "((2^3)))+3)";
    double result = 0;
    
    printf("\nSyntaxError:\n");
    RUN_TEST(2 == Calculator(invalid1, &result));
    RUN_TEST(2 == Calculator(invalid2, &result));
    RUN_TEST(0 == Calculator(invalid3, &result));
}

int main()
{    
    TestAdd();
    TestSub();
    TestMult();
    TestDiv();
    TestPower();
    TestComplex();
    TestSpaces();
    TestSyntaxError();    
     
    return 0;
}
