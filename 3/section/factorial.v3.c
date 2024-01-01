#include <cs50.h>
#include <stdio.h>

long fact(int num);

int main(void)
{
    int number = get_int("Enter a positive number: ");
    long factorial_num = fact(number);
    printf("Factorial of %i is %li\n", number, factorial_num);
}

long fact(int num)
{
    long product = 1;
    while (num > 0)
    {
        product *= num;
        num--;
    }

    return product;
}
