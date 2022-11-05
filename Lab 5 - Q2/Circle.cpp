/*
 * Circle class implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#include "Circle.h"
#include <iostream>

using namespace std;
/**
 * Constructs a circle with an x-value, y-value, and radius.
 * @param x the x-value
 * @param y the y-value
 * @param r the radius
 */
Circle::Circle(long int x, long int y, double r)
{
    centerX = x;
    centerY = y;
    radius = r;
    calcArea();
}

/**
 * Gets the x-value of the circle
 * @return x-value
 */
long int Circle::getCenterX()
{
    return centerX;
}

/**
 * Gets the y-value of the circle
 * @return y-value
 */
long int Circle::getCenterY()
{
    return centerY;
}

/**
 * Gets the radius of the circle
 * @return radius
 */
double Circle::getRadius()
{
    return radius;
}

/**
 * Sets the x-value of the circle
 * @param x the x-value
 */
void Circle::setCenterX(int x)
{
    centerX = x;   
}

/**
 * Sets the y-value of the circle
 * @param y the y-value
 */
void Circle::setCenterY(int y)
{
    centerY = y;
}

/**
 * Sets the radius of the circle
 * @param r the radius
 */
void Circle::setRadius(int r)
{
    radius = r;
}

/**
 * Calculates the area of the circle
 */
void Circle::calcArea() 
{
    area = 3.14 * radius * radius;
}

/**
 * Draws the circle using the radius of the circle
 * @param r the radius
 */
void Circle::draw(int r)
{       
    // x and y coordinate values inside the circle
    int x, y;
    // using the radius, get the diameter
    int d = (2 * r) + 1;
    
    // draw a square using the x and y values
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // start drawing from the left most corner point
            x = i - r;
            y = j - r;

            // using Pythagorean theorem, a^2 + b^2 = c^2, we get the area of the square
            // draw a dot, ".", when inside the area 
            if ((x * x) + (y * y) <= (r * r) + 1 ) cout<<".";
            // everything outside the area is drawn with a space, ' '.
            else cout << " ";
            // add a space between "."
            cout << " ";
        }
        // after row is finished, go to next row.
        cout << endl;
    }
}  