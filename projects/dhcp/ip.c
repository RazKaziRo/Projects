#include <string.h> /*memcpy*/
#include <math.h> /*pow*/
#include "ip.h"


static void ByteToBinaryString(unsigned char byte, char *buffer)
{
	size_t i = BITS_IN_BYTE;

	for(;i > 0; --i)
	{
		*(buffer + i - 1) = (byte % 2) + 48;
		 byte = byte / 2;
	}
}

void IPToBinaryString(ip_t ip, char *buffer)
{	
	size_t i = 0;

	for(; i < BYTES_IN_IP_ADDRESS; ++i)
	{
		ByteToBinaryString(ip.address[i], buffer + i * BITS_IN_BYTE);
	}

	*(buffer + BITS_IN_IP_ADDRESS) = '\0';
}

static void BinaryStringToByte(char *buffer, unsigned char *ip) 
{
	size_t i = BITS_IN_BYTE;
	double ch = 0;

	for(;i > 0; --i)
	{
		if('1' == *(buffer + i - 1))
		{
			ch += pow(2, i - 1);
		}	
	}

	*ip = ch;
}

void BinaryStringToIP(char *buffer, ip_t *ip)
{	
	size_t i = 0;

	for(;i < BYTES_IN_IP_ADDRESS; ++i) /*4*/
	{
		BinaryStringToByte(buffer + (i * BITS_IN_BYTE), &ip->address[i]);
	}
	
}
