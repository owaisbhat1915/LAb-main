#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int pid = fork();
    if (pid > 0)
    {
        printf("process 1 : pid %d  ppid %d\n", getpid(), getppid());
    }
    else
    {
        int pid1 = fork();
        if (pid1 > 0)
        {
            printf("process 2 : pid %d  ppid %d\n", getpid(), getppid());
        }
        else{
            printf("process 3 : pid %d  ppid %d\n", getpid(), getppid());
        }
    }
}
