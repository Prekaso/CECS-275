/*
 * Student class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.1.0 
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {

private: // private members of student class
    string studentID;
    string firstName;
    string lastName;
    LinkedList<Course> courseList;

public:
    Student() {}
    /**
     * Constructs a student with a student ID, first name, last name, course list
     * @param studentID the student ID
     * @param firstName the first name
     * @param lastName the last name
     * @param courseList the course list
     */
    Student(const string &studentId, const string &firstName, const string &lastName,
            const LinkedList<Course> &courseList) : studentID(studentId), firstName(firstName), lastName(lastName),
            courseList(courseList) {}
    /**
     * Gets the student ID of the student
     * @return studentID
     */
    const string &getStudentId() const {
        return studentID;
    }
    /**
     * Sets the student ID of the student
     * @param studentID
     */
    void setStudentId(const string &studentId) {
        studentID = studentId;
    }
    /**
     * Gets the first name of the student
     * @return firstName
     */
    const string &getFirstName() const {
        return firstName;
    }
    /**
     * Sets the first name of the student
     * @param firstName
     */
    void setFirstName(const string &firstName) {
        Student::firstName = firstName;
    }
    /**
     * Gets the last name of the student
     * @return lastName
     */
    const string &getLastName() const {
        return lastName;
    }
    /**
     * Sets the last name of the student
     * @param lastName
     */
    void setLastName(const string &lastName) {
        Student::lastName = lastName;
    }
    /**
     * Gets the course list of the student
     * @return courseList
     */
    void getCourseList() {
        return courseList.printSequence();
    }
    /**
     * Sets the course list of the student
     * @param courseList
     */
    void setCourseList(const LinkedList<Course> &courseList) {
        Student::courseList = courseList;
    }

    /**
     * Gets the initials of the student's name
     * @return initials
     */
    string getInitial(){
        ostringstream os;
        os << firstName[0] << "." << lastName[0] << ".";
        return os.str();
    }

    /**
     * Gets the full name of the student
     * @return full name
     */
    string getFullName() {
        return lastName + ", " + firstName;
    }

     /**
     * Gets the schedule of the student 
     */
    void getSchedule() {
        getCourseList();
    }

     /**
     * Drop the student's course to course list
     * @param course
     */
    void dropCourse(Course course) {
        Student::courseList.drop(course);
    }

     /**
     * Add the student's course to course list
     * @param course
     */
    void addCourse(Course course) {
        Student::courseList.add(course);
    }

     /**
     * Sort the student's courses by course number
     * @param course
     */
    void sortCourse() {
        //Student::courseList.sort(course);
    }

     /**
     * Print student's information and courses
     */
    void toString() {
        ostringstream os;
        os << "ID" << setw(18) << ": " << studentID << endl
           << "First Name" << setw(10) << ": " << firstName << endl
           << "Last Name" << setw(11) << ": " << lastName << endl
           << "Schedule for Spring 2022" << endl;
        cout << os.str();
        getCourseList();
    }
};

#endif