#include <stdlib.h> /*malloc*/
#include <stdio.h> /*printf()*/

#include "dhcp.h"
#include "trie.h"

#define FREE(ptr) free(ptr); ptr = NULL;

struct DHCP
{
	trie_t *trie;
	ip_t subnet_mask;
	size_t available_bits;
};

static aloc_status_t IMPDhcpReservedAddressAlloc(dhcp_t *dhcp)
{
	ip_t subnet_allocated_ip;
	ip_t broadcast_allocated_ip;
	aloc_status_t alloc_status;

	char *subnet_address_holder = malloc(BITS_IN_IP_ADDRESS + 1);

	/*CONVERT SUBMAST ADDRESS TO STRING*/
	IPToBinaryString(dhcp->subnet_mask, subnet_address_holder);

	/*CREATE BROADCAS (max address) IP ADDRESS FROM SUBMASK*/
	IPSetAvilableBits(subnet_address_holder, (BITS_IN_IP_ADDRESS - dhcp->available_bits), ON);
	/*MAKE BROADCAST AS IP_T*/
	BinaryStringToIP(subnet_address_holder, &broadcast_allocated_ip);

	/*INSERT SUBNET MASK ADDRESS*/
	alloc_status = DhcpAllocIp(dhcp, dhcp->subnet_mask, subnet_allocated_ip);

	/*INSERT BROADCAS MASK ADDRESS*/
	alloc_status = DhcpAllocIp(dhcp, broadcast_allocated_ip, broadcast_allocated_ip); 

	FREE(subnet_address_holder);
}

dhcp_t *DhcpCreate(ip_t subnet_mask, size_t subnet_mask_reserved_bits)
{
	dhcp_t *new_dhcp = malloc(sizeof(*new_dhcp));
	if(NULL != new_dhcp)
	{
		new_dhcp->trie = TrieCreate();
 		new_dhcp->subnet_mask = subnet_mask;
 		new_dhcp->available_bits = BITS_IN_IP_ADDRESS - subnet_mask_reserved_bits;

 		if(IP_AS_REQUESTED != IMPDhcpReservedAddressAlloc(new_dhcp))
 		{
			FREE(new_dhcp);
 		}
	}

	return new_dhcp;
}


aloc_status_t DhcpAllocIp(dhcp_t *dhcp, ip_t requested_ip, ip_t allocated_ip)
{	
	status_t insert_status;

	char *string_address = malloc(BITS_IN_IP_ADDRESS + 1);
	if(NULL != string_address)
	{
		IPToBinaryString(requested_ip, string_address);
	}

 	/*IS AVAILABLE*/
	insert_status = TrieInsert(dhcp->trie, string_address + (BITS_IN_IP_ADDRESS - dhcp->available_bits));
	if(SUCCESS == insert_status)
	{	
		FREE(string_address);
		return IP_AS_REQUESTED;
	}
	
}






