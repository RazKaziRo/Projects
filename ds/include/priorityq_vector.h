#ifndef __PRIORITYQ_H__
#define __PRIORITYQ_H__

#include <stddef.h> /*size_t*/

typedef struct VECPQueue vecpq_t;

typedef int (*compare_func)(const void *data1, const void *data2, void *param);
typedef int (*match_func)(void *iterator_data, void *action_param);

/**********************************************/
/* Returns pointer to the VECPQ data structure   */
/* complexity of malloc                       */
/**********************************************/
vecpq_t *VECPQCreate(compare_func cmp_ptr, void *param); /*DONE*/

/*************************************************/
/* Destroys the VECPQ  datastructure and frees it   */ 
/* from memory                                   */
/* complexity of free                            */
/*************************************************/
void VECPQDestroy(vecpq_t *vecpq_t); /*DONE*/ 

/*****************************************/
/* Gets the VECPQ structure and pops the    */
/* highest priority element              */
/* Returns the data removed              */
/* complexity O(1)                       */
/*****************************************/
void *VECPQDequeue(vecpq_t *vecpq); 

/*****************************************/
/* Gets the VECPQ structure and             */
/* Returns the pervious iterator         */
/* complexity O(1)                       */
/*****************************************/
int VECPQEnqueue(vecpq_t *vecpq, void *data); /*DONE*/ 

/*********************************************************************/
/* gets the data structure and returns the data wof the highest      */
/* priority element                                                  */
/* complexity O(1)                                                   */
/*********************************************************************/    
void *VECPQPeek(const vecpq_t *vecpq); /*DONE*/

/*********************************************************************/    
/* gets the data structure and returns the number of elements        */                                           
/* complexity O(n)                                                   */
/*********************************************************************/    
size_t VECPQSize(const vecpq_t *vecpq); /*DONE*/

/***********************************************/
/* Checks whether the data structure is empty  */
/* returns 1 if its empty or 0 if not empty    */
/* complexity O(1)                             */
/***********************************************/
int VECPQIsEmpty(const vecpq_t *vecpq); /*DONE*/

/***********************************************/
/* gets the data structure and removes its     */
/* elements                                    */
/* complexity O(n)                             */
/***********************************************/
void VECPQClear(vecpq_t *vecpq); /*DONE*/

/************************************************/
/* gets the data structure and a data to search,*/
/* once the element is found, its removed       */
/* complexity O(1)                              */
/************************************************/
void *VECPQErase(vecpq_t *vecpq, match_func m_ptr, const void *data); /*DONE*/

void VECPQHeapifyUp(void *arr, size_t size, size_t index, size_t element_size, compare_func cmp, void *param);

void VECPQHeapifyDown(void *arr, size_t size, size_t index, size_t element_size, compare_func cmp, void *param);


#endif