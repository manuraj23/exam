#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    char *source_file = "/home/manu-raj/CSE325LAB/UNIT3/f1.txt";
    char *destination_file = "/home/manu-raj/CSE325LAB/UNIT3/f2.txt";
    int half_choice;
    printf("Enter 1 to copy the first half or 2 to copy the second half: ");
    scanf("%d", &half_choice);
    int fd_source = open(source_file, O_RDONLY);
    int file_size = lseek(fd_source, 0, SEEK_END);
    int half_size = (half_choice == 1) ? 0 : file_size / 2;
    lseek(fd_source, half_size, SEEK_SET);
    int fd_dest = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;
    while ((bytes_read = read(fd_source, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(fd_dest, buffer, bytes_read);
    }
    close(fd_source);
    close(fd_dest);
    printf("File copied successfully.\n");
    return 0;
}
