#include<stdio.h>
#include<pthread.h>


void *castint(void *args)
{
int num=*(int *)args;
printf("number is :%d\n",num);
}

int main()

{
pthread_t thread;
int n;
int value=10;

n=pthread_create(&thread,NULL,castint,&value);

if(n<0)
{
perror("failed to createthread");
return 1;
}
n=pthread_join(thread,NULL);
if(n<0)
{
perror("failed to wait thread");
return 1;
}
return 0;
}
