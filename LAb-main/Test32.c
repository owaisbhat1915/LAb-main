#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int f1 = fork();
    if (f1 > 0)
    {
        printf("process 1 : pid %d  ppid %d\n", getpid(), getppid());
        int f3=fork();
        if(f3==0){
            printf("process 3 : pid %d  ppid %d\n", getpid(), getppid());
        }
    }
    else
    {
        int f2 = fork();
        if (f2 > 0)
        {
            printf("process 2 : pid %d  ppid %d\n", getpid(), getppid());
            
        }
        else{
            printf("process 4 : pid %d  ppid %d\n", getpid(), getppid());
            sleep(1);
            printf("P4 Orphan process");
        }
    }
    sleep(8);
}
