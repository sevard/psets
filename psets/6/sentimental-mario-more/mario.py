#!/usr/bin/env python3

def get_int(prompt):
    while True:
        try:
            n = int(input(prompt))
            if (n <= 0 or n > 8):
                continue
            return n
        except ValueError:
            pass


def print_pyramid(n):
    for i in range(n):
        spaces = " " * (n - (i + 1))
        hashes = "#" * (i + 1)
        print(f"{spaces}{hashes}  {hashes}")


def main():
    height = get_int("Height: ")
    print_pyramid(height)


main()
