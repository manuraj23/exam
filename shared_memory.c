#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

#define SHMSIZE 1024

int main() {
    void *shm;
    char buf[100];
    int shmid;

    // Creating a shared memory segment
    shmid = shmget(ftok(".", 'a'), SHMSIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("shmget Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("The Key value of shared memory is %d\n", shmid);

    // Attaching the process to the shared memory segment
    shm = shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("shmat Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Process attached to the address of %p\n", shm);
    printf("Write the data to shared memory (max 99 characters): ");
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0'; // Removing newline character if present
    strncpy((char *)shm, buf, SHMSIZE); // Ensuring data doesn't exceed SHMSIZE
    printf("The stored data in shared memory is: %s\n", (char *)shm);

    // Detaching shared memory
    if (shmdt(shm) == -1) {
        printf("shmdt Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}
