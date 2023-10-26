#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int n=open("MandeepSingh.txt",O_CREAT|O_WRONLY,0777);
    int size=write(n,"We are the Verto",16);
    if(size!=0){
        write(1,"Done",4);
    }

}

