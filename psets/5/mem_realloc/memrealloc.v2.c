#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(3));
    if (list == NULL)
    {
        printf("ERROR: Memory allocation failure!\n");
        return 1;
    }

    for(int i = 0; i < 3; i++)
    {
        list[i] = i+1;
        printf("%i\n", list[i]);
    }

    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        printf("ERROR: Memory reallocation failure!\n ");
        free(list);
        return 2;
    }
    // just checking if the memory address of realloc return value is
    // the same as its first argument, the pointer
    printf("tmp  : %p\n", tmp);
    printf("list : %p\n", tmp);

    list = tmp;
    list[3] = 4;

    for (int i =0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);

    return 0;
}
