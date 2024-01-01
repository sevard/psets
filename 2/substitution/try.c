#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int key_arg = strlen(argv[1]);
    int key_len = strlen(key_arg);
    char key[key_len];

    for (int i = 0; i < key_len; i++)
    {
        key[i] = toupper(key_arg[i]);
    }

    char word[256];
    printf("plaintext: ");
    fgets(word, sizeof(word), stdin);
    int word_len = strlen(word);

    printf("ciphertext: ");

    char c;
    int pos;
    for (int j = 0; j < word_len; j++)
    {
        c = word[j];
        if (isalpha(c) && isupper(c))
        {
            pos = c - 65;
            printf("%c", toupper(key[pos]));
        }
        else if (isalpha(c) && islower(c))
        {
            pos = c - 97;
            printf("%c", tolower(key[pos]));
        }
        else
        {
            printf("%c", c);
        }
    }
    // printf("\n");
}
