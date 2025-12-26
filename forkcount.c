#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int arv,char *args[])
{
 int bytes,fd;
 
 if(arv<2)
 {
perror("failed to read from cmd");
}

fd=open(args[1],O_RDONLY);
if(fd<0)
{
perror("failed to read file");
}

int pipes[2];
pipe(pipes);
pid_t pid=fork();
if(pid<0)
{
perror("failed to create fork");
}
if(pid==0)
{
close(pipes[0]);
int count;
char buffer[1024];
bytes=read(fd,buffer,sizeof(buffer));
if(bytes<0)
{
perror("failed t read file");
}

while(bytes>0){
count=count+bytes;
bytes=read(fd,buffer,sizeof(buffer));
}
bytes=write(pipes[1],&count,sizeof(count));
if(bytes<0)
{
perror("failed to write into file");
}
close(fd);
close(pipes[1]);
}
else{
close(pipes[1]);
close(fd);  
int charCount;
bytes=read(pipes[0], &charCount, sizeof(charCount)) ;
        if (bytes<0) {
            perror("read from pipe");
            close(pipes[0]);
        }

        printf("Child counted: %d characters\n", charCount);

        close(pipes[0]);


}
return 0;
}
