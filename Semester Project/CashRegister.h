/*
 * CashRegister class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.5 
 */

#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include <iomanip>
#include <iostream>
#include <string>

#include "CashRegister.h"
#include "Inventory.h"

class CashRegister {
    private:
        int    quantity;            // Item quantity to be bought
        double cost;                // Cost of the item
        double taxRate;             // Tax rate (6%)
        double unitPrice;           // The unit price of an item
        double salesTax;            // The sales tax (6%)
        double taxTotal;            // The tax total (sales tax)
        double subTotal;            // The subtotal (cost)
        double total;               // The grand-total

    public:
        /**
         * Constructs an inventory with tax rate
         * @param rate the tax rate
         */     
        CashRegister(double rate = 0.06) {
            taxRate = rate;
            unitPrice = 0.0;
            salesTax = 0.0;
            subTotal = 0.0;
            taxTotal = 0.0;
            total = 0.0;
        }

        // Accessors
        void setCost(const Inventory item);
        bool isQuantity(Inventory item, int iQty);
        void updateRegister();
        void updateUnits(Inventory &item);
        void displayReceipt();

        /**
         *  Gets the item cost
         *  @return the item cost
         */
        double getCost() const { 
            return cost; 
        }
        /**
         *  Gets the item unit price
         *  @return getCost() the item cost
         */
        double getUnitPrice() const { 
            return (getCost()); 
        }
        /**
         *  Gets the sale tax
         *  @return (getCost() * taxRate) the sale tax
         */
        double getSalesTax() const { 
            return (getCost() * taxRate);
        }
        /**
         *  Gets the total tax
         *  @return getSalesTax() the total tax
         */
        double getTaxTotal() const { 
            return (getSalesTax()); 
        }
        /**
         *  Gets the sub total
         *  @return getCost() the sub total
         */
        double getSubTotal() const { 
            return (getCost()); 
        }
        /**
         *  Gets the total cost
         *  @return (getSubToal() * getSalesTax) the total cost
         */
        double getTotal() const { 
            return (getSubTotal() + getSalesTax()); 
        }
        /**
         *  Gets the item quantity
         *  @return quantity the item quantity
         */
        int getQuantity() const { 
            return quantity; 
        }
        /**
         *  Gets the item unit price for receipt
         *  @return unitPrice the item unit price
         */
        double recUnitPrice() const { 
            return unitPrice; 
        }
        /**
         *  Gets the sales tax for receipt
         *  @return salesTax the sales tax
         */
        double recSalesTax() const { 
            return salesTax; 
        }
        /**
         *  Gets the total tax for receipt
         *  @return taxTotal the total tax
         */
        double recTaxTotal() const { 
            return taxTotal; 
        }
        /**
         *  Gets the subtotal for receipt
         *  @return subTotal the subtotal
         */
        double recSubTotal() const { 
            return subTotal; 
        }
        /**
         *  Gets the total cost for receipt
         *  @return total the total cost
         */
        double recTotal() const { 
            return total; 
        }
};

/**
 * Determines whether the value passed to it is valid
 * If it is valid, the value is assigned to the quantity member and returns true
 * If number of available units is 0, quantity is assigned 0, output out of stock message, returns true
 * If value entered is greater than quantity available, ouput item and quantity available, retuns false
 * @param Inventory object the item
 * @param integer value the amount the customer wants to purchase
 * @return true if value is valid, false if value is invalid
 */     
bool CashRegister::isQuantity(Inventory item, int iQty) {
    if (item.getUnits() > 0 && iQty <= item.getUnits()) { // make sure value inputted is valid
        quantity = iQty; // sets quantity to inputted value
        return true;
    } else if (item.getUnits() == 0) { 
        quantity = 0;
        std::cout << "\n" << item.getDescription() << " Out Of Stock\n"; // output out of stock if quantity is 0
        return true;
    } else {
        std::cout << "\nItem: " << item.getDescription() << "\n"; // if invalid output name and quantity
        std::cout << "Availabe quantity: " << item.getUnits() << "\n";
        return false;
    }
    return false;
}
/**
 * Sets the cost for an item
 * The value to be assigned to the cost is passed to it by the item object
 * @param Inventory object the item
 */ 
void CashRegister::setCost(const Inventory item) {
    cost = item.getCost();
}
/**
 * Sets the number of units on hand stored in the item object
 * The new value is calculated by subtracting the quantity of items 
 * bought from the units on hand stored in the item object
 * @param reference to an Inventory object the item
 */ 
void CashRegister::updateUnits(Inventory &item) {
    item.setUnits(item.getUnits() - getQuantity());
}
/**
 * Keeps a running total of taxes and prices while items are added to the basket
 * All values are multiplied by the quantity being purchased
 */ 
void CashRegister::updateRegister() { 
    unitPrice += getUnitPrice() * getQuantity();
    salesTax  += getSalesTax()  * getQuantity();
    subTotal  += getSubTotal()  * getQuantity();
    taxTotal  += getTaxTotal()  * getQuantity();
    total     += getTotal()     * getQuantity();
}
/**
 * Outputs to screen with the unit price, sales tax, total tax,
 * subtotal, total cost
 */ 
void CashRegister::displayReceipt() { // formatting prices for receipt
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << std::left << "Sales-Tax (6%): " << std::setw(18)
              << std::right << "$ " << std::setw(6)
              << recSalesTax() << "\n";

    std::cout << std::left << "Tax-Total: " << std::setw(23)
              << std::right << "$ " << std::setw(6)
              << recTaxTotal() << "\n\n";

    std::cout << std::left << "Sub-Total: " << std::setw(23)
              << std::right << "$ " << std::setw(6)
              << recSubTotal() << "\n";

    std::cout << std::left << "Purchase Price: " << std::setw(18)
              << std::right << "$ " << std::setw(6)
              << recTotal() << "\n";

    std::cout << "\n\t      THANK YOU FOR  \n"
              << "\t  SHOPPING AT WALMART!" << endl;
}
#endif