#include <signal.h>  
#include <stdio.h>  
#include <string.h>  
#include <sys/types.h>  
#include <unistd.h>
#include <sys/wait.h>

volatile sig_atomic_t state =  0;

void SigHandler(int sig)
{
    if (sig == SIGUSR1)
    {
        write(1, "PING\n", 5);
        state = 1;
    }

    if (sig == SIGUSR2)
    {
        write(1, "PONG\n", 5);
        state = 0;
    }
}

int main(int argc, char *argv[])
{

    pid_t child_pid = 0;
    struct sigaction sigact;

    sigact.sa_handler = SigHandler;
    sigact.sa_flags = 0;

	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);

	child_pid = fork();

	if(0 < child_pid)
	{
		while(1)
		{
			while(1 == state)
			{

			}

			state = 1;
			kill(child_pid, SIGUSR1);
		}
	}

	if(0 == child_pid)
	{
		while(1)
		{
			while(0 == state)
			{

			}

			state = 0;
			kill(getppid(), SIGUSR2);
		}
	}	

  	return 0;  
}