#include<stdio.h>
#include<fcntl.h>
int main()
{
int n,m;
n=open(new_file"'O_RDONLY);
printtf("file descriptor is %d\n",n);
m=open("new_file1",O_CREAT|O_WRONLY,0777);
printf("file descriptor is %d \n", m);
}
