#include <stdio.h>
#include <pthread.h>

int numbers[10] = {1,2,3,4,5,6,7,8,9,10};

// Thread function
void* partialsum(void* args)
{
    int index = *(int*)args; // 0 or 1
    int start = index * 5;
    int end = start + 5;
    int sum = 0;

    for(int j = start; j < end; j++)
        sum += numbers[j];

    return (void*)(long)sum;
}

int main()
{
    pthread_t threads[2];
    int indices[2] = {0, 1}; // Each thread gets its own copy of index
    void* ret;
    int total_sum = 0;

    // Create threads
    for(int i = 0; i < 2; i++)
    {
        if(pthread_create(&threads[i], NULL, partialsum, &indices[i]))
        {
            perror("failed to create thread");
            return 1;
        }
    }

    // Join threads and collect partial sums
    for(int i = 0; i < 2; i++)
    {
        if(pthread_join(threads[i], &ret) != 0)
        {
            perror("failed to join thread");
            return 1;
        }
        total_sum += (int)(long)ret;
    }

    printf("Sum of array = %d\n", total_sum);
    return 0;
}

