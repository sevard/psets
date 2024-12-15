#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 3)
    {
        printf("Error: Two arguments are required!\n");
        return 1;
    }

    char fn = toupper(argv[1][0]);
    char ln = toupper(argv[2][0]);

    printf("initials: %c.%c.\n", fn, ln);

    return 0;
}
