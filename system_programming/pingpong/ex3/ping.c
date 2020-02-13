#define _POSIX_C_SOURCE  199309L

#include <signal.h>  
#include <stdio.h>  
#include <string.h>  
#include <sys/types.h>  
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void SigHandler(int sig, siginfo_t *sa , void *param)
{   
    sleep(1);
    write(1, "PING\n", 5);
    kill(sa->si_pid, SIGUSR2);
}

int main()
{
    struct sigaction ping_handler;

    ping_handler.sa_sigaction = SigHandler;
    ping_handler.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &ping_handler, NULL);

    printf("PID %d : Ping Proccess\n", getpid());

    while(1)
    {
    }
}