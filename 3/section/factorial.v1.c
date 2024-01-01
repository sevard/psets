#include <cs50.h>
#include <stdio.h>

int print_factorial(int n);

int main(void)
{
    int num = get_int("Enter a number: ");

    print_factorial(num);
}

int print_factorial(int n)
{
    if (n == 1)
    {
        return n;
    }

    n = n - 1;

    int f = print_factorial(n);

    f = (n + 1) * f;

    printf("%i! is %i\n", n + 1, f);

    return f;
}
