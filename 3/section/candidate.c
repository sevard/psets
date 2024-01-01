#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate candidate_array[3];
    for (int i = 0; i < 3; i++)
    {
        candidate_array[i] = get_candidate("Enter a candidate: ");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s, Voles: %i\n", candidate_array[i].name, candidate_array[i].votes);
    }
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("Entern candidate name: ");
    c.votes = get_int("Enter candidate votes: ");
    return c;
}
