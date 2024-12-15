#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

sllnode* create(int value);
sllnode* insert(sllnode *head, int value);
void print_list(sllnode* head);
void destroy(sllnode *head);

int main(int argc, char *argv[])
{
    if  (argc < 2)
    {
        printf("USAGE: ./ll_v2 <num1> [num2 num3 ...]\n");
        printf("num1: is positive integer\n");
        return 1;
    }

    int arr_len = argc - 1;
    int arr[arr_len];
    for (int i = 0; i < arr_len; i++)
    {
        int n = atoi(argv[i+1]);
        arr[i] = n;
    }

    sllnode *head = create(arr[0]);
    if (head == NULL)
    {
        // First node, nothing to free;
        printf("ERROR: Memory allocation falure!\n");
        return 1;
    }

    for (int i = 1; i < arr_len; i++)
    {
        sllnode *tmp_head = insert(head, arr[i]);
        if (tmp_head == NULL)
        {
            printf("ERROR: Memory allocation falure!\n");
            printf("FYI  : Destroying existing linked list..\n");
            // if tmp_head is NULL head is still unchanged;
            destroy(head);
            return 2;
        }
        head = tmp_head;
    }

    print_list(head);

    destroy(head);
    return 0;
}

// Create a completely new node
sllnode* create(int value)
{
    /** ************************************************
     * Steps involved:
     * a. Dynamically allocate space for a new sllnode.
     * b. Check to make sure we didn’t run out of memory.
     * c. Initialize the node’s val field.
     * d. Initialize the node’s next field.
     * e. Return a pointer to the newly created sllnode.
     * ********************************************** **/
    sllnode *node = malloc(sizeof(sllnode));
    if (node == NULL)
    {
        return NULL;
    }

    node->number = value;
    node->next = NULL;

    return node;
}

sllnode* insert(sllnode *head, int value)
{
    sllnode *new_node = malloc(sizeof(sllnode));
    if (new_node == NULL)
    {
        return NULL;
    }

    new_node->number = value;
    new_node->next = head;
    head = new_node;

    return head;
}

void destroy(sllnode *head)
{
    sllnode *tmp = NULL;
    while (head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

void print_list(sllnode* head)
{
    for (sllnode *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("num: %*i; next: %p\n", 2,tmp->number, tmp->next);
    }
}

/**
 * STACK
 * destroy(head->next) <= this wll return thes same 'node' was passed to it
 * destroy(head) <= to this, and this destroy will destroy it
 *
 * for recursive version with double linked list
 *    if (head == NULL)
 *    {
 *      return head;
 *    }
 *    sllnode *tmp = head;
 *    free(head);
 *    destroy(tmp->prev);
*/
