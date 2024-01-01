#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("USAGE: mycat <path/to/filename>\n");
        return 1;
    }

    FILE *fhand = fopen(argv[1], "r");

    if (fhand == NULL)
    {
        printf("Error: File does not exist!\n");
        return 2;
    }

    char chr;
    while ((chr = fgetc(fhand)) != EOF)
    {
        printf("%c", chr);
    }

    fclose(fhand);

    return 0;
}
