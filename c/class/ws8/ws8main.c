#include <stdio.h>

#define MAX2(a,b) 		a>b ? a : b
#define MAX3(a,b,c) 	a>b ? MAX2(a,c) : MAX2(b,c)


/*#define DECLARE_TYPE(type)  typeof(type) newvar*/
#define SIZEOF_VAR(newvar) (char *)(&newvar + 1) - (char *)(&newvar)
/*#define SIZEOF_TYPE(type)  SIZEOF_VAR(DECLARE_TYPE(type))*/



typedef struct MyStruct
{
    int x;
    char ch;
    float y;

}MyStruct;

int main()
{
    long int x = 4;
    MyStruct s;

   /* printf("SIZEOF_TYPE %ld",SIZEOF_TYPE(int));*/
	printf("SIZEOF_VAR:  %ld\n", SIZEOF_VAR(s));
	printf("MAX2(2,19): %d \n", MAX2(2,19));
	printf("MAX3(1,8,5): %d \n", MAX3(1,8,5));

	return 0;
}