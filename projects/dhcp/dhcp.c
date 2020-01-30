#include <stdlib.h> /*malloc*/
#include <stdio.h> /*printf()*/

#include "dhcp.h"
#include "trie.h"

struct DHCP
{
	trie_t *trie;
	ip_t subnet_mask;
	size_t available_bits;
};

dhcp_t *DhcpCreate(ip_t subnet_mask, size_t subnet_mask_reserved_bits)
{
	ip_t allocated_ip;

	dhcp_t *new_dhcp = malloc(sizeof(*new_dhcp));
	if(NULL != new_dhcp)
	{
		new_dhcp->trie = TrieCreate();
 		new_dhcp->subnet_mask = subnet_mask;
 		new_dhcp->available_bits = BITS_IN_IP_ADDRESS - subnet_mask_reserved_bits;

 		DhcpAllocIp(new_dhcp, subnet_mask, allocated_ip); /*RESERVE BASE ADDRESS*/

	}

	return new_dhcp;
}


aloc_status_t DhcpAllocIp(dhcp_t *dhcp, ip_t requested_ip, ip_t allocated_ip)
{	
	status_t insert_status;

	char *reserved = malloc(BITS_IN_IP_ADDRESS + 1);
	if(NULL != reserved)
	{
		IPToBinaryString(requested_ip, reserved);
	}
	
 	/*IS AVAILABLE*/
	insert_status = TrieInsert(dhcp->trie, reserved + (BITS_IN_IP_ADDRESS - dhcp->available_bits));
	if(SUCCESS == insert_status)
	{
		return IP_AS_REQUESTED;
	}
	
}






