#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("Enter your name: ");
    int name_len = strlen(name);
    char name_upper[name_len];

    printf("Hello, ");
    for (int i = 0; i < name_len; i++)
    {
        // if (name[i] == 32)
        // {
        //     name_upper[i] = name[i];
        //     continue;
        // }
        // name_upper[i] = toupper(name[i]);
        printf("%c", toupper(name[i]));
    }
    printf("\n");

}
