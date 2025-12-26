#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int arg,char *argv[])
{
int fd,n;
char buffer[128];

char *filename=argv[1];
char *data = "shiva kumar neela is learning Embedded system at tessolve"; 

fd=open(filename,O_WRONLY | O_CREAT,0777);
if(fd<0){
perror("failed to create file");
}
write(fd,data,strlen(data));
close(fd);
fd = open(filename, O_RDONLY);
n=read(fd,buffer,sizeof(buffer));
if(n<0){
perror("failed to read file");
}
while(n>0)
{
	 write(STDOUT_FILENO, buffer, n); 
	n=read(fd,buffer,sizeof(buffer));
}


return 0;




}
