#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0;
int in = 0;
int out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg)
{
    int item = 1;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count == BUFFER_SIZE) {
            printf("Buffer is full, producer is waiting...\n");
            pthread_mutex_unlock(&mutex);
            sleep(1);
            continue;
        }
        buffer[in] = item;
        printf("Producer produced item %d at index %d.\n", item, in);
        item++;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg)
{
    int item;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            printf("Buffer is empty, consumer is waiting...\n");
            pthread_mutex_unlock(&mutex);
            sleep(1);
            continue;
        }
        item = buffer[out];
        printf("Consumer consumed item %d at index %d.\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        count--;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
