#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{

    int pid = fork();
    if (pid > 0)
    {
        int pid1 = fork();
        if (pid1 > 0)
        {
            printf("process 1 : pid %d  ppid %d\n", getpid(), getppid());
            
        }
        else
        {
            int pid2 = fork();
            if (pid2 > 0)
            {
                printf("process 5 : pid %d  ppid %d\n", getpid(), getppid());
                
            }
            else
            {
                int pid3 = fork();
                if (pid3 > 0)
                {
                    printf("process 6 : pid %d  ppid %d\n", getpid(), getppid());
                    sleep(15);
                }
                else
                {
                    printf("process 7 : pid %d  ppid %d\n", getpid(), getppid());
                    printf("p7 zombie\n");
                }
            }
        }
    }
    else
    {
        int pid = fork();
        if (pid > 0)
        {
            printf("process 2 : pid %d  ppid %d\n", getpid(), getppid());
            
        }
        else
        {
            int pid2 = fork();

            if (pid2 > 0)
            {
                printf("process 3 : pid %d  ppid %d\n", getpid(), getppid());
                
            }
            else
            {
                printf("process 4 : pid %d  ppid %d\n", getpid(), getppid());
                printf("p4 orphan\n");
                sleep(15);
                
            }
        }
    }
    sleep(10);
}
