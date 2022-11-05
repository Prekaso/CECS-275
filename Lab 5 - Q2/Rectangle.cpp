/*
 * Rectangle class implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#include "Rectangle.h"
#include <iostream>

using namespace std;
/**
 * Constructs a rectangle with a width, height, x-value, and y-value.
 * @param w the width
 * @param h the height
 * @param x the x-value
 * @param y the y-value
 */
Rectangle::Rectangle(long int w, long int h, long int x, long int y)
{
    width = w;
    height = h;
    centerX = x;
    centerY = y;
    calcArea();
}

/**
 * Gets the width of the rectangle
 * @return width
 */
long int Rectangle::getWidth()
{
    return width;
}

/**
 * Gets the height of the rectangle
 * @return height
 */
long int Rectangle::getHeight()
{
    return height;
}

/**
 * Gets the x-value of the rectangle
 * @return x-value
 */
long int Rectangle::getCenterX()
{
    return centerX;
}

/**
 * Gets the y-value of the rectangle
 * @return y-value
 */
long int Rectangle::getCenterY()
{
    return centerY;
}

/**
 * Sets the width of the rectangle
 * @param w the width
 */
void Rectangle::setWidth(int w)
{
    width = w;
}

/**
 * Sets the height of the rectangle
 * @param h the height
 */
void Rectangle::setHeight(int h)
{
    height = h;
}

/**
 * Sets the x-value of the rectangle
 * @param x the x-value
 */
void Rectangle::setCenterX(int x)
{
    centerX = x;
}

/**
 * Sets the y-value of the rectangle
 * @param y the y-value
 */
void Rectangle::setCenterY(int y)
{
    centerY = y;
}

/**
 * Calculates the area of the rectangle
 */
void Rectangle::calcArea()
{
    area = width * height;
}

/**
 * Draws the rectangle using the width and height of the rectangle
 * @param w the width
 * @param h the height
 */
void Rectangle::draw(int w, int h)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            // draw a "." when at the sides of the rectangle
            if (i == 0 || j == 0 || i == h - 1 || j == w - 1) cout << ".";
            // inside of the rectangle is drawn with space, " ".
            else cout << " ";
        }
        cout << endl;
    }
}