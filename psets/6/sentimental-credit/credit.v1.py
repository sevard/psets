#!/usr/bin/env python3


def get_credit_card_number(prompt):
    while True:
        try:
            n = int(input(prompt))
            if (n <= 1_000_000):
                continue
            return n
        except ValueError:
            pass


def check_luhn(num):
    # Luhn's algorithm
    # 1 - Multiply every other digit by 2, starting with the number’s second-to-last digit,
    #     and then add those products’ digits together.
    #
    # 2 - Add the sum to the sum of the digits that weren’t multiplied by 2.
    #
    # 3 - If the total’s last digit is 0
    #     (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

    digits = [[], []]
    cc_num = num // 10  # start from the second-to-last
    while (cc_num > 0):
        digit = (cc_num % 10) * 2
        digits[0].append(digit)
        cc_num //= 100

    cc_num = num  # start from the last number
    while (cc_num > 0):
        digit = (cc_num % 10)
        digits[1].append(digit)
        cc_num //= 100

    sums = [0, 0]
    for i in range(2):
        for n in digits[i]:
            if n > 9:
                # add products’ digits (i.e., not the products themselves)
                # ex: digit is 12, add 1 + 2
                sums[i] += sum([int(x) for x in str(n)])
                continue
            sums[i] += n

    total = sum(sums)

    if (total % 10 == 0):
        return True

    return False


def get_card_type(cc_number):
    # AMEX uses 15-digit numbers start with 34 or 37
    # MasterCard uses 16-digit numbers start with 51, 52, 53, 54, 55
    # Visa uses 13- and 16-digit numbers start with 4

    amex_digits = ['34', '37']
    mast_digits = ['51', '52', '53', '54', '55']
    visa_digits = ['40', '41', '42', '43', '44', '45', '46', '47', '48', '49']

    cc_types = ["AMEX", "MASTERCARD", "VISA", "INVALID"]
    frst_two = str(cc_number)[:2]
    card_len = len(str(cc_number))

    if (frst_two in amex_digits and card_len == 15):
        if (check_luhn(cc_number)):
            return cc_types[0]  # AMEX

    elif (frst_two in mast_digits and card_len == 16):
        if (check_luhn(cc_number)):
            return cc_types[1]  # MASTERCARD

    elif (frst_two in visa_digits and (card_len == 16 or card_len == 13)):
        if (check_luhn(cc_number)):
            return cc_types[2]  # VISA

    return cc_types[3]  # INVALID


def main():
    cc_nmbr = get_credit_card_number("Number: ")
    cc_type = get_card_type(cc_nmbr)
    print(cc_type)


main()
