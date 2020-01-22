/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Hash Table.
 * Date: 21.01.2020
 * Language: C
 * Reviewer: 
 */

#include <stdlib.h> /*malloc()*/
#include <stdio.h> /*printf()*/

#include "hash.h"
#include "../include/doublelist.h"

#define FREE(ptr) free(ptr); ptr = NULL;
#define START_POSITION 1

struct Hash
{
	size_t table_size;
	match_func_t is_match_func;
	hash_func_t hash_func;
	dll_t *table[START_POSITION];
};


static int HashDLLInitHelper(dll_t *table[], size_t table_size)
{	
	size_t i = 0;

	for(; i < table_size; ++i)
	{
		table[i] = DLLCreate();
		if(NULL == table[i])
		{
			for(--i; i <= 0; --i)
			{
				DLLDestroy(table[i]);
			}

			return 1;
		}
	}

	return 0;
}

hash_t *
HashCreate(size_t user_table_size, hash_func_t user_hash_func, match_func_t user_is_match)
{
	hash_t *new_hash = (hash_t *)malloc(offsetof(hash_t, table) + (user_table_size * sizeof(dll_t *)));
	if(NULL != new_hash)
	{
		new_hash->table_size = user_table_size;
		new_hash->is_match_func = user_is_match;
		new_hash->hash_func = user_hash_func;
		if(0 != HashDLLInitHelper(new_hash->table, user_table_size))
		{
			FREE(new_hash);
		}
	}

	return new_hash;
}

void HashDestroy(hash_t *hash)
{	
	size_t i = 0;

	for(; i < hash->table_size; ++i)
	{
		DLLDestroy(hash->table[i]);
	}

	FREE(hash);
}

int HashInsert(hash_t *hash, void *data)
{
	size_t key = hash->hash_func(data);
	if(NULL != DLLPushFront(hash->table[key], data))
	{
		return 0;
	}

	return 1;
}

static size_t HashGetKey(hash_t *hash, const void *data)
{
	return(hash->hash_func(data));
}

static void *HashDLLGetIterator(hash_t *hash, void *data)
{
	size_t key = HashGetKey((hash_t*)hash, data);

	iterator_t dll_begin = DLLBegin(hash->table[key]);
	iterator_t dll_end = DLLEnd(hash->table[key]);
	iterator_t dll_result = DLLFind(dll_begin, dll_end, hash->is_match_func, (void *)data);

	return(dll_result);
}

void *HashFind(const hash_t *hash, const void *data)
{
	HashDLLGetIterator(hash, data);
	
	return DLLGetData(dll_result);
	
}


void HashRemove(hash_t *hash, const void *data)
{	

}

