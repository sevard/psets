#include "helpers.h"
#include <math.h>

// Prototypes
void get_coordinates(int pos, int axis, int arr[]);
RGBTRIPLE calculate_avg(int x[], int y[], int height, int width, RGBTRIPLE image[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average and assign new value
            int sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int avg = round((float) sum / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int origBlue = image[i][j].rgbtBlue;
            int origGreen = image[i][j].rgbtGreen;
            int origRed = image[i][j].rgbtRed;

            int sepiaBlue = round((.272 * origRed) + (.534 * origGreen) + (.131 * origBlue));
            int sepiaGreen = round((.349 * origRed) + (.686 * origGreen) + (.168 * origBlue));
            int sepiaRed = round((.393 * origRed) + (.769 * origGreen) + (.189 * origBlue));

            image[i][j].rgbtBlue = sepiaBlue <= 255 ? sepiaBlue : 255;
            image[i][j].rgbtGreen = sepiaGreen <= 255 ? sepiaGreen : 255;
            image[i][j].rgbtRed = sepiaRed <= 255 ? sepiaRed : 255;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int indx;
    RGBTRIPLE row[width];

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            row[j] = image[i][j];
            indx = j;
        }

        for (int k = 0; k < width; k++)
        {
            image[i][k] = row[indx];
            indx--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE avg_triple;
    RGBTRIPLE image_copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    int x_axis[3];
    int y_axis[3];
    for (int i = 0; i < height; i++)
    {
        get_coordinates(i, height, x_axis);

        for (int j = 0; j < width; j++)
        {
            get_coordinates(j, width, y_axis);
            avg_triple = calculate_avg(x_axis, y_axis, height, width, image_copy);
            image[i][j].rgbtBlue = avg_triple.rgbtBlue;
            image[i][j].rgbtGreen =avg_triple.rgbtGreen;
            image[i][j].rgbtRed = avg_triple.rgbtRed;
        }
    }

    return;
}

void get_coordinates(int pos, int axis, int arr[])
{
    pos--;
    for (int i = 0; i < 3; i++)
    {
        if (pos >= axis)
        {
            pos = -1;
        }

        arr[i] = pos;
        pos++;
    }
}

RGBTRIPLE calculate_avg(int x[], int y[], int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE triple;
    int count = 0;
    int blue = 0;
    int green = 0;
    int red = 0;

    for (int i = 0; i < 3; i++)
    {
        if (x[i] >= 0)
        {
            for (int j = 0; j < 3; j++)
            {
                if (y[j] >= 0)
                {
                    int x_axis = x[i];
                    int y_axis = y[j];

                    blue += image[x_axis][y_axis].rgbtBlue;
                    green += image[x_axis][y_axis].rgbtGreen;
                    red += image[x_axis][y_axis].rgbtRed;
                    count++;
                }
            }
        }
    }

    triple.rgbtBlue = round((float) blue / count);
    triple.rgbtGreen = round((float) green / count);
    triple.rgbtRed = round((float) red / count);
    return triple;
}
