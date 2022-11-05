/*
 * This C++ program purporse is to: Store employee information from "salary.txt" into a vector,
 * allocate a bank account for each employee on the heap and set bank account id using employee id,
 * traverse the vector of employee info, and for each employee, deposit 1/12th of their annual salary into their bank account,
 * and finally print all employee info, including account balances, into "monthly_salary.txt"
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#include "BankAccount.h"
#include "Employee.h"

using namespace std;

// this function is responsible for removing the comma in the salary string
// returns salary as a double
double removeComma(string salary)
{
    string new_salary; // create new string to hold string without comma

    for (int i = 0; i < salary.length(); ++i)   
    {
        if (salary[i] != ',')   // only keep characters that aren't commas
            new_salary += salary[i];
    }
    return stod(new_salary); // converting the string salary into a double salary
}

//this function is responsible for reading the "salary.txt" and extracting the employees' information
// returns a vector with all the information from "salary.txt"
vector<Employee> storeEmployeeInfo()
{
    ifstream input_file("salary.txt"); // salary.txt input file

    vector<Employee> allEmployeeInfo; // vector created to store employee info

    string id, first_name, last_name, salary;

    BankAccount *account; // pointer to bank account

    while (!input_file.eof()) // reading file until the end 
    {
        input_file >> id >> first_name >> last_name >> salary; // employee information stored in this order

        double d_salary = removeComma(salary); // remove comma from salary and convert to double

        account = new BankAccount(); // allocating new bank account on the heap for each employee

        account->set_id(id); // bank account gets the employee's id

        string fullName = first_name + " " + last_name; // have to combine the first and last name to fulfill Employee object parameters

        Employee employee(id, fullName, d_salary, account); // create employee object with gathered info
        allEmployeeInfo.push_back(employee);  // push employee object into vector
    }

    input_file.close(); // close file after reaching end of file

    return allEmployeeInfo; // return vector 
}

// this function is responsible for printing the employee info from the vector into "montly_salary.txt"
// it is also responsible for depositing 1/12th of each employee's annual income into their bank account
void printEmployeeInfo(vector<Employee> allEmployeeInfo)
{
    ofstream output_file("monthly_salary.txt"); // "monthly_salary.txt" output file

    // creating a table format that holds the headers
    // each header is left aligned with appropriate spacing in between
    output_file << "|———————————————————|———————————————|———————————————|———————————————————|———————————————————|—————————————| " << "\n"  
             << left << setw(16) << "| Employee ID"
             << "\t"
             << left << setw(14) << "| Last Name"
             << "\t"
             << left << setw(15) << "| First Name"
             << "\t"
             << left << setw(18) << "| Annual Salary"
             << "\t"
             << left << setw(19) << "| Monthly Salary"
             << "\t"
             << left << setw(12) << "| Balance" << "  | "
             << "\n"
             << "|———————————————————|———————————————|———————————————|———————————————————|———————————————————|—————————————| " << "\n";

    for (int i = 0; i < allEmployeeInfo.size(); ++i) // traversing the vector of employee information and printing to "monthly_salary.txt"
    {
        allEmployeeInfo[i].print(output_file);
    }

    output_file.close(); // close "montly_salary.txt" after printing
}

int main()
{
    vector<Employee> allEmployeeInfo = storeEmployeeInfo(); // read the employees
    
    for (int i = 0; i < allEmployeeInfo.size(); ++i) // traversing through the vector that stores employee's info 
    {                                 // for each employee, deposit 1/12th of their annual salary
        allEmployeeInfo[i].deposit_monthly_salary();
    }

    printEmployeeInfo(allEmployeeInfo); // call function which prints the employees' information and monthly salary into "monthly_salary.txt" output file

    return 0;
}