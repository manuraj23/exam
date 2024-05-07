#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 5
#define MAX_COUNT 1000000

int shared_variable = 0;
sem_t semaphore;

void *increment_variable(void *threadid) {
    for (int i = 0; i < MAX_COUNT; i++) {
        sem_wait(&semaphore);
        shared_variable++;
        sem_post(&semaphore);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    sem_init(&semaphore, 0, 1); // Initializing semaphore with value 1
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_variable, (void *)i);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&semaphore); // Destroying semaphore
    printf("Value of shared variable after synchronization: %d\n", shared_variable);
    return 0;
}
