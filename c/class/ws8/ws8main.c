#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ws8head.h"

#define MAX2(a,b) 		    a>b ? a : b
#define MAX3(a,b,c) 	    a>b ? MAX2(a,c) : MAX2(b,c)
#define SIZEOF_VAR(var)     (char *)(&var + 1) - (char *)(&newvar)
#define SIZEOF_TYPE(type)   (size_t)(1 + ((type*)0)+1)
#define MYPRINT(a,b)           printf("%s%d\n",a,b);


int main()
{ 

    StructInfrastructure();

    /*
        StructInfrastructure();

    void *raztheking = NULL;
    int num = 1230;
    int x = CountDigitsOfInt(num);
    raztheking = "Hello World";
    
    printf("%ld", sizeof(raztheking));
    void *data = NULL;
    int x = 10;

    *((float *)(&data)) = 2.5;
    addPtr(&data, x);
   
    printf("%f \n",  *((float *)(&data)));


    StructInfrastructure();

    void *ptr = NULL;
    int x = 10;
    *((float *)(&ptr)) = 2.5;

    PrintFloat(ptr);
    AddToFloat(ptr, x);
    PrintFloat(ptr);
    */


/* Test Print Functions */
/*
    void *ptr = "hello";
    PrintChar(ptr);

    *((float *)(&ptr)) = 2.5;
    PrintFloat(ptr);

    *((int *)(&ptr)) = 10;
    PrintInt(ptr);
*/


   
    /*printf("%p \n", ptr);*/
  
  
   /* printf("SIZEOF_TYPE %ld",SIZEOF_TYPE(int));*/
    /*
	printf("SIZEOF_VAR:  %ld\n", SIZEOF_VAR(s));
	printf("MAX2(2,19): %d \n", MAX2(2,19));
	printf("MAX3(1,8,5): %d \n", MAX3(1,8,5));
*/
    /*printf("%ld \n", (size_t)(((int*)0)+1));*/

	return 0;
}