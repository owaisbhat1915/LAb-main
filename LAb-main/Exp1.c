#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){


    int file1=open("file1.txt",O_RDONLY,0777);
    char buff[330];

    int s=read(file1,buff,330);
    
    int file2=open("file2.txt",O_CREAT|O_WRONLY,0777);
    int n1=write(file2,buff,s/2);
    printf("%d\n",n1);

    int file3=open("file3.txt",O_CREAT|O_WRONLY,0777);
    int n2=write(file3,buff+n1,s/2);
    printf("%d",n1);
    
    close(file1);
    close(file2);
    close(file3);

}