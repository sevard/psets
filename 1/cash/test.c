#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
    do
    {
        x = get_int("Enter positive integer: ");
        printf("%d\n", x / 25);
    }
    while (x < 0);
}