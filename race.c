#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_COUNT 1000000

int shared_variable = 0;

void *increment_variable(void *threadid) {
    for (int i = 0; i < MAX_COUNT; i++) {
        shared_variable++;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_variable, (void *)i);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Value of shared variable after race condition: %d\n", shared_variable);
    return 0;
}
