#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int ASCII_UPPER_A = 65;
int ASCII_LOWER_A = 97;

char get_cipher_char(char c, char key[]);
bool has_nonalpha_chars(char key[]);
bool has_duplicate_chars(char key[]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: substitution <key>\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (has_nonalpha_chars(argv[1]))
    {
        printf("Key must contain only alphabetical chars)\n");
        return 1;
    }

    if (has_duplicate_chars(argv[1]))
    {
        printf("Key most not have duplicates.\n");
        return 1;
    }

    // Get user input
    string plaintext = get_string("plaintext: ");

    // Make cipher and print
    printf("ciphertext: ");
    char c;
    int plaintext_len = strlen(plaintext);
    for (int j = 0; j < plaintext_len; j++)
    {
        c = get_cipher_char(plaintext[j], argv[1]);
        printf("%c", c);
    }
    printf("\n");
}

bool has_duplicate_chars(char key[])
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (toupper(key[i]) == toupper(key[j]))
            {
                return true;
            }
        }
    }

    return false;
}

bool has_nonalpha_chars(char key[])
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return true;
        }
    }
    return false;
}

char get_cipher_char(char c, char key[])
{
    int pos;
    if (isalpha(c) && isupper(c))
    {
        pos = c - ASCII_UPPER_A;
        return toupper(key[pos]);
    }
    else if (isalpha(c) && islower(c))
    {
        pos = c - ASCII_LOWER_A;
        return tolower(key[pos]);
    }
    else
    {
        return c;
    }
}
