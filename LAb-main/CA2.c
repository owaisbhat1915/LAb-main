#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int n=open("Owais.txt",O_RDONLY,0777);
    char c;
    while (read(n,&c,1))
    {
        write(1,&c,1);
    }
}

