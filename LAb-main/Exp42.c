#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main()
{
    DIR *dp;
    struct dirent *dirent;
    dp = opendir("mydir");
    mkdir("newDir", 0777);
    while ((dirent = readdir(dp)) != NULL)
    {

        if (dirent->d_name[0] != '.')
        {
            printf("%s \n", dirent->d_name);
            char path[] = "./mydir/";
            strcat(path, dirent->d_name);
            int n = open(path, O_RDONLY, 0777);
            if (n != -1)
            {
                char path1[] = "./newDir/";
                strcat(path1, dirent->d_name);
                int n1 = open(path1, O_WRONLY | O_CREAT, 0777);
                char c;
                while (read(n, &c, 1))
                {
                    write(n1, &c, 1);
                }
                close(n1);
            }

            close(n);
        }
    }
}