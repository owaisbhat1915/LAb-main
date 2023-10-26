#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
struct st
{
    char *m1;
    char *m2;
    char *m3;
};
char ans[50];
void *marge(void *str)
{
    struct st *s = (struct st *)str;
    
    strcat(ans, s->m1);
    strcat(ans, s->m2);
    strcat(ans, s->m3);
}
int main()
{
    pthread_t thread1;
    struct st s;
    s.m1 = "hello1";
    s.m2 = " hello2";
    s.m3 = " hello3";
    pthread_create(&thread1, NULL, &marge, &s);
    pthread_join(thread1, NULL);
    printf("%s", ans);
}