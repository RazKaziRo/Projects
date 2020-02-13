#include <signal.h>  
#include <unistd.h>

void PingHandler(int sig)
{
    if (sig == SIGUSR1)
    {
        write(1, "PING\n", 5);
    }
}

int main(int argc, char const *argv[])
{
    struct sigaction sigact;

    sigact.sa_handler = PingHandler;
    sigact.sa_flags = 0;

	sigaction(SIGUSR1, &sigact, NULL);

	while(1)
	{	
		kill(getppid(), SIGUSR2);
		pause();
	}

	return 0;
}