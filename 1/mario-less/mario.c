#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Start printing
    for (int i = 1; i <= height; i++)
    {
        int spaces = height - i;
        for (int s = 0; s < spaces; s++)
        {
            printf(" ");
        }

        for (int hashes = 0; hashes < i; hashes++)
        {
            printf("#");
        }

        printf("\n");
    }
}