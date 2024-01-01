#include <stdio.h>

int main(void)
{
    int height = 4;
    int width = 7;
    int two_d_arr[height][width];

    int x = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            two_d_arr[i][j] = x;
            x++;
        }
    }

    for (int w = 0; w < width; w++)
    {
        for (int h = 0; h < height; h++)
        {
            printf("%i ", two_d_arr[h][w]);
        }
        printf("\n");
    }

}
