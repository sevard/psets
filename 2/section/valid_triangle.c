#include <cs50.h>
#include <stdio.h>

// Prototype declaration
bool valid_triangle(int a, int b, int c);

int main(int argc, string argv[])
{
    // printf("argc %i; argv 1 %s; argv 2 %s\n", argc, argv[0], argv[1]);
    int sides[3];
    for (int i = 0; i < 3; i++)
    {
        do
        {
            printf("Enter side %i", i + 1);
            sides[i] = get_int(" : ");
        }
        while (sides[i] < 0);
    }

    bool t_is_valid = valid_triangle(sides[0], sides[1], sides[2]);
    if (t_is_valid)
    printf("Trangle is: %s\n", result ? "Valid" : "Not valid");
}

bool valid_triangle(int a, int b, int c)
{
    if ((a + b) > c || (a + c) > b || (b + c) > a)
    {
        return true;
    }

    return false;
}