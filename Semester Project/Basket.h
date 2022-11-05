/*
 * ShoppingBasket class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.0.2 
 */

#ifndef SHOPPING_BASKET_H
#define SHOPPING_BASKET_H

#include <string>

#include "Inventory.h"

class Basket {
    private:
        std::string description;            // item description
        int numItems;                       // number of items in the basket
        double cost;                        // cost of items in the basket

    public:
        // Default constructor
        Basket() {                            
            description = " ";
            numItems = 0;
            cost = 0.0;
        }
        /**
         * Constructs a basket with an item quantity.
         * @param iQty the item quantity
         */        
        Basket(int iQty) {
            numItems = iQty;
        }
        /**
         * Sets values to description and cost
         * @param Inventory object the item 
         */
        void setItemInfo(const Inventory item) {
            description  = item.getDescription();
            cost         = item.getCost();
        }
        /**
         * Sets number of items
         * @param iQty the item quanitity
         */
        void setNumItems(int iQty) { 
            numItems += iQty; 
        }
        /**
         * Gets the item quantity
         * @return numItems the number of items
         */
        int getQuantity() const { 
            return numItems; 
        }
        /**
         * Gets the item description
         * @return description the item description
         */
        std::string getDescription() const { 
            return description; 
        }
        /**
         * Gets the item cost
         * @return cost the item cost
         */        
        double getCost() const { 
            return cost; 
        }
};
#endif