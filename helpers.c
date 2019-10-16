#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int c = 0; c < height; c++)
    {
        for(int r = 0; r < width; r++)
        {
            int avg = round((image[c][r].rgbtRed+image[c][r].rgbtBlue+image[c][r].rgbtGreen)/3.0);
            image[c][r].rgbtGreen=avg;
            image[c][r].rgbtBlue=avg;
            image[c][r].rgbtRed=avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int c = 0; c < height; c++)
    {
        for(int r = 0; r < width/2; r++)
        {

            RGBTRIPLE temp = image[c][r];
            image[c][r] = image[c][width - 1 - r];
            image[c][width - 1 - r] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
        // RGBTRIPLE imageCopy[height][width];
    RGBTRIPLE imageCopy[height][width];
    for(int c = 0; c < height; c++)
    {
        for(int r = 0; r < width; r++)
        {
               if(c==0 && r==0){
                int avgRed =round((image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed)/4.0) ;
                imageCopy[c][r].rgbtRed=avgRed;
                int avgGreen =round((image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen)/4.0) ;
                imageCopy[c][r].rgbtGreen=avgGreen;
                int avgBlue =round((image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue)/4.0) ;
                imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(c==0 && r==width-1)
            {
               int avgRed =round((image[c+1][r].rgbtRed+image[c][r].rgbtRed+image[c][r-1].rgbtRed+image[c+1][r-1].rgbtRed)/4.0);
               imageCopy[c][r].rgbtRed=avgRed;
               int avgGreen =round((image[c+1][r].rgbtGreen+image[c][r].rgbtGreen+image[c][r-1].rgbtGreen+image[c+1][r-1].rgbtGreen)/4.0);
               imageCopy[c][r].rgbtGreen=avgGreen;
               int avgBlue =round((image[c+1][r].rgbtBlue+image[c][r].rgbtBlue+image[c][r-1].rgbtBlue+image[c+1][r-1].rgbtBlue)/4.0);
               imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(c==height-1 && r==width-1)
            {
                int avgRed =round((image[c-1][r].rgbtRed+image[c][r].rgbtRed+image[c][r-1].rgbtRed+image[c-1][r-1].rgbtRed)/4.0);
                imageCopy[c][r].rgbtRed=avgRed;
                 int avgBlue =round((image[c-1][r].rgbtBlue+image[c][r].rgbtBlue+image[c][r-1].rgbtBlue+image[c-1][r-1].rgbtBlue)/4.0);
                imageCopy[c][r].rgbtBlue=avgBlue;
                 int avgGreen =round((image[c-1][r].rgbtGreen+image[c][r].rgbtGreen+image[c][r-1].rgbtGreen+image[c-1][r-1].rgbtGreen)/4.0);
                imageCopy[c][r].rgbtGreen=avgGreen;
            }
            else if(c==height-1 && r==0)
            {
                int avgRed =round((image[c-1][r].rgbtRed+image[c][r].rgbtRed+image[c][r+1].rgbtRed+image[c-1][r+1].rgbtRed)/4.0);
                imageCopy[c][r].rgbtRed=avgRed;
                int avgGreen =round((image[c-1][r].rgbtGreen+image[c][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c-1][r+1].rgbtGreen)/4.0);
                imageCopy[c][r].rgbtGreen=avgGreen;
                int avgBlue =round((image[c-1][r].rgbtBlue+image[c][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c-1][r+1].rgbtBlue)/4.0);
                imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(r==0)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed+image[c-1][r].rgbtRed+image[c-1][r+1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgBlue =round((image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue+image[c-1][r].rgbtBlue+image[c-1][r+1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            int avgGreen =round((image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen+image[c-1][r].rgbtGreen+image[c-1][r+1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            }
            else if(r==width-1)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c-1][r].rgbtRed+image[c+1][r].rgbtRed+image[c+1][r-1].rgbtRed+image[c][r-1].rgbtRed+image[c-1][r-1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgGreen =round((image[c][r].rgbtGreen+image[c-1][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c+1][r-1].rgbtGreen+image[c][r-1].rgbtGreen+image[c-1][r-1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            int avgBlue =round((image[c][r].rgbtBlue+image[c-1][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c+1][r-1].rgbtBlue+image[c][r-1].rgbtBlue+image[c-1][r-1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(c==0)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c+1][r-1].rgbtRed+image[c][r-1].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgBlue =round((image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c+1][r-1].rgbtBlue+image[c][r-1].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            int avgGreen =round((image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c+1][r-1].rgbtGreen+image[c][r-1].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            }
            else if(c==height-1)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c-1][r].rgbtRed+image[c][r+1].rgbtRed+image[c-1][r-1].rgbtRed+image[c-1][r+1].rgbtRed+image[c][r-1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgGreen =round((image[c][r].rgbtGreen+image[c-1][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c-1][r-1].rgbtGreen+image[c-1][r+1].rgbtGreen+image[c][r-1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            int avgBlue =round((image[c][r].rgbtBlue+image[c-1][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c-1][r-1].rgbtBlue+image[c-1][r+1].rgbtBlue+image[c][r-1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else
            {
              int avgRed =round((image[c-1][r].rgbtRed+image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c-1][r+1].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed+image[c-1][r-1].rgbtRed+image[c][r-1].rgbtRed+image[c+1][r-1].rgbtRed)/9.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgBlue =round((image[c-1][r].rgbtBlue+image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c-1][r+1].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue+image[c-1][r-1].rgbtBlue+image[c][r-1].rgbtBlue+image[c+1][r-1].rgbtBlue)/9.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            int avgGreen =round((image[c-1][r].rgbtGreen+image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c-1][r+1].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen+image[c-1][r-1].rgbtGreen+image[c][r-1].rgbtGreen+image[c+1][r-1].rgbtGreen)/9.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            }
        }

    }
     for(int c = 0; c < height; c++)
    {
        for(int r = 0; r < width; r++)
        {
            image[c][r]=imageCopy[c][r];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
       RGBTRIPLE imageCopy[height][width];
    for(int c = 0; c < height; c++)
    {
        for(int r = 0; r < width; r++)
        {
               if(c==0 && r==0){
                int gXRed = image[c][r].rgbtRed*0+image[c+1][r].rgbtRed*0+image[c+1][r+1].rgbtRed*1+image[c][r+1].rgbtRed*2;
                int gXGreen = image[c][r].rgbtGreen*0+image[c+1][r].rgbtGreen*0+image[c+1][r+1].rgbtGreen*1+image[c][r+1].rgbtGreen*2;
                int gXBlue = image[c][r].rgbtBlue*0+image[c+1][r].rgbtBlue*0+image[c+1][r+1].rgbtBlue*1+image[c][r+1].rgbtBlue*2;

                int gYRed = image[c][r].rgbtRed*0+image[c][r+1].rgbtRed*0+image[c+1][r].rgbtRed*2+image[c+1][r+1].rgbtRed*1;
                int gYGreen = image[c][r].rgbtGreen*0+image[c][r+1].rgbtGreen*0+image[c+1][r].rgbtGreen*2+image[c+1][r+1].rgbtGreen*1;
                int gYBlue = image[c][r].rgbtBlue*0+image[c][r+1].rgbtBlue*0+image[c+1][r].rgbtBlue*2+image[c+1][r+1].rgbtBlue*1;

                int red = round(sqrt(pow(gXRed,2.0)+pow(gYRed,2.0)));
                int green = round(sqrt(pow(gXGreen,2.0)+pow(gYGreen,2.0)));
                int blue =  round(sqrt(pow(gXBlue,2.0)+pow(gYBlue,2.0)));
                if(red>=255){
                    red = 255;
                }
                if(green >= 255){
                    green=255;
                }
                if(blue >=255){
                    blue = 255;
                }
                imageCopy[c][r].rgbtRed=red ;
                imageCopy[c][r].rgbtGreen= green;
                imageCopy[c][r].rgbtBlue= blue;
            }
            else if(c==0 && r==width-1)
            {
               int gXRed = image[c][r].rgbtRed*0+image[c+1][r].rgbtRed*0+image[c+1][r-1].rgbtRed*(-1)+image[c][r-1].rgbtRed*(-2);
                int gXGreen = image[c][r].rgbtGreen*0+image[c+1][r].rgbtGreen*0+image[c+1][r-1].rgbtGreen*(-1)+image[c][r-1].rgbtGreen*(-2);
                int gXBlue = image[c][r].rgbtBlue*0+image[c+1][r].rgbtBlue*0+image[c+1][r-1].rgbtBlue*(-1)+image[c][r-1].rgbtBlue*(-2);

                int gYRed = image[c][r].rgbtRed*0+image[c][r-1].rgbtRed*0+image[c+1][r].rgbtRed*2+image[c+1][r-1].rgbtRed*1;
                int gYGreen = image[c][r].rgbtGreen*0+image[c][r-1].rgbtGreen*0+image[c+1][r].rgbtGreen*2+image[c+1][r-1].rgbtGreen*1;
                int gYBlue = image[c][r].rgbtBlue*0+image[c][r-1].rgbtBlue*0+image[c+1][r].rgbtBlue*2+image[c+1][r-1].rgbtBlue*1;

                int red = round(sqrt(pow(gXRed,2.0)+pow(gYRed,2.0)));
                int green = round(sqrt(pow(gXGreen,2.0)+pow(gYGreen,2.0)));
                int blue =  round(sqrt(pow(gXBlue,2.0)+pow(gYBlue,2.0)));
                if(red>=255){
                    red = 255;
                }
                if(green >= 255){
                    green=255;
                }
                if(blue >=255){
                    blue = 255;
                }
                imageCopy[c][r].rgbtRed=red ;
                imageCopy[c][r].rgbtGreen= green;
                imageCopy[c][r].rgbtBlue= blue;
            }
            else if(c==height-1 && r==width-1)
            {
                int avgRed =round((image[c-1][r].rgbtRed+image[c][r].rgbtRed+image[c][r-1].rgbtRed+image[c-1][r-1].rgbtRed)/4.0);
                imageCopy[c][r].rgbtRed=avgRed;
                 int avgBlue =round((image[c-1][r].rgbtBlue+image[c][r].rgbtBlue+image[c][r-1].rgbtBlue+image[c-1][r-1].rgbtBlue)/4.0);
                imageCopy[c][r].rgbtBlue=avgBlue;
                 int avgGreen =round((image[c-1][r].rgbtGreen+image[c][r].rgbtGreen+image[c][r-1].rgbtGreen+image[c-1][r-1].rgbtGreen)/4.0);
                imageCopy[c][r].rgbtGreen=avgGreen;
            }
            else if(c==height-1 && r==0)
            {
                int avgRed =round((image[c-1][r].rgbtRed+image[c][r].rgbtRed+image[c][r+1].rgbtRed+image[c-1][r+1].rgbtRed)/4.0);
                imageCopy[c][r].rgbtRed=avgRed;
                int avgGreen =round((image[c-1][r].rgbtGreen+image[c][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c-1][r+1].rgbtGreen)/4.0);
                imageCopy[c][r].rgbtGreen=avgGreen;
                int avgBlue =round((image[c-1][r].rgbtBlue+image[c][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c-1][r+1].rgbtBlue)/4.0);
                imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(r==0)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed+image[c-1][r].rgbtRed+image[c-1][r+1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgBlue =round((image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue+image[c-1][r].rgbtBlue+image[c-1][r+1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            int avgGreen =round((image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen+image[c-1][r].rgbtGreen+image[c-1][r+1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            }
            else if(r==width-1)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c-1][r].rgbtRed+image[c+1][r].rgbtRed+image[c+1][r-1].rgbtRed+image[c][r-1].rgbtRed+image[c-1][r-1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgGreen =round((image[c][r].rgbtGreen+image[c-1][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c+1][r-1].rgbtGreen+image[c][r-1].rgbtGreen+image[c-1][r-1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            int avgBlue =round((image[c][r].rgbtBlue+image[c-1][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c+1][r-1].rgbtBlue+image[c][r-1].rgbtBlue+image[c-1][r-1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(c==0)
            {
                 int gXRed = image[c][r].rgbtRed*0+image[c+1][r].rgbtRed*0+image[c+1][r+1].rgbtRed*1+image[c][r+1].rgbtRed*2+image[c][r-1].rgbtRed*(-2)+image[c+1][r-1].rgbtRed*(-1) ;
                int gXGreen = image[c][r].rgbtGreen*0+image[c+1][r].rgbtGreen*0+image[c+1][r+1].rgbtGreen*1+image[c][r+1].rgbtGreen*2+image[c][r-1].rgbtGreen*(-2)+image[c+1][r-1].rgbtGreen*(-1);
                int gXBlue = image[c][r].rgbtBlue*0+image[c+1][r].rgbtBlue*0+image[c+1][r+1].rgbtBlue*1+image[c][r+1].rgbtBlue*2+image[c][r-1].rgbtBlue*(-2)+image[c+1][r-1].rgbtBlue*(-1);

                int gYRed = image[c][r].rgbtRed*0+image[c][r+1].rgbtRed*0+image[c][r-1].rgbtRed*0+image[c+1][r].rgbtRed*2+image[c+1][r+1].rgbtRed*1+image[c+1][r-1].rgbtRed*1;
                int gYGreen = image[c][r].rgbtGreen*0+image[c][r+1].rgbtGreen*0+image[c][r-1].rgbtGreen*0+image[c+1][r].rgbtGreen*2+image[c+1][r+1].rgbtGreen*1+image[c+1][r-1].rgbtGreen*1;
                int gYBlue = image[c][r].rgbtBlue*0+image[c][r+1].rgbtBlue*0+image[c][r-1].rgbtBlue*0+image[c+1][r].rgbtBlue*2+image[c+1][r+1].rgbtBlue*1+image[c+1][r-1].rgbtBlue*1;

                int red = round(sqrt(pow(gXRed,2.0)+pow(gYRed,2.0)));
                int green = round(sqrt(pow(gXGreen,2.0)+pow(gYGreen,2.0)));
                int blue =  round(sqrt(pow(gXBlue,2.0)+pow(gYBlue,2.0)));
                if(red>=255){
                    red = 255;
                }
                if(green >= 255){
                    green=255;
                }
                if(blue >=255){
                    blue = 255;
                }
                imageCopy[c][r].rgbtRed=red ;
                imageCopy[c][r].rgbtGreen= green;
                imageCopy[c][r].rgbtBlue= blue;
            }
            else if(c==height-1)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c-1][r].rgbtRed+image[c][r+1].rgbtRed+image[c-1][r-1].rgbtRed+image[c-1][r+1].rgbtRed+image[c][r-1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgGreen =round((image[c][r].rgbtGreen+image[c-1][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c-1][r-1].rgbtGreen+image[c-1][r+1].rgbtGreen+image[c][r-1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            int avgBlue =round((image[c][r].rgbtBlue+image[c-1][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c-1][r-1].rgbtBlue+image[c-1][r+1].rgbtBlue+image[c][r-1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else
            {
            int gXRed = image[c][r].rgbtRed*0+image[c+1][r].rgbtRed*0+image[c-1][r].rgbtRed*0+image[c+1][r+1].rgbtRed*1+image[c-1][r+1].rgbtRed*1+image[c][r+1].rgbtRed*2+image[c][r-1].rgbtRed*(-2)+image[c-1][r-1].rgbtRed*(-1)+image[c+1][r-1].rgbtRed*(-1) ;
            int gXGreen = image[c][r].rgbtGreen*0+image[c+1][r].rgbtGreen*0+image[c-1][r].rgbtGreen*0+image[c+1][r+1].rgbtGreen*1+image[c-1][r+1].rgbtGreen*1+image[c][r+1].rgbtGreen*2+image[c][r-1].rgbtGreen*(-2)+image[c-1][r-1].rgbtGreen*(-1)+image[c+1][r-1].rgbtGreen*(-1);
            int gXBlue = image[c][r].rgbtBlue*0+image[c+1][r].rgbtBlue*0+image[c-1][r].rgbtBlue*0+image[c+1][r+1].rgbtBlue*1+image[c-1][r+1].rgbtBlue*1+image[c][r+1].rgbtBlue*2+image[c][r-1].rgbtBlue*(-2)+image[c-1][r-1].rgbtBlue*(-1)+image[c+1][r-1].rgbtBlue*(-1);

            int gYRed = image[c][r].rgbtRed*0+image[c][r+1].rgbtRed*0+image[c][r-1].rgbtRed*0+image[c+1][r].rgbtRed*2+image[c+1][r+1].rgbtRed*1+image[c+1][r-1].rgbtRed*1+image[c-1][r].rgbtRed*(-2)+image[c-1][r+1].rgbtRed*(-1)+image[c-1][r-1].rgbtRed*(-1);
            int gYGreen = image[c][r].rgbtGreen*0+image[c][r+1].rgbtGreen*0+image[c][r-1].rgbtGreen*0+image[c+1][r].rgbtGreen*2+image[c+1][r+1].rgbtGreen*1+image[c+1][r-1].rgbtGreen*1+image[c-1][r].rgbtGreen*(-2)+image[c-1][r+1].rgbtGreen*(-1)+image[c-1][r-1].rgbtGreen*(-1);
            int gYBlue = image[c][r].rgbtBlue*0+image[c][r+1].rgbtBlue*0+image[c][r-1].rgbtBlue*0+image[c+1][r].rgbtBlue*2+image[c+1][r+1].rgbtBlue*1+image[c+1][r-1].rgbtBlue*1+image[c-1][r].rgbtBlue*(-2)+image[c-1][r+1].rgbtBlue*(-1)+image[c-1][r-1].rgbtBlue*(-1);

            int red = round(sqrt(pow(gXRed,2.0)+pow(gYRed,2.0)));
            int green = round(sqrt(pow(gXGreen,2.0)+pow(gYGreen,2.0)));
            int blue =  round(sqrt(pow(gXBlue,2.0)+pow(gYBlue,2.0)));
            imageCopy[c][r].rgbtRed=red %255;
            imageCopy[c][r].rgbtGreen= green %255;
            imageCopy[c][r].rgbtBlue= blue%255;
        }
        // int gXRed = image[c][r].rgbtRed*0+image[c+1][r].rgbtRed*0+image[c-1][r].rgbtRed*0+image[c+1][r+1].rgbtRed*2+image[c-1][r+1].rgbtRed*2+image[c][r+1].rgbtRed*2+image[c][r-1].rgbtRed*(-2)+image[c-1][r-1].rgbtRed*(-2)+image[c+1][r-1].rgbtRed*(-2) ;
        // int gXGreen = image[c][r].rgbtGreen*0+image[c+1][r].rgbtGreen*0+image[c-1][r].rgbtGreen*0+image[c+1][r+1].rgbtGreen*2+image[c-1][r+1].rgbtGreen*2+image[c][r+1].rgbtGreen*2+image[c][r-1].rgbtGreen*(-2)+image[c-1][r-1].rgbtGreen*(-2)+image[c+1][r-1].rgbtGreen*(-2);
        // int gXBlue = image[c][r].rgbtBlue*0+image[c+1][r].rgbtBlue*0+image[c-1][r].rgbtBlue*0+image[c+1][r+1].rgbtBlue*2+image[c-1][r+1].rgbtBlue*2+image[c][r+1].rgbtBlue*2+image[c][r-1].rgbtBlue*(-2)+image[c-1][r-1].rgbtBlue*(-2)+image[c+1][r-1].rgbtBlue*(-2);

        // int gYRed = image[c][r].rgbtRed*0+image[c][r+1].rgbtRed*0+image[c][r-1].rgbtRed*0+image[c+1][r].rgbtRed*2+image[c+1][r+1].rgbtRed*2+image[c+1][r-1].rgbtRed*2+image[c-1][r].rgbtRed*(-2)+image[c-1][r+1].rgbtRed*(-2)+image[c-1][r-1].rgbtRed*(-2);
        // int gYGreen = image[c][r].rgbtGreen*0+image[c][r+1].rgbtGreen*0+image[c][r-1].rgbtGreen*0+image[c+1][r].rgbtGreen*2+image[c+1][r+1].rgbtGreen*2+image[c+1][r-1].rgbtGreen*2+image[c-1][r].rgbtGreen*(-2)+image[c-1][r+1].rgbtGreen*(-2)+image[c-1][r-1].rgbtGreen*(-2);
        // int gYBlue = image[c][r].rgbtBlue*0+image[c][r+1].rgbtBlue*0+image[c][r-1].rgbtBlue*0+image[c+1][r].rgbtBlue*2+image[c+1][r+1].rgbtBlue*2+image[c+1][r-1].rgbtBlue*2+image[c-1][r].rgbtBlue*(-2)+image[c-1][r+1].rgbtBlue*(-2)+image[c-1][r-1].rgbtBlue*(-2);

        // imageCopy[c][r].rgbtRed=sqrt(pow(gXRed,2)+pow(gYRed,2));
        // imageCopy[c][r].rgbtBlue=sqrt(pow(gXBlue,2)+pow(gYBlue,2));
        // imageCopy[c][r].rgbtGreen=sqrt(pow(gXGreen,2)+pow(gYGreen,2));

    }
    }
     for(int c = 0; c < height; c++)
    {
        for(int r = 0; r < width; r++)
        {
            image[c][r]=imageCopy[c][r];
        }
    }
    return;
}
