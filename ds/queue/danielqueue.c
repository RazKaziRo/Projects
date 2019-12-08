/*********************************/
/*    Data Structures            */
/*    Linked List                */
/*    Author : Daniel Ifrah      */
/*    Reviewed By:               */
/*    Date:    4/12/2019         */
/*                               */
/*********************************/

#include <stdlib.h>  /* malloc */
#include <assert.h>  /* assert */

#include "queue.h"

struct Queue
{
    node_t *front;
    node_t *rear;
};

queue_t *QCreate()
{
	queue_t *new_queue = NULL;
    new_queue = (queue_t*)malloc(sizeof(queue_t));
    if (NULL == new_queue)
    {
    	return NULL;
    } 

    new_queue->rear = SLLCreateNode(NULL, NULL);
     if (NULL == new_queue->rear)
    {
    	free(new_queue);
    	return NULL;
    } 

    new_queue->front = SLLCreateNode(new_queue->rear, NULL);
    if (NULL == new_queue->rear)
    {
    	free(new_queue->front); new_queue->front = NULL;
    	free(new_queue); new_queue = NULL;
    	return NULL;
    } 

    return new_queue;  
}

void QDestroy(queue_t *queue)
{
	assert(NULL != queue);

	SLLDestroy(queue->front);
	free(queue); queue = NULL;
}

int QEnqueue(queue_t *queue, void *data)
{
	node_t *new_node = NULL;

	assert(NULL != queue);

   new_node = SLLCreateNode(NULL,data);
   if (NULL == new_node)
   {
   		return 1;
   }

   SLLInsert(new_node,queue->rear);
   queue->rear = new_node;

	return 0;
}

void QDequeue(queue_t *queue)
{
	assert(NULL != queue);

	SLLRemoveAfter(queue->front);
}

int QIsEmpty(const queue_t *queue)
{
	return (queue->front == queue->rear);
}

void *QPeek(const queue_t *queue)
{
	return queue->front->next->data;
}

size_t QSize(const queue_t *queue)
{
	node_t *runner = queue->front->next;
	size_t size = 0;

	assert(NULL != queue);

	while (runner != queue->rear)
	{
		++size;
		runner = runner->next;
	}

	return size;
}

queue_t *QAppend(queue_t *queue1, queue_t *queue2)
{
	assert(NULL !=queue1);
	assert(NULL !=queue2);

	queue1->rear->next = queue2->front;
	SLLRemoveNode(queue1->rear);
	SLLRemoveNode(queue1->rear);
	queue1->rear = queue2->rear;
	free(queue2); queue2 = NULL;

	return queue1;
}