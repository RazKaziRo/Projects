/*
 * Author: Raz KaziRo
 * Purpose: Tests for Recursion.
 * Date: 14.01.2020
 * Language: C
 * Reviewer: 
 */

#include <stdio.h> 	/*printf()*/
#include <string.h> /*strlen()*/
#include <time.h> 	/*clock()*/

#include "recursion.h"

static clock_t start, end;
static double cpu_time_used;

#define RUN_TEST(test, errmsg)\
							{\
								if(test)\
								{\
									printf("SUCCESS\n");\
								}\
								else\
								{\
									printf("\033[1;31m");\
									printf("%s \n", errmsg);\
									printf("\033[0m");\
								}\
							}
#define UNUSED(x) (void)(x)

void TestRecursiveFibonacci()
{	
	printf("TestRecursiveFibonacci():\n");
	RUN_TEST(8 == RecursiveFibonacci(6), "FAIL: WRONG FIB(6)");

	start = clock();
	RecursiveFibonacci(50);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("RecursiveFibonacci(6) took %f seconds to execute \n", cpu_time_used); 

	printf("\n");
}

void TestIterativeFibonacci()
{	
	printf("TestIterativeFibonacci():\n");
	RUN_TEST(2 == IterativeFibonacci(3), "FAIL: WRONG FIB (6)");

	printf("\n");
}

void TestRecursiveStrLen()
{	
	char *s1 = "Hello World";

	printf("TestRecursiveStrLen():\n");
	RUN_TEST(strlen(s1) == RecursiveStrLen(s1), "FAIL: WRONG STRLEN(str1)")

	start = clock();
	RecursiveStrLen(s1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("RecursiveStrLen() took %f seconds to execute \n", cpu_time_used); 

    start = clock();
	strlen(s1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("strlen() took %f seconds to execute \n", cpu_time_used); 

	printf("\n");
}

void TestRecursiveStrCmp()
{
	char *s1 = "a";
	char *s2 = "w";

	printf("RecursiveStrCmp(s1, s2): %d \n", RecursiveStrCmp(s1, s2));
	printf("strcmp(s1, s2): %d \n", strcmp(s1, s2));
}

void TestRecursiveStrCpy()
{
	char *src = "Hello";
	char dest[80] = "World";

	RUN_TEST(0 == strcmp(strcpy(dest, src), RecursiveStrCpy(dest, src)),"FAIL: strcmp FAIL")
}

void TestRecursiveStrCat()
{
	char *src = "";
	char dest[80] = "";

	char *src2 = "";
	char dest2[80] = "";

	RUN_TEST(0 == strcmp(strcat(dest2, src2), RecursiveStrCat(dest, src)),"FAIL: strcmp FAIL")
}

void TestRecursiveStrStr()
{
	char *src = "ABCDE";
	char *tofind = "BC"; 

	char *src2 = "ABCDE";
	char *tofind2 = "BC"; 

	char *src3 = "ABCDEF";
	char *tofind3 = "ab"; 

	char *src4 = "ABCDEF";
	char *tofind4 = "ab"; 

	RUN_TEST(0 == strcmp(strstr(src, tofind), RecursiveStrStr(src2, tofind2)),"FAIL: strcmp FAIL")
	RUN_TEST(RecursiveStrStr(src4, tofind4) == strstr(src3, tofind3),"FAIL: strcmp FAIL")
}

void TestRecursiveMultiply()
{	
	int res = recMultiply(5,1);
	printf("%d\n", res);

}

void TestRecursiveDivision()
{	
	int res = recDivision(15,0);
	printf("%d\n", res);

}

void TestBitWiseAddition()
{
	printf("%u \n", BitWiseAddition(28, 1));
}

int main(int argc, char const *argv[])
{

	/*
 	TestRecursiveFibonacci();

	TestIterativeFibonacci();

	TestRecursiveStrLen();

	TestRecursiveStrCmp();
	
	TestRecursiveStrCpy();

	TestRecursiveStrCat();

	TestRecursiveStrStr();
	*/

	TestRecursiveMultiply();

	TestRecursiveDivision();

	TestBitWiseAddition();

	UNUSED(argc);
	UNUSED(argv);
	return 0;
}