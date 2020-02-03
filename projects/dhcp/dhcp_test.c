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

unsigned char flipByte(unsigned char c)
{
    c = ((c>>1)&0x55)|((c<<1)&0xAA);
    c = ((c>>2)&0x33)|((c<<2)&0xCC);
    c = (c>>4) | (c<<4);

    return c;
}

void TestDhcpCreate()
{
	size_t reserved = 30;
	dhcp_t *new_dhcp = NULL;
	ip_t subnet_mask;
	ip_t requested_ip;
	ip_t allocated_ip;
	unsigned char *ip_address = allocated_ip.address;

	subnet_mask.address[0] = 255;
	subnet_mask.address[1] = 255;
	subnet_mask.address[2] = 255;
	subnet_mask.address[3] = 252;


	requested_ip.address[0] = 255;
	requested_ip.address[1] = 255;
	requested_ip.address[2] = 255;
	requested_ip.address[3] = 253;


	new_dhcp = DhcpCreate(subnet_mask, reserved);
	DhcpAllocIp(new_dhcp, requested_ip, allocated_ip);

	DhcpAllocIp(new_dhcp, requested_ip, allocated_ip);


}

int main(int argc, char const *argv[])
{
	TestDhcpCreate();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}