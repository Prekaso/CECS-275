/*
 * Shape class implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#include "Shape.h"
#include <iostream>

using namespace std;

/**
 * Gets the area of the shape
 * @return area
 */
double Shape::getArea()
{
    return area;
}

/**
 * Sets the area of the shape
 * @param a the area to be set
 */
void Shape::setArea(double a)
{
    area = a;
}

