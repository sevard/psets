#include <stdio.h>

int main(void)
{
    // int takes up 4 bytes == 32 bits
    int n = 50;

    printf("Value %i at %p\n", n, &n);
}
