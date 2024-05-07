#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();  // Create a child process
    if (pid == -1) {
        printf("Error: Failed to fork process.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process running.\n");
        sleep(2);  // Simulate some work
        printf("Child process exiting.\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent process waiting for child process...\n");
        wait(&status);  // Wait for child process to terminate
        printf("Child process exited with status %d.\n", status);
    }

    return 0;
}
