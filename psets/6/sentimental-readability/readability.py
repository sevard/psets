#!/usr/bin/env python3


"""
A program that first asks the user to type in some text,
and then outputs the grade level for the text,
according to the Coleman-Liau formula

0.0588 * L - 0.296 * S - 15.8
L is the average number of letters per 100 words in the text,
S is the average number of sentences per 100 words in the text.
"""


def get_string(prompt):
    return input(prompt)


def get_text_values(text):

    # any lowercase character from [a-z] or [A-Z]
    letters = len([l for l in text if l.isalpha()])

    # any sequence of characters separated by spaces
    words = len(text.split(" "))

    # ends with period '.', exclamation point '!', question mark '?'
    sentence = len([s for s in text if s in ['.', '!', '?']])

    return (letters, words, sentence)


def calc_grade(letters=0, words=0, sentences=0):

    try:
        # L is the average number of letters per 100 words in the text,
        L = (letters / words) * 100

        # S is the average number of sentences per 100 words in the text.
        S = 100 / (words / sentences)

        return round((0.0588 * L) - (0.296 * S) - 15.8)

    except ZeroDivisionError as err:
        print(f"ERROR: {err} !")
        return None


def get_grade(text):
    values = get_text_values(text)  # returns a tuple (letters, words, sentences)
    grade = calc_grade(values[0], values[1], values[2])
    if (not grade):
        return "ERROR: 'grade' returns None!"

    if grade < 1:
        return "Before Grade 1"
    elif grade > 16:
        return "Grade 16+"
    else:
        return f"Grade {grade}"


def main():
    text = get_string("Text: ")
    grade = get_grade(text)

    print(grade)


main()
