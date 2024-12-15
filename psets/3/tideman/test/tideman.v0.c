#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    // DEBUG
    for (int i = 0; i < candidate_count; i++)
    {
        printf("[");
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i, ", preferences[i][j]);
        }
        printf("]");
    }
    printf("\n");
    // END DEBUG

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    /** *****************************************************************
     * TODO #1
     * Return true if the rank was successfully recorded, otherwise false
     * (if, for instance, name is not the name of one of the candidates).
    ** ******************************************************************/

    for (int i = 0; i < candidate_count; i++)
    {
        // Indicate the voter has the candidate as their 'rank' preference
        if (strcasecmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    /**
     * TODO #2
     * The function is called once for each voter
     * Update the global preferences[] to add the current voter’s preferences
    */
    // candidates = ["Alice", "Bob", "Charlie"]
    // preferences[i][j] represents the number of voters who prefer candidate i over candidate j.
    // preferences[[0, 1, 1], [0, 0, 1], [0, 0, 0]] => [0, 2, 1];
    // preferences[[0, 1, 1], [0, 0, 0], [0, 1, 0]] => [0, 2, 1];
    // preferences[[0, 2, 2], [0, 0, 0], [0, 2, 0]] => [0, 2, 1];
    // preferences[[1, 2, 2], [1, 0, 0], [0, 0, 0]] => [2, 0, 1];
    // preferences[[0, 0, 0], [0, 0, 0], [0, 0, 0]] => [1, 0, 2];

    int cand_row;
    int candidate;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        cand_row = ranks[i];
        for (int j = i + 1; j < candidate_count; j++)
        {
            candidate = ranks[j];
            preferences[cand_row][candidate] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    /**
     * TODO #3
     * 1 - Add all pairs of candidates where one candidate is preferred to the pairs array.
     *     if a pair of candidates are tied, do not add to the array.
     * 2 - Update the global variable pair_count to be the number of pairs of candidates.
     * (The pairs should thus all be stored between pairs[0] and pairs[pair_count - 1], inclusive).
    */

    int score1, score2;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            score1 = preferences[i][j];
            score2 = preferences[j][i];

            if (score1 != score2)
            {
                pairs[pair_count].winner = score1 > score2 ? i : j;
                pairs[pair_count].loser =  score1 < score2 ? i : j;

                // if (score1 > score2)
                // {
                //     pairs[pair_count].winner = i;
                //     pairs[pair_count].loser = j;
                // }
                // else if (score2 > score1)
                // {
                //     pairs[pair_count].winner = j;
                //     pairs[pair_count].loser = i;
                // }

                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}
