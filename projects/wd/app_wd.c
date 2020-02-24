#include <stdio.h>
#include <sys/types.h> /*getpid()*/
#include <unistd.h>
#include "wd_api_func.h"

#define NUM_OF_ITERATIONS 10
int g_arr[NUM_OF_ITERATIONS] = {0};

int main(int argc, char const *argv[])
{
	wd_status_t status;
	wd_t *app_wd = NULL;

	size_t i = 0;
	printf("APP PID: %d \n", getpid());

	app_wd = WDStart(argv[0], &status);

	for(; i < NUM_OF_ITERATIONS; ++i)
	{
		sleep(1);
		g_arr[i] = i;
	}

	WDStop(app_wd);

	return 0;
}