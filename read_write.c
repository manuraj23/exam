#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFERSIZE 1024

int main() {
    char buffer[BUFFERSIZE];
    ssize_t bytesRead = read(0, buffer, BUFFERSIZE);
    write(1, buffer, bytesRead);
    return 0;
}
