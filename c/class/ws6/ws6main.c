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
		printf("SUCCESS\n");
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



/* Q1 - Following Code */
	/*
	unsigned int x = 5;
	printf("%u,%u,%u", x, x<<2, x>>2);
	*/

/* EX 10 Count Set Of Bit No loop */

/*
	Test(5 == CountSetOfBitsNOLoop(796), "FAILED: Wrong Bit Counting");
	Test(12 == CountSetOfBitsNOLoop(4567891), "FAILED: Big Numger Bit Counting");
	Test(0 == CountSetOfBitsNOLoop(0), "FAILED: Equal To 0");
	Test(7 == CountSetOfBitsNOLoop(127), "FAILED: All Bit On");
*/

/* EX 9 - Count Set Of Bit Using Loop
	Test(5 == CountSetOfBitsLoop(796), "FAILED: Wrong Bit Counting");
	Test(12 == CountSetOfBitsLoop(4567891), "FAILED: Big Numger Bit Counting");
	Test(0 == CountSetOfBitsLoop(0), "FAILED: Equal To 0");
	Test(7 == CountSetOfBitsLoop(127), "FAILED: All Bit On");

unsigned int num1 = 6;
unsigned int num2 = 9;
unsigned int *ptr_num1 = &num1;
unsigned int *ptr_num2 = &num2;

printf("Before:\nx = %d, y = %d \n", *ptr_num1, *ptr_num2);
SwapTwoVariables(ptr_num1, ptr_num2);
printf("After:\nx = %d, y = %d \n", *ptr_num1, *ptr_num2);

*/

/*	E7 - Smallest Divided By 16 */
/*
	Test(32 == ClosestDivideBySixteen(33), "FAILED: More then 16");
	Test(32 == ClosestDivideBySixteen(32), "FAILED: Equal To 32");
	Test(0 == ClosestDivideBySixteen(0), "FAILED: 0");
	Test(16 == ClosestDivideBySixteen(16), "FAILED: Equal To 16");
	Test(0 == ClosestDivideBySixteen(8), "FAILED: Less Then 16");

*/
/*	
	E6.3 - Swap Bit 3 And 5
*/

/*
	printf("%d", SwapThreeAndFiveBits(647));
*/

/*E6.2 - Check Bits 6 | 2 Is on*/

/*
	Test(1 == TwoORSixBitON(35), "FAILED: 6&2 Is ON");
	Test(0 == TwoORSixBitON(65), "FAILED: 6&2 Is Off");
	Test(1 == TwoORSixBitON(18), "FAILED: 2 Is On 6 Is Off");
	Test(1 == TwoORSixBitON(36), "FAILED: 6 Is On 2 Is Off");
	Test(0 == TwoORSixBitON(0), "FAILED: 0");
	Test(1 == TwoORSixBitON(-86), "FAILED: Negative 6&2 Is ON");
*/
	/*E6.1 - Check Bit 2&6 Is on*/

/*
	Test(1 == TwoANDSixBitON(35), "FAILED: 6&2 Is ON");
	Test(0 == TwoANDSixBitON(12), "FAILED: 6&2 Is Off");
	Test(0 == TwoANDSixBitON(18), "FAILED: 2 Is On 6 Is Off");
	Test(0 == TwoANDSixBitON(36), "FAILED: 6 Is On 2 Is Off");
	Test(0 == TwoANDSixBitON(0), "FAILED: 0");
	Test(1 == TwoANDSixBitON(-86), "FAILED: Negative 6&2 Is ON");

*/	


/* EX5 - ByteMirror */

/*

Test(1677721600 == ByteMirrorLoop(38), "FAILED: Wrong Mirror/Reverse");
Test(0 == ByteMirrorLoop(0), "FAILED: 0 Mirror");
Test(2147483648 == ByteMirrorLoop(1), "FAILED: 1 Mirror");
*/


/*
	Test(1677721600 == ByteMirrorNOLoop(38), "FAILED: Wrong Mirror/Reverse");
	Test(0 == ByteMirrorNOLoop(0), "FAILED: 0 Mirror");
	Test(2147483648 == ByteMirrorNOLoop(1), "FAILED: 1 Mirror");

*/
/* E4 - Print Only is 3 bits is on */
	/*
	unsigned int arr[] = {11,2,3,4,13,2567,7,19,2561,0};
	int size = 10;
	ThreeBitsOn(arr, size);

	*/

	/* E3 */
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