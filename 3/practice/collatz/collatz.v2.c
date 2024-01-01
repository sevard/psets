/**
 * The Collatz conjecture is applied to positive integers
 * and speculates that it is always possible to get "back to 1" if you
 * follow these steps:
 *      - if n is 1, stop
 *      - Otherwise, if n is even, repeat this process on n/2
 *      - Otherwise, if n is odd, repeat this process on 3n + 1
 *
 * Write a recursive function collatz(n) that calculates how
 * many steps it takes to get to 1 if you start from n and recurse
 * as indicated above.
*/
#include <cs50.h>
#include <stdio.h>

int collatz(int num);

int main(void)
{
    int number = get_int("Enter a positive number: ");
    printf("Steps taken: %i\n", collatz(number));
}

int collatz(int num)
{
    if (num == 1)
    {
        return 0;
    }
    else if ((num % 2) == 0)
    {
        return 1 + collatz(num/2);
    }
    else
    {
        return 1 + collatz(3*num + 1);
    }
}
