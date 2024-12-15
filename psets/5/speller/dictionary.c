// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table: Done. Changed from 26 to 100
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO: Don
    int index = hash(word);
    node *check_node = table[index];
    node *ptr;

    // node is not NULL
    while (check_node)
    {
        if (strcasecmp(check_node->word, word) == 0)
        {
            return true;
        }
        ptr = check_node->next;
        check_node = ptr;
    }

    // node at table[index] was NULL, no such word in the table
    return false;
}

// Hashes word to a number
// djb2 hash algorithm created by Den Berstain
// (k=33) was first reported many years ago in comp.lang.c
// http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';
    unsigned long long hash = 5381;

    int c;
    while ((c = *word++))
    {
        c = toupper(c);
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    int number = hash % N;
    return number;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO: Done

    // pre-set table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // 1 - open the dictionary
    FILE *inpfile = fopen(dictionary, "r");
    if (!inpfile)
    {
        printf("ERROR: Cannot open file!\n");
        return 1;
    }

    // 2 - read words from dictionary
    char word_buffer[LENGTH + 1];
    while (fscanf(inpfile, "%s", word_buffer) == 1)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("ERROR: Memory allocation failed!\n");
            printf("\tClosing file (dictionary): %s \n", dictionary);
            fclose(inpfile);

            // free all previously allocated memory
            unload();
            printf("Exit 'load' function...\n");
            return false;
        }

        // 3 - Load the word to the new node
        strcpy(new_node->word, word_buffer);
        new_node->next = NULL;

        // 4 - is there an existing node at table[index] ?
        int index = hash(new_node->word);
        node *existing_node = table[index];
        if (existing_node)
        {
            // 4.1 - there is an existing node at table[index]
            //         prepend the new node before existing
            new_node->next = existing_node;
            table[index] = new_node;
        }
        else // 4.2 - table[index] is empty - add the new node table[index]
        {
            table[index] = new_node;
        }
    }

    fclose(inpfile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO: Done;
    int counter = 0;
    node *current_node, *ptr;
    for (int i = 0; i < N; i++)
    {
        current_node = table[i];
        while (current_node)
        {
            counter++;
            ptr = current_node->next;
            current_node = ptr;
        }
    }

    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO: Done
    for (int indx = 0; indx < N; indx++)
    {
        // Check if there is an existing node
        node *current_node = table[indx];
        if (current_node)
        {
            while(current_node)
            {
                node *ptr = current_node->next;
                free(current_node);
                current_node = ptr;
            }
            table[indx] = NULL;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            return false;
        }
    }
    return true;
}
