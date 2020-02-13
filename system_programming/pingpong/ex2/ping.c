#include <signal.h>  
#include <stdio.h>  
#include <string.h>  
#include <sys/types.h>  
#include <unistd.h>
#include <sys/wait.h>

void PongHandler(int sig)
{
    if (sig == SIGUSR2)
    {
        write(1, "PONG\n", 5);
    }
}

int main(int argc, char *const argv[])
{
	pid_t child_pid = 0;

    struct sigaction sigact;

    sigact.sa_handler = PongHandler;
    sigact.sa_flags = 0;

	sigaction(SIGUSR2, &sigact, NULL);

	child_pid = fork();

	if(0 < child_pid)
	{

		while(1)
		{
			pause();
			kill(child_pid, SIGUSR1);
		}
		
	}

	if(0 == child_pid)
	{
		execv(argv[1], argv);
	}

	return 0;
}