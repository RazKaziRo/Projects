#include <pthread.h>  
#include <stdio.h>
#include <semaphore.h> 

#include "cbuffer_overflow.h"
#define RUN_TEST(test, errmsg)\
							{\
								if(test)\
								{\
									printf("SUCCESS\n");\
								}\
								else\
								{\
									printf("\033[1;31m");\
									printf("%s", errmsg);\
									printf("\033[0m");\
								}\
							}

#define UNUSED(x) (void)(x)

#define NUM_OF_THREADS 100
#define CBUFFER_CAPACITY 100

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER; 

sem_t write_queue_count;  
sem_t read_queue_count;  

int g_i = 1;

void *ProducerWriteFunction(void *param) /*WRITE*/
{	
	cbuffer_t *cbuffer = (cbuffer_t*)param;

	sem_wait(&write_queue_count);

	pthread_mutex_lock (&job_queue_mutex);
	
	printf("Producer ID: %lu Write: %d \n", pthread_self(), g_i);

	CBufferWrite(cbuffer, g_i);
	++g_i;

	sem_post (&read_queue_count);  /*++READ INDEX*/

	pthread_mutex_unlock (&job_queue_mutex); 

	UNUSED(param);
	return NULL;
}

void *ConsumerReadFunction(void *param) /*READ*/
{	
	cbuffer_t *cbuffer = (cbuffer_t*)param;

	sem_wait(&read_queue_count); 

	pthread_mutex_lock(&job_queue_mutex);

	printf("Consumer ID: %lu Read: %d \n",pthread_self(), CBufferRead(cbuffer));

	sem_post(&write_queue_count);  /*++WRITE INDEX*/

	pthread_mutex_unlock(&job_queue_mutex); 

	UNUSED(param);
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t producer_threads[NUM_OF_THREADS] = {0};
	pthread_t consumer_threads[NUM_OF_THREADS] = {0};
	size_t i = 0;

	size_t cbuffer_capacity = CBUFFER_CAPACITY;
	cbuffer_t *new_cbuffer = CBufferCreate (cbuffer_capacity);

	sem_init (&write_queue_count, 0, CBUFFER_CAPACITY); 
	sem_init (&read_queue_count, 0, 0); 

	for(i = 0; i < NUM_OF_THREADS; ++i)
	{
		pthread_create(&producer_threads[i], NULL, &ProducerWriteFunction, new_cbuffer);
		pthread_create(&consumer_threads[i], NULL, &ConsumerReadFunction, new_cbuffer);
	}

	for(i = 0; i < NUM_OF_THREADS; ++i)
	{
		pthread_join(producer_threads[i], NULL);
		pthread_join(consumer_threads[i], NULL);
	}

	CBufferDestroy(new_cbuffer);

	return 0;
}

