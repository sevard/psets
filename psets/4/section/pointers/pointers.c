#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 28;
    int b = 50;
    int *c = &a; // is address of 'a'

    *c = 14; // 'a' gets value 14
    c = &b; // 'c' gets address of 'b'
    *c = 25; // 'b' gets value 25

    // Print results
    printf("a has the value %i, located at %p\n", a, &a); // 14, 0xA123
    printf("b has the value %i, located at %p\n", b, &b); // 25, 0xB123
    printf("c has the value %p, located at %p\n", c, &c); // 0xB123, 0xC123
}
