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
    FILE *inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("ERROR: Cannot open file!\n");
        return 1;
    }

    BYTE (*buffer)[BLOCK_SIZE] = malloc(BLOCK_SIZE * sizeof(BYTE));
    if (buffer == NULL)
    {
        fclose(inptr);
        printf("ERROR: Memory allocation failure occurred!");
        return 1;
    }

    bool out_file_open = false;
    FILE *tmp = NULL;
    int filenum = 10;
    while(fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        bool mark_jpeg = is_jpeg_marker(*buffer);
        if (mark_jpeg && (!out_file_open))
        {
            char fname[15];
            sprintf(fname, "images/%i.jpeg", filenum++);
            FILE *outptr = fopen(fname, "w");
            if (outptr == NULL)
            {
                printf("Could not open output file!\n");
                free(buffer);
                fclose(inptr);
                return 1;
            }

            out_file_open = true;
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
            tmp = outptr;
            // fclose(outptr);
        }
        else if ((!mark_jpeg) && out_file_open)
        {
            fwrite(buffer, BLOCK_SIZE, 1, tmp);
        }
        else if ( mark_jpeg && out_file_open )
        {
            out_file_open = false;
            fclose(tmp);
            printf("pic is written\n");
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

