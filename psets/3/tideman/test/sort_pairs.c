#include <stdio.h>

// Max number of candidates
#define MAX 3

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

pair pairs[MAX];
int preferences[MAX][MAX];
int pair_count = 3;

void print_pairs(void);
void sort_pairs(void);

int main(void)
{
    pairs[0].winner = 0;
    pairs[0].loser = 1;
    pairs[1].winner = 0;
    pairs[1].loser = 2;
    pairs[2].winner = 2;
    pairs[2].loser = 1;

    // preferences[[0, 3, 3], [1, 0, 1], [1, 3, 0]]
    // preferences[[0, 3, 3], [1, 0, 0], [1, 4, 0]]
    preferences[0][0] = 0;
    preferences[0][1] = 3;
    preferences[0][2] = 3;

    preferences[1][0] = 1;
    preferences[1][1] = 0;
    preferences[1][2] = 0;

    preferences[2][0] = 1;
    preferences[2][1] = 4;
    preferences[2][2] = 0;


    // print_pairs();
    printf("---- Before sort ----\n");
    print_pairs();
    sort_pairs();
    printf("---- After sort ----\n");
    print_pairs();

}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    /** **************************************************************
     * sort the pairs array in decreasing order of strength of victory
     * If multiple pairs have the same strength of victory,
     *   assume that the order does not matter.
    ** ***************************************************************/

    for (int i = 0; i < pair_count; i++)
    {
        int votes1, votes2;
        int indx = i;

        // find winner with the highest score
        for (int j = i + 1; j < pair_count; j++)
        {
            votes1 = preferences[pairs[i].winner][pairs[i].loser];
            votes2 = preferences[pairs[j].winner][pairs[j].loser];

            if (votes2 > votes1)
            {
                // higher_votes_pair = pairs[j];
                indx = j;
            }
        }

        // swap highest score pair with currently compared pair
        pair higher_votes_pair = pairs[indx];
        pairs[indx] = pairs[i];
        pairs[i] = higher_votes_pair;
    }

    return;
}

void print_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        printf("pairs[%i].winner %i\n", i, pairs[i].winner);
        printf("pairs[%i].loser %i\n", i, pairs[i].loser);
        printf("\n");
    }
}
