#include <stdlib.h> /*malloc*/

#include "trie.h"

#define NUM_OF_DIRECTION 2

typedef enum NODE_AVILABILITY
{
	AVAILABLE,
	OCCUPIED
} avilabilit_t;

typedef struct TRIE_NODE
{
	struct TRIE_NODE *direction[NUM_OF_DIRECTION];
	avilabilit_t state;
}trie_node_t;

struct TRIE
{
	trie_node_t *root;
};

static trie_node_t *IMPTrieNodeCreate()
{
	trie_node_t *new_trie_node = malloc(sizeof(*new_trie_node));
	if(NULL != new_trie_node)
	{
		new_trie_node->direction[LEFT] = NULL;
		new_trie_node->direction[RIGHT] = NULL;
		new_trie_node->state = AVAILABLE;
	}

	return new_trie_node;
}

trie_t *TrieCreate()
{
	trie_t *new_trie = malloc(sizeof(*new_trie));
	if(NULL != new_trie)
	{
		new_trie->root = IMPTrieNodeCreate();
	}

	return new_trie; 
}

static void IMPTrieUpdateAvailabily(trie_node_t *node)
{
	if(NULL != node->direction[LEFT] && NULL != node->direction[RIGHT])
	{
		if(OCCUPIED == node->direction[LEFT]->state && OCCUPIED == node->direction[RIGHT]->state)
		{
			node->state = OCCUPIED;
		}
	}
}

static status_t TrieInsertHalper(trie_node_t *node, char *str)
{	
	status_t status = FAIL;

	if('\0' == *str)
	{
		node->state = OCCUPIED;
		return SUCCESS;
	}

	if(NULL == node->direction[*str - 48])
	{
		node->direction[*str - 48] = IMPTrieNodeCreate();
		if(NULL == node->direction[*str - 48])
		{
			return FAIL;
		}
	}

	status = TrieInsertHalper(node->direction[*str - 48], str + 1);
	IMPTrieUpdateAvailabily(node);

	return status;
}

status_t TrieInsert(trie_t *trie, char *str)
{	
	return(TrieInsertHalper(trie->root, str));
}

void TrieDestroyHalper(trie_node_t *node)
{
	if(NULL == node)
	{
		return;
	}

	TrieDestroyHalper(node->direction[LEFT]);
	TrieDestroyHalper(node->direction[RIGHT]);

	free(node);
	node = NULL;
}

bool_t TrieIsEmpty(const trie_t *trie)
{
	if(NULL == trie->root->direction[LEFT] && NULL == trie->root->direction[RIGHT])
	{
		return TRUE;
	}

	return FALSE;
}

void TrieDestroy(trie_t *trie)
{
	TrieDestroyHalper(trie->root);

	free(trie);
	trie = NULL;
}

size_t TrieSizeHelper(trie_node_t *node)
{
	size_t count = 0;

	if(NULL == node)
	{
		return 0;
	}

	count += TrieSizeHelper(node->direction[LEFT]);
	count += TrieSizeHelper(node->direction[RIGHT]);

	return 1;
}

size_t TrieSize(const trie_t *trie)
{
	if(!TrieIsEmpty(trie))
	{
		return(TrieSizeHelper(trie->root));
	}

	return 0;
}

size_t TrieCountLeafsHelper(trie_node_t *node)
{
	size_t leaf_count = 0;

	if(NULL == node->direction[LEFT] && NULL == node->direction[RIGHT])
	{
		return 1;
	}

	leaf_count += TrieCountLeafsHelper(node->direction[LEFT]);
	leaf_count += TrieCountLeafsHelper(node->direction[RIGHT]);

	return leaf_count;
}

size_t TrieCountLeafs(const trie_t *trie)
{
	if(!TrieIsEmpty(trie))
	{
		return(TrieCountLeafs((trie_t *)trie->root));
	}

	return 0;
}