/**************************************************************************************
			Ws09 
			Ben Zaad
			24.11.19
			revirewer- Raz
**************************************************************************************/
#include "mem.h"

#define NRM "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"

#define WORD 8
#define CHAR 65 

void Test(int condition, char* err_message)
{
    if(1 == condition)
    {
        printf("\033[0;32m"); 
        printf("SUCCESS\n");
    }
    else
    {
        printf("\033[0;31m");
        printf("FAIL - %s\n", err_message);
    }
    printf("\033[0m"); 
}

int main()
{
    int x = 4660;
    
    char arr1[4] = {'a', 'g', 'b', 'c'};
    char arr2[6] = {'a', 'c', 'b', 'l', 's', 'h'};
    char arr3[5] = {'b', 'c', 'm', 'r', 'd'};
    
    char *str1, *str2, *str3, *str4, *str5, *str6, *str7, *str8;
    
    str1 = (char*) malloc(31);
    str2 = (char*) malloc(12);
    str3 = (char*) malloc(16);
    str4 = (char*) malloc(11);
    str5 = (char*) malloc(11);
    str7 = (char*) malloc(8);
    str8 = (char*) malloc(13);    
    
    strcpy(str1, "abcdefghijklmnopqrstuvwxyz");
    strcpy(str2, "hello world");
    strcpy(str3, "abcdefghijklmno");
    strcpy(str4, "abcdefghijklmno");
    strcpy(str5, "0123456789");
    str6 = str3+5;
    strcpy(str7, "abcdefg"); 
    strcpy(str8, "abcdefghijk");
    
    printf("Check 3 Arrays: ");
    TwoGoodToBeThree(arr1, arr2, arr3);
    
    printf("MyMemset: ");
    Test(0 == strcmp((char*)MyMemSet(str1, CHAR, 25) ,(char*)MyMemSet(str1, CHAR, 25)), "");
    
    printf("MyMemcpy: ");
    Test(0 == strcmp((char*)MyMemCpy(str8, str7, 4) ,(char*)memcpy(str8, str7, 4)), "");
    
    printf("MyMemmove: ");
    Test(0 == strcmp((char*)MyMemMove(str3+1, str3, 8) ,(char*)memmove(str4+1, str4, 8)), "");
    
    free(str1);
    free(str2);
    free(str3);
    free(str4);
    free(str5);
    free(str7);
    free(str8);
    

	return 0;
}