#include<stdio.h>

int main(int arg,char *argv[])
{
printf("number arguments:%d\n",arg);
for(int i=0;i<arg;i++)
{
printf("argument %d %s\n",i,argv[i]);
}
return 0;
}
