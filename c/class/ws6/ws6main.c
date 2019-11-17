/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW6 - Bitwise Operations.
 * Date: 13.11.2019
 * Language: C
 */

#include "ws6head.h"

void Test(int condition, const char *msg)
{
	if (condition)
	{
		printf("\033[0;32m");
		printf("SUCCESS \n");
 		printf("\033[0m");
	}
	else
	{
		printf("\033[1;31m");
		printf("%s \n",msg);
		 printf("\033[0m");
	}
}

int main()
{

/* Q9 - Count Set Of Bit With Loop
	Test(1 == CountSetOfBits(32), "FAILED: Wrong Bit Counting");
	Test(12 == CountSetOfBits(4567891), "FAILED: Big Numger Bit Counting");
	Test(0 == CountSetOfBits(0), "FAILED: Equal To 0");
	Test(7 == CountSetOfBits(127), "FAILED: All Bit On");

*/

/*

unsigned int num1 = 6;
unsigned int num2 = 9;
unsigned int *ptr_num1 = &num1;
unsigned int *ptr_num2 = &num2;

printf("Before:\nx = %d, y = %d \n", *ptr_num1, *ptr_num2);
SwapTwoVariables(ptr_num1, ptr_num2);
printf("After:\nx = %d, y = %d \n", *ptr_num1, *ptr_num2);
*/

/*	Q7 - Smallest Divided By 16

	Test(32 == DivideBySixteen(33), "FAILED: More then 16");
	Test(32 == DivideBySixteen(32), "FAILED: Equal To 32");
	Test(0 == DivideBySixteen(0), "FAILED: 0");
	Test(16 == DivideBySixteen(16), "FAILED: Equal To 16");
	Test(0 == DivideBySixteen(8), "FAILED: Less Then 16");
	Test(0 == DivideBySixteen(-86), "FAILED: Negative -86");
*/

/*	

	Test(0 < TwoANDSixON(35), "FAILED: 6&2 Is ON");
	Test(0 == TwoANDSixON(12), "FAILED: 6&2 Is Off");
	Test(0 == TwoANDSixON(18), "FAILED: 2 Is On 6 Is Off");
	Test(0 == TwoANDSixON(36), "FAILED: 6 Is On 2 Is Off");
	Test(0 == TwoANDSixON(0), "FAILED: 0");
	Test(0 < TwoANDSixON(-86), "FAILED: Negative 6&2 Is ON");

*/


	/* Q4 */
	/*
	unsigned int arr[] = {11,2,3,4,13,2567,7,19,2561,0};
	int size = 10;
	ThreeBitsOn(arr, size);

	*/

	/* Q3 */
/*

	int n = -4;
	int x = 1;

	printf("Result: %d \n",AddOneToInt(n));
*/

	/* Q1 */
	/*
	long int x = 3;
	long int y = 3;
	long int result = 0;

	result = Pow2(x,y);

	printf("Result: %lu \n",result);
	*/

	/*
	unsigned int foo = 42;
	unsigned int bar = 57;
	unsigned int quux = 0;
	
	printf("\n***********AND*************\n\n");

	printf("42 in binary: 0 0 1 0 1 0 1 0\n");
	printf("57 in binary: 0 0 1 1 1 0 0 1\n");
	printf("42 & 57 in  : 0 0 1 0 1 0 0 0\n");

	printf("\n***********OR**************\n\n");

	printf("42 in binary: 0 0 1 0 1 0 1 0\n");
	printf("57 in binary: 0 0 1 1 1 0 0 1\n");
	printf("42 | 57     : 0 0 1 1 1 0 1 1\n");

	printf("\n***********XOR***************\n\n");

	printf("42 in binary: 0 0 1 0 1 0 1 0\n");
	printf("57 in binary: 0 0 1 1 1 0 0 1\n");
	printf("42 ^ 57     : 0 0 0 1 0 0 1 1\n");

	printf("\n***********NOT***************\n\n");

	printf("42 in binary: 0 0 1 0 1 0 1 0\n");
	printf("~42 in      : 1 1 0 1 0 1 0 1\n");

	printf("\n*****************************\n\n");

	printf("42 in binary: 0 0 1 0 1 0 1 0\n");
	printf("42<<1 in    : 0 1 0 1 0 1 0 0\n");

	printf("\n*****************************\n\n");

	printf("42 in binary: 0 0 1 0 1 0 1 0\n");
	printf("42>>1 in    : 0 0 0 1 0 1 0 1\n");

	printf("\n*****************************\n\n");

*/
	return 0;
}