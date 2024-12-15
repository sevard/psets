#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string name = "se";
    int length = strlen(name);
    int num;
    int arr_indx;
    int arr_byte[8];

    for (int i = 0; i < length; i++)
    {
        num = name[i]; // i is string position
        printf("%i\n", num);
        arr_indx = 8;

        // Reset elems in array to 0
        for (int j = 0; j < arr_indx; j++)
        {
            arr_byte[j] = 0;
        }

        // Convert each numbr to bin and store in array
        while (num > 0)
        {
            printf("%i ,", num % 2);
            arr_byte[arr_indx - 1] = num % 2;
            num = num / 2;
            arr_indx--;
        }
        printf("\n");

        // print array
        for (int k = 0; k < 8; k++)
        {
            printf("%i ", arr_byte[k]);
        }

    printf("\n");
    }
}
