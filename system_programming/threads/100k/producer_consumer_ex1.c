#include <pthread.h>  
#include <stdio.h>

#define NUM_OF_INTS 1000
#define ARR_START_LOCATION 0

int g_int_arr[NUM_OF_INTS] = {0};
int g_lock = 0;

void *SetArray(void *param)
{	
	size_t i = 0, j = 0;

	for(i = 0; i < NUM_OF_INTS; ++i)
	{
		/*while (1 == g_lock){}*/
		while(__sync_lock_test_and_set (&g_lock, 1));

		for(j = 0; j < NUM_OF_INTS; ++j)
		{
			g_int_arr[j] = i;
		}
		__sync_lock_release(&g_lock);
		g_lock = 1;
	}

	return NULL;
}

void *GetArray(void *param)
{
	size_t i = 0, j = 0;

	for(j = 0; j < NUM_OF_INTS - 1; ++j)
	{
		/*while (0 == g_lock){}*/
		while(__sync_lock_test_and_set (&g_lock, 0));
		
		for(i = 0 ;i < NUM_OF_INTS; ++i)
		{
			printf("%d", g_int_arr[i]);
		}
		printf("\n");
		__sync_lock_release(&g_lock);
		g_lock = 1;

	}

	return NULL;
}

int main(int argc, char const *argv[])
{

	pthread_t producer_tread;
	pthread_t consumer_tread;

	
	pthread_create(&producer_tread, NULL, &SetArray, NULL);
	pthread_create(&consumer_tread, NULL, &GetArray, NULL);

	pthread_join(producer_tread, NULL);
    pthread_join(consumer_tread, NULL);

	return 0;
}

