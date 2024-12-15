#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("USAGE: ./modulo_test num1 num2\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("ERROR: %s is not digit!\n", argv[1]);
            return 2;
        }
    }

    for (int i = 0, len = strlen(argv[2]); i < len; i++)
    {
        if (!isdigit(argv[2][i]))
        {
            printf("ERROR: %s is not digit!\n", argv[2]);
            return 3;
        }
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int out = num1 % num2;

    printf("%i %% %i = %i\n", num1, num2, out);
}
