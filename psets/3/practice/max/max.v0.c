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
    n = n - 1;
    if (n == 0)
    {
        return array[0];
    }
    else
    {
        // [1, 2, ...]
        int m;
        if (array[n] > array[n - 1])
        {
            m = array[n];
        }
        else
        {
            m = array[n - 1];
        }

        return max(array, n - 1) > m ? max(array, n - 1) : m ;
    }
}
