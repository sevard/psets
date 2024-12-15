#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_INDX = 26; // 26 letters in English alphabet
const int ASCII_UPPER_A = 65;
const int ASCII_LOWER_A = 97;

char get_cipher_char(char c, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if passed cli argument <key> is digit
    string arg_key = argv[1];
    int arg_key_len = strlen(arg_key);
    for (int i = 0; i < arg_key_len; i++)
    {
        if (!isdigit(arg_key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    // Get input plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    char c;
    int plaintext_len = strlen(plaintext);
    for (int i = 0; i < plaintext_len; i++)
    {
        c = get_cipher_char(plaintext[i], key);
        printf("%c", c);
    }
    printf("\n");
}

char get_cipher_char(char c, int key)
{
    int pos = toupper(c) - ASCII_UPPER_A;
    if (isalpha(c) && isupper(c))
    {
        return ASCII_UPPER_A + (pos + key) % MAX_INDX;
    }
    else if (isalpha(c) && islower(c))
    {
        return ASCII_LOWER_A + (pos + key) % MAX_INDX;
    }
    return c;
}
