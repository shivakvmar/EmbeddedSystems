#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    char *string = "shivakumar neela";
    size_t len = strlen(string);

    write(fd, string, len);
    close(fd);
    return 0;
}

