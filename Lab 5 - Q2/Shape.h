/*
 * Shape abstract class header
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

// abstract class Shape
class Shape
{
    // area is declared as protected because it will be accessed directly from derived classes
    protected:
        double area;
    public:
        /**
         * Gets the area of the shape
         * @return area
         */       
        double getArea();       
        /**
         * Sets the area of the shape
         * @param a the area to be set.
         */       
        void setArea(double a);  
        /**
         * Calculates the area of the shape
         */                     
        virtual void calcArea() = 0;   
        /**
         * Draws the shape
         */               
        void draw();
};
#endif