#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("USAGE: get int[str]\n");
        return 1;
    }

    if (strcmp(argv[1], "int") == 0)
    {

        long x;
        printf("Enter a number: ");
        scanf("%li", &x);
        printf("%li\n", x);

    }
    else if (strcmp(argv[1], "str") == 0)
    {
        char *s = malloc(1024);

        printf("Enter a word: ");

        fgets(s, 1024, stdin);

        // printf("len of s: %li\n", strlen(s));
        char *user_input = malloc(strlen(s));

        strcpy(user_input, s);

        printf("%s\n", user_input);

        free(s);
        free(user_input);

        // char string[10];
        // printf("Enter the String: ");
        // gets(string);

        // printf("\n%s",string);
        // return 0;
    }
}
