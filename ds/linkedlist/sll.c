/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Single Linked List.
 * Date: 02.12.2019
 * Language: C
 * Reviewer: 
 */
#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/

#include "sll.h"

node_t *SLLCreateNode(node_t *node, const void *data)
{	
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	if(NULL != newNode)
	{
		newNode->data = (void *)data;
		newNode->next = node;
	}
	return newNode;
}

void SLLDestroy(node_t *current_node)
{	
	node_t *next_runner = current_node->next;
	node_t *temp = NULL;

	while (NULL != next_runner)
	{	
		temp = next_runner;
		next_runner = next_runner->next;
		free(temp);
	}
	current_node->next = NULL;
	free(current_node);
	current_node = NULL;
}

void SLLRemoveNode(node_t *current_node)
{	
	node_t *next_node = current_node->next;

	assert (NULL != current_node);

	while (NULL != next_node)
	{
		current_node->data = next_node->data;
		current_node->next = next_node->next;
		free(next_node);
		next_node = NULL;
	}
}
/*
void SLLDestroy(node_t **node)
{	
	node_t *tmp1 = NULL;
	node_t *tmp2 = NULL; 
	tmp1 = *node;

	assert(NULL != node);

	while (NULL != tmp1)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(*node);
	*node = NULL;
}
*/

/* Node A Before Node B */
int InsertBefore(node_t *node_b, node_t *node_a)
{
	void *tmp_data = node_a->data;

	node_a->next = node_b->next;
	node_a->data = node_b->data;
	node_b->data = tmp_data;
	node_b->next = node_a;

	return 0;
}

int SLLInsertAfter(node_t *new_node, node_t *previous_node)
{	
	new_node->next = previous_node->next;
	previous_node->next = new_node;
	
	return 0;
}

size_t SLLSize(const node_t *head)
{	
	node_t *node_runner = (node_t *)head; 
	size_t count = 0;
	while (NULL != node_runner)
	{	
		node_runner = node_runner->next;
		++count;
	}

	return count;
}

void SLLRemoveAfter(node_t *node)
{
	node_t *next_node = node->next;
	*node->next = *next_node->next;
}
