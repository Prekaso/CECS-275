/*
 * Course class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.1.0 
 */

#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

class Course { // course class
private: // private members of course class
    int courseNumber;
    string courseName;
    string courseTime;
    string courseSemester;

public:
    Course() {}
    /**
     * Constructs a course with a course number, course name, course time, course semester
     * @param courseNumber the course number
     * @param courseName the course name
     * @param courseTime the course time
     * @param courseSemester the course semester
     */
    Course(int courseNumber, const string &courseName, const string &courseTime, const string &courseSemester)
            : courseNumber(courseNumber), courseName(courseName), courseTime(courseTime),
              courseSemester(courseSemester) {}

    /**
     * Gets the course number of the course
     * @return courseNumber
     */
    int getCourseNumber() const {
        return courseNumber;
    }
    /**
     * Sets the course number of the course
     * @param courseNumber
     */
    void setCourseNumber(int courseNumber) {
        Course::courseNumber = courseNumber;
    }
    /**
     * Gets the course name of the course
     * @return courseName
     */
    const string &getCourseName() const {
        return courseName;
    }
    /**
     * Sets the course name of the course
     * @param courseName
     */
    void setCourseName(const string &courseName) {
        Course::courseName = courseName;
    }
    /**
     * Gets the course time of the course
     * @return courseTime
     */
    const string &getCourseTime() const {
        return courseTime;
    }
    /**
     * Sets the course time of the course
     * @param courseTime
     */
    void setCourseTime(const string &courseTime) {
        Course::courseTime = courseTime;
    }
    /**
     * Gets the course semester of the course
     * @return courseSemester
     */
    const string &getCourseSemester() const {
        return courseSemester;
    }
    /**
     * Sets the course semester of the course
     * @param courseSemester
     */
    void setCourseSemester(const string &courseSemester) {
        Course::courseSemester = courseSemester;
    }
    /**
     * Convert course information into string
     * @return course info as string
     */
    string toString() { // courseSemester + " " + 
        return courseName + ": " + to_string(courseNumber) + " " + courseTime;
    }

};

#endif