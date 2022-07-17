#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            avg = round((blue + green + red) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;


            // rgbtBlue;
            // rgbtGreen;
            // rgbtRed;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0, sepiaGreen = 0, sepiaBlue = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = image[i][j];
        }
    }
    // 0 1 2 3 4 5 6 7 8  8 - 0 = 8
    // 8 7 6 5 4 3 2 1 0  8 - 1 = 7
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = newImage[i][width - j - 1];

        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // image[i-1][j-1]  image[i-1][j]    image[i-1][j+1]
    //
    // image[i][j-1]    image[i][j]      image[i][j+1]

    // image[i+1][j-1]  image[i+1][j]    image[i+1][j+1]

    //
    RGBTRIPLE newImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = image[i][j];
        }
    }

    // for each row
    // for each col
    //     set count to 0
    //     for every neighboring pixel within the radius m in the x direction
    //         for every neighboring pixel within the radius m in the y direction
    //              add the color to the total
    //              count++
    //     final_color = total/count
    //     setpixel(current x, current y, final_color)

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int counter = 0;
            float totalBlue = 0, totalGreen = 0, totalRed = 0;
            int rowCount[] = {row - 1, row, row + 1};
            int colCount[] = {col - 1, col, col + 1};

            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    int curRow = rowCount[r];
                    int curCol = colCount[c];

                    if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                    {
                        totalBlue += newImage[curRow][curCol].rgbtBlue;
                        totalGreen += newImage[curRow][curCol].rgbtGreen;
                        totalRed += newImage[curRow][curCol].rgbtRed;
                        counter++;
                    }
                }
            }


            //avgBlue = round((newImage[i-1][j-1].rgbtBlue + newImage[i-1][j].rgbtBlue + newImage[i-1][j+1].rgbtBlue + newImage[i][j-1].rgbtBlue + newImage[i][j].rgbtBlue + newImage[i][j+1].rgbtBlue + newImage[i+1][j-1].rgbtBlue + newImage[i+1][j].rgbtBlue + newImage[i+1][j+1].rgbtBlue) / 9);
            //avgGreen = round((newImage[i-1][j-1].rgbtGreen + newImage[i-1][j].rgbtGreen + newImage[i-1][j+1].rgbtGreen + newImage[i][j-1].rgbtGreen + newImage[i][j].rgbtGreen + newImage[i][j+1].rgbtGreen + newImage[i+1][j-1].rgbtGreen + newImage[i+1][j].rgbtGreen + newImage[i+1][j+1].rgbtGreen) / 9);
            //avgRed = round((newImage[i-1][j-1].rgbtRed + newImage[i-1][j].rgbtRed + newImage[i-1][j+1].rgbtRed + newImage[i][j-1].rgbtRed + newImage[i][j].rgbtRed + newImage[i][j+1].rgbtRed + newImage[i+1][j-1].rgbtRed + newImage[i+1][j].rgbtRed + newImage[i+1][j+1].rgbtRed) / 9);
            image[row][col].rgbtBlue = round(totalBlue / counter);
            image[row][col].rgbtGreen = round(totalGreen / counter);
            image[row][col].rgbtRed = round(totalRed / counter);

        }
    }



    return;
}
