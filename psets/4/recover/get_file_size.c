#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("USAGE: ./get_file_size <filename>\n");
        return 1;
    }

    FILE *fhand = fopen(argv[1], "rb");
    if (fhand == NULL)
    {
        printf("ERROR: Cannot open file!\n");
        return 2;
    }

    if (fseek(fhand, 0L, SEEK_END) != 0)
    {
        printf("ERROR: fseek failed!\n");
        return 3;
    }

    long size = ftell(fhand);
    fclose(fhand);
    printf("Size: %li\n", size);

    return 0;
}
