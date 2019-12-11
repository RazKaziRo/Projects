#ifndef __SORT_LIST_H__
#define __SORT_LIST_H__

#include <stddef.h> /* size_t */

#include "../doublelist/doublelist.h"

typedef struct Iterator
{
	struct DLLNode *current;
}sll_iterator_t;

typedef struct SLL sll_t;

typedef int (*is_before)(const void *data1, const void *data2, void *param);

/**********************************************/
/* Returns pointer to the sll data structure  */
/* complexity of malloc                       */
/**********************************************/
sll_t *SortLLCreate(is_before func, void *param); /*DONE*/

/*************************************************/
/* Destroys the sll data and free it from memory */
/* complexity of free                            */
/*************************************************/
void SortLLDestroy(sll_t *sll); /*DONE*/

/*****************************************/
/* Gets a iterator                       */
/* Returns the current iterator          */
/* complexity O(n)                       */
/*****************************************/
sll_iterator_t SortLLInsert(sll_t *sll, void *data);

/*********************************************************************/    
/* Removes the iterator sent to it and returns the iterator next     */
/* to the iterator removed                                           */
/* complexity O(1)                                                   */
/*********************************************************************/    
sll_iterator_t SortLLRemove(sll_iterator_t sll_it); /*DONE*/

/***********************************************/
/* Checks if the SLL is empty                  */
/* returns 1 if its empty or 0 if not empty    */
/* complexity O(1)                             */
/***********************************************/
int SLLIsEmpty(const sll_t *sll); /*DONE*/

/***********************************************/
/* Returns the size of the SLL                 */
/* complexity O(n)                             */
/***********************************************/
size_t SLLSize(const sll_t *sll); /*DONE*/

/***********************************************/
/* Returns the first iterator                  */
/* complexity O(1)                             */
/***********************************************/
sll_iterator_t SLLBegin(const sll_t *sll); /*DONE*/

/***********************************************/
/* Returns the last iterator                   */
/* complexity O(1)                             */
/***********************************************/
sll_iterator_t SLLEnd(sll_t *sll); /*DONE*/

/***********************************************/
/* Returns the next iterator                   */
/* complexity O(1)                             */
/***********************************************/
sll_iterator_t SLLNext(sll_iterator_t it); /*DONE*/

/***********************************************/
/* Returns the previos iterator                */
/* complexity O(1)                             */
/***********************************************/
sll_iterator_t SLLPrev(sll_iterator_t it); /*DONE*/

/***********************************************/
/* Returns the data of the current iterator    */
/* complexity O(1)                             */
/***********************************************/
void *SLLGetData(sll_iterator_t it); /*DONE*/

/*********************************************************/
/* Returns 1 if the iterators are equal or 0 otherwise   */
/* complexity O(1)                                       */
/*********************************************************/
int SLLIsSameIter(const sll_iterator_t it1, const sll_iterator_t it2); /*DONE*/

/**********************************************************************/
/* Removes the iterator sent to it from the end of the data structure */
/* complexity O(1)                                                    */
/**********************************************************************/
void* SLLPopBack(sll_t *sll); /*DONE*/

/***********************************************************************/
/* Removes the iterator sent to it from the head of the data structure */
/* complexity O(1)                                                     */
/***********************************************************************/
void* SLLPopFront(sll_t *sll); /*DONE*/

/********************************************************************/
/* Performs an action defined by a pointer to a function on all the */ 
/* run on the iterators from the start up to end(not include)       */
/* return 0 if succeeds or 1 if fails                               */
/* complexity O(n)                                                  */
/********************************************************************/
int SLLForEach(sll_iterator_t start, sll_iterator_t end, action_func_ptr a_ptr, void *ap); /*DONE*/

/********************************************************************/
/* Traverse the list and returns the first iterator that matchs     */
/* a condition defined by the function that sent in create          */ 
/* run on the iterators from the start up to end(not include)       */
/* complexity O(n)                                                  */
/********************************************************************/
sll_iterator_t SLLFind(const sll_t *sll, const void *data, sll_iterator_t start, sll_iterator_t end); /*DONE*/

/********************************************************************/
/* Traverse the list and returns the first iterator that matchs     */
/* a condition defined by the function                              */
/* complexity O(n)                                                  */
/********************************************************************/
sll_iterator_t SLLFindBy(const sll_t *sll, sll_iterator_t start , sll_iterator_t end, /*DONE*/
                                        match_func_ptr m_ptr ,const void *data);

/**************************************/
/* Gets 2 lists                       */
/* Return merged list into dest       */
/* complexity:                        */
/**************************************/                                        
void SLLMerge(sll_t *dest, sll_t *src);                                        

#endif