#include <stdio.h>
#include <cs50.h>

#define MAX 6

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

pair pairs[MAX * (MAX - 1) / 2];
int pair_count = 6;
int candidate_count = 4;

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

void print_result(void);

int main(void)
{
    pairs[0].winner = 3;
    pairs[0].loser = 0;

    pairs[1].winner = 0;
    pairs[1].loser = 1;

    pairs[2].winner = 1;
    pairs[2].loser = 2;

    pairs[3].winner = 2;
    pairs[3].loser = 0;

    pairs[4].winner = 3;
    pairs[4].loser = 1;

    pairs[5].winner = 3;
    pairs[5].loser = 2;

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    // 0[ 3,0 ]
    // 1[ 0,1 ]
    // 2[ 1,2 ]
    // 3[ 2,0 ]
    // 4[ 3,1 ]
    // 5[ 3,2 ]
    for (int i = 0; i < pair_count; i++)
    {
        // printf("=============================================\n");
        // printf("Checking pairs[%i] = (%i,%i)\n", i, pairs[i].winner, pairs[i].loser);


        // check if current loser was a winner in any pair
        int pair_num = 0;
        for (int j = 0; j < i; j++)
        {
            if (pairs[i].loser == pairs[j].winner)
            {
                printf("pairs[%i] = (%i,%i)\n", j, pairs[j].winner, pairs[j].loser);
                printf("pairs[%i] = (%i,%i)\n", i, pairs[i].winner, pairs[i].loser);
                pair_num = j;
                break;
            }
        }

        int row = pairs[i].winner;
        int pos = pairs[i].loser;
        locked[row][pos] = true;

        // Trace each chain to determine if creates a cycle
        for (int pn = pair_num; pn <= i; pn++)
        {
            int w = pairs[pn].winner;
            int l = pairs[pn].loser;
            if (!locked[w][l])
            {
                break;
            }
            else if (locked[w][l] && pn == i)
            {
                locked[row][pos] = false; // there is a cycle;
            }
            // locked[row][pos] = true; // there is no cycle;
        }

    }

    print_result();
    return 0;
}

void print_result(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%i |", i);
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i: %s", j, locked[i][j] ? "true  |" : "false |");
        }
        printf("\n");
    }
}
