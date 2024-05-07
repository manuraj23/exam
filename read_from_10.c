#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE 11

int main() {
    int fileDescriptor;
    char buffer[BUFFERSIZE];
    fileDescriptor = open("input.txt", O_RDONLY);
    lseek(fileDescriptor, 10, SEEK_SET);
    read(fileDescriptor, buffer, BUFFERSIZE - 1);
    buffer[BUFFERSIZE - 1] = '\0';
    printf("Characters from 11th to 20th position: %s\n", buffer);
    close(fileDescriptor);
    return 0;
}
