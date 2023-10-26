#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int arr[] = {5, 1, 3, 4, 2};
int size = 5;
int arr1[] = {5, 1, 3, 4, 2};
int final[10];
struct st
{
    int *a1;
    int *a2;
};
void *sort(void *args)
{
    int *a = (int *)args;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}
void *marge(void *args)
{
    struct st *s;
    s = (struct st *)args;
    int i = 0, j = 0, k = 0;
    while (i < size && j < size)
    {
        if (s->a1[i] < s->a2[j])
        {
            final[k] = s->a1[i];
            i++;
            k++;
        }
        else
        {
            final[k] = s->a2[i];
            j++;
            k++;
        }
    }
    while (i < size)
    {
        final[k] = s->a1[i];
        i++;
        k++;
    }
    while (j < size)
    {
        final[k] = s->a2[i];
        j++;
        k++;
    }
}

int main()
{
    struct st s;
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, sort, &arr);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, sort, &arr1);
    pthread_join(thread2, NULL);
    s.a1 = arr;
    s.a2 = arr1;
    pthread_create(&thread3, NULL, marge, &s);
    pthread_join(thread3, NULL);
    for (int i = 0; i < size * 2; i++)
    {
        printf("%d ", final[i]);
    }
}