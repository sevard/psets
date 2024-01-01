#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void replace(char *s);

int main(void)
{
    // string name = get_string("Enter a word: ");
    char name[7] = "sergey";

    printf("%s\n", name);

    replace(name);

    printf("%s\n", name);
}

void replace(char *s)
{
    // printf("%li\n", sizeof(s));
    // printf("%c", *s);
    *s = 'J';
}
