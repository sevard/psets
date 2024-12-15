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
                sums[i] += (n // 10) + (n % 10)
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

    credit_card_info = {
        'AMEX': {
            'first_two': ['34', '37'],
            'cc_len': [15, ],
        },
        'MASTERCARD': {
            'first_two': ['51', '52', '53', '54', '55'],
            'cc_len': [16, ],
        },
        'VISA': {
            'first_two': ['40', '41', '42', '43', '44', '45', '46', '47', '48', '49'],
            'cc_len': [13, 16],
        },
    }

    check_cc_frst_two = str(cc_number)[:2]  # get first two digits
    check_cc_len = len(str(cc_number))

    for dkey, val in credit_card_info.items():
        valid_first_two = val.get('first_two')
        valid_length = val.get('cc_len')

        # are the first two digits are valid ?
        if (check_cc_frst_two not in valid_first_two):
            continue
        # is the length of the card valid ?
        if (check_cc_len not in valid_length):
            continue
        # at this point need to check Luhn
        if (check_luhn(cc_number)):
            return dkey

    return "INVALID"


def main():
    cc_nmbr = get_credit_card_number("Number: ")
    cc_type = get_card_type(cc_nmbr)
    print(cc_type)


main()
