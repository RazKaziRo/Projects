#include <pthread.h>  
#include <stdio.h>
#include <semaphore.h> 


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

#define NUM_OF_CONSUMERS 10

enum
{
	CLOSE,
	OPEN
};

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t producer_wait_cv;

sem_t consumer_queue_count;

int g_data = 0;

void *ProducerFunction(void *param)
{
	size_t i = 0;

	while(1)
	{
		for(i = 0; i < NUM_OF_CONSUMERS; ++i)
		{	
			sem_wait(&consumer_queue_count);
		}

		pthread_mutex_lock (&job_queue_mutex); 

			printf("Producer ID: %lu Write: %d \n", pthread_self(), ++g_data);

			pthread_cond_broadcast(&producer_wait_cv);
			
		pthread_mutex_unlock (&job_queue_mutex);

	}

	UNUSED(param);
	return NULL;
}

void *ConsumerFunction(void *param)
{
	while(1)
	{
		int local_data = g_data;

		pthread_mutex_lock (&job_queue_mutex);    

			sem_post(&consumer_queue_count);

			while(g_data == local_data)
			{	
				pthread_cond_wait(&producer_wait_cv, &job_queue_mutex);
			}

			printf("Consumer ID: %lu Read: %d \n",pthread_self(), g_data);

		pthread_mutex_unlock (&job_queue_mutex); 

	}

	UNUSED(param);
	return NULL;
}

int main(int argc, char const *argv[])
{

	pthread_t producer_thread = 0;
	pthread_t consumer_threads[NUM_OF_CONSUMERS] = {0};
	size_t i = 0;

	pthread_cond_init (&producer_wait_cv, NULL);  
	sem_init (&consumer_queue_count, 0, 0); 

	pthread_create(&producer_thread, NULL, &ProducerFunction, NULL);

	for(i = 0; i < NUM_OF_CONSUMERS; ++i)
	{
		pthread_create(&consumer_threads[i], NULL, &ConsumerFunction, NULL);
	}

	pthread_join(producer_thread, NULL);

	for(i = 0; i < NUM_OF_CONSUMERS; ++i)
	{
		pthread_join(consumer_threads[i], NULL);
	}

	UNUSED(argv);
	UNUSED(argc);
	return 0;
}