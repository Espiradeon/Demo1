#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            float avg = (float)(r + g + b) / 3;
            int RGBavg = round(avg);
            image[i][j].rgbtRed = RGBavg;
            image[i][j].rgbtGreen = RGBavg;
            image[i][j].rgbtBlue = RGBavg;
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
            float r = round(0.393 * image[i][j].rgbtRed
            + 0.769 * image[i][j].rgbtGreen
            + 0.189 * image[i][j].rgbtBlue);
            float g = round(0.349 * image[i][j].rgbtRed
            + 0.686 * image[i][j].rgbtGreen
            + 0.168 * image[i][j].rgbtBlue);
            float b = round(0.272 * image[i][j].rgbtRed
            + 0.534 * image[i][j].rgbtGreen
            + 0.131 * image[i][j].rgbtBlue);

            int sep_r = r;
            int sep_g = g;
            int sep_b = b;

            // Sepia Red
            if (sep_r > 255)
            {
                sep_r = 255;
            }
            image[i][j].rgbtRed = sep_r;

            // Sepia Green
            if (sep_g > 255)
            {
                sep_g = 255;
            }
            image[i][j].rgbtGreen = sep_g;

            // Sepia Blue
            if (sep_b > 255)
            {
                sep_b = 255;
            }
            image[i][j].rgbtBlue = sep_b;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Temporary storage
            RGBTRIPLE r = image[i][width - (j + 1)];
            RGBTRIPLE l = image[i][j];
            // Output
            image[i][width - (j + 1)] = l;
            image[i][j] = r;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE output[height][width])
{
    RGBTRIPLE image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = output[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float r;
            float g;
            float b;
            // TOP LEFT
            if (i == 0 && j == 0)
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j + 1].rgbtRed
                + image[i + 1][j].rgbtRed
                + image[i + 1][j + 1].rgbtRed) / 4);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j + 1].rgbtGreen
                + image[i + 1][j].rgbtGreen
                + image[i + 1][j + 1].rgbtGreen) / 4);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j + 1].rgbtBlue
                + image[i + 1][j].rgbtBlue
                + image[i + 1][j + 1].rgbtBlue) / 4);
            }
            // TOP RIGHT
            else if (i == 0 && j == width - 1)
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j - 1].rgbtRed
                + image[i + 1][j].rgbtRed
                + image[i + 1][j - 1].rgbtRed) / 4);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j - 1].rgbtGreen
                + image[i + 1][j].rgbtGreen
                + image[i + 1][j - 1].rgbtGreen) / 4);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j - 1].rgbtBlue
                + image[i + 1][j].rgbtBlue
                + image[i + 1][j - 1].rgbtBlue) / 4);
            }
            // BOTTOM LEFT
            else if (i == height - 1 && j == 0)
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j + 1].rgbtRed
                + image[i - 1][j].rgbtRed
                + image[i - 1][j + 1].rgbtRed) / 4);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j + 1].rgbtGreen
                + image[i - 1][j].rgbtGreen
                + image[i - 1][j + 1].rgbtGreen) / 4);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j + 1].rgbtBlue
                + image[i - 1][j].rgbtBlue
                + image[i - 1][j + 1].rgbtBlue) / 4);
            }
            // BOTTOM RIGHT
            else if (i == height - 1 && j == width - 1)
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j - 1].rgbtRed
                + image[i - 1][j].rgbtRed
                + image[i - 1][j - 1].rgbtRed) / 4);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j - 1].rgbtGreen
                + image[i - 1][j].rgbtGreen
                + image[i - 1][j - 1].rgbtGreen) / 4);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j - 1].rgbtBlue
                + image[i - 1][j].rgbtBlue
                + image[i - 1][j - 1].rgbtBlue) / 4);
            }
            // LEFT EDGE
            else if (j == 0 && i != 0 && i != height - 1)
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j + 1].rgbtRed
                + image[i - 1][j].rgbtRed
                + image[i - 1][j + 1].rgbtRed
                + image[i + 1][j].rgbtRed
                + image[i + 1][j + 1].rgbtRed) / 6);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j + 1].rgbtGreen
                + image[i - 1][j].rgbtGreen
                + image[i - 1][j + 1].rgbtGreen
                + image[i + 1][j].rgbtGreen
                + image[i + 1][j + 1].rgbtGreen) / 6);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j + 1].rgbtBlue
                + image[i - 1][j].rgbtBlue
                + image[i - 1][j + 1].rgbtBlue
                + image[i + 1][j].rgbtBlue
                + image[i + 1][j + 1].rgbtBlue) / 6);
            }
            // UPPER EDGE
            else if (i == 0 && j != 0 && j != width - 1)
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j - 1].rgbtRed
                + image[i][j + 1].rgbtRed
                + image[i + 1][j].rgbtRed
                + image[i + 1][j - 1].rgbtRed
                + image[i + 1][j + 1].rgbtRed) / 6);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j - 1].rgbtGreen
                + image[i][j + 1].rgbtGreen
                + image[i + 1][j].rgbtGreen
                + image[i + 1][j - 1].rgbtGreen
                + image[i + 1][j + 1].rgbtGreen) / 6);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j - 1].rgbtBlue
                + image[i][j + 1].rgbtBlue
                + image[i + 1][j].rgbtBlue
                + image[i + 1][j - 1].rgbtBlue
                + image[i + 1][j + 1].rgbtBlue) / 6);
            }
            // RIGHT EDGE
            else if (j == width - 1 && i != 0 && i != height - 1)
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j - 1].rgbtRed
                + image[i - 1][j].rgbtRed
                + image[i - 1][j - 1].rgbtRed
                + image[i + 1][j].rgbtRed
                + image[i + 1][j - 1].rgbtRed) / 6);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j - 1].rgbtGreen
                + image[i - 1][j].rgbtGreen
                + image[i - 1][j - 1].rgbtGreen
                + image[i + 1][j].rgbtGreen
                + image[i + 1][j - 1].rgbtGreen) / 6);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j - 1].rgbtBlue
                + image[i - 1][j].rgbtBlue
                + image[i - 1][j - 1].rgbtBlue
                + image[i + 1][j].rgbtBlue
                + image[i + 1][j - 1].rgbtBlue) / 6);
            }
            // BOTTOM EDGE
            else if (i == height - 1 && j != 0 && j != width - 1)
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j - 1].rgbtRed
                + image[i][j + 1].rgbtRed
                + image[i - 1][j].rgbtRed
                + image[i - 1][j - 1].rgbtRed
                + image[i - 1][j + 1].rgbtRed) / 6);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j - 1].rgbtGreen
                + image[i][j + 1].rgbtGreen
                + image[i - 1][j].rgbtGreen
                + image[i - 1][j - 1].rgbtGreen
                + image[i - 1][j + 1].rgbtGreen) / 6);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j - 1].rgbtBlue
                + image[i][j + 1].rgbtBlue
                + image[i - 1][j].rgbtBlue
                + image[i - 1][j - 1].rgbtBlue
                + image[i - 1][j + 1].rgbtBlue) / 6);
            }
            // THE REST OF THE IMAGE
            else
            {
                r = round((float)(image[i][j].rgbtRed
                + image[i][j - 1].rgbtRed
                + image[i][j + 1].rgbtRed
                + image[i - 1][j].rgbtRed
                + image[i - 1][j - 1].rgbtRed
                + image[i - 1][j + 1].rgbtRed
                + image[i + 1][j].rgbtRed
                + image[i + 1][j - 1].rgbtRed
                + image[i + 1][j + 1].rgbtRed) / 9);

                g = round((float)(image[i][j].rgbtGreen
                + image[i][j - 1].rgbtGreen
                + image[i][j + 1].rgbtGreen
                + image[i - 1][j].rgbtGreen
                + image[i - 1][j - 1].rgbtGreen
                + image[i - 1][j + 1].rgbtGreen
                + image[i + 1][j].rgbtGreen
                + image[i + 1][j - 1].rgbtGreen
                + image[i + 1][j + 1].rgbtGreen) / 9);

                b = round((float)(image[i][j].rgbtBlue
                + image[i][j - 1].rgbtBlue
                + image[i][j + 1].rgbtBlue
                + image[i - 1][j].rgbtBlue
                + image[i - 1][j - 1].rgbtBlue
                + image[i - 1][j + 1].rgbtBlue
                + image[i + 1][j].rgbtBlue
                + image[i + 1][j - 1].rgbtBlue
                + image[i + 1][j + 1].rgbtBlue) / 9);
            }

            int blur_r = r;
            int blur_g = g;
            int blur_b = b;

            output[i][j].rgbtRed = blur_r;
            output[i][j].rgbtGreen = blur_g;
            output[i][j].rgbtBlue = blur_b;
        }
    }
    return;
}
