#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string name = "sergey";
    int length = strlen(name);

    for (int i = 0; i < length; i++)
    {
        printf("%c ", name[i]);
    }
    printf("\n");

    for (int i = 0; i < length; i++)
    {
        printf("%i ", name[i]);
    }
    printf("\n");
}