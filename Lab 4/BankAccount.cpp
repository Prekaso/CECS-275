/*
 * Bank account class implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.0 
 */

#include "BankAccount.h"
#include <iostream>

using namespace std;

/**
 * constructs a bank account with a $2000 balance.
 */
BankAccount::BankAccount()
{
    balance = 2000;
}

/**
 * Deposits money into this account.
 *
 * @param amount the amount to deposit
 */
void BankAccount::deposit(double amount)
{
    balance += amount;
}

/**
 * Withdraws money from this account.
 *
 * @param amount the amount to withdraw
 */
void BankAccount::withdraw(double amount)
{
    // make sure that user doesn't withdraw more money than they have in their account
    if (amount > balance)
        cout << "You do not have enough money in your account." << endl;
    else
        balance -= amount;
}

/**
 * Gets the balance of this account
 *
 * @return double the balance
 */
double BankAccount::get_balance() const
{
    return balance;
}

/**
 * Gets the id of this account
 *
 * @return std::string the id
 */
std::string BankAccount::get_id() const
{
    return id;
}

/**
 * Sets the id of this account
 *
 * @param id the id
 */
void BankAccount::set_id(std::string id)
{
    this->id = id;
}