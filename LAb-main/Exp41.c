#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
int main()
{

    DIR *dp;
    struct dirent *dptr;
    int a = mkdir("mydir", 0777);
    int n1 = open("./mydir/files1.txt", O_CREAT | O_WRONLY, 0777);
    write(n1, "hello how are you", 17);
    int n2 = open("./mydir/files2.txt", O_CREAT| O_WRONLY, 0777);
    write(n2, "hello how are you", 17);
    dp = opendir("mydir");
    while ((dptr = readdir(dp)) != NULL)
    {
        printf(" Inode %ld \n", dptr->d_ino);
        printf(" Name %s \n", dptr->d_name);
        printf(" Type %u \n", dptr->d_type);
        printf(" Length %u \n", dptr->d_reclen);
        printf(" Offset %ld \n\n", dptr->d_off);
    }
    close(n1);
    close(n2);
    closedir(dp);
}