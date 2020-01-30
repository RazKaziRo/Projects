#ifndef __TRIE_H__
#define __TRIE_H__

#include <stddef.h> /* size_t */

typedef struct TRIE trie_t;

typedef enum Status
{
    SUCCESS,
    FAIL
} status_t;

typedef enum BOOL
{
    FALSE,
    TRUE
} bool_t;

typedef enum DIRECTIONS
{
	LEFT,
	RIGHT
} direction_t;

/*
* TrieCreate() - 
* Returns pointer to the Trie, will return NULL if failed. 
* complexity of malloc();       
*/
trie_t *TrieCreate();/*DONE*/

/*
* TrieDetroy() -
* Destroys and frees Trie from memory.
* undefined behaviour for @trie NULL pointer
* complexity: free();                  
*/
void TrieDestroy(trie_t *trie);/*DONE*/

/*
* TrieInsert() -
* Inserts a new trie element.
* undefined behaviour for @trie NULL pointer
* complexity: malloc();                  
*/
status_t TrieInsert(trie_t *trie, char *str);

/*
* TrieIsEmpty() -
* Checks if the trie is empty.
* undefined behaviour for @trie NULL pointer
* return value:
    -TRUE
    -FALSE
* complexity: O(1);                  
*/
bool_t TrieIsEmpty(const trie_t *trie);/*DONE*/

/*
* TrieSize() -
* Counts the number of elements in the trie.
* undefined behaviour for @trie NULL pointer
* complexity: O(n);                  
*/
size_t TrieSize(const trie_t *trie); /*DONE*/

/*
* TrieCountLeafs() -
* Counts the number of leafs in the trie.
* undefined behaviour for @trie NULL pointer
* complexity: O(n);                  
*/
size_t TrieCountLeafs(const trie_t *trie); /*DONE*/

#endif 