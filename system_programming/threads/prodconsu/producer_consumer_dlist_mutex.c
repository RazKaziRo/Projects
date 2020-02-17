#include <pthread.h>  
#include <stdio.h>

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

#define NUM_OF_THREADS 100

enum
{
	UNLOCKED,
	LOCKED
};

dll_t *new_dll = NULL;

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER; 

size_t g_i = 0;

void *ProducerFunction(void *param)
{	
	pthread_mutex_lock (&job_queue_mutex);

	++g_i;
	
	printf("Producer Push: %lu \n", g_i);

	if(!DLLPushFront(new_dll, (void *)g_i))
	{
		return NULL;
	}

	pthread_mutex_unlock (&job_queue_mutex);

	UNUSED(param);
	return NULL;
}

void *ConsumerFunction(void *param)
{
	int milli_seconds = 1000 * 6000; 
    clock_t start_time = clock(); 

    while (clock() < start_time + milli_seconds) 
	{
		pthread_mutex_lock (&job_queue_mutex);

		if(!DLLIsEmpty(new_dll))
		{
			printf("Consumer Pop: %lu \n", (size_t )DLLPopBack(new_dll));
		}

		pthread_mutex_unlock (&job_queue_mutex); 

	}

	UNUSED(param);
	return NULL;
}

int main(int argc, char const *argv[])
{

	pthread_t producer_threads[NUM_OF_THREADS] = {0};
	pthread_t consumer_threads[NUM_OF_THREADS] = {0};

	size_t i = 0;

	new_dll = DLLCreate();

	for(i = 0; i < NUM_OF_THREADS; ++i)
	{
		pthread_create(&producer_threads[i], NULL, &ProducerFunction, NULL);
		pthread_create(&consumer_threads[i], NULL, &ConsumerFunction, NULL);
	}

	for(i = 0; i < NUM_OF_THREADS; ++i)
	{
		pthread_join(producer_threads[i], NULL);
		pthread_join(consumer_threads[i], NULL);
	}

	RUN_TEST(0 == DLLSize(new_dll), "FAIL");

	DLLDestroy(new_dll);

  	UNUSED(argc);
  	UNUSED(argv);

	return 0;
}