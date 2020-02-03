#include <stdlib.h> /*malloc*/

#include "trie.h"
#include "ip.h"

#define FREE(ptr) free(ptr); ptr = NULL;

#define NUM_OF_DIRECTION 2

typedef enum NODE_AVILABILITY
{
	AVAILABLE,
	OCCUPIED
} avilability_t;

typedef struct TRIE_NODE
{
	struct TRIE_NODE *direction[NUM_OF_DIRECTION];
	avilability_t state;
}trie_node_t;

struct TRIE
{
	trie_node_t *root;
	size_t height;
};

typedef enum DIRECTIONS
{
	LEFT,
	RIGHT
} direction_t;

static trie_node_t *IMPTrieNodeCreate()
{
	trie_node_t *new_trie_node = malloc(sizeof(*new_trie_node));
	if (NULL != new_trie_node)
	{
		new_trie_node->direction[LEFT] = NULL;
		new_trie_node->direction[RIGHT] = NULL;
		new_trie_node->state = AVAILABLE;
	}

	return new_trie_node;
}

trie_t *TrieCreate(size_t trie_height)
{
	trie_t *new_trie = malloc(sizeof(*new_trie));
	if (NULL != new_trie)
	{
		new_trie->root = IMPTrieNodeCreate();
		if (NULL != new_trie->root)
		{
			new_trie->height = trie_height;
		}
		else
		{
			FREE(new_trie);
		}
	}

	return new_trie; 
}

static void IMPTrieUpdateAvailabily(trie_node_t *node)
{
	if (NULL != node->direction[LEFT] && NULL != node->direction[RIGHT])
	{
		if (OCCUPIED == node->direction[LEFT]->state && OCCUPIED == node->direction[RIGHT]->state)
		{
			node->state = OCCUPIED;
		}
		else
		{
			node->state = AVAILABLE;
		}
	}
}

static bool_t TrieIsLocationAvailableHelper(size_t height, trie_node_t *node, const unsigned char *ip_address)
{
	direction_t side = ((*(ip_address + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) & ((1 << (height - 1) % BITS_IN_BYTE))) >> (height - 1) % BITS_IN_BYTE;

	if (0 == height || NULL == node->direction[side])
	{
		return TRUE;
	}
	
	if (OCCUPIED == node->state)
	{
		return FALSE;
	}

	return (TrieIsLocationAvailableHelper(height - 1, node->direction[side], ip_address));
}

int TrieIsLocationAvailable(trie_t *trie, const unsigned char *ip_address)
{
	return (TrieIsLocationAvailableHelper(trie->height, trie->root, ip_address));
}

static status_t TrieInsertHelper(size_t height, trie_node_t *node, unsigned char *ip_address)
{
	direction_t side = ((*(ip_address + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) & ((1 << (height - 1) % BITS_IN_BYTE))) >> (height - 1) % BITS_IN_BYTE;
	status_t status = 0;

	if (0 == height)
	{
		node->state = OCCUPIED;
		return SUCCESS;
	}

	if (NULL == node->direction[side])
	{
		node->direction[side] = IMPTrieNodeCreate();
		if (NULL == node->direction[side])
		{
			return FAIL;
		}
	}

	status = TrieInsertHelper(height - 1, node->direction[side], ip_address);
	IMPTrieUpdateAvailabily(node);

	return status;
}

status_t TrieInsert(trie_t *trie, unsigned char *ip_address)
{	
	if (TrieIsLocationAvailable(trie, ip_address))
	{
		TrieInsertHelper(trie->height, trie->root, ip_address);

		return SUCCESS;
	}

	return FAIL;
}

static void TrieDestroyHalper(trie_node_t *node)
{
	if (NULL == node)
	{
		return;
	}

	TrieDestroyHalper(node->direction[LEFT]);
	TrieDestroyHalper(node->direction[RIGHT]);

	free(node);
	node = NULL;
}

void TrieDestroy(trie_t *trie)
{
	TrieDestroyHalper(trie->root);

	free(trie);
	trie = NULL;
}

bool_t TrieIsEmpty(const trie_t *trie)
{
	if (NULL == trie->root->direction[LEFT] && NULL == trie->root->direction[RIGHT])
	{
		return TRUE;
	}

	return FALSE;
}

static size_t TrieSizeHelper(trie_node_t *node)
{
	size_t count = 0;

	if (NULL == node)
	{
		return 0;
	}

	if ((OCCUPIED == node->state) && (NULL == node->direction[LEFT]) && (NULL == node->direction[RIGHT]))
	{
		return 1;
	}

	count += TrieSizeHelper(node->direction[LEFT]);
	count += TrieSizeHelper(node->direction[RIGHT]);

	return count;
}

size_t TrieSize(const trie_t *trie)
{
	if (!TrieIsEmpty(trie))
	{
		return (TrieSizeHelper(trie->root));
	}

	return 0;
}

static void TrieFreeLeafHelper(size_t height, trie_node_t *node, const unsigned char *ip_address)
{
	direction_t side = ((*(ip_address + (BITS_IN_IP_ADDRESS - height)/BITS_IN_BYTE)) & ((1 << (height - 1) % BITS_IN_BYTE))) >> (height - 1) % BITS_IN_BYTE;

	if (OCCUPIED == node->state && NULL == node->direction[LEFT] && NULL == node->direction[RIGHT])
	{
		node->state = AVAILABLE;
		return;
	}

	if (0 == height)
	{
		return;
	}

	TrieFreeLeafHelper(height - 1, node->direction[side], ip_address);
	IMPTrieUpdateAvailabily(node);
}

void TrieFreeLeaf(trie_t *trie, const unsigned char *ip_address)
{
	TrieFreeLeafHelper(trie->height, trie->root, ip_address);
}

static void TrieNextAvilableHelper(size_t height, trie_node_t *node, unsigned char *ip_address)
{
	direction_t side = ((*(ip_address + (BITS_IN_IP_ADDRESS - height) / BITS_IN_BYTE)) & ((1 << (height - 1) % BITS_IN_BYTE))) >> (height - 1) % BITS_IN_BYTE;

	if (height > 0)
	{
		if (AVAILABLE == node->state)
		{
			if (NULL != node->direction[side] && AVAILABLE == node->direction[side]->state)
			{
				TrieNextAvilableHelper(height - 1, node->direction[side], ip_address);
			}
			else if (NULL != node->direction[!side] && AVAILABLE == node->direction[!side]->state)
			{
				(*(ip_address + (BITS_IN_IP_ADDRESS - height) / BITS_IN_BYTE)) ^= ((1 << (height - 1) % BITS_IN_BYTE));
				TrieNextAvilableHelper(height - 1, node->direction[!side], ip_address);
			}
			else
			{
				(*(ip_address + (BITS_IN_IP_ADDRESS - height) / BITS_IN_BYTE)) ^= ((1 << (height - 1) % BITS_IN_BYTE));
			}
		}
	}
}

void TrieNextAvilable(trie_t *trie, unsigned char *ip_address)
{
	TrieNextAvilableHelper(trie->height, trie->root, ip_address);
}
