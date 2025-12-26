#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
int a=10,b=20;
pid_t pid=fork();

if(pid<0)
{

printf("fork is failed to create\n");
}
else if(pid==0)
{
printf("substration of two numbers is %d\n",b-a);
}
else
{
printf("addation of two numbers is %d\n",b+a);
}
return 0;
}
