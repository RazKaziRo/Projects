/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Single Linked List.
 * Date: 03.12.2019
 * Language: C
 * Reviewer: Itai Marienberg
 */

#ifndef __SLL_H__
#define __SLL_H__

#include <stddef.h> /*size_t*/

typedef struct Node
{
    void *data;
    struct Node *next;
}node_t;

typedef int (*action_func)(void *node, void *additional);
typedef int (*match_func)(void *node, void *additional);

/* Creates a new node */
/* WARNING: Doesnt get NULL pointer */
node_t *SLLCreateNode(node_t *next, const void *data); /*DONE*/

/* Destroys the data structure */
/* WARNING: Doesnt get NULL pointer */
void SLLDestroy(node_t *node); /*DONE*/

/* Inserts a new node before the node sent to the function */
/* WARNING: Doesnt get NULL pointer */
int SLLInsert(node_t *node, node_t *next_node);/*DONE*/

/* Inserts a new node after the node sent to the function */
/* WARNING: Doesnt get NULL pointer */
int SLLInsertAfter(node_t *new_node, node_t *previous_node);/*DOME*/

/* Removes the node before the node sent to the function */
/* WARNING: Can't remove last  node */
/* WARNING: Doesnt get NULL pointer */
void SLLRemoveNode(node_t *node);/*DONE*/

/* Removes the node after the node sent to the function */
/* WARNING: Doesnt get NULL pointer */
void SLLRemoveAfter(node_t *node);/*DONE*/

/* Returns a node according to a condition specified by the user */
/* WARNING: Doesnt get NULL pointer */
node_t *SLLGetNode(const node_t *head, match_func match_ptr, void *additional);/*DONE*/

/* Performs a generic operation on all nodes in the data structure */
/* WARNING: Doesnt get NULL pointer */
int SLLForEach(node_t *head, action_func action_ptr, void *additional);/*DONE*/

/* Returns the number of nodes */
/* WARNING: Doesnt get NULL pointer */
size_t SLLSize(const node_t *head);/*DONE*/

/* Flips the direciton of pointing from last to first */
/* WARNING: Doesnt get NULL pointer */
node_t *SLLFlip(node_t *head); /*HEAD*/

/* Checks if a loop occurs in the structure */
/* Returns 0 - loop occurs, 1 - loop doesnt occur */
/* WARNING: Doesnt get NULL pointer */
int SLLHasLoop(const node_t *head);

/* Returns a pointer to the node the create an  */
/* WARNING: Doesnt get NULL pointer */
node_t *SLLFindIntersection(const node_t *head1, const node_t *head2);

#endif
