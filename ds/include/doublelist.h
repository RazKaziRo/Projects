#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#include <stddef.h> /* size_t */

typedef struct DLLNode *iterator_t;
typedef struct DLL dll_t;

typedef int (*action_func_ptr)(void *iterator_data, void *ap);
typedef int (*match_func_ptr)(void *iterator_data, void *ap);

/**********************************************/
/* Returns pointer to the DLL data structure  */
/* complexity of malloc                       */
/**********************************************/
dll_t *DLLCreate(); /*DONE*/

/*************************************************/
/* Destroys the DLL data and free it from memory */
/* complexity of free                            */
/*************************************************/
void DLLDestroy(dll_t *dll); /*DONE*/

/*****************************************/
/* Gets a iterator                       */
/* Returns the next iterator             */
/* complexity O(1)                       */
/*****************************************/
iterator_t DLLGetNext(iterator_t it); /*DONE*/

/*****************************************/
/* Gets a iterator                       */
/* Returns the pervious iterator         */
/* complexity O(1)                       */
/*****************************************/
iterator_t DLLGetPrev(iterator_t it); /*DONE*/

/*********************************************************************/
/* Gets a pointer to a data structure, a iterator and a data pointer */
/* and inserts a iterator after the iterator sent with its data      */
/* complexity O(1)                                                   */
/*********************************************************************/    
iterator_t DLLInsert(dll_t *dll, iterator_t prev, void *data); /*DONE*/

/*********************************************************************/    
/* Removes the iterator sent to it and returns the iterator next     */
/* to the iterator removed                                           */
/* complexity O(1)                                                   */
/*********************************************************************/    
iterator_t DLLRemove(iterator_t it);/*DONE*/

/***********************************************/
/* Checks if the DLL is empty                  */
/* returns 1 if its empty or 0 if not empty    */
/* complexity O(1)                             */
/***********************************************/
int DLLIsEmpty(const dll_t *dll); /*DONE*/

/***********************************************/
/* Returns the size of the DLL                 */
/* complexity O(n)                             */
/***********************************************/
size_t DLLSize(const dll_t *dll);/*DONE*/

/***********************************************/
/* Returns the first iterator                  */
/* complexity O(1)                             */
/***********************************************/
iterator_t DLLBegin(const dll_t *dll); /*DONE*/

/***********************************************/
/* Returns the last iterator                   */
/* complexity O(1)                             */
/***********************************************/
iterator_t DLLEnd(dll_t *dll); /*DONE*/

/***********************************************/
/* Returns the data of the current iterator    */
/* complexity O(1)                             */
/***********************************************/
void *DLLGetData(iterator_t it); /*DONE*/

/*********************************************************/
/* Returns 1 if the iterators are equal or 0 otherwise   */
/* complexity O(1)                                       */
/*********************************************************/
int DLLIsSameIter(const iterator_t it1, const iterator_t it2); /*DONE*/

/*******************************************************/
/* Adds an iterator with the data sent to the function */
/* to the end of the data structure                    */
/* complexity O(1)                                     */
/*******************************************************/
iterator_t DLLPushBack(dll_t *dll, void *data); /*DONE*/

/**********************************************************************/
/* Removes the iterator sent to it from the end of the data structure */
/* complexity O(1)                                                    */
/**********************************************************************/
void *DLLPopBack(dll_t *dll);/*DONE*/

/******************************************************/
/* Adds a iterator with the data sent to the function */
/* to the head of the data structure                   */
/* complexity O(1)                                    */
/******************************************************/
iterator_t DLLPushFront(dll_t *dll, void *data);/*DONE*/

/***********************************************************************/
/* Removes the iterator sent to it from the head of the data structure */
/* complexity O(1)                                                     */
/***********************************************************************/
void *DLLPopFront(dll_t *dll); /*DONE*/

/*************************************************************************/
/* Returns a new list that contains the elements between the iterators   */
/* start and end                                                         */
/* complexity O(1)                                                       */  
/*************************************************************************/    
iterator_t DLLSplice(iterator_t start, iterator_t end, iterator_t where);

/********************************************************************/
/* Performs an action defined by a pointer to a function on all the */ 
/* iterators from the start to end.                                 */
/* return 0 if succeeds or 1 if fails                               */
/* complexity O(n)                                                  */
/********************************************************************/
int DLLForEach(iterator_t start, iterator_t end, action_func_ptr a_ptr, void *ap);

/********************************************************************/
/* Traverse the list and returns the first iterator that matchs     */
/* a condition defined by the function                              */
/* complexity O(n)                                                  */
/********************************************************************/
iterator_t DLLFind(iterator_t start, iterator_t end, match_func_ptr m_ptr, void *ap);

#endif

