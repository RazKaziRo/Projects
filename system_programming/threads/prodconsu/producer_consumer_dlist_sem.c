#include <pthread.h>  
#include <stdio.h>
#include <semaphore.h> 

#include "../../../ds/include/doublelist.h"

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

#define NUM_OF_PRODUCER 100
#define NUM_OF_CONSUMER 100

enum
{
	UNLOCKED,
	LOCKED
};

dll_t *new_dll = NULL;
pthread_mutex_t  job_queue_mutex = PTHREAD_MUTEX_INITIALIZER; 
sem_t job_queue_count;  

size_t g_i = 0;

void *ProducerFunction(void *param)
{	
	pthread_mutex_lock (&job_queue_mutex);

	++g_i;
	
	printf("Producer ID %lu Push: %lu \n", pthread_self(), g_i);

	if(!DLLPushFront(new_dll, (void *)g_i))
	{
		return NULL;
	}

	sem_post (&job_queue_count);   
	pthread_mutex_unlock (&job_queue_mutex);

	UNUSED(param);
	return NULL;
}

void *ConsumerFunction(void *param)
{

    sem_wait(&job_queue_count);  

	pthread_mutex_lock (&job_queue_mutex);

	printf("Consumer ID %lu Pop: %lu \n",pthread_self(), (size_t )DLLPopBack(new_dll));

	pthread_mutex_unlock  (&job_queue_mutex); 

	UNUSED(param);
	return NULL;
}

int main(int argc, char const *argv[])
{

	pthread_t producer_threads[NUM_OF_PRODUCER] = {0};
	pthread_t consumer_threads[NUM_OF_CONSUMER] = {0};

	size_t i = 0;

	sem_init (&job_queue_count, 0, 0); 
	new_dll = DLLCreate();

	for(i = 0; i < NUM_OF_PRODUCER; ++i)
	{
		pthread_create(&producer_threads[i], NULL, &ProducerFunction, NULL);
	}

	for(i = 0; i < NUM_OF_CONSUMER; ++i)
	{
		pthread_create(&consumer_threads[i], NULL, &ConsumerFunction, NULL);
	}

	for(i = 0; i < NUM_OF_PRODUCER; ++i)
	{
		pthread_join(producer_threads[i], NULL);
	}

	for(i = 0; i < NUM_OF_CONSUMER; ++i)
	{
		pthread_join(consumer_threads[i], NULL);
	}

	RUN_TEST(0 == DLLSize(new_dll), "FAIL");

	DLLDestroy(new_dll);
	sem_destroy(&job_queue_count);

  	UNUSED(argc);
  	UNUSED(argv);

	return 0;
}