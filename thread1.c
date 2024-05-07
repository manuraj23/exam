#include <stdio.h>
#include <pthread.h>

void *thread_function(void *message) {
    printf("Message received in thread: %s\n", (char *)message);

    // Print the table of 2
    printf("Table of 2:\n");
    for (int i = 1; i <= 10; i++) {
        printf("2 x %d = %d\n", i, 2*i);
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, "Hello from the main thread!");
    pthread_join(thread_id, NULL);
    return 0;
}
