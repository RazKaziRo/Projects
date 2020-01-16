/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - AVL.
 * Date: 16.01.2020
 * Language: C
 * Reviewer: Guy Cohen Zedek
 */

#include <stdlib.h> /*malloc()*/

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
	if(NULL != new_tree)
	{
		new_tree->root = NULL;
		new_tree->cmp = user_cmp_func;
	}

	return new_tree;
}

static avl_node_t *AVLNodeCreate(void *user_data)
{
	avl_node_t *new_node = (avl_node_t *)malloc(sizeof(avl_node_t));
	if(NULL != new_node)
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
	if(NULL == node || ((NULL == node->child[LEFT]) && (NULL == node->child[RIGHT])))
	{
		return 0;
	}

	return (1 + (MaxNodeHeight(AVLGetNodeHeightRecursive(node->child[LEFT]), AVLGetNodeHeightRecursive(node->child[RIGHT]))));
}

static void AVLInsertRecursiveHandler(avl_node_t **root, avl_node_t *insert_node, compare_func_t cmp)
{
	if (NULL == *root)
	{
		*root = insert_node;
		return;
	}

	if(0 < cmp(insert_node->data, (*root)->data))
	{	
		AVLInsertRecursiveHandler(&(*root)->child[RIGHT], insert_node, cmp);
	}
	else if (0 > cmp(insert_node->data, (*root)->data))
	{
		AVLInsertRecursiveHandler(&(*root)->child[LEFT], insert_node, cmp);
	}

	/*IsBalanced?
	balance*/

	return;
}

int AVLInsert(avl_t *tree, void *user_data)
{
	avl_node_t *new_node = AVLNodeCreate(user_data);
	if (NULL != new_node)
	{	
		AVLInsertRecursiveHandler(&tree->root, new_node, tree->cmp);

		return 0;
	}

	return 1;
}

int AVLIsEmpty(const avl_t *tree)
{
	return(NULL == tree->root);
}

static size_t AVLSizeHandler(const avl_node_t *node)
{
	if(NULL == node)
	{
		return 0;
	}

	return (1 + AVLSizeHandler(node->child[LEFT]) + AVLSizeHandler(node->child[RIGHT]));
}

size_t AVLSize(const avl_t *tree)
{
	return((AVLSizeHandler(tree->root)));
}

static void *AVLFindDataRecursiveHandler(const avl_node_t *node, const void *user_data, compare_func_t cmp)
{	
	if(NULL != node)
	{
		if (0 == cmp(user_data, node->data))
		{
			return node->data;
		}

		(0 < cmp(user_data, node->data)) ? 
		AVLFindDataRecursiveHandler(node->child[RIGHT], user_data, cmp) : 
		AVLFindDataRecursiveHandler(node->child[LEFT], user_data, cmp);
	}

	return NULL;
}

void *AVLFind(const avl_t *tree, const void *user_data)
{	
	return (AVLFindDataRecursiveHandler(tree->root, user_data, tree->cmp));
}


static int AVLForeachRecursiveHandler(avl_node_t *node, action_ptr_t action, void *param)
{
	int res = 0;

	if(NULL == node)
	{
		return 0;
	}

	if(0 == res)
	{
		res = AVLForeachRecursiveHandler(node->child[LEFT], action, param);
	}

	if(0 == res)
	{
		res = action(node->data, param);
	}

	if(0 == res)
	{
		res = AVLForeachRecursiveHandler(node->child[RIGHT], action, param);
	}
	
	return res;

}

int AVLForeach(avl_t *tree, action_ptr_t action, void *param)
{
	return(AVLForeachRecursiveHandler(tree->root, action, param));
}

size_t AVLGetHeight(const avl_t *tree)
{
	return(AVLGetNodeHeightRecursive(tree->root));
}

static void AVLDestroyRecursiveHandler(avl_node_t *root)
{	
	if(NULL == root)
	{
		return;
	}

	AVLDestroyRecursiveHandler(root->child[LEFT]);
	AVLDestroyRecursiveHandler(root->child[RIGHT]);

	FREE(root);

	return;
}

void AVLDestroy(avl_t *tree)
{
	AVLDestroyRecursiveHandler(tree->root);
	FREE(tree);
}

static avl_node_t *AVLFindNodeRecursiveHandler(avl_node_t *node, const void *user_data, compare_func_t cmp)
{	
	if(NULL != node)
	{
		if (0 == cmp(user_data, node->data))
		{
			return node;
		}

		(0 < cmp(user_data, node->data)) ? 
		AVLFindDataRecursiveHandler(node->child[RIGHT], user_data, cmp) : 
		AVLFindDataRecursiveHandler(node->child[LEFT], user_data, cmp);
	}

	return NULL;
}


static void AVLRemoveRecursiveHandler(avl_node_t *root, const void *data, compare_func_t cmp)
{	
	avl_node_t *node_to_remove = NULL;
	avl_node_t *replacment_node = NULL;

	node_to_remove = AVLFindNodeRecursiveHandler(root, data, cmp);
}

void AVLRemove(avl_t *tree, const void *data)
{
	AVLRemoveRecursiveHandler(tree->root, data, tree->cmp);
}

