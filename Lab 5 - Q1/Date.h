#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string> 
using namespace std;

#define YYYYMMDD  "yyyy-mm-dd"
#define DDMMYYYY  "dd-mm-yyyy"
#define MMDDYYYY  "mm-dd--yyyy"

//Use enum class for Month (January, February, etc.)
enum class Month
{
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};


class Date
{
public:
//Provide inner class InvalidDateException to throw error if a date is not valid. For example, 02/29/2005 is an invalid date.
    class InvalidDate
    {
        public:
        InvalidDate(string str):m_Str(str){}
        string invalid()const{ return m_Str;}
        private:
        string m_Str;
    };
    
    Date();
    Date(Month mm, int dd,int yy);

    Month set_Month() const { return m_Month;}
    void set_Month(Month mon) { m_Month = mon;} 

    int day() const 
    {
        return d_Day;
    }
    void day(int day) {d_Day = day;}

    int year() const 
    {
        return y_Year;
    }
    void year(int year) {y_Year = year;}

    string toString(string format);
    static string listAllDates(int year);
    
    Date& operator ++();
    Date operator++(int); 
    Date& operator --();
    Date operator--(int); 

    friend ostream& operator <<(ostream &out,const Date &date);
    friend istream& operator >>(istream& is, Date& date);
    
//The Date class has three private members of int type month, day, year 
private:
    Month m_Month;
    int d_Day;
    int y_Year;

};
bool isValidDate(const Date &date);
Date operator + (const Date &date,int days);
Date operator - (const Date &date,int days);
#endif