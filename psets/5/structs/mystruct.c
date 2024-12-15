#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

// typedef struct person
// {
//     int age;
//     char name[20];
// } employee;

int main(void)
{
    // Create variable of type 'employee'
    employee *empl_01 = malloc(sizeof(employee));
    if (empl_01 == NULL)
    {
        return 1;
    }
    empl_01->age = 20;
    strcpy(empl_01->name, "serg");
    printf("Name: %s; Age: %i\n", empl_01->name, empl_01->age);
    free(empl_01);

    // Create variable of type 'skill'
    struct skill *sk01 = malloc(sizeof(struct skill));
    if (sk01 == NULL)
    {
        return 2;
    }
    strcpy((*sk01).name, "programming");
    (*sk01).level = 3;
    printf("Skill: %s; Level:%i\n", sk01->name, sk01->level);
    free(sk01);

    return 0;
}
