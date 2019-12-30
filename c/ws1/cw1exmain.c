/*
 * Author: Raz KaziRo
 * Purpose: Answares for CW1 - Exersice Section.
 * Language:  C
 */

#include <stdio.h>
#include "ex3.c"
#include "ex4.c"
#include "ex5.c"
#include "ex6.c"

int main()
{

	int num, x, y;

	printf ("\nResult of EX3 - Print \"Hello World!:\"\n");		/* Exersice 3 - Prints "Hello World!" > require ex3.c */	
        helloworld(); 							

	printf("\n***********************************\n\n");

	printf("Input Number to 10^number:");				/* Exersice 4 - 10^num* > require ex4.c */ 
	scanf("%d", &num);
	printf("10^%d = %lf\n",num, pow_to10(num));			
				
	printf("\n***********************************\n\n");

	printf("Input Number to flip: ");	
	scanf("%d", &num);
	printf("The Reverce Number of %d is: %d\n", num, flips(num));	/* Exersice 5 - Flips Number (12340 flip into 4321) > require ex5.c */

	printf("\n***********************************\n\n");	
	
	x=5; y=6;							/* Exersice 6 - Swap 2 Variables (x=y y=x) require > ex6.c */
	printf("Result of EX6 - Swap 2 Variables (x=y y=x):\n");
	printf("Befor Swap x=%d y=%d\n",x,y);
	swap(&x,&y);							
	printf("After Swap: x=%d y=%d\n",x,y);

return 0;

}

