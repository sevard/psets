#include <stdio.h>

void swap(int *p1, int *p2);

int main(void)
{
    int num1 = 10;
    int num2 = 20;
    // printf("%p\n%p\n", &num1, &num2);
    printf("num1: %i, num2: %i\n", num1, num2);

    swap(&num1, &num2);

    printf("num1: %i, num2: %i\n", num1, num2);
}

void swap(int *p1, int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
