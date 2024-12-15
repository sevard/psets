#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    /**
     * Start with the last char and convert it into an integer value.
     * Then shorten the string, removing the last char,
     * and then recursively call convert using the shortened string as input,
     * where the next char will be processed.
    */

    int indx = strlen(input) - 1;

    if (indx == 0)
    {
        return input[indx] - '0';
    }
    else
    {
        // use a temporary variables for better visibility while debugging.

        // convert the last char
        int num = input[indx] - '0';

        // shorten the string
        input[indx] = '\0';

        // recursively call convert using the shortened string.
        int result = 10 * convert(input) + num;
        return result;
    }
}
