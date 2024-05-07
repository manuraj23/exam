#include <stdio.h>
#include <pthread.h>

// Function to calculate factorial
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void *thread_function(void *message) {
    int num = *((int *)message);
    printf("Message received in thread: Calculating factorial of %d\n", num);

    // Calculate factorial
    int fact = factorial(num);
    
    // Print the factorial
    printf("Factorial of %d = %d\n", num, fact);

    return NULL;
}

int main() {
    pthread_t thread_id;
    int number = 5; // Change this to calculate factorial of a different number
    pthread_create(&thread_id, NULL, thread_function, &number);
    pthread_join(thread_id, NULL);
    return 0;
}
