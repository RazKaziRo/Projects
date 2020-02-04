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
	subnet_mask.address[3] = 255;

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
	ip_t subnet_mask;
	ip_t allocated_ip;

	ip_t ip1;
	ip_t ip2;

	dhcp_t *new_dhcp = NULL;

	subnet_mask.address[0] = 255;
	subnet_mask.address[1] = 255;
	subnet_mask.address[2] = 255;
	subnet_mask.address[3] = 240;

	ip1.address[0] = 255;
	ip1.address[1] = 255;
	ip1.address[2] = 255;
	ip1.address[3] = 241;

	ip2.address[0] = 0;
	ip2.address[1] = 0;
	ip2.address[2] = 0;
	ip2.address[3] = 0;


	printf("TestDhcpAllocIp(): \n");

	new_dhcp = DhcpCreate(subnet_mask, 28);
	RUN_TEST(14 == DhcpCountFree(new_dhcp), "FAIL: WRONG COUNT FREE (2)");
	RUN_TEST(IP_AS_REQUESTED == DhcpAllocIp(new_dhcp, &ip1, &allocated_ip),"FAIL: IP NOT AS REQUESTED (IP1)");
	RUN_TEST(IP_NOT_AS_REQUESTED == DhcpAllocIp(new_dhcp, &ip1, &allocated_ip),"FAIL: IP NOT AS REQUESTED (IP1 X2)");
	RUN_TEST(12 == DhcpCountFree(new_dhcp), "FAIL: WRONG COUNT FREE (2)");

	printf("Allocated IP After 241 is taken:\n");
	printf("%d.", allocated_ip.address[0]);
	printf("%d.", allocated_ip.address[1]);
	printf("%d.", allocated_ip.address[2]);
	printf("%d \n", allocated_ip.address[3]);

	RUN_TEST(IP_NOT_AS_REQUESTED == DhcpAllocIp(new_dhcp, &ip2, &allocated_ip),"FAIL: IP NOT AS REQUESTED (IP1 X2)");
	RUN_TEST(11 == DhcpCountFree(new_dhcp), "FAIL: WRONG COUNT FREE (2)");

	printf("Allocated IP After 0.0.0.0 sent:\n");
	printf("%d.", allocated_ip.address[0]);
	printf("%d.", allocated_ip.address[1]);
	printf("%d.", allocated_ip.address[2]);
	printf("%d \n", allocated_ip.address[3]);

	DhcpFreeIp(new_dhcp, ip1);
	RUN_TEST(12 == DhcpCountFree(new_dhcp), "FAIL: WRONG COUNT FREE (2)");

	DhcpDestroy(new_dhcp);

	printf("\n");
}

int main(int argc, char const *argv[])
{
	TestDhcpCreate();

	TestDhcpAllocIp();

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}