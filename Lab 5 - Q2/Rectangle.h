/*
 * Rectangle class header
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

#include <iostream>

using namespace std;

// Rectangle class derived from Shape class
class Rectangle : public Shape
{
    private:
        long int width;
        long int height;
        long int centerX;
        long int centerY;
    public:
        /**
         * Constructs a rectangle with a width, height, x-value, and y-value.
         * @param w the width
         * @param h the height
         * @param x the x-value
         * @param y the y-value
         */
        Rectangle(long int w, long int h, long int x, long int y); 
        /**
         * Gets the width of the rectangle
         * @return width
         */
        long int getWidth();          
        /**
         * Gets the height of the rectangle
         * @return height
         */   
        long int getHeight();      
        /**
         * Gets the x-value of the rectangle
         * @return x-value
         */     
        long int getCenterX();   
        /**
         * Gets the y-value of the rectangle
         * @return y-value
         */        
        long int getCenterY();      
        /**
         * Sets the width of the rectangle
         * @param w the width
         */     
        void setWidth(int w);           
        /**
         * Sets the height of the rectangle
         * @param h the height
         */ 
        void setHeight(int h);          
        /**
         * Sets the x-value of the rectangle
         * @param x the x-value
         */ 
        void setCenterX(int x);          
        /**
         * Sets the y-value of the rectangle
         * @param y the y-value
         */
        void setCenterY(int y);       
        /**
         * Calculates the area of the rectangle
         */   
        void calcArea();                
        /**
         * Draws the rectangle using the width and height of the rectangle
         * @param w the width
         * @param h the height
         */
        void draw(int w, int h);         
};
#endif