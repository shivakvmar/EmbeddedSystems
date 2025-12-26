#include<stdio.h>
#include<string.h>
#include<pthread.h>



typedef struct{
char name[20];
int age;
char vil[20];
} student;

void *structpointer(void *args)
{

student *s=(student *)args;
printf("name is : %s\n",(*s).name);
printf("age is : %d\n",(*s).age);
printf("name is : %s\n",(*s).vil);
return NULL;
}

int main()
{
 student students[3];
pthread_t thread[3];
int n;

for(int i=0;i<3;i++)
{
sprintf(students[i].name, "Shiva%d", i);
sprintf(students[i].vil, "ShivaVil%d", i);
students[i].age=i;
}

for(int j=0;j<3;j++)
{
n=pthread_create(&thread[j],NULL,structpointer,&students[j]);

}
for(int j=0;j<3;j++)
{
n=pthread_join(thread[j],NULL);

}

return 0;
}
