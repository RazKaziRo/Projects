#include <pthread.h>  
#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc()*/

#define UNSUSED(x) (void )(x)

typedef struct thread_params  
{ 	
	pthread_t thread;
	size_t start;  
	size_t end; 
	size_t sum;
	size_t the_num;

}threads_struct_t;  

void *CalculateSection(void *param)
{
	threads_struct_t *p= (threads_struct_t *)param;
	size_t i = p->start;

	for(;i <= p->end; ++i)
	{
		if(0 == (p->the_num % i))
		{
			p->sum += i;
		}
	}
	
	return NULL;
}

int main(int argc, char *argv[])
{
	size_t num_to_divide = atoi(argv[1]);
	size_t num_of_sections = atoi(argv[2]);
	size_t sum = 0, i = 0;

	threads_struct_t *threads_struct = malloc(num_of_sections * sizeof(*threads_struct));
	threads_struct_t *threads_runner = threads_struct;

	for(;i < num_of_sections; ++i)
	{	
		threads_runner->start = (i * (num_to_divide / num_of_sections)) + 1;
		threads_runner->end = ((i + 1) * (num_to_divide / num_of_sections));
		threads_runner->the_num = num_to_divide;
		pthread_create(&threads_runner->thread, NULL, &CalculateSection, threads_runner);
		++threads_runner;
	}

	threads_runner = threads_struct;

	for(i = 0; i < num_of_sections; ++i)
	{
		pthread_join(threads_runner->thread, NULL);
		sum += threads_runner->sum;
		++threads_runner;
	}
	
	printf("Sum Of Dividers: %lu", sum);

	UNSUSED	(argc);
	return 0;
}