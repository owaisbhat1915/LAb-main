#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<fcntl.h>
int main(){

    int file=open("newfile.txt",O_WRONLY,0777);
    while (true)
    {
        char c;
        read(0,&c,1);
        if(c=='$'){
            break;
        }
        else{
            int x=write(file,&c,1);
        }
    }
    close(file);
    file=open("newfile.txt",O_RDONLY,0777);
    char c;
    while(read(file,&c,1)!=0){
        printf("%c",c);
    }
    close(file);
}
