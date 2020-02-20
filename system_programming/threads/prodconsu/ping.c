#include <stdio.h> /*perror()*/
#include <fcntl.h>  
#include <sys/stat.h>
#include <semaphore.h>
#include <stdlib.h> /*exit()*/
#include <unistd.h> /*getpid*/

#define SEM_PONG_NAME "/semaphore_pong"
#define SEM_PING_NAME "/semaphore_ping"

#define INITIAL_VALUE 0
#define ITERATIONS 5

/*
*   '0x0100' or S_IRUSR     Permits the creator of the named semaphore to open the semaphore in read mode.
*   '0x0080' or S_IWUSR     Permits the creator of the named semaphore to open the semaphore in write mode.
*   '0x0020' or S_IRGRP     Permits the group associated with the named semaphore to open the semaphore in read mode.
*   '0x0010' or S_IWGRP     Permits the group associated with the named semaphore to open the semaphore in write mode.
*   '0x0004' or S_IROTH     Permits others to open the named semaphore in read mode.
*   '0x0002' or S_IWOTH     Permits others to open the named semaphore in write mode.
*/

#define SEM_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP)

int main(void) 
{
    sem_t *ping = sem_open(SEM_PING_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
    sem_t *pong = sem_open(SEM_PONG_NAME, O_CREAT, SEM_PERMS, INITIAL_VALUE);
    size_t i = 0;
    /*  '0x0010' or O_EXCL Causes sem_open() to fail if O_CREAT is also set and the named semaphore already exists.*/

    if (ping == SEM_FAILED || pong == SEM_FAILED) 
    {
        perror("sem_open(3) failed");
        exit(EXIT_FAILURE);
    }
    for (; i < ITERATIONS; ++i)
    {
        printf("PING\n");
     
        if (sem_post(pong) < 0) {
            perror("sem_post(3) error on post(pong");
        }

        if (sem_wait(ping) < 0) 
        {
         perror("sem_wait(3) failed on pong wait");
        }
        
        sleep(1);
    }

    if (sem_close(ping) < 0) 
    {
        perror("sem_close(3) failed");
        sem_unlink(SEM_PING_NAME);
        exit(EXIT_FAILURE);
    }

    if (sem_close(pong) < 0) 
    {
        perror("sem_close(3) failed");
        sem_unlink(SEM_PING_NAME);
        exit(EXIT_FAILURE);
    }

    if (sem_unlink(SEM_PING_NAME) < 0)
    {
        perror("sem_unlink(3) failed");
    }

    if (sem_unlink(SEM_PONG_NAME) < 0)
    {
        perror("sem_unlink(3) failed");
    }
    return 0;
}