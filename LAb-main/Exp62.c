#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void *find(void *str)
{
    char *s = (char *)str;
    int a = strlen(s);
    printf("length is : %d", a);
    pthread_exit(NULL);
}
int main()
{
    pthread_t thread1;
    char *a = "hi my name is Owais";
    pthread_create(&thread1, NULL, &find, a);
    pthread_join(thread1, NULL);
}
