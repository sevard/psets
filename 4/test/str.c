#include <stdio.h>

typedef char *string;

int main(void)
{
    char *name1 = "Sergey 1";
    string name2 = "Sergey 2";

    printf("%s\n", name1);
    printf("%s\n", name2);
}
