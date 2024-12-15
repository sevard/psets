// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool is_upper = false;
    bool is_lower = false;
    bool is_num = false;
    bool is_sym = false;

    int length = strlen(password);

    char c;
    for (int i = 0; i < length; i++)
    {
        c = password[i];

        if (isupper(c))
        {
            is_upper = true;
        }
        else if (islower(c))
        {
            is_lower = true;
        }
        else if (isdigit(c))
        {
            is_num = true;
        }
        else if (ispunct(c))
        {
            is_sym = true;
        }
    }

    if (is_upper && is_lower && is_num && is_sym)
    {
        return true;
    }

    return false;
}
