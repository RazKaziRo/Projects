#ifndef __PRIORITYQ_H__
#define __PRIORITYQ_H__

#include <stddef.h> /*size_t*/

typedef struct PQueue pq_t;

typedef int (*compare_func)(const void *data1, const void *data2, void *param);
typedef int (*match_func)(void *iterator_data, void *action_param);

/**********************************************/
/* Returns pointer to the PQ data structure   */
/* complexity of malloc                       */
/**********************************************/
pq_t *PQCreate(compare_func cmp_ptr, void *param); /*DONE*/

/*************************************************/
/* Destroys the PQ  datastructure and frees it   */ 
/* from memory                                   */
/* complexity of free                            */
/*************************************************/
void PQDestroy(pq_t *pq); /*DONE*/ 

/*****************************************/
/* Gets the PQ structure and pops the    */
/* highest priority element              */
/* Returns the data removed              */
/* complexity O(1)                       */
/*****************************************/
void *PQDequeue(pq_t *pq); 

/*****************************************/
/* Gets the PQ structure and             */
/* Returns the pervious iterator         */
/* complexity O(1)                       */
/*****************************************/
int PQEnqueue(pq_t *pq, void *data); /*DONE*/ 

/*********************************************************************/
/* gets the data structure and returns the data wof the highest      */
/* priority element                                                  */
/* complexity O(1)                                                   */
/*********************************************************************/    
void *PQPeek(const pq_t *pq); /*DONE*/

/*********************************************************************/    
/* gets the data structure and returns the number of elements        */                                           
/* complexity O(n)                                                   */
/*********************************************************************/    
size_t PQSize(const pq_t *pq); /*DONE*/

/***********************************************/
/* Checks whether the data structure is empty  */
/* returns 1 if its empty or 0 if not empty    */
/* complexity O(1)                             */
/***********************************************/
int PQIsEmpty(const pq_t *pq); /*DONE*/

/***********************************************/
/* gets the data structure and removes its     */
/* elements                                    */
/* complexity O(n)                             */
/***********************************************/
void PQClear(pq_t *pq); /*DONE*/

/************************************************/
/* gets the data structure and a data to search,*/
/* once the element is found, its removed       */
/* complexity O(1)                              */
/************************************************/
void *PQErase(pq_t *pq, match_func m_ptr, const void *data); /*DONE*/

void PQHeapifyUp(void *arr, size_t size, size_t index, size_t element_size, compare_func cmp, void *param);

void PQHeapifyDown(void *arr, size_t size, size_t index, size_t element_size, compare_func cmp, void *param);


#endif