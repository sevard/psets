#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

// Prototypes
bool is_jpeg_marker(BYTE arr[]);

int main(int argc, char *argv[])
{
    // Verify correct usage
    if (argc < 2)
    {
        printf("USAGE: ./recover <filename>\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("ERROR: Cannot open file!\n");
        return 1;
    }

    BYTE *buffer = malloc(BLOCK_SIZE * sizeof(BYTE));
    if (buffer == NULL)
    {
        fclose(inptr);
        printf("ERROR: Cannot allocate memory!");
        return 1;
    }

    bool out_file_open = false;
    FILE *tmp = NULL;
    char fname[8];
    int fname_int = 0;

    while(fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        bool mark_jpeg = is_jpeg_marker(buffer);

        // checks first time
        if ( (mark_jpeg && !out_file_open) )
        {
            sprintf(fname, "%0*d.jpg", 3, fname_int);
            FILE *outptr = fopen(fname, "w");
            if (outptr == NULL)
            {
                printf("ERROR: Cannot open output file!\n");
                free(buffer);
                fclose(inptr);
                return 1;
            }

            fwrite(buffer, 1, BLOCK_SIZE, outptr);
            out_file_open = true;
            tmp = outptr;
        }
        // check if next 512 B is continue of same picture
        else if (!mark_jpeg && out_file_open)
        {
            fwrite(buffer, 1, BLOCK_SIZE, tmp);
        }
        // check if at the end of picture
        else if (mark_jpeg && out_file_open)
        {
            out_file_open = false;
            fname_int++;
            fclose(tmp);
        }
    }
    fclose(inptr);
    free(buffer);
    return 0;
}

bool is_jpeg_marker(BYTE arr[])
{
    BYTE first = arr[0];
    BYTE second = arr[1];
    BYTE third = arr[2];
    BYTE fourth = arr[3];

    if (first != 0xff)
    {
        return false;
    }
    if (second != 0xd8)
    {
        return false;
    }
    if (third != 0xff)
    {
        return false;
    }
    // 0xe0 - 0xef
    if (fourth < 224 || fourth > 239)
    {
        return false;
    }
    return true;
}

