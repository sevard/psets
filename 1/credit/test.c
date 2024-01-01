#include <cs50.h>
#include <stdio.h>

bool luhn_check(long card_number);

int main(void)
{
    int cc_len = 15;
    long cc_number = 4003600000000014; // 4 0 6 0 0 0 0 1
    // long cc_number = 4003600000000014;// 0 3 0 0 0 0 0 4
    // long cc_number = 378282246310005; //  7 2 2 4 3 0 0
    // long cc_number = 378282246310005; //  3 8 8 2 6 1 0 5
    long card_number = cc_number;
    long divider = 10;
    int second_sum = 0;
    int num;

    while((card_number / divider) > 0)
    {
        num = (card_number / divider) % 10;
        printf("num: %i ", num);
        printf("div: %li ;", divider);
        if ((num * 2) > 9)
        {   // add digits, not the product; ex: if 14 then sum += 4; sum += 1
            second_sum += (num % 10) + 1;
            printf("sum: %i \n", second_sum);
        }
        else
        {
            second_sum += num;
            printf("sum: %i \n", second_sum);
        }
        divider *= 10;
    }
}
