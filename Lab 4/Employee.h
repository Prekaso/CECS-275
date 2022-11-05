/*
 * Employee class header
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "BankAccount.h"

using namespace std;

class Employee
{
public:
   /**
      Constructs an employee with a id, given name, salary, and
      bank account.
      @param id the id
      @param n the name
      @param s the annual salary
      @param a a pointer to the bank account
   */
   Employee(std::string id, string n, double s, BankAccount* a);
   /**
      Deposits one month's salary into the bank account.
   */
   void deposit_monthly_salary();
   /**
      Prints this employee's information to cout.
   */
   void print(std::ostream &output_file) const;

private:
   std::string id;
   string name;
   double salary;
   BankAccount* account;
};
#endif