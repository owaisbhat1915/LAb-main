#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    DIR *dp;
    struct dirent *d;
    

    dp = opendir("Rk21wbA19");
    while ((d=readdir(dp))!=NULL)
    {
        printf("%s Filename \t ",d->d_name);
        printf("%u Type ",d->d_type);
        printf("\n");
    }
    
    
}
