#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    do
    {
        length = get_int("Enter the a positive number: ");

    }
    while (length < 1);

    int arr[length];
    int elem = 1;

    for(int i = 0; i < length; i++)
    {
        printf("i:%i; elem: %i\n", i, elem);
        elem = elem * 2;
        arr[i] = elem;
    }
}