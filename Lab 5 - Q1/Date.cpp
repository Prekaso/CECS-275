#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

using namespace std;

bool IsLeapYear(const Date &date);

string monthToString(Month mm)
{
    switch (mm)
    {
    case Month::January:
        return "Jan";
    case Month::February:
        return "Feb";
    case Month::March:
        return "Mar";
    case Month::April:
        return "Apr";
    case Month::May:
        return "May";
    case Month::June:
        return "Jun";
    case Month::July:
        return "Jul";
    case Month::August:
        return "Aug";
    case Month::September:
        return "Sep";
    case Month::October:
        return "Oct";
    case Month::November:
        return "Nov";
    case Month::December:
        return "Dec";
    }
}
string monthToInt(Month mm)
{
    switch (mm)
    {
    case Month::January:
        return "01";
    case Month::February:
        return "02";
    case Month::March:
        return "03";
    case Month::April:
        return "04";
    case Month::May:
        return "05";
    case Month::June:
        return "06";
    case Month::July:
        return "07";
    case Month::August:
        return "08";
    case Month::September:
        return "09";
    case Month::October:
        return "10";
    case Month::November:
        return "11";
    case Month::December:
        return "12";
    }
}
Month intToString(int mm)
{
    switch (mm)
    {
    case 1:
        return Month::January;
    case 2:
        return Month::February;
    case 3:
        return Month::March;
    case 4:
        return Month::April;
    case 5:
        return Month::May;
    case 6:
        return Month::June;
    case 7:
        return Month::July;
    case 8:
        return Month::August;
    case 9:
        return Month::September;
    case 10:
        return Month::October;
    case 11:
        return Month::November;
    case 12:
        return Month::December;
    }
}
//Overload operator << to display the date in form Month Day, Year (e.g. May 06, 2018)
ostream &operator<<(ostream &os, const Date &dt)
{
    string date;
    string month = monthToString(dt.set_Month());
    string days;
    string year = to_string(dt.year());

    if (dt.day() < 10)
    {
        days += "0";
    }
    days += to_string(dt.day());
    date = month + " " + days + ", " + year;

    os << date;
    return os;
}

//Overload operator >> to prompt the user for a date to be stored in a Date object
istream &operator>>(istream &is, Date &dt)
{

    if (isValidDate(dt))
        return is;
    else
        throw Date::InvalidDate("Date is Invalid");
}

Date::Date() : m_Month(Month::February), d_Day(29), y_Year(2005){}
Date::Date(Month mm, int dd, int yy) : m_Month(mm), d_Day(dd), y_Year(yy)
{
    if (isValidDate(*this) == false)
    {
        throw InvalidDate("Date is Invalid");
    }
}
//It limits the maximum and minimum number of days by the month it also use isleapyear to check feburay has 29 days.
bool isValidDate(const Date &date)
{
    if (date.set_Month() < Month::January || date.set_Month() > Month::December)
        return false;

    if (date.set_Month() == Month::February)
    {
        if (IsLeapYear(date))
        {
            if (date.day() < 1 || date.day() > 29)
            {
                return false;
            }
        }
        else
        {
            if (date.day() < 1 || date.day() > 28)
            {
                return false;
            }
        }
    }
    if (date.set_Month() == Month::April || date.set_Month() == Month::June || date.set_Month() == Month::September || date.set_Month() == Month::November)
    {
        if (date.day() < 1 || date.day() > 30)
        {
            return false;
        }
    }
    else
    {
        if (date.day() < 1 || date.day() > 31)
        {
            return false;
        }
    }

    return true;
}

//Provide function listAllDates that takes in a year as parameter and returns the list of all dates for that year.
string Date::listAllDates(int year)
{
    vector<Month> vec{Month::January, Month::February, Month::March, Month::April, Month::May, Month::June, Month::July, Month::August,
                      Month::September, Month::October, Month::November, Month::December};
    Date temp(Month::January, 1, year);
    string date("Jan\n");

    int totalDays;
    for (auto it : vec)
    {
        if (it == Month::January || it == Month::March || it == Month::May || it == Month::July || it == Month::August || it == Month::October || it == Month::December)
        {
            int totalDays = 31;
        }
            
        if (it == Month::February)
        {
            int totalDays = 28;
            if (IsLeapYear(temp))
            {
            totalDays = 29;
            }

        }
        if (it == Month::April || it == Month::June || it == Month::September || it == Month::November)
        {
            totalDays = 30;
        }

        string mon = monthToString(it);
        date = "\n" + mon + "\n";
        for (int i = 1; i <= totalDays; i++)
        {
            date += to_string(i);
            date += "  ";
            if (i % 7 == 0)
                date += "\n";
        }
    }
    return date;
}

//Provide toString member function that takes in format as parameter and display the Date in the corresponding format. Three acceptable formats: yyyy-mm-dd, dd-mm-yyyy, and mm-dd-yyyy.
string Date::toString(string format)
{
    string year = to_string(y_Year);
    string month = monthToInt(m_Month);
    if (format == YYYYMMDD)
    {
        string dateFormat = year+"-"+month+"-";
        string days;

        if (d_Day < 10)
        {
            days += "0";
        }
        days += to_string(d_Day);
        dateFormat += days;
        return dateFormat;
    }
    else if (format == DDMMYYYY)
    {
        string days;
        if (d_Day < 10)
        {
            days += "0";
        }
        days += to_string(d_Day);
        string dateFormat = days + "-" + month + "-" + year;
        return dateFormat;
    }
    else if (format == MMDDYYYY)
    {
        string dateFormat = month;
        string days;
        if (d_Day < 10)
        {
            days += "0";
        }
        days += to_string(d_Day);

        dateFormat = month + "-" + days + "-" + year;
        return dateFormat;
    }
    else
    {
        cout << "Format is wrong\n";
        return "";
    }
}

//Overload postfix increment operator
Date &Date::operator++()
{
    Date temp(*this);
    int day = temp.day() + 1;
    int monInDigit = stoi(monthToInt(m_Month));
    int year = temp.year();

    if (m_Month == Month::April || m_Month == Month::June || m_Month == Month::September || m_Month == Month::November)
    {
        if (day > 30)
        {
            monInDigit++;
            day = 1;
        }
    }
    else if (m_Month == Month::December)
    {
        if (day > 31)
        {
            monInDigit = 1;
            day = 1;
            year += 1;
        }
    }    
    else if (m_Month == Month::February)
    {
        if (IsLeapYear(temp))
        {
            if (day > 29)
            {
                monInDigit++;
                day = 1;
            }
        }
        else
        {
            if (day > 28)
            {
                monInDigit++;
                day = 1;
            }
        }
    }
    else
    {
        if (day > 31)
        {
            monInDigit += 1;
            day = 1;
        }
    }

    d_Day = day;
    m_Month = intToString(monInDigit);
    y_Year = year;
    return *this;
}
//Overload postfix increment operator
Date Date::operator++(int)
{

    Date temp(*this);
    int day = temp.day() + 1;
    int monInDigit = stoi(monthToInt(m_Month));
    int year = temp.year();

    if (m_Month == Month::April || m_Month == Month::June || m_Month == Month::September || m_Month == Month::November)
    {
        if (day > 30)
        {
            monInDigit++;
            day = 1;
        }
    }
    else if (m_Month == Month::December)
    {
        if (day > 31)
        {
            monInDigit = 1;
            day = 1;
            year += 1;
        }
    }
    else if (m_Month == Month::February)
    {
        if (IsLeapYear(temp))
        {
            if (day > 29)
            {
                monInDigit++;
                day = 1;
            }
        }
        else
        {
            if (day > 28)
            {
                monInDigit++;
                day = 1;
            }
        }
    }
    else
    {
        if (day > 31)
        {
            monInDigit += 1;
            day = 1;
        }
    }

    d_Day = day;
    m_Month = intToString(monInDigit);
    y_Year = year;
    return temp;
}
//Overload postfix decrement operator
Date &Date::operator--()
{
    Date temp(*this);
    int day = temp.day() - 1;
    int monInDigit = stoi(monthToInt(m_Month));
    int year = temp.year();

    if (m_Month == Month::April || m_Month == Month::June || m_Month == Month::September || m_Month == Month::November)
    {
        if (day < 1)
        {
            monInDigit--;
            day = 31;
        }
    }
    else if (m_Month == Month::January)
    {
        if (day < 1)
        {
            monInDigit = 12;
            day = 31;
            year -= 1;
        }
    }
    else if (m_Month == Month::February || m_Month == Month::August)
    {
        if (day < 1)
        {
            monInDigit--;
            day = 31;
        }
    }
    else if (m_Month == Month::March)
    {
        if (IsLeapYear(temp))
        {
            if (day < 1)
            {
                monInDigit--;
                day = 29;
            }
        }
        else
        {
            if (day < 1)
            {
                monInDigit--;
                day = 28;
            }
        }
    }
    else
    {
        if (day < 1)
        {
            monInDigit -= 1;
            day = 30;
        }
    }

    d_Day = day;
    m_Month = intToString(monInDigit);
    y_Year = year;
    return *this;
}

//Overload postfix decrement operator
Date Date::operator--(int)
{
    Date temp(*this);
    int day = temp.day() - 1;
    int monInDigit = stoi(monthToInt(m_Month));
    int year = temp.year();

    if (m_Month == Month::April || m_Month == Month::June || m_Month == Month::September || m_Month == Month::November)
    {
        if (day < 1)
        {
            monInDigit--;
            day = 31;
        }
    }
    else if (m_Month == Month::January)
    {
        if (day < 1)
        {
            monInDigit = 12;
            day = 31;
            year -= 1;
        }
    }
    else if (m_Month == Month::February || m_Month == Month::August)
    {
        if (day < 1)
        {
            monInDigit--;
            day = 31;
        }
    }
    else if (m_Month == Month::March)
    {
        if (IsLeapYear(temp))
        {
            if (day < 1)
            {
                monInDigit--;
                day = 29;
            }
        }
        else
        {
            if (day < 1)
            {
                monInDigit--;
                day = 28;
            }
        }
    }
    else
    {
        if (day < 1)
        {
            monInDigit -= 1;
            day = 30;
        }
    }

    d_Day = day;
    m_Month = intToString(monInDigit);
    y_Year = year;
    return temp;
}
//Overload addition operator (+). (E.g. Date(12, 1, 2001) + 1 --> Date(12, 2, 2001))
Date operator+(const Date &date, int days)
{
    Date temp = date;

    for (int i = 0; i < days; i++)
    {
        ++temp;
    }
    return temp;
}
//Overload addition operator (-). (E.g. Date(12, 1, 2001) - 1 --> Date(11, 30, 2001))
Date operator-(const Date &date, int days)
{
    Date temp = date;

    for (int i = 0; i < days; i++)
    {
        --temp;
    }
    return temp;
}
//check leapyear
bool IsLeapYear(const Date &date)
{
    if (date.year() % 400 == 0)
        return true;
    else if (date.year() % 100 == 0)
        return false;
    else if (date.year() % 4 == 0)
        return true;
    else
        return false;
}
