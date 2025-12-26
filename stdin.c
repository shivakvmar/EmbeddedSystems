#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int arv,char *args[])
{
    int fd,n;
    char buffer[128];

    if(arv < 2)
    {
        perror("No filename provided");
        return 1;
    }

    fd=open(args[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fd<0)
    {
        perror("failed to create file");
        return 1;
    }

    write(STDOUT_FILENO, "Enter text and press Ctrl+D to finish\n",
          strlen("Enter text and press Ctrl+D to finish\n"));

  
n = read(STDIN_FILENO, buffer, sizeof(buffer)); 
while (n > 0) {
    write(fd, buffer, n);         
    n = read(STDIN_FILENO, buffer, sizeof(buffer)); 
}


    if(n < 0)
    {
        perror("failed to read the data from input");
    }

    close(fd);

    fd=open(args[1],O_RDONLY);
    if(fd<0)
    {
        perror("failed to read");
        return 1;
    }

   n=read(fd, buffer, sizeof(buffer));
    while(n>0)
    {
        write(STDOUT_FILENO, buffer, n);
         n=read(fd, buffer, sizeof(buffer));
    }

    if(n < 0)
    {
        perror("failed to read file");
    }

    close(fd);
    printf("\n");
    return 0;
}

