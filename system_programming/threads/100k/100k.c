#include <pthread.h>  
#include <unistd.h> /*sleep()*/
#include <stdio.h> /*printf()*/

#define NUM_OF_ELEMENTS 100000

struct thread_params  
{ 
	int num;  
	int count;  
};  

int arr[NUM_OF_ELEMENTS] = {0};

void *thread_func_using_struct(void *param)
{	
	struct thread_params *p= (struct thread_params *)param;
	arr[p->count] = p->num;

	return NULL;
}

void *thread_func_using_i(void *param)
{	
	arr[(int)param] = 1;

	return NULL;
}

size_t SumArray()
{
	size_t i = 0;
	size_t counter = 0;

	for(;i < NUM_OF_ELEMENTS; ++i)
	{
		counter += arr[i];
	}

	return counter;
}

int main()
{
	pthread_t threads[NUM_OF_ELEMENTS];
	struct  thread_params thread_args;
	size_t i = 0;

	thread_args.num = 1;

	for(; i <= NUM_OF_ELEMENTS; ++i)
	{
		thread_args.count = i;

		while(0 != pthread_create(&threads[i],  NULL,  &thread_func_using_i, (void *)i))
		{
			
		}

		pthread_detach(threads[i]);
	}

	/*sleep(10);*/

	printf("Sum Of Array: %lu", SumArray());

	return 0;
}