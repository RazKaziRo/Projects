/*
 * Author: Raz KaziRo
 * Purpose: Answares for DHCP.
 * Date: 04.02.2020
 * Language: C
 * Reviewer: Yoav Hattav
 */

#include <stdlib.h> /*malloc*/
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

static void AdjustSubnetMask(size_t height, unsigned char *requested_ip)
{
	assert(NULL != requested_ip);

	if (height > 0)
	{
		if (0 == (height % BITS_IN_BYTE))
		{
			(*(requested_ip + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) &= 0;
			 AdjustSubnetMask((height - BITS_IN_BYTE), requested_ip);
		}
		else
		{
			(*(requested_ip + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) >>= (height%BITS_IN_BYTE);
			(*(requested_ip + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) <<= (height%BITS_IN_BYTE);
			AdjustSubnetMask((height - (height%BITS_IN_BYTE)), requested_ip);
		}
	}

	return;
}

static aloc_status_t IMPDhcpReservedAddressAlloc(dhcp_t *dhcp)
{
	unsigned char min_address[] = {0, 0, 0, 0};
	unsigned char max_address[] = {255, 255, 255, 255};

	if (SUCCESS == TrieInsert(dhcp->trie, min_address))
	{
		if (SUCCESS == TrieInsert(dhcp->trie , max_address))
		{
			return IP_AS_REQUESTED;
		}
	}
	return FAIL_TO_ALLOC_IP;
}

dhcp_t *DhcpCreate(ip_t subnet_mask, size_t subnet_mask_reserved_bits)
{
	size_t trie_height = BITS_IN_IP_ADDRESS - subnet_mask_reserved_bits;
	unsigned char *subnet_mask_holder = subnet_mask.address;

	dhcp_t *new_dhcp = malloc(sizeof(*new_dhcp));
	if (NULL != new_dhcp)
	{
		new_dhcp->trie = TrieCreate(trie_height);
		if (NULL != new_dhcp->trie)
		{
			AdjustSubnetMask(trie_height, subnet_mask_holder);
			new_dhcp->subnet_mask = subnet_mask;
 			new_dhcp->available_bits = trie_height;

 			if (IP_AS_REQUESTED != IMPDhcpReservedAddressAlloc(new_dhcp))
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
	assert(NULL != dhcp);

	TrieDestroy(dhcp->trie);
	FREE(dhcp);
}

static bool_t IsIPInRange(dhcp_t *dhcp, unsigned char *requested_ip)
{	
	AdjustSubnetMask(dhcp->available_bits, requested_ip);

	return (0 == memcmp(dhcp->subnet_mask.address, requested_ip, BYTES_IN_IP_ADDRESS));
}

static bool_t IsZeroAddress(ip_t *requested_ip)
{	
	ip_t zero_address;

	assert (NULL != requested_ip);

	zero_address.address[0] = 0;
	zero_address.address[1] = 0;
	zero_address.address[2] = 0;
	zero_address.address[3] = 0;

	return (0 == memcmp(zero_address.address, requested_ip->address, BYTES_IN_IP_ADDRESS));
}

aloc_status_t DhcpAllocIp(dhcp_t *dhcp, ip_t *requested_ip, ip_t *allocated_ip)
{
	unsigned char *requested_ip_ptr = NULL;
	unsigned char *allocated_ip_ptr = NULL;

	assert (NULL != requested_ip);
	assert (NULL != allocated_ip);

	requested_ip_ptr = requested_ip->address;
    allocated_ip_ptr = allocated_ip->address;

	memcpy(allocated_ip_ptr, requested_ip_ptr, BYTES_IN_IP_ADDRESS);

	assert(IsIPInRange(dhcp, allocated_ip_ptr) || IsZeroAddress(requested_ip));

	if (0 != DhcpCountFree(dhcp))
	{
		if (TrieIsLocationAvailable(dhcp->trie, requested_ip_ptr))
 		{
 			if (SUCCESS == TrieInsert(dhcp->trie, requested_ip_ptr))
			{	
				memcpy(allocated_ip_ptr, requested_ip_ptr, BYTES_IN_IP_ADDRESS);

				return IP_AS_REQUESTED;
			}

			return FAIL_TO_ALLOC_IP;
 		}

		memcpy(allocated_ip_ptr, dhcp->subnet_mask.address, BYTES_IN_IP_ADDRESS);
		TrieNextAvilable(dhcp->trie, allocated_ip_ptr);

		if (SUCCESS == TrieInsert(dhcp->trie, allocated_ip_ptr))
		{
			return IP_NOT_AS_REQUESTED;
		}
	}

	return FAIL_TO_ALLOC_IP;
}

free_status_t DhcpFreeIp(dhcp_t *dhcp, ip_t ip_address)
{
	assert(NULL != dhcp);

	if (0 == TrieIsLocationAvailable(dhcp->trie, ip_address.address))
	{
		TrieFreeLeaf(dhcp->trie, ip_address.address);
		
		return SUCCESS_FREE;
	}

	return ADDRESS_NOT_FOUND;
}

size_t DhcpCountFree(const dhcp_t *dhcp)
{	
	size_t total_address = 0;

	assert(NULL != dhcp);

	total_address = pow(2, dhcp->available_bits);

	return (total_address - TrieSize(dhcp->trie));
}