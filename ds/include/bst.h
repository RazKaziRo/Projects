#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <stddef.h> /* size_t */

typedef struct BSTree bst_t;
typedef struct BSTNode *bst_itr_t;

typedef int (*compare_func_t)(const void *data1, const void *data2, void *param);
typedef int (*action_func_ptr)(void *data1, void *param);

/*********************************************** 
    Returns a pointer to the BST data structure
	Complexity of malloc     
 ***********************************************/
bst_t *BSTCreate(compare_func_t cmp, void *param); /*DONE*/

/************************************************** 
	Destroys the DLL data and free it from memory 
	Complexity of free                            
 **************************************************/
void BSTDestroy(bst_t *tree); /*DONE*/

/********************************************************************* 
	Gets a pointer to the tree and insert new data in the right place  
	Return 0 for success, otherwise: 1
	Complexity of malloc + O(log(n))                            
 ********************************************************************/
int BSTInsert(bst_t *tree, void *data); /*DONE*/

/*********************************************** 
	Get an iterator to remove from the tree
	Complexity: O(1)
 ***********************************************/
void BSTRemove(bst_itr_t it);/*DONE*/

/*********************************************************************** 
	Gets a pointer to the tree and search if the data exist in the tree
	Returns an iterator to the data if it was found, otherwise: NULL
	Complexity: avg-case: O(log(n)), worst-case: O(n)
 ***********************************************************************/
bst_itr_t BSTFind(const bst_t *tree, const void *data);

/********************************************************************************** 
	Gets iterators to the start and the end,
		 action function to operate on the elements in the tree
	Returns 0 for success, otherwise: non-zero value
	Complexity: worst-case: O(n) 
 ***********************************************************************************/
int BSTForeach(bst_itr_t start, bst_itr_t end, action_func_ptr action, void *param);

/*********************************************** 
	Gets a pointer to the tree
	Returns the size of the tree
	complexity: O(n)                  
 ***********************************************/
size_t BSTSize(const bst_t *tree);/*DONE*/

/*********************************************** 
	Gets a pointer to the tree
	Returns 1 if empty, otherwise: 0
	Complexity: O(1)
 ***********************************************/
int BSTIsEmpty(const bst_t *tree); /*DONE*/

/*********************************************** 
	Gets an iterator 
	Returns the data it contains
	complexity: O(1)                       
 ***********************************************/
void *BSTGetData(bst_itr_t it);/*DONE*/

/***************************************************** 
	Gets pointer to the tree
	Returns the first element in the tree
	Complexity: avg-case: O(log(n)), worst-case: O(n)
 *****************************************************/
bst_itr_t BSTBegin(const bst_t *tree);/*DONE*/

/***************************************************** 
	Gets pointer to the tree
	Returns the last element in the tree
	Complexity: avg-case: O(log(n)), worst-case: O(n)
 *****************************************************/
bst_itr_t BSTEnd(const bst_t *tree); /*DONE*/

/******************************************************* 
	Gets an iterator
	Returns an iterator to the next element in the tree
	Complexity: O(1)
 *******************************************************/
bst_itr_t BSTNext(bst_itr_t it);/*DONE*/

/******************************************************* 
	Gets an iterator
	Returns an iterator to the previous element in the tree
	Complexity: O(1)
 *******************************************************/
bst_itr_t BSTPrev(bst_itr_t it);/*DONE*/

/******************************************************* 
	Gets 2 iterators
	Returns 1 if they are equal, otherwise: 0
	Complexity: O(1)
 *******************************************************/
int BSTIsSameItr(bst_itr_t it1, bst_itr_t it2);/*DONE*/

#endif