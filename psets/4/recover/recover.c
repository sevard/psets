#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

    FILE *inptr = fopen(argv[1], "rb");
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
        return 2;
    }

    // Get the size of input file
    if (fseek(inptr, 0L, SEEK_END) != 0)
    {
        printf("ERROR: fseek failed!\n");
        return 3;
    }
    long file_size = ftell(inptr);
    fseek(inptr, 0L, SEEK_SET);

    FILE *outptr = NULL;
    long fname_int = 0;
    long curr_byte = 0;

    while (curr_byte <= file_size)
    {
        curr_byte += fread(buffer, 1, BLOCK_SIZE, inptr);

        if (is_jpeg_marker(buffer))
        {
            char fname[8];
            sprintf(fname, "%0*li.jpg", 3, fname_int++);
            outptr = fopen(fname, "wb");
            if (outptr == NULL)
            {
                printf("ERROR: Cannot open output file!\n");
                free(buffer);
                fclose(inptr);
                return 1;
            }

            do
            {
                fwrite(buffer, 1, BLOCK_SIZE, outptr);
                fread(buffer, 1, BLOCK_SIZE, inptr);
                curr_byte += BLOCK_SIZE;
            }
            while (!is_jpeg_marker(buffer) && (curr_byte <= file_size));

            fclose(outptr);
            curr_byte -= BLOCK_SIZE;
            fseek(inptr, -512, SEEK_CUR);
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
