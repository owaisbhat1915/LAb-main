#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

int shared_variable = 0;
int num_readers = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t reader_sem, writer_sem;

void *reader(void *arg)
{
    while (1) {
        sem_wait(&reader_sem);
        pthread_mutex_lock(&mutex);
        num_readers++;
        if (num_readers == 1) {
            sem_wait(&writer_sem);
        }
        pthread_mutex_unlock(&mutex);

        printf("Reader %d read the shared variable: %d\n", (int)arg, shared_variable);

        pthread_mutex_lock(&mutex);
        num_readers--;
        if (num_readers == 0) {
            sem_post(&writer_sem);
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&reader_sem);

        sleep(1);
    }
    return NULL;
}

void *writer(void *arg)
{
    while (1) {
        sem_wait(&writer_sem);

        printf("Writer %d is writing to the shared variable.\n", (int)arg);
        shared_variable++;

        sem_post(&writer_sem);

        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t reader_threads[NUM_READERS], writer_threads[NUM_WRITERS];

    sem_init(&reader_sem, 0, NUM_READERS);
    sem_init(&writer_sem, 0, 1);

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_create(&reader_threads[i], NULL, reader, (void *)i);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_create(&writer_threads[i], NULL, writer, (void *)i);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(reader_threads[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    sem_destroy(&reader_sem);
    sem_destroy(&writer_sem);

    return 0;
}
