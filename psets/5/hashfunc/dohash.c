#include <stdio.h>
#include <string.h>
#include <ctype.h>

const unsigned int N = 100;

unsigned long long hash_v2(const char *word);
unsigned int hash_v3(const char *word);

int main(void)
{
    // File with words
    // FILE *infile = fopen("../speller/dictionaries/words1000", "r");
    FILE *infile = fopen("../speller/dictionaries/large", "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Just making sure the last pos reamins unused
    int frequence[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        frequence[i] = 0;
    }

    char input_word[45];
    while (fscanf(infile, "%s", input_word) == 1)
    {
        int h = hash_v2(input_word);
        int index = h % N;
        // printf("ind: %*i, ", 2, index);
        frequence[index]++;
    }

    int total_words = 0;
    for (int i = 0; i < N + 1; i++)
    {
        total_words += frequence[i];
        printf("%*i: %*i \n", 3, i, 2, frequence[i]);
    }
    printf("Total words: %i\n", total_words);
    fclose(infile);
}

// djb2 hash algorithm created by Den Berstain
// (k=33) was first reported many years ago in comp.lang.c
// http://www.cse.yorku.ca/~oz/hash.html
unsigned long long hash_v2(const char *word)
{
    unsigned long hash = 0x1505; // 5381;

    int c;
    while ((c = *word++))
    {
        c = toupper(c);
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    // int number = hash % N;
    return hash;
}

// another version of this algorithm (now favored by bernstein)
unsigned int hash_v3(const char *word)
{
    unsigned long long hash = 5381;

    int c, n;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        c = toupper(word[i]);
        n = (i - 1);
        hash = ( n * ( (hash << 5) + hash ) ) ^ c;
    }
    int number = hash % N;
    return number;
}
