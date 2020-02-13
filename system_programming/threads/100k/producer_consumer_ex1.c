#include <pthread.h>  
#include <stdio.h>

#define NUM_OF_INTS 1000
#define ARR_START_LOCATION 0

int g_int_arr[NUM_OF_INTS] = {0};
volatile int g_lock = 0;

void *SetArray(void *param)
{	
	size_t i = 0;
	size_t j = 0;
	while (__sync_lock_test_and_set(&g_lock, 0));

	if(!g_lock)
	{
		for(; i < NUM_OF_INTS; ++i)
		{
			for(;j < NUM_OF_INTS; ++j)
			{
				g_int_arr[i] += j;
			}
		}
		g_lock = 1;
	}

	__sync_lock_release(&g_lock);

	return NULL;
}

void *GetArray(void *param)
{
	size_t i = 0;
	size_t j =0;

	while (__sync_lock_test_and_set(&g_lock, 1));

	if(g_lock)
	{
		for(; i < NUM_OF_INTS; ++i)
		{
			for(; j < NUM_OF_INTS; ++j)
			{
				printf("%d", g_int_arr[i]);
			}
		}
	g_lock = 0;
	}
	__sync_lock_release(&g_lock);
	return NULL;
}

int main(int argc, char const *argv[])
{

	pthread_t producer_tread;
	pthread_t consumer_tread;
	size_t i = 0;


	pthread_create(&producer_tread, NULL, &SetArray, NULL);
	pthread_create(&consumer_tread, NULL, &GetArray, NULL);

	pthread_join(producer_tread, NULL);
    pthread_join(consumer_tread, NULL);

	return 0;
}

