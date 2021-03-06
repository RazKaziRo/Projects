#include <sys/types.h> /*getpid()*/
#include <unistd.h>  /*getpid()*/

#include "wd_api_func.h"

#define NUM_OF_ITERATIONS 1

int g_arr[NUM_OF_ITERATIONS] = {0};

int main(int argc, char const *argv[])
{
	wd_status_t status = 0;
	wd_t *app_wd = NULL;

	size_t i = 0;
	printf("APP PID: %d \n", getpid());

	app_wd = WDStart(argv[0], &status);

	for(; i < NUM_OF_ITERATIONS; ++i)
	{
		sleep(1);
		g_arr[i] = i;
	}

	status = WDStop(app_wd);

	printf("Status: %d \n", status);

	UNUSED(argc);

	return 0;
}