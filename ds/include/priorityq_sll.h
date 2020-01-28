#ifndef __PRIORITYQ_H__
#define __PRIORITYQ_H__

#include <stddef.h> /*size_t*/

typedef struct SLLPQueue SLLPQ_t;

typedef int (*compare_func)(const void *data1, const void *data2, void *param);
typedef int (*match_func)(void *iterator_data, void *action_param);

/**********************************************/
/* Returns pointer to the SLLPQ data structure   */
/* complexity of malloc                       */
/**********************************************/
SLLPQ_t *SLLPQCreate(compare_func cmp_ptr, void *param); /*DONE*/

/*************************************************/
/* Destroys the SLLPQ  datastructure and frees it   */ 
/* from memory                                   */
/* complexity of free                            */
/*************************************************/
void SLLPQDestroy(SLLPQ_t *SLLPQ); /*DONE*/ 

/*****************************************/
/* Gets the SLLPQ structure and pops the    */
/* highest priority element              */
/* Returns the data removed              */
/* complexity O(1)                       */
/*****************************************/
void *SLLPQDequeue(SLLPQ_t *SLLPQ); /*DONE*/

/*****************************************/
/* Gets the SLLPQ structure and             */
/* Returns the pervious iterator         */
/* complexity O(1)                       */
/*****************************************/
int SLLPQEnqueue(SLLPQ_t *SLLPQ, void *data); /*DONE*/ 

/*********************************************************************/
/* gets the data structure and returns the data wof the highest      */
/* priority element                                                  */
/* complexity O(1)                                                   */
/*********************************************************************/    
void *SLLPQPeek(const SLLPQ_t *SLLPQ);/*DONE*/

/*********************************************************************/    
/* gets the data structure and returns the number of elements        */                                           
/* complexity O(n)                                                   */
/*********************************************************************/    
size_t SLLPQSize(const SLLPQ_t *SLLPQ); /*DONE*/

/***********************************************/
/* Checks whether the data structure is empty  */
/* returns 1 if its empty or 0 if not empty    */
/* complexity O(1)                             */
/***********************************************/
int SLLPQIsEmpty(const SLLPQ_t *SLLPQ); /*DONE*/

/***********************************************/
/* gets the data structure and removes its     */
/* elements                                    */
/* complexity O(n)                             */
/***********************************************/
void SLLPQClear(SLLPQ_t *SLLPQ); /*DONE*/

/************************************************/
/* gets the data structure and a data to search,*/
/* once the element is found, its removed       */
/* complexity O(1)                              */
/************************************************/
void *SLLPQErase(SLLPQ_t *SLLPQ, match_func m_ptr, const void *data); /*DONE*/

#endif