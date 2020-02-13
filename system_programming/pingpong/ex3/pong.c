#define _POSIX_C_SOURCE  199309L

#include <signal.h>  
#include <stdio.h>  
#include <string.h>  
#include <sys/types.h>  
#include <unistd.h>
#include <sys/wait.h>

volatile sig_atomic_t state =  1;

void SigHandler(int sig)
{
    write(1, "PONG\n", 5);
    state = 1;
}

int main(int argc, char const *argv[])
{
    pid_t caller_id = 0;

    struct sigaction pong_handler;

    caller_id = atoi(argv[1]);

    printf("caller id = %d\n", caller_id);

    pong_handler.sa_flags = 0;
    pong_handler.sa_handler = SigHandler;

    sigemptyset(&pong_handler.sa_mask);
    sigaction(SIGUSR2, &pong_handler, NULL);

    while(1)
        {
            while(0 == state)
            {

            }

            state = 0;
            kill(caller_id, SIGUSR1);
        }

    return 0;
}