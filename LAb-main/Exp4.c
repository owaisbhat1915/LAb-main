#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
int main(){
   DIR *dp;
   struct dirent *dptr;
   // int b=mkdir("",0777);
   dp=opendir("./newuser");

   while (NULL!=(dptr=readdir(dp)))
   {
    printf("Name %s \t",dptr->d_name);
    printf("Type %d \t",dptr->d_type);
    printf("Inode %ld \t",dptr->d_ino);
    printf("length %d \t",dptr->d_reclen);
   //  printf("offset %ld \n",dptr->d_off);
   }
   
   
}