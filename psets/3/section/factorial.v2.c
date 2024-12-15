#include <cs50.h>
#include <stdio.h>

long get_factorial(int n);

int main(void)
{
    int num = get_int("Enter positive integer: ");
    long factorial_num = get_factorial(num);

    printf("Factorial of %i is %li\n", num, factorial_num);
}

long get_factorial(int n)
{
    if (n == 1)
    {
        return n;
    }

    n = n - 1;

    long f = get_factorial(n);

    return (n + 1) * f;
}
