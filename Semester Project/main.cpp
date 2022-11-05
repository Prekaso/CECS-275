/*
 * This C++ program's purpose is to: 
 * - output a receipt of purchase at a marcket or a convenience store
 * - create cash register that includes at least 5 different classes
 * - manage an inventory system
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.3.0 
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <array>

#include "Basket.h"
#include "CashRegister.h"
#include "Inventory.h"
#include "Barcode.h"
#include "Address.h"

// global variable
const int NUM_ITEMS = 6;

// function prototypes
void displayItems(std::array<Inventory, NUM_ITEMS>);
void shoppingBasket(std::array<Inventory, NUM_ITEMS> &, std::array <Basket, NUM_ITEMS> &, CashRegister &);
void displayBasket(const std::array <Basket, NUM_ITEMS>);

int main()
{
    CashRegister sales;
    Address addy("Walmart", "8885 N Florida Ave", "Tampla FL", "33604", "(983) 932-0562");
    Barcode bc;

    // creating inventory item objects                                                   
    std::array<Inventory, NUM_ITEMS> items { Inventory("Apples", 0.95, 10),  // name, price, quantity
                                             Inventory("Marker", 1.75, 15),
                                             Inventory("Drills", 20.99, 10),
                                             Inventory("Shirts", 7.95, 20),
                                             Inventory("Shampoo", 24.97, 15),
                                             Inventory("Pencils", 2.50, 25) };
   
    // basket array to hold items
    std::array <Basket, NUM_ITEMS> content{ };

    // keeps track of customer response
    char yes_no = ' ';
    string cash_or_credit = " ";

    // holds customer credit card info
    string credit_number = " ";

    // keeps track of cash needed to pay for item
    double cash = 0;
    double cash_count = 0;

    std::cout << "\t\t   WELCOME TO WALMART\n\n";

    do {
        shoppingBasket(items, content, sales);

        std::cout << "\nDo you wish to buy another item? (y/n) ";
        std::cin >> yes_no;
        std::cout << "\n";

        // makes sure customer answers with a valid responses
        while (toupper(yes_no) != 'Y' && toupper(yes_no) != 'N') {
            std::cout << "\nDo you wish to buy another item? (y/n) ";
            std::cin >> yes_no;
        }

        // if customer wants to purchase another item
        if (toupper(yes_no) == 'N')
        {   
            // asks if customer wants to pay with cash or credit
            std::cout << "Would you like to pay with cash or credit? " << endl; 
            std::cin >> cash_or_credit;

            // makes sure customer answers with a valid response
            while (cash_or_credit != "cash" && cash_or_credit != "credit") {
                    std::cout << "Invalid payment option. " << endl << "cash or credit? ";
                    std::cin >> cash_or_credit;
            }

            // if customer wants to pay with cash
            if (cash_or_credit == "cash") {

                // show customer the total price including tax to pay 
                std::cout << "\nTotal Due (including sales tax): $" << sales.recTotal() << endl << endl;
                std::cout << "Please insert cash. " << endl;
                std::cin >> cash;
                cash_count += cash;

                // makes sure the customer pays the correct amount 
                while (cash_count < (sales.recTotal()-0.01)) {
                    std::cout << "Please insert more cash. " << endl;
                    std::cin >> cash;
                    cash_count += cash;
                }
                std::cout << "PRINTING RECEIPT..." << endl;

            // if customer wants to pay with credit
            } else if (cash_or_credit == "credit") {
                std::cout << "\nTotal Due (including sales tax): $" << sales.recTotal() << endl << endl;
                std::cout << "Please enter credit card number. " << endl;
                std::cin >> credit_number;

                // makes sure the customer inputs valid credit card number, output denied
                while (credit_number.length() != 16) {
                    std::cout << "CARD DENIED! INVALID CREDIT CARD NUMBER! " << "MUST BE 16 DIGITS." << endl;
                    std::cin >> credit_number;
                }
                // output approved if card number is valid
                if (credit_number.length() == 16) {
                    std::cout << "CARD APPROVED!\n" << "PRINTING RECEIPT..." << endl;
                } 
            } 

            // printing store address, items purchased, receipt, and barcode   
            std::cout << endl;
            addy.toString();
            displayBasket(content);
            sales.displayReceipt();
            std::cout << endl;
            bc.printBarcode();
            
           
        }
    } while (toupper(yes_no) != 'N');

    std::cin.get();
    std::cin.ignore();

    return 0;
}

/**
 * Displays the item names, units on hand, and item cost
 * @param pointer to an Inventory object
 */ 
void displayItems(std::array<Inventory, NUM_ITEMS> item) {
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "Item ID\t\t" << "Description\t\t" << "Inventory\t" << "Cost\n\n";

    // iterate through items in array and display them
    for (int i = 0; i < NUM_ITEMS; i++) {
        if (item[i].getUnits() > 0) {
            std::cout << (i + 1) << "\t\t"
                       << item[i].getDescription() << "\t\t\t"
                         << item[i].getUnits() << "\t\t"
                         << item[i].getCost() << "\n";
        } else {
            // once customer bought up the entire stock 
            // output "Out of stock" instead of 0
            std::cout << (i + 1) << "\t\t"
                       << item[i].getDescription() << "\t\t\t"
                         << "Out of stock\t"
                         << item[i].getCost() << "\n";
        }
    }
}

/**
 * Asks the customer to enter the item ID and quantity he/she wishes to purchase
 * This information is processed by functions of the sales and basket classes
 * @param reference to an array of item objects
 * @param reference to an array of basket objects
 * @param reference to a sales object
 */ 
void shoppingBasket(std::array<Inventory, NUM_ITEMS> &item, std::array <Basket, NUM_ITEMS> &basket, CashRegister &sales) {
    int iQty = 0;
    int iID = 0;

    displayItems(item);

    std::cout << "\nWhich item do you wish to buy? (1 - 6) ";
    std::cin >> iID;

    while (iID <= 0 || iID > NUM_ITEMS) {
        std::cout << "\nWhich item do you wish to buy? (1 through " << NUM_ITEMS << ") ";
        std::cin >> iID;
    }

    // gets the amount the customer wants to purchase and subtract from total quantity in inventory
    std::cout << "How many items do you wish to buy? ";
    std::cin >> iQty;

    while (sales.isQuantity(item[iID - 1], iQty) == false) {
        std::cout << "How many items do you wish to buy? ";
        std::cin >> iQty;
    }   

    // update units on hand and prices after customer takes items from inventory 
    sales.setCost(item[iID-1]);
    sales.updateUnits(item[iID - 1]);
    sales.updateRegister();

    // update basket with new items
    basket[iID - 1].setItemInfo(item[iID-1]);
    basket[iID - 1].setNumItems(sales.getQuantity());
}

/**
 * Outputs to the screen the item name, quantity and cost of tiems currently in the basket
 * @param array of basket objects
 */ 
void displayBasket(const std::array <Basket, NUM_ITEMS> content) {

    // formatting the output of what the customer has in their basket
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    for (int i = 0; i < NUM_ITEMS; i++) {
        if (content[i].getQuantity() > 0) {
            std::cout << "ITEM NAME: " << std::setw(28) << content[i].getDescription() << "\n"
                      << "QUANTITY:  " << std::setw(28) << content[i].getQuantity() << "\n"
                      << "COST: "      << std::setw(26)
                      << "$"           << std::setw(7) << (content[i].getCost() * content[i].getQuantity()) << "\n\n";
        }   
    }
    std::cout << "---------------------------------------\n\n";
}