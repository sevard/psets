#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // char filename[8];
    char *filename = malloc(8 * sizeof(char));
    for (int i = 0; i < 24; i++)
    {
        // 000.jpg
        sprintf(filename, "%0*d.jpg", 3, i);
        printf("%s\n", filename);
    }
    free(filename);
}
