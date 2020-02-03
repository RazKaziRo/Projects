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
	ip_t subnet_mask;
	ip_t requested_ip253;
	ip_t requested_ip254;
	ip_t allocated_ip;

	dhcp_t *new_dhcp = NULL;

	subnet_mask.address[0] = 255;
	subnet_mask.address[1] = 255;
	subnet_mask.address[2] = 255;
	subnet_mask.address[3] = 252;

	requested_ip253.address[0] = 255;
	requested_ip253.address[1] = 255;
	requested_ip253.address[2] = 255;
	requested_ip253.address[3] = 253;

	requested_ip254.address[0] = 255;
	requested_ip254.address[1] = 255;
	requested_ip254.address[2] = 255;
	requested_ip254.address[3] = 254;

	printf("TestDhcpCreate(): \n");

	new_dhcp = DhcpCreate(subnet_mask, 30);
	RUN_TEST(2 == DhcpCountFree(new_dhcp), "FAIL: WRONG COUNT FREE (2)");

	DhcpAllocIp(new_dhcp, &requested_ip253, &allocated_ip);
	RUN_TEST(1 == DhcpCountFree(new_dhcp), "FAIL: WRONG COUNT FREE (1)");
	DhcpAllocIp(new_dhcp, &requested_ip254, &allocated_ip);

	RUN_TEST(0 == DhcpCountFree(new_dhcp), "FAIL: WRONG COUNT FREE (0)");

	DhcpDestroy(new_dhcp);

	printf("\n");

}

void TestDhcpAllocIp()
{
	
}

int main(int argc, char const *argv[])
{
	TestDhcpCreate();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}