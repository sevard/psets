#include <stdio.h>

int main(void)
{
    // int takes up 4 bytes == 32 bits
    int n = 50;
    // pointer takes up 8 bytes == 64 bits
    int *pn = &n;

    printf("Value %i at %p\n", n, pn);

    *pn = 333;

    // Dereference pointer *pn (go to the address and print the value stored there)
    printf("Value %i at %p\n", *pn, pn);

}
