/*
 * Circle class header
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

#include <iostream>

using namespace std;

// Circle class derived from Shape class
class Circle : public Shape
{
    private:
        long int centerX;
        long int centerY;
        double radius;
    public:
        /**
         * Constructs a circle with an x-value, y-value, and radius.
         * @param x the x-value
         * @param y the y-value
         * @param r the radius
         */
        Circle(long int x, long int y, double r); 
        /**
         * Gets the x-value of the circle
         * @return x-value
         */        
        long int getCenterX();
        /**
         * Gets the y-value of the circle
         * @return y-value
         */           
        long int getCenterY();    
        /**
         * Gets the radius of the circle
         * @return radius
         */       
        double getRadius();        
        /**
         * Sets the x-value of the circle
         * @param x the x-value
         */     
        void setCenterX(int x);      
        /**
         * Sets the y-value of the circle
         * @param y the y-value
         */    
        void setCenterY(int y);     
        /**
         * Sets the radius of the circle
         * @param r the radius
         */     
        void setRadius(int r);          
        /**
         * Calculates the area of the circle
         */
        void calcArea();
        /**
         * Draws the circle using the radius of the circle
         * @param r the radius of the circle
         */
        void draw(int r);                
};
#endif