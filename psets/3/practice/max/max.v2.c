// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int indx = n - 1;
    if (indx == 0)
    {
        return array[0];
    }
    else
    {
        // [1, 2, ...]
        if (array[indx] > array[indx - 1])
        {
            return array[indx] > max(array, indx - 1)
                ? array[indx]
                : max(array, indx - 1);
        }
        else
        {
            return array[indx - 1] > max(array, indx - 1)
                ? array[indx - 1]
                : max(array, indx - 1);
        }
    }
}
