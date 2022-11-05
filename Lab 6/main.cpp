/*
 * This C++ program's purpose is to: 
 * - Implement a Singly Linked List class, Student class, Course class
 * - Get Student info and courses and output to screen
 * - Add and drop courses using linked list of Courses
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Course.h"
#include "Student.h"

using namespace std;

// main class
int main() {

    // defining course objects
    Course c1(275, "CECS", "MW 5:30 PM - 7:45 PM", "Spring 2022");
    Course c2(329, "CECS", "MW 8:00 PM - 9:15 PM", "Spring 2022");
    Course c3(271, "CECS", "TuTh 8:00 PM - 9:15 PM", "Spring 2022");
    Course c4(347, "CECS", "MW 10:00 AM - 12:15 PM", "Spring 2022");

    // creating linkedlist called courses1 for student 1
    LinkedList<Course> courses1;
    // adding course objects in linked list
    courses1.add(c1);
    courses1.add(c2);
    courses1.add(c3);

    // creating 1st student 
    Student stu1("1234567", "Manny", "Chavez", courses1);
    stu1.toString();
    cout << "Student Initials: " << stu1.getInitial() << endl << endl;
   
    stu1.dropCourse(c1); // dropping 1st course
    cout << "\nAdded course: " << c4.toString() << endl;
    stu1.addCourse(c4);  // adding new course
    cout << "\nNew schedule after changes: " << endl;
    stu1.getSchedule();  // getting updated schedule
    
    return 0;
}