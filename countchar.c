#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("hello.txt", O_RDONLY);
   
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    ssize_t n;
    char buf[1024];
    long total = 0;

    while ((n = read(fd, buf, sizeof(buf))) > 0) {
      
        total += n;
    }

    if (n == -1) {
        perror("read failed");
    }

    close(fd);
    printf("Total characters: %ld\n", total);
    return 0;
}

