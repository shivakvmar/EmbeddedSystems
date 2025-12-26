#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int src, dest;
    char buffer[128];
    char *p = "shiva kumar neela is learning Embedded system at tessolve";
    int n;

    // open src.txt for writing (create/truncate)
    src = open("src.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (src < 0) {
        perror("failed to create or open src.txt");
        return 1;
    }

    // write the string to src.txt
    write(src, p, strlen(p));
    close(src); // close after writing

    // reopen src.txt for reading
    src = open("src.txt", O_RDONLY);
    if (src < 0) {
        perror("failed to open src.txt for reading");
        return 1;
    }

    // open dest.txt for writing (create/truncate)
    dest = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest < 0) {
        perror("failed to create dest.txt");
        close(src);
        return 1;
    }

   n = read(src, buffer, sizeof(buffer));
while (n > 0) {
    write(dest, buffer, n);
    n = read(src, buffer, sizeof(buffer));
}


    if (n < 0) {
        perror("read error");
    }

    close(src);
    close(dest);

    printf("source.txt copied to dest.txt\n");
    return 0;
}

