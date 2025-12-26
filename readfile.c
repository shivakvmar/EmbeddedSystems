#include <stdio.h>    // for perror()
#include <fcntl.h>    // for open() flags
#include <unistd.h>   // for read(), write(), close()

int main(void) {
    int fd;
    ssize_t n;
    char data[1024];

    // 1. Open file correctly
    fd = open("hello.txt", O_RDONLY);
    if (fd == -1) {
        perror("failed to open file");
        return 1;
    }

    // 2. Read and write loop
    while ((n = read(fd, data, sizeof(data))) > 0) {
        write(STDOUT_FILENO, data, n);
    }

    // 3. Check for read error
    if (n == -1) {
        perror("read failed");
    }

    // 4. Close file descriptor
    close(fd);
    return 0;
}

