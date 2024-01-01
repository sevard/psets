#include <cs50.h>
#include <string.h>
#include <stdio.h>


int main(void)
{
    // string name = get_string("Enter name: ");
    // int len = strlen(name);
    // int len = strlen(name);
    // int new_len = len - 1;
    // char new_name[new_len];

    // strncpy(new_name, name, new_len);

    // printf("New name: %s; last char: %c\n", new_name, new_name[new_len]);

    char arr[] = {'\0', '\0', '\0'};
    if (!arr[0])
    {
        printf("done: len is %li\n", strlen(arr));
    }
    // while (len > 0)
    // {
    //     for (int i = 0; i < len; i++)
    //     {
    //         printf("%c ", name[i]);
    //     }
    //     printf("\n");

    //     len = strlen(name);
    // }
    // printf("len %i\n", len);
    // memmove(name, name, len - 1);
    // printf("len %li\n", strlen(name));
}
