#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    int message_len = strlen(message);
    int bits_arr[BITS_IN_BYTE];

    int indx, num;
    for (int c = 0; c < message_len; c++)
    {
        // Reset elements in array
        indx = BITS_IN_BYTE;
        for (int j = 0; j < indx; j++)
        {
            bits_arr[j] = 0;
        }

        // Convert each number to binary and store in array
        num = message[c]; // 'num' is current char number
        while (num > 0)
        {
            bits_arr[indx - 1] = num % 2; // starting from end
            num = num / 2;
            indx--;
        }

        // print bulbs
        for (int i = 0; i < BITS_IN_BYTE; i++)
        {
            print_bulb(bits_arr[i]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
