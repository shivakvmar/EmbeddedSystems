#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

char filename[100];

int main()
{
scanf("%s",filename);

pid_t pid=fork();

if(pid==0)
{
		int fd,n;
		char buffer[121];
		fd=open(filename,O_RDONLY);
		if(fd<0)
		{
		perror("failed to open file");
		}
		n=read(fd,buffer,sizeof(buffer));
		if(n<0)
		{
		perror("failed to read file");
		}
		while(n>0)
		{
			write(STDOUT_FILENO,buffer,n);
			n=read(fd,buffer,sizeof(buffer));
		}
		close(fd);
		
}



return 0;
}
