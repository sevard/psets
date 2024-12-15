#include <cs50.h>
#include <stdio.h>

long factorial(int num);

int main(void)
{
    int number;
    do
    {
        number = get_int("Enter a positive number: ");
    }
    while (number <= 0);

    printf("Factorial of %i is %li\n", number, factorial(number));
}

long factorial(int num)
{
    if (num == 1)
    {
        return num;
    }
    else
    {
        return num * factorial(num - 1);
    }
}
