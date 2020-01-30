#ifndef __IP_H__
#define __IP_H__

#define BYTES_IN_IP_ADDRESS 4
#define BITS_IN_IP_ADDRESS 32
#define BITS_IN_BYTE 8

typedef enum BIT_STATE
{ 
    OFF,
    ON
} bit_state_t;

typedef struct IP_T
{ 
	unsigned char address[BYTES_IN_IP_ADDRESS]; 
} ip_t;

void IPToBinaryString(ip_t ip, char *buffer);

void BinaryStringToIP(char *buffer, ip_t *ip);

void IPSetAvilableBits(char *binary_ip_address, size_t num_of_reserved_bits, bit_state_t state);

#endif