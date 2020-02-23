#include "stdio.h"
#include "wd.h"
#include <sys/types.h> /*getpid()*/
#include <unistd.h>

int main(int argc, char const *argv[])
{
	wd_status_t wd_init_status;
	wd_t *wd = WDInit(&wd_init_status);
	wd->app_id_to_watch = getppid();
	wd->path_to_app = argv[0];

	printf("inside wd path to app: %s \n", wd->path_to_app);
	printf("WD PID: %d \n", getpid());

	WDSchedulerRun(&wd->scheduler);

	

	return 0;
}