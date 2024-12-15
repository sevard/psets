#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

sllnode* create(int value);

int main(void)
{
    int arr[] = {1, 2, 3}; // , 4, 5};

    sllnode *list = create(6);
    sllnode *new = create(12);

    // DO NOT DO IT !!! Will orfane the rest of the list
    // list->next = new;

    new->next = list;
    list = new;

    printf("\n");
    printf("list self addr: %p\n", list); // 0x55e14d3572a0
    printf("list->number: %i ; list->next: %p\n", list->number, list->next);
    printf("---\n");
    printf("new self addr : %p\n", new);  // 0x55e14d3572c0
    printf("new->number : %i ; new->next : %p\n", new->number, new->next);

    free(new);
    free(list);
}

// Create a completely new node
sllnode* create(int value)
{
    sllnode *node = malloc(sizeof(sllnode));
    if (node == NULL)
    {
        printf("ERROR: Memory allocation falure!\n");
        return NULL;
    }

    node->number = value;
    node->next = NULL;

    return node;
}
