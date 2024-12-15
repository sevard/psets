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
    n--;
    if (n == 0)
    {
        return array[0] > array[n + 1] ? array[0] : array[n + 1];
    }
    else
    {
        // [1, 2, ...]
        int m = max(array, n);
        return m > array[n] ? m : array[n];
    }
}
