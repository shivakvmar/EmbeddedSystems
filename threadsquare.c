#include<stdio.h>
#include<pthread.h>

void *squarefun(void *args)
{
 int num=*(int *)args;
 return (void *)(long)(num*num);
}

int main()
{
pthread_t thread;
int num=7;
int *retr;
int n;

n=pthread_create(&thread,NULL,squarefun,&num);
if(n<0)
{
perror("failed to create thread");
return 1;

}
n=pthread_join(thread,(void **)&retr);
if(n<0)
{
perror("failed to wait thread");
return 1;

}
int square = (int)(long)retr;
    printf("Square of %d is %d\n", num, square);
return 0;

}
