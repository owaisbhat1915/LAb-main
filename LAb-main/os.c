#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    if(fork()||fork()){
     fork();
    }
    printf("hi\n");
    return 0;
}
