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
int get_winner(int current_pair_pos);
bool trace_chain(int win_pair_indx, int cur_pair_indx);
bool not_cycle(int start, int end);

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
        locked[pairs[i].winner][pairs[i].loser] = true;
        for (int j = 0; j <= i; j++)
        {

            if (not_cycle(j, i))
            {
                continue;
            }
            locked[pairs[i].winner][pairs[i].loser] = false;
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

bool not_cycle(int start, int end)
{
    // *this function will be called in a loop for each pair* //
    // starting from pair 0(j) up to pair 'i' ( 'i' not included )
    // check if pair[j].winner == pair[i].loser
    // if it is -> check if it is locked
    //             -> if locked
    //                -> check if creates a cycle
    //             -> if not locked
    //                -> check next pair
    if (pairs[start].winner == pairs[end].loser)
    {
        // if locked -> check if it creates a cycle
        if (locked[pairs[start].winner][pairs[start].loser])
        {
            // starting from the pair where match was found, up to end pair check
            for (int i = start; i < end; i++)
            {
                if (!locked[pairs[i].winner][pairs[i].loser])
                {
                    return true; // no cycle, terminate early
                }
            }
            return false; // cycle is potential at this point;
        }
        return true; // not cycle, there is no matching winner with current loser
    }
    return true; // not cycle
}

// printf("=============================================\n");
// printf("Checking pairs[%i] = (%i,%i)\n", i, pairs[i].winner, pairs[i].loser);
// bool trace_chain(int win_indx, int cur_pair_indx)
// {
//     // Trace each chain to determine if creates a cycle
//     if (!locked[pairs[win_indx].winner][pairs[win_indx].loser])
//     {
//         return false;
//     }

//     for (int i = win_indx; i < cur_pair_indx; i++)
//     {
//         if (!locked[i][pairs[i].loser])
//         {
//             return false;
//         }
//         if (pairs[win_indx].winner == pairs[i].loser)
//         {
//             return true;
//         }
//     }
//     return false;
// }



// int get_winner(int current_pair_pos)
// {
//     // check if current loser was a winner in any pair
//     for (int check_pair_indx = current_pair_pos - 1; check_pair_indx > 0; check_pair_indx--)
//     {
//         if (pairs[current_pair_pos].loser == pairs[check_pair_indx].winner)
//         {
//             int cur_pair_win = pairs[current_pair_pos].winner;
//             int cur_pair_los = pairs[current_pair_pos].loser;
//             int check_pair_win = pairs[check_pair_indx].winner;
//             int check_pair_los = pairs[check_pair_indx].loser;
//             printf("pairs[%i] = (%i,%i)\n", check_pair_indx, check_pair_win, check_pair_los);
//             printf("pairs[%i] = (%i,%i)\n", current_pair_pos, cur_pair_win, cur_pair_los);

//             return check_pair_indx;
//         }
//     }

//     return current_pair_pos;
// }


// KEEP for now!!!

// bool trace_chain(int win_pair_indx, int cur_pair_indx)
// {
//     // Trace each chain to determine if creates a cycle
//     for (int i = win_pair_indx; i < cur_pair_indx; i++)
//     {
//         int w = pairs[i].winner;
//         int l = pairs[i].loser;

//         if (!locked[w][l])
//         {
//             return false;
//         }

//         // if last check and did not break with false, then true
//         if (i == cur_pair_indx - 1)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// bool trace_chain(int win_pair_indx, int cur_pair_indx)
// {
//     // Trace each chain to determine if creates a cycle
//     int len = win_pair_indx + cur_pair_indx;
//     bool arr[len];

//     for (int i = 0; i < len; i++)
//     {
//         arr[i] = 0;
//     }

//     int indx = 0;
//     for (int i = win_pair_indx; i < cur_pair_indx; i++)
//     {
//         arr[indx] = locked[i][pairs[i].loser];
//         indx++;
//     }

//     int total = 0;
//     arr[cur_pair_indx] = true;
//     for (int i = 0; i < len; i++)
//     {
//         total += arr[i];
//     }

//     if (total == len)
//     {
//         return true;
//     }
//     return false;
// }
