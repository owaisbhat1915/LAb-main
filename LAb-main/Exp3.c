#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<fcntl.h>
int main(){

    int file=open("newfile.txt",O_RDONLY,0777);
    char c;
    while(read(file,&c,1)!=0){
        write(1,&c,1);
    }
    close(file);
}