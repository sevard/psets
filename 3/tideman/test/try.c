#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int arr[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = get_int("Enter int: ");
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("i: %i, j: %i\n", i, arr[i][j]);
        }
    }

}
