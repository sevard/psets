#!/usr/bin/env python3

# Program calculates the number of coins given the amount
# Coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).

def get_positive_float(prompt):
    while True:
        try:
            n = float(input(prompt))
            if ((n * 100) <= 0):
                continue
            return n
        except ValueError:
            pass


def calculate_coins(change):

    cents = int(change * 100)
    coins = [25, 10, 5, 1]

    num_of_coins = 0
    for coin in coins:
        if (cents >= coin):
            num_of_coins += cents // coin
            cents = cents - ((cents // coin) * coin)

    return num_of_coins


def main():
    change = get_positive_float("Change: ")
    coins_to_give = calculate_coins(change)
    print(coins_to_give)


main()
