#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        printf("ERROR: Memory allocation failure!");
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }

    // ...

    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        printf("ERROR: Memory allocation failure!\n");
        free(list);
        return 2;
    }

    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    free(list);
    list = tmp;
    list[3] = 4;

    for (int i =0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
}






