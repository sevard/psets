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

// Auxilary function prototypes
bool is_cycle(int current_pair);
bool trace_passed(int start, int end);

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
    /** *****************************************************************
     * Update the global preferences[] - add current voter’s preferences
    ** *****************************************************************/

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
    /** ******************************************************************************
     * Add all pairs of candidates where one candidate is preferred to the pairs array.
     *     if a pair of candidates are tied, do not add to the array.
     * Update the global variable 'pair_count' to be the number of pairs of candidates.
     * (The pairs should be stored between pairs[0] and pairs[pair_count - 1], inclusive).
    ** *******************************************************************************/

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
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int votes1, votes2;
        int indx = i;

        // find the pair with the highest score
        for (int j = i + 1; j < pair_count; j++)
        {
            votes1 = preferences[pairs[i].winner][pairs[i].loser];
            votes2 = preferences[pairs[j].winner][pairs[j].loser];

            if (votes2 > votes1)
            {
                indx = j;
            }
        }

        // swap the highest score pair with the pair that is currently compared
        pair higher_votes_pair = pairs[indx];
        pairs[indx] = pairs[i];
        pairs[i] = higher_votes_pair;
    }

    return;
}

// Last visit was on 12/14/2023. Could not solve the function.
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{

    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        if(is_cycle(i))
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int loser = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            loser += locked[i][j];
            if (!loser)
            {
                printf("%s", candidates[pairs[j].winner]);
                return;
            }
        }
    }

    printf("%s\n", candidates[pairs[0].winner]);

    return;
}

bool is_cycle(int pair_num)
{
    // *this function will be called in a loop for each pair* //

    bool check = false;
    for (int i = 0; i < pair_num; i++)
    {
        // for each matching head tail, check trace
        if (pairs[i].winner == pairs[pair_num].loser)
        {
            check = trace_passed(i, pair_num);
        }
    }

    return check;
}

bool trace_passed(int start, int end)
{
    // function will be called only if current pair's loser was seen as a winner //

    for (int i = start; i < end; i++)
    {
        // check if chain is not broken
        if (pairs[i].loser != pairs[i + 1].winner)
        {
            return false;
        }
    }

    for (int i = start; i <= end; i++)
    {
        // check if pair is locked
        if (!locked[pairs[i].winner][pairs[i].loser])
        {
            return false;
        }
    }

    return true;
}
