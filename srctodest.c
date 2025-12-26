#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <string.h>
#include <ctype.h>
int main(int arv,char *args[])
{
int bytes;
int srcfd,destfd;
char srcfuffer[121];
int total=0;

if(arv<3)
{
perror("failed to read file names from arguments");
}

srcfd=open(args[1],O_WRONLY | O_CREAT | O_TRUNC,0777);
if(srcfd<0)
{
perror("faild to create sorce file");
}
write(STDOUT_FILENO,"enter text to src file\n",strlen("enter text to src file\n"));

bytes=read(STDIN_FILENO,srcfuffer,sizeof(srcfuffer));
if(bytes<0)
{
perror("failed to read from command line");
}
while(bytes>0){
write(srcfd,srcfuffer,bytes);
bytes=read(STDIN_FILENO,srcfuffer,sizeof(srcfuffer));
}
printf("\n");
close(srcfd);
destfd=open(args[2],O_WRONLY | O_CREAT | O_TRUNC,0777);
if(destfd<0){
perror("failed to create destfile");
}
srcfd=open(args[1],O_RDONLY);
if(srcfd<0){
perror("failed to read src file");
}
bytes=read(srcfd,srcfuffer,sizeof(srcfuffer));
while(bytes>0)
{
write(destfd,srcfuffer,bytes);
bytes=read(srcfd,srcfuffer,sizeof(srcfuffer));
}
close(srcfd);
close(destfd);
destfd=open(args[2],O_RDONLY);
if(destfd<0)
{
perror("failed to read dest file");
}
bytes=read(destfd,srcfuffer,sizeof(srcfuffer));
while(bytes>0){
for(int i=0;i<bytes;i++)
{
srcfuffer[i]=toupper(srcfuffer[i]);
total=total+1;
}
write(STDOUT_FILENO,srcfuffer,bytes);
bytes=read(destfd,srcfuffer,sizeof(srcfuffer));
}
printf("\n");
close(destfd);

char charctertotal[100];
int n=sprintf(charctertotal,"number of charcter are : %d",total);
write(STDOUT_FILENO,charctertotal,n);
printf("\n");

return 0;
}
