#include <stdio.h>
#include <cs50.h>

int main(void)
{
    bool a = false;
    bool b = true;
    bool c = true;

    int x = a + b + c;
    printf("%i\n", x);
    printf("'x' is %s\n", x ? "true" : "false");
}
