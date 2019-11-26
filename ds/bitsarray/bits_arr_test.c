#include "bits_array.h"

#define RUN_TEST(test) 
#define UNUSED(x) (void)(x)

int main(int argc, char const *argv[])
{
	size_t bits = 7UL;

	UNUSED(argc);
	UNUSED(argv);

	printf("%ld \n", bits);
	bits = BArrSetBit(bits,1,0);
	printf("%ld\n", bits);
	
	/*
	printf("before reset: %d\n", BArrIsOff(bits, 1));

	
	bits = BArrResetAllBits(bits);
	printf("after reset: %d\n", BArrIsOff(bits, 1));
	PrintSize_t(bits);
*/
/*
	PrintSize_t(BArrResetAllBits(bits));
	PrintSize_t(BArrSetAllBits(bits));
*/

	return 0;
}



