/*
 * Inventory class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.2.0 
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
using namespace std;

class Inventory {
    private:
        string description;        // The item name
        double    cost;            // Cost of an item
        int       units;           // Number of units on hand
       
    public:
        // Default constructor
        Inventory() {
            description = " ";
            cost = 0.0;
            units = 0;
        }
        /**
         * Constructs an inventory with item description, cost, units
         * @param desc the item description
         * @param c the item cost
         * @param u the units at hand
         */      
        Inventory(string desc, double c, int u) {
            description = desc;
            cost = c;
            units = u;
        }
        /**
         * Sets the description of item
         * @param desc the description
         */
        void setDescription(string desc) { 
            description = desc; 
        }
        /**
         * Sets the cost of item
         * @param c the cost
         */
        void setCost(double c) { 
            cost = c; 
        }
        /**
         * Sets the units on hand
         * @param u the units
         */
        void setUnits(int u) { 
            units = u; 
        }
        /**
         * Gets the description of item
         * @return description the item description
         */
        string getDescription() const { 
            return description; 
        }
        /**
         * Gets the cost of item
         * @return cost the item cost
         */
        double getCost() const { 
            return cost; 
        }
        /**
         * Gets the units on hand
         * @return units the units on hand
         */
        int getUnits() { 
            return units; 
        }
};
#endif
