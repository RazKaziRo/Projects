/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Binary Search Tree.
 * Date: 08.01.2020
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/

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
} bst_node_t;

struct BSTree
{
	bst_node_t dummy;
	compare_func_t cmp;
	void *param;
};

bst_t *BSTCreate(compare_func_t cmp, void *param)
{
	bst_t *new_tree = (bst_t *) malloc(sizeof(bst_t));

	assert(NULL != cmp);

	if (NULL != new_tree)
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

	assert(NULL != parent);

	if (NULL != new_node)
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

	assert(NULL != tree);

	while (NULL != node_runner->children[where])
	{
			node_runner = node_runner->children[where];
			where = tree->cmp(user_data, node_runner->data, tree->param);
	}

	node_runner->children[where] = BSTCreateNode(user_data, node_runner);
	
	return (NULL == node_runner->children[where]);
}

static int BTSParentNodeSide(bst_itr_t node_it)
{	
	assert(NULL != node_it);

	return (node_it->parent->children[RIGHT] == node_it);
}

bst_itr_t BSTNext(bst_itr_t node_it)
{
	bst_node_t *node_runner = node_it;

	assert(NULL != node_it);

	if (NULL != node_it->children[RIGHT])
	{
		node_runner = node_it->children[RIGHT];
		
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

bst_itr_t BSTPrev(bst_itr_t node_it)
{	
	bst_node_t *node_runner = node_it;

	assert(NULL != node_it);

	if (NULL != node_it->children[LEFT])
	{
		node_runner = node_it->children[LEFT];
		while (NULL != node_runner->children[RIGHT])
		{
			node_runner = node_runner->children[RIGHT];
		}
	}
	else
	{
		while ((NULL != node_runner->parent) && (node_runner == node_runner->parent->children[LEFT]))
		{
			node_runner = node_runner->parent;
		}
		if(NULL != node_runner->parent)
		{
			node_runner = node_runner->parent;
		}
	}

	return node_runner;
}

size_t BSTSize(const bst_t *tree)
{
	size_t counter = 0;
	bst_node_t *node_runner = BSTBegin(tree);
	bst_node_t *end_node = BSTEnd(tree);

	assert(NULL != tree);

	while (!(BSTIsSameItr(node_runner,end_node)))
	{
		++counter;
		node_runner = BSTNext(node_runner);
	}

	return counter;	
}

bst_itr_t BSTBegin(const bst_t *tree)
{	
	bst_node_t *node_runner = (bst_node_t *)&tree->dummy;

	assert(NULL != tree);

	while (NULL != node_runner->children[LEFT])
	{
		node_runner = node_runner->children[LEFT];
	}

	return node_runner;
}

bst_itr_t BSTEnd(const bst_t *tree)
{	
	assert(NULL != tree);

	return ((bst_node_t *)&tree->dummy);
}

void *BSTGetData(bst_itr_t node_it)
{	
	assert(NULL != node_it);

	return (node_it->data);
}


int BSTIsEmpty(const bst_t *tree)
{	
	assert(NULL != tree);

	return (tree->dummy.children[LEFT] == NULL);
}


int BSTIsSameItr(bst_itr_t node_it_x,bst_itr_t node_it_y)
{	
	assert(NULL != node_it_x);
	assert(NULL != node_it_y);

	return (node_it_x == node_it_y);
}

void BSTRemove(bst_itr_t node_it)
{
	bst_node_t *successor_node = BSTNext(node_it);

	if (NULL != node_it->children[LEFT] && NULL != node_it->children[RIGHT])
	{
		node_it->parent->children[BTSParentNodeSide(node_it)] = node_it->children[RIGHT];
		node_it->children[RIGHT]->parent = node_it->parent;
		successor_node->children[LEFT] = node_it->children[LEFT];
		node_it->children[LEFT]->parent = successor_node;
	}
	else if (NULL != node_it->children[LEFT])
	{
		node_it->children[LEFT]->parent = node_it->parent;
		node_it->parent->children[BTSParentNodeSide(node_it)] = node_it->children[LEFT];
	}
	else if (NULL != node_it->children[RIGHT])
	{
		node_it->children[RIGHT]->parent = node_it->parent;
		node_it->parent->children[BTSParentNodeSide(node_it)] = node_it->children[RIGHT];
	}
	else
	{
		node_it->parent->children[BTSParentNodeSide(node_it)] = NULL;
	}

	FREE(node_it);
}

void BSTDestroy(bst_t *tree)
{
	bst_node_t *root_runner = tree->dummy.children[LEFT]; /*AFTER ASSERT*/

	assert(NULL != tree);

	while(!BSTIsEmpty(tree))
	{	
		BSTRemove(root_runner);
		root_runner = tree->dummy.children[LEFT];
	}

	FREE(tree);
}	

bst_itr_t BSTFind(const bst_t *tree, const void *user_data)
{
	bst_node_t *node_runner = tree->dummy.children[LEFT];

	int first_answare = tree->cmp(user_data, node_runner->data, tree->param);
	int second_answare = tree->cmp(node_runner->data, user_data, tree->param);

	assert(NULL != tree);

	while ((NULL != node_runner) && (first_answare != second_answare))
	{	
		node_runner = node_runner->children[first_answare];
		if (NULL != node_runner)
		{
			first_answare = tree->cmp(node_runner->data, user_data, tree->param);
			second_answare = tree->cmp(user_data, node_runner->data, tree->param);
		}
		else
		{
			return (bst_node_t *)&tree->dummy;
		}
	}

	return node_runner;
}

int BSTForeach(bst_itr_t start, bst_itr_t end, action_func_ptr action, void *param)
{	
	bst_node_t *node_runner = start;
	int result = 0;

	assert(NULL != start);
	assert(NULL != end);

	while ((!BSTIsSameItr(node_runner, end)) && (0 == result))
	{
		result = action(node_runner->data, param);
		node_runner = BSTNext(node_runner);
	}

	return result;	
}




