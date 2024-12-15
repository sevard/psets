import csv
import sys


def main():
    usage = """
         USAGE: python3 dna.py <database.csv> <sequence.txt>

        'database' - path to CSV file containing the STR counts for a list of individuals
        'sequence' - path to a text file containing the DNA sequence to identify
    """

    # TODO: Check for command-line usage
    if (len(sys.argv) < 3):
        print(usage)
        sys.exit(1)

    db_file = sys.argv[1]
    dna_str = sys.argv[2]

    # TODO: Read database file into a variable
    with open(db_file, "r") as db_fhand:
        reader = csv.DictReader(db_fhand)

        checklist_of_strs = reader.fieldnames[1:]  # Ex: ['name', 'AGATC', 'AATG', 'TATC']
        database_records = [line for line in reader]

    # TODO: Read DNA sequence file into a variable
    with open(dna_str, "r") as sequence_fhand:
        dna_sequence = sequence_fhand.readline()

    # TODO: Find longest match of each STR in DNA sequence
    matching_dna_strs = {}
    for el in checklist_of_strs:  # STRs from DB: ex ['AGATC', 'AATG', 'TATC']
        count = longest_match(dna_sequence, el)
        matching_dna_strs[el] = str(count)

    # TODO: Check database for matching profiles
    final_item_indx = len(checklist_of_strs) - 1

    for record in database_records:  # {'name': 'Bob', 'AGATC': '4', 'AATG': '1', 'TATC': '5'}
        name = record.get('name')

        for curr_item_indx, el in enumerate(checklist_of_strs):
            if record.get(el) != matching_dna_strs.get(el):
                break
            if curr_item_indx == final_item_indx:
                print(name)
                return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
