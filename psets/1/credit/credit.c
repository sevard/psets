#include <cs50.h>
#include <stdio.h>

// Prototypes
int get_number_len(long card_number);
int get_first_two_digits(long card_number);
bool check_luhn(long card_number);
bool check_amex(long number);
bool check_visa(long number);
bool check_master(long number);

int main(void)
{
    // Get user input
    long cc_number;
    int cc_number_len;

    cc_number = get_long("Number: ");
    cc_number_len = get_number_len(cc_number);

    // Checking min length and then luhn
    cc_number_len = get_number_len(cc_number);
    if (cc_number_len < 13)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (!check_luhn(cc_number))
    {
        printf("INVALID\n");
        return 0;
    }

    // At this point luhn and length are valid. Check if any of the card brand.
    if (check_amex(cc_number))
    {
        printf("AMEX\n");
    }
    else if (check_visa(cc_number))
    {
        printf("VISA\n");
    }
    else if (check_master(cc_number))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

// Functions
int get_number_len(long card_number)
{
    int counter = 0;
    while (card_number > 0)
    {
        card_number = card_number / 10;
        counter++;
    }
    return counter;
}

bool check_luhn(long card_number)
{
    int sum_one = 0;
    int sum_two = 0;
    // remove last digit to start from the second-to-last
    long stl_cc_num = card_number / 10;

    // Multiply and then sum every other digit
    int digit;
    while (stl_cc_num > 0)
    {
        digit = (stl_cc_num % 10) * 2;
        if (digit > 9) // add digits, not the product
        {
            sum_two += (digit % 10) + 1;
        }
        else
        {
            sum_two += digit;
        }
        stl_cc_num = stl_cc_num / 100;
    }

    // Sum every other digit
    while (card_number > 0)
    {
        sum_one += (card_number % 10);
        card_number = card_number / 100;
    }

    // Final check
    if ((sum_one + sum_two) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int get_first_two_digits(long number)
{
    while (number > 99)
    {
        number = number / 10;
    }
    return number;
}

bool check_amex(long number)
{
    // AMEX uses 15-digit numbers start with 34, 37
    int ccn_first_two = get_first_two_digits(number);
    int cc_number_len = get_number_len(number);

    if (ccn_first_two == 34 || ccn_first_two == 37)
    {
        if (cc_number_len == 15)
        {
            return true;
        }
    }

    return false;
}

bool check_visa(long number)
{
    // Visa uses 13- and 16-digit numbers start with 4
    int ccn_first_two = get_first_two_digits(number);
    int cc_number_len = get_number_len(number);

    if (ccn_first_two >= 40 && ccn_first_two <= 49)
    {
        if ((cc_number_len == 13 || cc_number_len == 16))
        {
            return true;
        }
    }

    return false;
}

bool check_master(long number)
{
    // MasterCard uses 16-digit numbers start with 51, 52, 53, 54, 55
    int ccn_first_two = get_first_two_digits(number);
    int cc_number_len = get_number_len(number);

    if (ccn_first_two >= 51 && ccn_first_two <= 55)
    {
        if (cc_number_len == 16)
        {
            return true;
        }
    }

    return false;
}
