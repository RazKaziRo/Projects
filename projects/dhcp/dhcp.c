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
	unsigned char min_address[] = {0, 0, 0, 0};
	unsigned char max_address[] = {255, 255, 255, 255};

	if(SUCCESS == TrieInsert(dhcp->trie , min_address))
	{
		if(SUCCESS == TrieInsert(dhcp->trie , max_address))
		{
			return IP_AS_REQUESTED;
		}
	}

	return FAIL_TO_ALLOC_IP;
}

dhcp_t *DhcpCreate(ip_t subnet_mask, size_t subnet_mask_reserved_bits)
{
	size_t trie_height = BITS_IN_IP_ADDRESS - subnet_mask_reserved_bits;

	dhcp_t *new_dhcp = malloc(sizeof(*new_dhcp));
	if(NULL != new_dhcp)
	{
		new_dhcp->trie = TrieCreate(trie_height);
		if(NULL != new_dhcp->trie)
		{
			new_dhcp->subnet_mask = subnet_mask;
 			new_dhcp->available_bits = trie_height;

 			if(IP_AS_REQUESTED != IMPDhcpReservedAddressAlloc(new_dhcp))
 			{
				DhcpDestroy(new_dhcp);
 			}
		}
		else
		{
			FREE(new_dhcp);
		}
	}

	return new_dhcp;
}

void DhcpDestroy(dhcp_t *dhcp)
{
	TrieDestroy(dhcp->trie);
	FREE(dhcp);
}


aloc_status_t DhcpAllocIp(dhcp_t *dhcp, ip_t requested_ip, ip_t allocated_ip)
{	

}






