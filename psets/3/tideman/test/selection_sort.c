#include <stdio.h>
#include <cs50.h>

// Array length
#define MAX 10

int main(void)
{
    // int arr[MAX] = {2, 5, 0, 1, 4, 8, 7, 9, 6, 3};
    int arr[MAX] = {2, 2, 0, 1, 4, 8, 7, 9, 6, 3};
    // int arr[MAX] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

    for (int i = 0; i < MAX; i++)
    {
        int max_num = arr[i];
        int indx = i;

        // find the highest number
        for (int j = i + 1; j < MAX; j++)
        {
            if (arr[j] > max_num)
            {
                max_num = arr[j];
                indx = j;
            }
        }

        arr[indx] = arr[i];
        arr[i] = max_num;

    }

    for (int i = 0; i < MAX; i++)
    {
        printf("%i ", arr[i]);
    }

    printf("\n");
}
