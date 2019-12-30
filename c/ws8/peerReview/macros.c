#include <stdio.h>

#define MAX2(a, b) (a > b) ? a : b
#define MAX3(a, b, c) (a+b) < c ? c : (a > b) ? a : b

#define SIZEOF_VAR(x) (char* )(&(x)+ 1) - (char* )(&x)
#define SIZEOF_TYPE(type) (size_t)(1 + (type*)0) 


int main()
{
    int x = 2;
    
    printf("max(3,9) = %d\n" , MAX2(3, 9));
    printf("max(3,4,1) = %d\n" , MAX3(3, 4, 1));
    printf("size of x = %ld\n" , SIZEOF_VAR(x));
    printf("size of x = %ld\n" , SIZEOF_TYPE(double));
    return 0;
}
