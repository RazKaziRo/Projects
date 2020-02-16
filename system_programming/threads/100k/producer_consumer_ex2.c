#include <pthread.h>  
#include <stdio.h>

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

#define NUM_OF_ELEMENTS 100
#define NUM_TO_PRODUCE 10
#define ARR_START_LOCATION 0

enum
{
	UNLOCKED,
	LOCKED
};

int g_int_arr[NUM_OF_ELEMENTS] = {0};

int g_producer_lock = UNLOCKED;
int g_consumer_lock = LOCKED;


void *ProducerFunction(void *param)
{	
	size_t i = 0, j = 0;

	for(i = 0; i < NUM_OF_ELEMENTS; ++i)
	{	
		while (__sync_lock_test_and_set (&g_producer_lock, LOCKED));

		for(j = 0; j < NUM_TO_PRODUCE; ++j)
		{
			g_int_arr[j] = i;
		}
		__sync_lock_release(&g_consumer_lock);
	}

	return NULL;
}

void *ConsumerFunction(void *param)
{
	size_t i = 0, j = 0;

	for(i = 0; i < NUM_OF_ELEMENTS; ++i)
	{	
		while (__sync_lock_test_and_set (&g_consumer_lock, LOCKED));

		for(j = 0; j < NUM_TO_PRODUCE; ++j)
		{
			printf("%d", g_int_arr[j]);
		}
		printf("\n");

		__sync_lock_release(&g_producer_lock);
	}

	return NULL;
}

int main(int argc, char const *argv[])
{

	pthread_t producer_tread = {0};
	pthread_t consumer_tread = {0};

	pthread_create(&producer_tread, NULL, &ProducerFunction, NULL);
	pthread_create(&consumer_tread, NULL, &ConsumerFunction, NULL);

	pthread_join(producer_tread, NULL);
  	pthread_join(consumer_tread, NULL);

	return 0;
}