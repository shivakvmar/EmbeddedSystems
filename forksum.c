#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int arv,char *args[])
{
int n,fd;
char buffer[121];

if(arv<2)
{
perror("failed to read cmd");
}

fd=open(args[1],O_WRONLY | O_CREAT | O_TRUNC,0777);
if(fd<0)
{
perror("failed to create file");
}

n=read(STDIN_FILENO,buffer,sizeof(buffer));
if(n<0)
{
perror("failed to read from cmd");
}
while(n>0)
{
write(fd,buffer,n);
n=read(STDIN_FILENO,buffer,sizeof(buffer));
}
close(fd);
pid_t pid=fork();
if(pid<0)
{
perror("failed to create fork");
}
	
if(pid==0)
{
fd=open(args[1],O_RDONLY);
if(fd<0)
{perror("failed to open file");
}
int sum=0;
n=read(fd,buffer,sizeof(buffer));
if(n<0)
{
perror("failed to read file");
}
while(n>0)
{
for(int i=0;i<n;i++)
{
		if (buffer[i] >= '0' && buffer[i] <= '9') {
                    sum += buffer[i] - '0';  // Convert char to int
                }
}
n=read(fd,buffer,sizeof(buffer));
}
char totalsum[100];
snprintf(totalsum,sizeof(totalsum),"sum of characternumber is : %d",sum);

write(STDOUT_FILENO,totalsum,strlen(totalsum));
printf("\n");
close(fd);
}




return 0;
}
