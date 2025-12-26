#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
int fd,n;

fd=open("output.txt",O_WRONLY | O_CREAT,0777);
if(fd<0)
{
perror("failed to create file");
}

pid_t pid=fork();

if(pid==0)
{

	n=write(fd,"Hello from Child\n" ,strlen("Hello from Child\n"));
	if(n<0)
	{
	perror("failed to write into file");
	}
}
else
{
n=write(fd,"Hello from Parent\n", strlen("Hello from Parent\n"));
	if(n<0)
	{
	perror("failed to write into file");
	}
}
close(fd);


return 0;

}
