/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Single Linked List.
 * Date: 03.12.2019
 * Language: C
 * Reviewer: Itai Marienberg
 */

#include <stdlib.h> /*malloc()*/
#include <assert.h> /*assert()*/

#include "sll.h" /*Single Linked List API Functions*/

node_t *SLLCreateNode(node_t *node, const void *data)
{	
	node_t *newNode = (node_t *)malloc(sizeof(node_t));

	assert(NULL != data);

	if (NULL != newNode)
	{
		newNode->data = (void *)data;
		newNode->next = node;
	}

	return newNode;
}

void SLLDestroy(node_t *current_node)
{	
    node_t *tmp_current = NULL;
    
    assert(NULL != current_node);

    while (NULL != current_node)
    {
       tmp_current = current_node;
       current_node = current_node->next;
       free(tmp_current);
    }
}

int SLLInsert(node_t *node_a, node_t *node_b)
{
	void *tmp_data = NULL;;

	assert(NULL != node_a);
	assert(NULL != node_b);

	tmp_data = node_a->data;
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
	node_t *node_runner = NULL;
	size_t count = 0;

	assert(NULL != head);

	node_runner = (node_t *)head;

	while (NULL != node_runner)
	{	
		node_runner = node_runner->next;
		++count;
	}

	return count;
}

void SLLRemoveNode(node_t *current_node)
{	
	node_t *next_node = NULL;

	assert(NULL != current_node);

	next_node = current_node->next;	

	while (NULL != next_node)
	{
		current_node->data = next_node->data;
		current_node->next = next_node->next;
		free(next_node);
		next_node = NULL;
	}
}

void SLLRemoveAfter(node_t *current_node)
{	
	node_t *next_node = NULL;

	assert(NULL != current_node);

	if (NULL != current_node->next)
	{
		next_node = current_node->next;
		current_node->next = next_node->next;
		free(next_node);
		next_node = NULL;
	}
}

node_t *SLLGetNode(const node_t *head, match_func match_ptr, void *additional)
{
	node_t *node_runner = NULL;

	assert(NULL != head);
	assert(NULL != match_ptr);
	assert(NULL != additional);

	node_runner = (node_t *)head;

	while (0 == match_ptr(node_runner, additional))
	{
		node_runner = node_runner->next;
	}
	
	return node_runner;
}

int SLLForEach(node_t *head, action_func action_ptr, void *additional)
{	
	node_t *node_runner = NULL;

	assert(NULL != head);
	assert(NULL != action_ptr);
	assert(NULL != additional);

	node_runner = (node_t *)head;

	while (0 == action_ptr(node_runner, additional) && NULL != node_runner)
	{
		node_runner = node_runner->next;
	}

	return !(NULL == node_runner);
}

node_t *SLLFlip(node_t *head)
{
	node_t *current_node = NULL; 
	node_t *next_node = NULL;
	node_t *prev_node = NULL;

	assert(NULL != head);

	current_node = head;

	while (NULL != current_node)
	{
		next_node = current_node->next;
		current_node->next = prev_node;
		prev_node = current_node;
		current_node = next_node;
	}
	head = prev_node;

	return head;
}

int SLLHasLoop(const node_t *head)
{		
	const node_t *slow_p = NULL, *fast_p = NULL;

	assert(NULL != head);

	slow_p = head;
	fast_p = head->next;

    while (slow_p && fast_p && fast_p->next && (slow_p != fast_p)) 
    { 
        slow_p = slow_p->next; 
        fast_p = fast_p->next->next;
    }

    return (slow_p == fast_p);
}

node_t *SLLFindIntersection(const node_t *head1, const node_t *head2)
{
	const node_t *head1_runner = NULL;
	const node_t *head2_runner = NULL;

	size_t size1 = 0;
	size_t size2 = 0;
	size_t steps = 0, i = 0;

	assert(NULL != head1);
	assert(NULL != head2);

	head1_runner = head1;
	head2_runner = head2;
	size1 = SLLSize(head1);
	size2 = SLLSize(head2);

	steps = size1 > size2 ? (size1 - size2) : (size2 - size1);

	if (size1 > size2)
	{
		for(; i < steps; ++i)
		{
			head1_runner = head1->next;
		}
	}
	else
	{
		for (; i < steps; ++i)
		{
			head2_runner = head2->next;
		}
	}

	while (NULL != head1_runner && NULL != head2_runner)
	{
		if (head1_runner == head2_runner)
		{
			return (node_t *)head1_runner;
		}

		head1_runner = head1_runner->next;
		head2_runner = head2_runner->next;
	}

	return (node_t *)head1_runner;
}



