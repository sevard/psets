#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    // 'File Signature' is the first 4 bytes stored in a file
    //  PDF File Signature is:  37 80 68 70
    // JPEG File Signature is: 255 216 255 224

    if (argc != 2)
    {
        printf("USAGE: pdf <filename>\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("ERROR: File does not exist!\n");
        return 2;
    }

    uint8_t buffer[4];
    uint8_t pdf_fsignature[4] = {37, 80, 68, 70};

    fread(buffer, 1, 4, input);
    fclose(input);

    // Does the buffer signature match?
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != pdf_fsignature[i])
        {
            printf("NOT a PDF File!\n");
            return 0;
        }
    }

    printf("Likely a PDF file.\n");

    return 0;
}
