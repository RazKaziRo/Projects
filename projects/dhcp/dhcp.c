#include <stdlib.h> /*malloc*/
#include <stdio.h> /*printf()*/
#include <string.h>/*memcmp*/
#include <math.h> /*pow*/
#include <assert.h> /*assert()*/

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

	if(SUCCESS == TrieInsert(dhcp->trie, min_address))
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

static void AdjustToSubnetMask(size_t height, unsigned char *requested_ip)
{
	if(height > 0)
	{
		if(0 == (height % BITS_IN_BYTE))
		{
			(*(requested_ip + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) &= 0;
			 AdjustToSubnetMask((height - BITS_IN_BYTE), requested_ip);
		}
		else
		{
			(*(requested_ip + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) >>= (height%BITS_IN_BYTE);
			(*(requested_ip + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) <<= (height%BITS_IN_BYTE);
		}
	}

	else
	{
		return;
	}
	
	AdjustToSubnetMask((height - (height%BITS_IN_BYTE)), requested_ip);
}

static bool_t IsIPInRange(dhcp_t *dhcp, unsigned char *requested_ip)
{	
	AdjustToSubnetMask(dhcp->available_bits, requested_ip);

	return(0 == memcmp(dhcp->subnet_mask.address, requested_ip, BYTES_IN_IP_ADDRESS));
}

aloc_status_t DhcpAllocIp(dhcp_t *dhcp, ip_t *requested_ip, ip_t *allocated_ip)
{
	unsigned char *requested_ip_ptr = requested_ip->address;
	unsigned char *allocated_ip_ptr = allocated_ip->address;

	memcpy(allocated_ip_ptr, requested_ip_ptr, BYTES_IN_IP_ADDRESS);

	assert(IsIPInRange(dhcp, allocated_ip_ptr));

	if(SUCCESS == TrieInsert(dhcp->trie, requested_ip_ptr))
	{	
		memcpy(allocated_ip_ptr, requested_ip_ptr, BYTES_IN_IP_ADDRESS);

		return IP_AS_REQUESTED;
	}
	else
	{
		return FAIL_TO_ALLOC_IP;
	}


	memcpy(allocated_ip_ptr, dhcp->subnet_mask.address, BYTES_IN_IP_ADDRESS);
	TrieNextAvilable(dhcp->trie, allocated_ip_ptr);

	if(SUCCESS == TrieInsert(dhcp->trie, allocated_ip_ptr))
	{
		return IP_NOT_AS_REQUESTED;
	}

	return FAIL_TO_ALLOC_IP;
}

free_status_t DhcpFreeIp(dhcp_t *dhcp, ip_t ip_address)
{

	if(0 == TrieIsLocationAvailable(dhcp->trie, ip_address.address))
	{
		TrieFreeLeaf(dhcp->trie, ip_address.address);
		return SUCCESS_FREE;
	}

	return ADDRESS_NOT_FOUND;
}

size_t DhcpCountFree(const dhcp_t *dhcp)
{
	size_t total_address = pow(2, dhcp->available_bits);

	return(total_address - TrieSize(dhcp->trie));
}