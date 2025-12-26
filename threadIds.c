#include<stdio.h>
#include<pthread.h>


void *threadid(void *args)
{
pthread_t threadid=pthread_self();
unsigned long id= (unsigned long) threadid;
printf("thread id is %lu\n",id);

}

int main()
{
pthread_t thread[5];
int n;

for(int i=0;i<5;i++){
n=pthread_create(&thread[i],NULL,threadid,NULL);
if(n<0)
{
perror("failed to create thread");
return 1;
}
}

for(int j=0;j<5;j++){
n=pthread_join(thread[j],NULL);
if(n<0)
{
perror("failed to wait thread");
return 1;
}
}
return 0;

}
