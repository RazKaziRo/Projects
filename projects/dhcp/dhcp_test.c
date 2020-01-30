#include <stdio.h> /*printf()*/

#include "dhcp.h"
#include "ip.h"

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

void TestDhcpCreate()
{
	
	size_t reserved = 23;

	ip_t subnet_mask;
	subnet_mask.address[0] = 255;
	subnet_mask.address[1] = 255;
	subnet_mask.address[2] = 254;
	subnet_mask.address[3] = 0;

	DhcpCreate(subnet_mask, reserved);

}

int main(int argc, char const *argv[])
{
	TestDhcpCreate();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}