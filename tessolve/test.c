#include <stdio.h>
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int , int);

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Addition = %d\n", add(a, b));
    printf("Subtraction = %d\n", sub(a, b));
    printf("Multiplication = %d\n", mul(a, b));
    printf("division  = %d\n", div(a,b));

    return 0;
}

