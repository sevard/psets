#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3};
    int tmp[3];

    int indx = 0;

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = arr[i];
        indx = i;
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i] = tmp[indx];
        printf("%i\n", arr[i]);
        indx--;
    }
}
