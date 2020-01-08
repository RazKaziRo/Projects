#include <stdlib.h> /*malloc()*/

#include "bst.h"

#define MAGIC_NUMBER (void *)0xDEADBEEF
#define LEFT 0
#define RIGHT 1

#define FREE(ptr) free(ptr); ptr=NULL;

typedef struct BSTNode
{
	void *data;
	struct BSTNode *children[2];
	struct BSTNode *parent;
}bst_node_t;

struct BSTree
{
	bst_node_t dummy;
	compare_func_t cmp;
	void *param;
};

bst_t *BSTCreate(compare_func_t cmp, void *param)
{
	bst_t *new_tree = (bst_t *) malloc(sizeof(bst_t));
	if(NULL != new_tree)
	{	
		new_tree->dummy.data = MAGIC_NUMBER;
		new_tree->dummy.children[LEFT] = NULL;
		new_tree->dummy.children[RIGHT] = NULL;
		new_tree->dummy.parent = NULL;
		new_tree->cmp = cmp;
		new_tree->param = param;
	}
	return new_tree;
}

static bst_node_t *BSTCreateNode(void *user_data, bst_node_t *parent)
{
	bst_node_t *new_node = (bst_node_t *)malloc(sizeof(bst_node_t));
	if(NULL != new_node)
	{
		new_node->data = user_data;
		new_node->children[LEFT]= NULL;
		new_node->children[RIGHT]= NULL;
		new_node->parent = parent;
	}

	return new_node;
}

int BSTInsert(bst_t *tree, void *user_data)
{
	bst_node_t *node_runner = &tree->dummy;
	int where = 0;

	while(!BSTIsEmpty(tree) && NULL != node_runner->children[where])
	{
			node_runner = node_runner->children[where];
			where = tree->cmp(user_data, node_runner->data, tree->param);
	}

	node_runner->children[where] = BSTCreateNode(user_data, node_runner);
	return(NULL == node_runner->children[where]);
}

static int BTSParentNodeSide(bst_itr_t it)
{
	return (BSTIsSameItr(it->parent->children[RIGHT], it));
}

bst_itr_t BSTNext(bst_itr_t it)
{
	bst_node_t *node_runner = it;

	if (NULL != it->children[RIGHT])
	{
		node_runner = it->children[RIGHT];
		while (NULL != node_runner->children[LEFT])
		{
			node_runner = node_runner->children[LEFT];
		}
	}
	else
	{
		while (LEFT != BTSParentNodeSide(node_runner))
		{
			node_runner = node_runner->parent;
		}
		node_runner = node_runner->parent;
	}

	return node_runner;
}

bst_itr_t BSTPrev(bst_itr_t it)
{	
	bst_node_t *node_runner = it;

	if(NULL != it->children[LEFT])
	{
		node_runner = it->children[LEFT];
		while(NULL != node_runner->children[RIGHT])
		{
			node_runner = node_runner->children[RIGHT];
		}
	}
	else
	{
		while(RIGHT != BTSParentNodeSide(node_runner))
		{
			node_runner = node_runner->parent;
		}
		node_runner = node_runner->parent;
	}
	return node_runner;
}

size_t BSTSize(const bst_t *tree)
{
	size_t counter = 0;
	bst_node_t *node_runner = BSTBegin(tree);
	bst_node_t *end_node = BSTEnd(tree);

	while(!(BSTIsSameItr(node_runner,end_node)))
	{
		++counter;
		node_runner = BSTNext(node_runner);
	}

	return counter;	
}

bst_itr_t BSTBegin(const bst_t *tree)
{	
	bst_node_t const *node_runner = &tree->dummy;

	while(NULL != node_runner->children[LEFT])
	{
		node_runner = node_runner->children[LEFT];
	}

	return((bst_itr_t)node_runner);
}

bst_itr_t BSTEnd(const bst_t *tree)
{
	return((bst_itr_t)&tree->dummy);
}

void *BSTGetData(const bst_itr_t bst_it)
{
	return(bst_it->data);
}


int BSTIsEmpty(const bst_t *tree)
{
	return(tree->dummy.children[LEFT] == NULL);
}


int BSTIsSameItr(const bst_itr_t it1, const bst_itr_t it2)
{
	return (it1 == it2);
}

void BSTRemove(bst_itr_t it)
{
	bst_node_t *successor_node = BSTNext(it);

	if(NULL != it->children[LEFT] && NULL != it->children[RIGHT])
	{
		it->parent->children[BTSParentNodeSide(it)] = it->children[RIGHT];
		it->children[RIGHT]->parent = it->parent;
		successor_node->children[LEFT] = it->children[LEFT];
		it->children[LEFT]->parent = successor_node;
	}
	else if (NULL != it->children[LEFT])
	{
		it->children[LEFT]->parent = it->parent;
		it->parent->children[BTSParentNodeSide(it)] = it->children[LEFT];
	}
	else if (NULL != it->children[RIGHT])
	{
		it->children[RIGHT]->parent = it->parent;
		it->parent->children[BTSParentNodeSide(it)] = it->children[RIGHT];
	}
	else
	{
		it->parent->children[BTSParentNodeSide(it)] = NULL;
	}

	FREE(it);
}

void BSTDestroy(bst_t *tree)
{
	bst_node_t *root_runner = tree->dummy.children[LEFT];

	while(!BSTIsEmpty(tree))
	{	
		BSTRemove(root_runner);
		root_runner = tree->dummy.children[LEFT];
	}
	FREE(tree);
}	

bst_itr_t BSTFind(const bst_t *tree, const void *data)
{
	bst_node_t *node_runner = tree->dummy.children[LEFT];
	bst_node_t *end_node = BSTEnd(tree);

	
	
}


