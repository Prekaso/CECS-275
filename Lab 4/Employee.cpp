/*
 * Employee class implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#include "Employee.h"
#include <iostream>
#include <iomanip>

using namespace std;
/**
 * Constructs an employee with a id, given name, salary, and bank account.
 *
 * @param id the id
 * @param fname the first name
 * @param lname the last name
 * @param s the annual salary
 * @param a a pointer to the bank account
 */
Employee::Employee(std::string id, string n, double s, BankAccount *a)
{
    this->id = id; // access member id
    name = n;
    salary = s;
    account = a;
}

/**
 * Deposits one month's salary into the bank account
 *
 */
void Employee::deposit_monthly_salary()
{
    account->deposit(salary / 12); // access member id so that we can deposit monthly salary
}

/**
 * Prints this employees's information to cout.
 *
 */
void Employee::print(std::ostream &output_file) const
{
    // we need to get the first and last name from file and concatenate it into full name
    int space = name.find(' ');
    string first_name = name.substr(0, space); // string before a space is the first name
    string last_name = name.substr(space + 1); // string after a space is the last name


    //--------------Converting the salary & balance into a string in order to add commas--------------------//
    // adding commas only account for up to a million dollar salary
    string str_salary = to_string(salary); // converting annual salary from double to string
    str_salary = str_salary.substr(0, str_salary.size()- 4); // limiting to 2 places after decimal point
    
    if (str_salary.size() >= 7 && str_salary.size() < 10) // places commas in correct spot for numbers under a million
    {
        int comma = str_salary.size() - 6;
        str_salary = str_salary.insert(comma, 1, ',');
    }
    else if (str_salary.size() >= 10) { // places commas in correct spot for numbers at and over a million
        int comma = str_salary.size() - 6;
        str_salary = str_salary.insert(str_salary.size()-9,1,',');
        str_salary = str_salary.insert(comma+1,1,',');
    }

    string str_monthlySalary = to_string(salary/12); // converting monthly salary from double to string
    str_monthlySalary = str_monthlySalary.substr(0, str_monthlySalary.size()- 4); // limiting to 2 places after decimal point

    if (str_monthlySalary.size() >= 7)
    {
        int comma = str_monthlySalary.size() - 6; 
        str_monthlySalary = str_monthlySalary.insert(comma, 1, ','); // places commas in correct spot for numbers under a million
    }

    string str_balance = to_string(account->get_balance()); // converting balance from double to string
    str_balance = str_balance.substr(0, str_balance.size()- 4); // limiting to 2 places after decimal point
        
     if (str_balance.size() >= 7)
    {
        int comma = str_balance.size() - 6;
        str_balance = str_balance.insert(comma, 1, ','); // places commas in correct spot for numbers under a million
    }
    //--------------Converting the salary & balance into a string in order to add commas--------------------//


    output_file << left << "| " << setw(16) <<  id << "\t"
    << left << "| " << setw(11) << last_name << "\t"
    << left << "| " << setw(13) << first_name << "\t"
    << left << "| $" << setw(15) << ("%.2f", str_salary) << "\t"
    << left << "| $" << setw(14) << ("%.2f", str_monthlySalary) << "\t"
    << left << "| $" << setw(10) << ("%.2f", str_balance) << " | " << "\t" << "\n"
    << "|———————————————————|———————————————|———————————————|———————————————————|———————————————————|—————————————| " << "\n";
}