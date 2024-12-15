#include <cs50.h>
#include <stdio.h>

//   print a line of
//     start with spaces := (height - loop number)
//     followed by hashes := loop number 'i'
//     followed by 2 spaces,
//     followed by hashes := loop number 'i'

int main(void)
{
    // Get positive integer
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Iterate number of times stored in 'height'
    for (int i = 0; i < height; i++)
    {
        // Print spaces := (height - loop number)
        int spaces = height - i;
        for (int s = 1; s < spaces; s++)
        {
            printf(" ");
        }

        // Print first sequence of hashes := loop number 'i'
        int loop = i + 1;
        for (int first_hashes = 0; first_hashes < loop; first_hashes++)
        {
            printf("#");
        }

        // Print 2 spaces
        printf("  ");

        // Print second sequence of hashes := loop number 'i'
        for (int second_hashes = 0; second_hashes < loop; second_hashes++)
        {
            printf("#");
        }

        printf("\n");
    }
}