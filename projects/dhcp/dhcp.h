#ifndef __DHCP_H__
#define __DHCP_H__

#include <stddef.h> /*size_t*/

#include "ip.h"     /*ip_t*/

typedef struct DHCP dhcp_t;
struct IP_T ipt_t;

typedef enum 
{ 
    IP_AS_REQUESTED,
    IP_NOT_AS_REQUESTED, 
    FAIL_TO_ALLOC_IP
} aloc_status_t;

typedef enum 
{
    SUCCESS_FREE, 
    ADDRESS_NOT_FOUND
} free_status_t;

/*
* DhcpCreate() - 
* Returns pointer to the Dhcp, will return NULL if failed. 
* @subnet_mask_reserved_bits: dhcp reserved bits in address. 
* ex: 255.255.255.0/24: the first 24 bits are dhcp reserved. 
* complexity of malloc();       
*/
dhcp_t *DhcpCreate(ip_t subnet_mask, size_t subnet_mask_reserved_bits); /*DONE*/

/*
* DhcpDetroy() -
* Destroys and frees dhcp from memory.
* undefined behaviour for @dhcp NULL pointer
* complexity: free();                  
*/
void DhcpDestroy(dhcp_t *dhcp); /*DONE*/

/*
* DhcpAllocIp() -
* will try to allocat the @requested_ip and returnd the result to the actual @alocated_ip variable.
* @requested_ip 0.0.0.0: will generate next avilable address. 
* undefined behaviour for @dhcp NULL pointer.
* undefined behaviour for @requested_ip address out of range.  
* return value: 
    - AS_REQUESTED
    - NOT_AS_REQUESTED - alocate a different address than requested
    - FAIL_TO_ALLOC 
* dhcp reserved:
* 0.0.0.0 - 
* 255.255.255.255 -
* 255.255.255.254 - 
* complexity: Olog(n)  
*/
aloc_status_t DhcpAllocIp(dhcp_t *dhcp, ip_t *requested_ip, ip_t *allocated_ip);/*DONE*/

/*
* DhcpFreeIp() -
* frees the @ip_address from the dhcp
* undefined behaviour for @dhcp NULL pointer
* return value: 
    - SUCCESS 
    - ADDRESS_NOT_FOUND  
* dhcp reserved: undefined behaviourr if free
* 0.0.0.0 
* 255.255.255.255 
* 255.255.255.254 
* complexity: Olog(n)            
*/
free_status_t DhcpFreeIp(dhcp_t *dhcp, ip_t ip_address);/*DONE*/

/*
* DhcpCountFree() -
* undefined behaviour for @dhcp NULL pointer 
* return the number of the available ip addresses in the subnet given range 
* complexity: O(n)          
*/
size_t DhcpCountFree(const dhcp_t *dhcp);

#endif