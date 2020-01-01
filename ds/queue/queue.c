/*
 * Author: Raz KaziRo
 * Purpose: Answares for DS - Queue.
 * Date: 04.12.2019
 * Language: C
 * Reviewer: Eliya Goldfisher
 */
#include <stdlib.h> /* malloc() */
#include <assert.h> /*assert()*/
#include "queue.h" /* Queue API Functions */

#define FREE(ptr) free(ptr); ptr = NULL;
#define DUMMY_NODE_COUNT 2

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
		if (NULL != newQueue->rear)
		{
			newQueue->front = SLLCreateNode(newQueue->rear, NULL);
			if (NULL != newQueue->front)
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
    int status = 0;
    node_t *newNode = NULL;

    assert(NULL != queue);
    assert(NULL != data);

	newNode = SLLCreateNode(NULL, data);
    if (NULL != newNode)
    {
        status = SLLInsert(newNode, queue->rear);
        queue->rear = newNode;   
    }
    return status;
}

void QDequeue(queue_t *queue)
{
    assert(NULL != queue);

	SLLRemoveAfter(queue->front);
}

size_t QSize(const queue_t *queue)
{
    assert(NULL != queue);

	return (SLLSize(queue->front) - DUMMY_NODE_COUNT);
}

void *QPeek(const queue_t *queue)
{
    assert(NULL != queue);

	return(queue->front->next->data);
}

int QIsEmpty(const queue_t *queue)
{
    assert(NULL != queue);

	return(queue->front->next == queue->rear);
}

void QDestroy(queue_t *queue)
{
    assert(NULL != queue);

	SLLDestroy(queue->front);
	FREE(queue);
}

queue_t *QAppend(queue_t *queue1, queue_t *queue2)
{
    assert(NULL != queue1);
    assert(NULL != queue2);
    
	queue1->rear->next = queue2->front;

	SLLRemoveAfter(queue1->rear);
	SLLRemoveNode(queue1->rear);
	queue1->rear = queue2->rear;
	FREE(queue2);

	return queue1;
}



