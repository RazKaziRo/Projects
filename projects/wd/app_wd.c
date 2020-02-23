#include <stdio.h>
#include <sys/types.h> /*getpid()*/
#include <unistd.h>
#include "wd_api_func.h"

int main(int argc, char const *argv[])
{
	wd_status_t status;
	wd_t *app_wd = NULL;

	printf("APP PID: %d \n", getpid());
	app_wd = WDStart(argv[0], &status);

	sleep(5);
	
	WDStop(app_wd);


	return 0;
}