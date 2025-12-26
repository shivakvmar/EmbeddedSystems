#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include <ctype.h>
int main()
{
int n,fd;
char *p="this is shivakumar neela";
char buffer[128];
char lower[128];

fd=open("uppercase.txt",O_RDONLY | O_CREAT | O_WRONLY,0777);
if(fd<0)
{
perror("failed to create the file");
}
n=write(fd,p,strlen(p));
if(n<0)
{
perror("failed to write");
}
close(fd);
fd=open("uppercase.txt",O_RDONLY);
if (fd < 0) {
        perror("Failed to open file for reading");
       
    }

n=read(fd,buffer,sizeof(buffer));
if(n<0)
{
perror("failed to read");
}
while(n>0)
{
		for(int i=0;i<n;i++)
		{
			buffer[i]=toupper(buffer[i]);
			lower[i]=tolower(buffer[i]);
		}
		write(STDOUT_FILENO,buffer,n);
		 printf("\n");
		write(STDOUT_FILENO,lower,n);
		n=read(fd,buffer,sizeof(buffer));
}

close(fd);
 printf("\n");
return 0;

}
