#include <stdio.h>

int main(void)
{
    char *name = "Sergey";

    printf("There is %s at %p\n", name, name);
    printf("--\n");
    printf("%c-%c-%c-%c-%c-%c\n", *name, *(name+1), *(name+2), *(name+3), *(name+4), *(name+5));
    printf("--\n");

    printf("%c at %p\n", name[0], &name[0]);
    printf("%c at %p\n", name[1], &name[1]);
    printf("%c at %p\n", name[2], &name[2]);
    printf("%c at %p\n", name[3], &name[3]);
    printf("%c at %p\n", name[4], &name[4]);
    printf("%c at %p\n", name[5], &name[5]);
    printf("\\0 at %p\n", &name[6]); // \0
}
