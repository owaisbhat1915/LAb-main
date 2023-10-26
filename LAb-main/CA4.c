#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
int maxbuff=3;
int buff[3];
int count=0;
sem_t mutex,full,empty;
void *pro()
{
    int item;
    
      sem_wait(&empty);
      sem_wait(&mutex);
      buff[count++]=count;
      
       printf("done pro \n");
      sem_post(&mutex);
      sem_post(&full);

    pthread_exit(NULL);
}
void *con()
{
    int item;
    
      sem_wait(&full);
      sem_wait(&mutex);
      item=buff[--count];
      printf("item is %d \n",item);
      sem_post(&mutex);
      sem_post(&empty);

    pthread_exit(NULL);
}
int main()
{

pthread_t p,p1,p2,c2,c1, c;
sem_init(&mutex,0,1);
sem_init(&full,0,0);
sem_init(&empty,0,3);
pthread_create(&p,NULL,pro,NULL);
pthread_join(p,NULL);
pthread_create(&p1,NULL,pro,NULL);
pthread_join(p1,NULL);
pthread_create(&p2,NULL,pro,NULL);
pthread_join(p2,NULL);
pthread_create(&c1,NULL,con,NULL);
pthread_join(c1,NULL);
pthread_create(&c,NULL,con,NULL);
pthread_join(c,NULL);
pthread_create(&c2,NULL,con,NULL);
pthread_join(c2,NULL);


sleep(1);
    
}