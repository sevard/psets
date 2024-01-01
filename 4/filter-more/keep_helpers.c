#include "helpers.h"

// Prototypes
void update_axis_values(int position, int axis_len, int arr[]);
RGBTRIPLE calculate_sobel(int y_axis[], int x_axis[], int height, int width, RGBTRIPLE image[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Make two copies of the image array
    RGBTRIPLE gx_image[height][width];
    RGBTRIPLE gy_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gx_image[height][width] = image[i][j];
            gy_image[height][width] = image[i][j];
        }
    }

    int x_axis[3];
    int y_axis[3];

    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE triple;
        update_axis_values(i, height, y_axis);

        for (int j = 0; j < width; j++)
        {
            update_axis_values(j, width, x_axis);
            triple = calculate_sobel(y_axis, x_axis, height, width, image);

            // Set colors of the current pixel
            gx_image[i][j].rgbtBlue = triple.rgbtBlue;
            gx_image[i][j].rgbtGreen = triple.rgbtGreen;
            gx_image[i][j].rgbtRed = triple.rgbtRed;
        }
    }

    return;
}

void update_axis_values(int position, int axis_len, int arr[])
{
    // Updates array with pixel location on 3x3 matrix
    int matrix_len = 3;
    position--;
    for (int i = 0; i < matrix_len; i++)
    {
        if (position <= axis_len)
        {
            arr[i] = -1;
        }
        arr[i] = position;
        position++;
    }
}

RGBTRIPLE calculate_sobel(int y_axis[], int x_axis[], int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE triple;
    int blue = 0;
    int green = 0;
    int red = 0;

    // Create gx_kernel
    // int gy_kernel = [ [ -1, 0, 1 ], [ -2, 0, 2 ], [ -1, 0, 1 ] ];
    int indx = 0;
    int gx_kernel[3][3];
    int gx_kernel_values[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gx_kernel[i][j] = gx_kernel_values[indx];
            indx++;
        }
    }

    // Iterate over x axis
    for (int i = 0; i < 3; i++)
    {
        int y = y_axis[i]; // EX: y_axis[-1, 0, 1]

        // Iterate over y axis
        for (int j = 0; j < 3; j++)
        {
            int x = x_axis[j]; // EX: x_axis[-1, 0, 1]

            // Set color black if pixel is behind the edge of image
            if (y < 0 || x < 0)
            {
                blue += gx_kernel[i][j] * 0x00;
                green += gx_kernel[i][j] * 0x00;
                red += gx_kernel[i][j] * 0x00;
                continue;
            }

            blue += image[y][x].rgbtBlue * gx_kernel[i][j];
            green += image[y][x].rgbtGreen * gx_kernel[i][j];
            red += image[y][x].rgbtRed * gx_kernel[i][j];
        }
    }

    triple.rgbtBlue = blue < 255 ? blue : 255;
    triple.rgbtGreen = green < 255 ? green : 255;
    triple.rgbtRed = red < 255 ? red : 255;

    return triple;
}
