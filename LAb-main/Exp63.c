#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
int ans;
double av;
int arr[] = {5, 6, 2, 3, 2, 1, 8, 7};
int n=sizeof(arr)/sizeof(int);
void *avg(void *arg)
{
    int *a = (int *)arg;
    
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += a[i];
    }

    av = total / n;
}
void *max(void *arg)
{

    int *a = (int *)arg;
    
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }

    ans = max;
}
void *min(void *arg)
{
    int *a = (int *)arg;
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (min > a[i])
            min = a[i];
    }

    ans = min;
}
int main()
{
    pthread_t thread1, thread2, thread3;
    
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
      printf("\n");
    void *a;
    pthread_create(&thread1, NULL, &max, arr);
    pthread_join(thread1, NULL);
    printf("max number is : %d\n", ans);
    pthread_create(&thread2, NULL, &min, arr);
    pthread_join(thread2, NULL);
    printf("min number is : %d\n", ans);
    pthread_create(&thread3, NULL, &avg, arr);
    pthread_join(thread3, NULL);
    printf("avg of number is : %f\n", av);
}