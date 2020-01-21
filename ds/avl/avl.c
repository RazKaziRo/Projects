/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - AVL.
 * Date: 20.01.2020
 * Language: C
 * Reviewer: Israel Drayfus
 */

#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/

#include "avl.h"

#define FREE(ptr) free(ptr); ptr=NULL;

typedef struct AVLNode avl_node_t;

struct AVLNode
{
	void *data;
	avl_node_t *child[NUM_OF_CHILDREN];
	size_t height;
};

struct AVLTree
{
	avl_node_t *root;
	compare_func_t cmp;
};

avl_t *AVLCreate(compare_func_t user_cmp_func)
{
	avl_t *new_tree = (avl_t *)malloc(sizeof(avl_t));
	if (NULL != new_tree)
	{
		new_tree->root = NULL;
		new_tree->cmp = user_cmp_func;
	}

	return new_tree;
}

static avl_node_t *AVLNodeCreate(void *user_data)
{
	avl_node_t *new_node = (avl_node_t *)malloc(sizeof(avl_node_t));
	if (NULL != new_node)
	{
		new_node->data = user_data;
		new_node->child[LEFT] = NULL;
		new_node->child[RIGHT] = NULL;
		new_node->height = 0;
	}

	return new_node;
}

static size_t MaxNodeHeight(size_t left_node_height, size_t right_node_height)
{
	return (left_node_height > right_node_height ? left_node_height : right_node_height);
}

static size_t AVLGetNodeHeightRecursive(avl_node_t *node)
{	
	if (NULL == node || ((NULL == node->child[LEFT]) && (NULL == node->child[RIGHT])))
	{
		return 0;
	}

	return (1 + (MaxNodeHeight(AVLGetNodeHeightRecursive(node->child[LEFT]), AVLGetNodeHeightRecursive(node->child[RIGHT]))));
}

static void UpdateHeights(avl_node_t *node)
{
	node->height = AVLGetNodeHeightRecursive(node);
}

static int BalanceFactor (avl_node_t *root)
{
	int child_right_height = 0;
	int child_left_height = 0;

	if (NULL != root->child[LEFT])
	{
		child_left_height = 1 + root->child[LEFT]->height;
	}

	if (NULL != root->child[RIGHT])
	{
		child_right_height = 1 + root->child[RIGHT]->height;
	}

	return (child_right_height - child_left_height);

}

static avl_node_t *AVLRotateTree(avl_node_t *root, int side)
{
	avl_node_t *node_holder = NULL;

	node_holder = root->child[!side];
	root->child[!side] = node_holder->child[side];
	node_holder->child[side] = root;

	UpdateHeights(root);

	return node_holder;
}

static avl_node_t *AVLBalanceTree(avl_node_t *node)
{
	int root_balance_factor = BalanceFactor(node);
	int pivot_balance_factor = 0;

	int side = (root_balance_factor < 0) ? RIGHT : LEFT;

	if (-2 == root_balance_factor || 2 == root_balance_factor)
	{	
		pivot_balance_factor = BalanceFactor(node->child[!side]);

		if (((root_balance_factor < 0) && (pivot_balance_factor > 0)) || /*LR Case*/
		   ((root_balance_factor > 0) && (pivot_balance_factor < 0))) /*RL Case*/
		{
			node->child[!side] = AVLRotateTree(node->child[!side], !side);
		}

		node = AVLRotateTree(node, side);
	}

	return node;
}

static avl_node_t *
AVLInsertRecursiveHelper(avl_node_t *root, avl_node_t *insert_node, compare_func_t cmp)
{

	int side = 0;

	if (NULL == root)
	{
		root = insert_node;
		return root;
	}

	side = cmp(insert_node->data, root->data);
	side = (side > 0)? RIGHT : LEFT;

	root->child[side] = AVLInsertRecursiveHelper(root->child[side], insert_node, cmp);

	UpdateHeights(root);
	root = AVLBalanceTree(root);
 
	return root;
}

int AVLInsert(avl_t *tree, void *user_data)
{
	avl_node_t *new_node = AVLNodeCreate(user_data);
	if (NULL != new_node)
	{	
		tree->root = AVLInsertRecursiveHelper(tree->root, new_node, tree->cmp);

		return 0;
	}

	return 1;
}

int AVLIsEmpty(const avl_t *tree)
{
	return (NULL == tree->root);
}

static size_t AVLSizeHelper(const avl_node_t *node)
{
	if (NULL == node)
	{
		return 0;
	}

	return (1 + AVLSizeHelper(node->child[LEFT]) + AVLSizeHelper(node->child[RIGHT]));
}

size_t AVLSize(const avl_t *tree)
{
	return ((AVLSizeHelper(tree->root)));
}

static void *AVLFindDataRecursiveHelper(const avl_node_t *node, const void *user_data, compare_func_t cmp)
{	
	int side = 0;

	if (NULL != node)
	{
		side = cmp(user_data, node->data);

		if (0 == side)
		{
			return node->data;
		}

		side = (side > 0)? RIGHT : LEFT;

		return AVLFindDataRecursiveHelper(node->child[side], user_data, cmp);
	}

	return NULL;
}

void *AVLFind(const avl_t *tree, const void *user_data)
{	
	return (AVLFindDataRecursiveHelper(tree->root, user_data, tree->cmp));
}


static int AVLForeachRecursiveHelper(avl_node_t *node, action_ptr_t action, void *param)
{
	int res = 0;

	if (NULL == node)
	{
		return 0;
	}

	if (0 == res)
	{
		res = AVLForeachRecursiveHelper(node->child[LEFT], action, param);
	}

	if (0 == res)
	{
		res = action(node->data, param);
	}

	if (0 == res)
	{
		res = AVLForeachRecursiveHelper(node->child[RIGHT], action, param);
	}
	
	return res;
}

int AVLForeach(avl_t *tree, action_ptr_t action, void *param)
{
	return (AVLForeachRecursiveHelper(tree->root, action, param));
}

size_t AVLGetHeight(const avl_t *tree)
{
	return (tree->root->height);
}

static void AVLDestroyRecursiveHelper(avl_node_t *root)
{	
	if (NULL == root)
	{
		return;
	}

	AVLDestroyRecursiveHelper(root->child[LEFT]);
	AVLDestroyRecursiveHelper(root->child[RIGHT]);

	FREE(root);

	return;
}

void AVLDestroy(avl_t *tree)
{
	AVLDestroyRecursiveHelper(tree->root);
	FREE(tree);
}

static avl_node_t *AVLFindSuccessorNode(avl_node_t *node, avl_node_t **successor_node)
{	

	if (NULL == node->child[LEFT])
	{
		*successor_node = node;
		return node->child[RIGHT];
	}

	node->child[LEFT] = AVLFindSuccessorNode(node->child[LEFT], successor_node);

	UpdateHeights(node);
	node = AVLBalanceTree(node);

	return node;
}

static avl_node_t *AVLFindNodeReplacer(avl_node_t *node)
{
	avl_node_t *successor_node = NULL;

	if (NULL != node->child[RIGHT])
	{
		if (NULL != node->child[LEFT])
		{
			node->child[RIGHT] = AVLFindSuccessorNode(node->child[RIGHT], &successor_node);
			successor_node->child[LEFT] = node->child[LEFT];

			if (node->child[RIGHT] != successor_node)
			{
				successor_node->child[RIGHT] = node->child[RIGHT];
			}
		
			UpdateHeights(successor_node);
			successor_node = AVLBalanceTree(successor_node);

			return successor_node;
		}

		return node->child[RIGHT];
	}

	return node->child[LEFT];
}

static avl_node_t *
AVLRemoveRecursiveHelper(avl_node_t *node, const void *user_data, compare_func_t cmp)
{	
	avl_node_t *replacer_node = NULL;

	if (NULL != node)
	{
		if (0 == cmp(user_data, node->data))
		{	
			replacer_node =  AVLFindNodeReplacer(node);
			if (NULL != replacer_node)
			{	
				if (node->child[LEFT] != replacer_node)
				{
					replacer_node->child[LEFT] = node->child[LEFT];
				}
				
				if (node->child[RIGHT] != replacer_node)
				{
					replacer_node->child[RIGHT] = node->child[RIGHT];
				}

				replacer_node = AVLBalanceTree(replacer_node);
				UpdateHeights(replacer_node);
			}

			FREE(node);

			return replacer_node;
		}

		else
		{
			node->child[0 < cmp(user_data, node->data)] = 
			AVLRemoveRecursiveHelper(node->child[0 < cmp(user_data, node->data)], user_data, cmp);
		}
	}

	UpdateHeights(node);
	node = AVLBalanceTree(node);

	return node;
}

void AVLRemove(avl_t *tree, const void *user_data)
{
	tree->root = AVLRemoveRecursiveHelper(tree->root, user_data, tree->cmp);
}