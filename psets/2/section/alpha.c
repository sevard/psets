#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    // char name[] = {'s', 'e', 'r', 'g', 'e', 'y', '\0'};
    string word = get_string("Word: ");
    int length = strlen(word);

    for (int i = 1; i < length; i++)
    {
        if (word[i - 1] > word[i])
        {
            printf("No\n");
            // printf("%c ", word[i]);
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}