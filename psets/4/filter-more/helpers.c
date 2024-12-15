#include "helpers.h"
#include <math.h>

// Prototypes
void update_axis_values(int position, int axis_len, int arr[]);
void copy_array(int height, int width, RGBTRIPLE orig[height][width], RGBTRIPLE copy[height][width]);
RGBTRIPLE get_pixel_val(char direction, int y_axis[], int x_axis[], int height, int width, RGBTRIPLE image[height][width]);

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
    copy_array(height, width, image, gx_image);
    copy_array(height, width, image, gy_image);

    // Iterate over image left to right (x axis)
    // Calculate each pixel's color value
    // and update pixels's color value in the gx_image
    int x_axis[3];
    int y_axis[3];
    RGBTRIPLE gx_triple;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            update_axis_values(i, height, y_axis);
            update_axis_values(j, width, x_axis);
            gx_triple = get_pixel_val('x', y_axis, x_axis, height, width, image);

            // Set colors of the current pixel
            gx_image[i][j].rgbtBlue = gx_triple.rgbtBlue;
            gx_image[i][j].rgbtGreen = gx_triple.rgbtGreen;
            gx_image[i][j].rgbtRed = gx_triple.rgbtRed;
        }
    }

    // Iterate over image top to bottom (y axis)
    // Calculate each pixel's color value
    // and update pixels's color value in the gy_image
    RGBTRIPLE gy_triple;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            update_axis_values(i, width, y_axis);
            update_axis_values(j, height, x_axis);
            gy_triple = get_pixel_val('y', y_axis, x_axis, height, width, image);
            // Set colors of the current pixel
            gy_image[i][j].rgbtBlue = gy_triple.rgbtBlue;
            gy_image[i][j].rgbtGreen = gy_triple.rgbtGreen;
            gy_image[i][j].rgbtRed = gy_triple.rgbtRed;
        }
    }

    // Assign calculated value to image
    int blue, green, red, sqrt_gx, sqrt_gy, sqrt_gxgy;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blue = green = red = sqrt_gx = sqrt_gy = sqrt_gxgy = 0;

            sqrt_gx = sqrt(gx_image[i][j].rgbtRed);
            sqrt_gy = sqrt(gy_image[i][j].rgbtRed);
            sqrt_gxgy = sqrt_gx + sqrt_gy;
            blue = (sqrt_gxgy) <= 255 ? (sqrt_gx + sqrt_gy) : 255;

            sqrt_gx = sqrt(gx_image[i][j].rgbtGreen);
            sqrt_gy = sqrt(gy_image[i][j].rgbtGreen);
            sqrt_gxgy = sqrt_gx + sqrt_gy;
            green = (sqrt_gxgy) <= 255 ? (sqrt_gx + sqrt_gy) : 255;

            sqrt_gx = sqrt(gx_image[i][j].rgbtRed);
            sqrt_gy = sqrt(gy_image[i][j].rgbtRed);
            sqrt_gxgy = sqrt_gx + sqrt_gy;
            red = (sqrt_gxgy) <= 255 ? (sqrt_gx + sqrt_gy) : 255;

            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;
        }
    }

    return;
}

void update_axis_values(int position, int axis_len, int arr[])
{
    // Get pixel location on a 'x' or 'y' coordinate of 3x3 matrix
    // Ex: if position is 7, 'x' coordinate pixel location is 6, 7, 8
    // Ex: if position is 2, 'y' coordinate pixel location is 1, 2, 3

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

RGBTRIPLE get_pixel_val(char direction, int y_axis[], int x_axis[], int height, int width, RGBTRIPLE image[height][width])
{
    int gx_kernel[3][3];
    int gy_kernel[3][3];
    int x_values[] = {-1,-0, 1,-2, 0, 2,-1, 0, 1};
    int y_values[] = {-1,-2,-1, 0, 0, 0, 1, 2, 1};
    int indx = 0;
    for (int i = 0; i < 3; i++)
    {
        // gx_kernel [[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]];
        // gy_kernel [[-1,-2,-1], [ 0, 0, 0], [ 1, 2, 1]];
        for (int j = 0; j < 3; j++)
        {
            gx_kernel[i][j] = x_values[indx];
            gy_kernel[i][j] = y_values[indx];
            indx++;
        }
    }


    // Calculate color values of the surrounding current pixel
    int blue, green, red, x_axis_len, y_axis_len, x, y;
    blue = green = red = 0;
    x_axis_len = y_axis_len = 3;
    for (int i = 0; i < x_axis_len; i++)
    {
        for (int j = 0; j < y_axis_len; j++)
        {
            x = x_axis[j]; // EX: x_axis[-1, 0, 1]
            y = y_axis[i]; // EX: y_axis[-1, 0, 1]

            // Set color black if pixel is behind the edge of image
            if (y < 0 || x < 0)
            {
                blue +=  0;
                green += 0;
                red += 0;
                continue;
            }

            if (direction == 'x')
            {
                blue += image[y][x].rgbtBlue * gx_kernel[i][j];
                green += image[y][x].rgbtGreen * gx_kernel[i][j];
                red += image[y][x].rgbtRed * gx_kernel[i][j];
            }
            else if (direction == 'y')
            {
                blue += image[y][x].rgbtBlue * gy_kernel[i][j];
                green += image[y][x].rgbtGreen * gy_kernel[i][j];
                red += image[y][x].rgbtRed * gy_kernel[i][j];
            }
        }
    }

    RGBTRIPLE triple;
    triple.rgbtBlue = blue < 255 ? blue : 255;
    triple.rgbtGreen = green < 255 ? green : 255;
    triple.rgbtRed = red < 255 ? red : 255;

    return triple;
}

void copy_array(int height, int width, RGBTRIPLE orig[height][width], RGBTRIPLE copy[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[height][width] = orig[i][j];
        }
    }
}
