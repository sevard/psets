// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: no-vowels <word>\n");
        return 1;
    }

    string word = replace(argv[1]);

    printf("%s\n", word);
}

string replace(string word)
{
    // change the following vowels to numbers:
    // a becomes 6,
    // e becomes 3,
    // i becomes 1,
    // o becomes 0
    // u does not change.

    int length = strlen(word);
    char letter;
    for (int i = 0; i < length; i++)
    {
        letter = word[i];
        switch (letter)
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
        }
    }
    return word;
}