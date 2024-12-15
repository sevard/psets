#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;

    // THIS IS DANGEROUS!
    // Assigning a value into an unallocated memory address
    // *y = 13;

    y = x; // pointer 'y' is assigned the same address as pointer 'x'
    *y = 13; // assign a new value at the address pointed by both 'x' and 'y'

    // Do not use free on both pointers if they point to the same address
    // free(x);
    free(y);
}
