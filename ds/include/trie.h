#ifndef __TRIE_H__
#define __TRIE_H__

#include <stddef.h> /* size_t */

typedef struct TRIE trie_t;

typedef enum STATUS
{
    SUCCESS,
    FAIL
} status_t;

typedef enum BOOL
{
    FALSE,
    TRUE
} bool_t;

/*
* TrieCreate() - 
* Returns pointer to the Trie, will return NULL if failed. 
* complexity of malloc();       
*/
trie_t *TrieCreate(size_t trie_height);/*DONE*/

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
status_t TrieInsert(trie_t *trie, unsigned char *ip_address); /*DONE*/
/*
* TrieIsEmpty() -
* Checks if the trie is empty.status_t TrieInsert(trie_t *trie, unsigned int bits)
* undefined behaviour for @trie NULL pointer
* return value:
    -TRUE
    -FALSE
* complexity: O(1);                  
*/
bool_t TrieIsEmpty(const trie_t *trie);/*DONE*/

/*
* TrieSize() -
* Counts the number of the OCCUPIDE elements in the trie.
* undefined behaviour for @trie NULL pointer
* complexity: O(n);                  
*/
size_t TrieSize(const trie_t *trie); /*DONE*/

/*
* TrieFreeLeaf() -
* Counts the number of leafs in the trie.
* undefined behaviour for @trie NULL pointer
* complexity: O(n);                  
*/
void TrieFreeLeaf(trie_t *trie, const unsigned char *ip_address);/*DONE*/

void TrieNextAvilable(trie_t *trie, unsigned char *ip_holder);

bool_t TrieIsLocationAvailable(trie_t *trie, const unsigned char *ip_address);

#endif 