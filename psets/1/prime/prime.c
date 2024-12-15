#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>


bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    if (number == 2)
    {
        return true;
    }
    // Prime numbers are odd
    if (number % 2 == 0)
    {
        return false;
    }

    int N = number;
    int k = (N - 1) / 2;
    int k_plus_one = k + 1;
    char arr[k_plus_one];

    for (int i = 0; i < k_plus_one; i++)
    {
        arr[i] = 'T';
    }

    int sqrt_k = sqrt(k);
    int x, y, ind;
    for (int i = 1; i < sqrt_k; i++)
    {
        x = i;
        y = i;

        while (x + y + (2 * x * y) <= k)
        {
            ind = x + y + (2 * x * y);
            arr[ind] = 'F';
            // printf("pos: %i; val: %c\n", ind, arr[ind]);
            y += 1;
        }
    }

    for (int i = 0; i < k_plus_one; i++)
    {
        if (arr[i] == 'T')
        {
            if (number == (i * 2) + 1)
            {
                return true;
            }
            // printf("Prime: %i\n",(i * 2) + 1);
        }
    }
    return false;
}


// for (int i = 0; i < 10; i++)
// {
//     printf("pos: %i; value: %c\n", i, arr[i]);
// }

