#include<stdio.h>
#include<pthread.h>

void * threadfun(void * args)
{
printf("Hello from thread\n");
    return NULL;
}


int main(void)
{

pthread_t thread;
 int n;
 
 n=pthread_create(&thread,NULL,threadfun,NULL);
 if(n<0)
 {
perror("pthread_create");
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

