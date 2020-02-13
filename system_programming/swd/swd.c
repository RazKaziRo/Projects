
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h> /*system()*/
#include <string.h> /*strcmp()*/
#include <assert.h>

void SimpleWatchDogFork(char *argv[])
{
	pid_t fork_return_status = 0;

	while(1)
	{
		fork_return_status = fork();

		if(fork_return_status > 0)
		{
			wait(NULL);
		}

		else if(0 == fork_return_status)
		{
			sleep(1);
			execvp(argv[2], &argv[2]);
		}
		else
		{

		}
	}
}

void SimpleWatchDogSystem(char *argv[])
{
	while(1)
	{
		system(argv[2]);
	}
}

int main(int argc, char *argv[])
{
	if(0 == strcmp(argv[1], "fork"))
	{
		SimpleWatchDogFork(argv);
	}
	else if (0 == strcmp(argv[1], "system"))
	{
		SimpleWatchDogSystem(argv);
	}

	return 0;
}