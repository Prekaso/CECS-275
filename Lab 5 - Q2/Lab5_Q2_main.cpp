/*
 * This C++ program's purpose is to: 
 * - Implement an abstract class called Shape and create 2 classes Circle and Rectangle which are derived classes of Shape.
 * - Get data for each shape from the user and draw the shape.
 * - After creating the shape, store the shape into a Shape array
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.2.0 
 */

#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
   // variables used to store the parameters of the shapes
   long int x_circle, y_circle, x_rect, y_rect, width, height;
   double radius;
   
   // variables used to control/navigate the menu
   bool run = true;
   int shapeChoice = 0;
   int finalChoice = 0;

   // array used to hold the shapes created by the user
   Shape* shapes[10];
   int countShapes =- 1;

   while (run == true)
   {
      // asks user which shape they would like to create
      cout << "Which shape would you like to create? " << endl;
      cout << "\t1. Circle " << endl;
      cout << "\t2. Rectangle " << endl;
      cin >> shapeChoice;

      if (shapeChoice == 1)
      {
         // getting x, y, radius values from user
         cout << "Enter x-value: " << endl; cin >> x_circle;
         cout << "Enter y-value: " << endl; cin >> y_circle;
         cout << "Enter radius: " << endl; cin >> radius;

         // creating Circle object
         Circle circle(x_circle, y_circle, radius);

         // outputting data user has entered using getter functions
         // drawing circle using given data
         cout << endl << "X-value: " << circle.getCenterX() << endl;
         cout << "Y-value: " << circle.getCenterY() << endl;
         cout << "Radius: " << circle.getRadius() << endl;
         cout << "Area of circle: " << circle.getArea() << endl;
         cout << endl;
         circle.draw(circle.getRadius());

         // store circle in Shape array
         shapes[countShapes] = new Circle(x_circle, y_circle, radius);
         cout << endl;

         // asks user if they would like to continue adding more shapes
         cout << "Would you like to add more shapes? " << endl;
         cout << "\t1. Continue " << endl;
         cout << "\t2. Stop " << endl;
         cin >> finalChoice;
         if (finalChoice == 2) run = false;
      }
      else if (shapeChoice == 2)
      {
         // getting width, height, x, y values from user
         cout << "Enter the width: " << endl; cin >> width;
         cout << "Enter the height: " << endl; cin >> height;
         cout << "Enter x-value: " << endl; cin >> x_rect;
         cout << "Enter y-value: " << endl; cin >> y_rect;

         // creating Rectangle Object
         Rectangle rect(width, height, x_rect, y_rect);

         // outputting data user has entered using getter functions
         // drawing rectangle using given data
         cout << endl << "Width of rectangle: "<< rect.getWidth() << endl;
         cout << "Height of rectangle: "<< rect.getHeight() << endl;
         cout << "X-value: " << rect.getCenterX() << endl;
         cout << "Y-value: " << rect.getCenterY() << endl;
         cout << "Area of rectangle: " << rect.getArea() << endl;
         cout << endl;
         rect.draw(rect.getWidth(), rect.getHeight());

         // store rectangle in Shape array
         shapes[countShapes] = new Rectangle(width, height, x_rect, y_rect);
         cout << endl;

         // asks user if they would like to continue adding more shapes
         cout << "Would you like to add more shapes? " << endl;
         cout << "\t1. Continue " << endl;
         cout << "\t2. Stop " << endl;
         cin >> finalChoice;
         if (finalChoice == 2) run = false; 
      }
      else
      {
         // make sure user enters valid choice
         cout << "Please enter a valid choice." << endl;
      }
   }
   return 0;
}
