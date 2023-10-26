#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    // read 
    char Buffname[30];
    char BuffRollNo[3];
    int size1=read(0,Buffname,14);
    int size2=read(0,BuffRollNo,2);
    // write
    write(1,"Name:",5);
    write(1,Buffname,size1);
    write(1," RollNo:",8);
    write(1,BuffRollNo,size2);    
}

