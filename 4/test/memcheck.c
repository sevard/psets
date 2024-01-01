#include <stdio.h>
#include <stdlib.h>

/**
 * Simple example with valgrind
 * USAGE: valgrind ./memcheck
*/

int main(void)
{
    int *x = malloc(3 * sizeof(int));

    if (x == NULL)
    {
        return 1;
    }

    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    printf("%c%c%c\n", x[0], x[1], x[2]);
    // free(x);
    return 0;
}
