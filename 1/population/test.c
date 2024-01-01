#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Positive integer greater or equal than 9: ");
        printf("You entered %d \n", n);
    }
    while (n < 9);
}
