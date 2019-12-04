/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Queue.
 * Date: 04.12.2019
 * Language: C
 * Reviewer: Eliya Goldfisher
 */
#include <stdlib.h> /* malloc() */

#include "queue.h" /* Queue API Functions */

#define FREE(ptr) free(ptr); ptr = NULL;

struct Queue
{
	node_t *front;
	node_t *rear;
};

queue_t *QCreate()
{
	queue_t *newQueue = (queue_t *)malloc(sizeof(queue_t));
	if (NULL != newQueue)
	{
		newQueue->rear = SLLCreateNode(NULL, NULL);
		if(NULL != newQueue->rear)
		{
			newQueue->front = SLLCreateNode(newQueue->rear, NULL);
			if(NULL != newQueue->front)
			{
				return newQueue;
			}
			SLLDestroy(newQueue->rear);
		}
	}
	FREE(newQueue);
	return NULL;
}

int QEnqueue(queue_t *queue, void *data)
{	
	node_t *newNode = SLLCreateNode(NULL, data);
	SLLInsert(newNode, queue->rear);
	queue->rear = newNode;
}

void QDequeue(queue_t *queue)
{
	SLLRemoveAfter(queue->front);
}

size_t QSize(const queue_t *queue)
{
	node_t *runner = queue->front->next;
	size_t counter = 0;

	while(queue->rear != runner)
	{	
		runner = runner->next;
		++counter;
	}

	return counter;
}

void *QPeek(const queue_t *queue)
{
	return(queue->front->next->data);
}

int QIsEmpty(const queue_t *queue)
{
	return(queue->front->next == queue->rear);
}

void QDestroy(queue_t *queue)
{
	SLLDestroy(queue->front);
	FREE(queue);
}

queue_t *QAppend(queue_t *queue1, queue_t *queue2)
{
	queue1->rear->next = queue2->front;

	SLLRemoveAfter(queue1->rear);
	SLLRemoveNode(queue1->rear);
	queue1->rear = queue2->rear;
	FREE(queue2);

	return (queue1);
}



