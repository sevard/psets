#include <math.h>
#include <stdio.h>

int main(void)
{
    int param1 = 12;
    int param2 = 13;


    int result1 = round(sqrt(param1));
    int result2 = round(sqrt(param2));
    printf("sqrt( %i) = %i\n", param1, result1);
    printf("sqrt( %i) = %i\n", param2, result2);
}
