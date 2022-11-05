/*
 * Address class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.1.0 
 */

#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Address {
    private:
        string store_name;      // the store's name
        string street;          // the street where the store is located
        string state;           // the state where the store is located
        string zipcode;         // the zipcode where the store is located 
        string phone_number;    // the store's phone number
        
    public:
        // Default constructor
        Address() {
            store_name = " ";
            street = " ";
            state = " ";
            zipcode = " ";
            phone_number = " ";
        }
        /**
         * Constructs an address with a store name, street, state, zipcode, phone number.
         *
         * @param store_name the store name
         * @param street the street
         * @param state the last state
         * @param zipcode the annual zipcode
         * @param phone_number the phone_number
         */
        Address(const string &store_name, const string &street, const string &state, const string &zipcode, const string &phone_number) 
                : store_name(store_name), street(street), state(state), zipcode(zipcode), phone_number(phone_number) {}

        /**
         *  Gets the store name 
         *  @return store_name the store name
         */
        const string &getStoreName() const {
            return store_name;
        }
        /**
         *  Sets the store name 
         *  @param sn the store name
         */
        void setStoreName(const string &sn) {
            store_name = sn;
        }
        /**
         *  Gets the street  
         *  @return street the street 
         */
        const string &getStreetName() const {
            return street;
        }
        /**
         *  Sets the street  
         *  @param s the street 
         */
        void setStreetName(const string &s) {
            street = s;
        }
        /**
         *  Gets the state  
         *  @return state the state 
         */
        const string &getStateName() const {
            return state;
        }
        /**
         *  Sets the state  
         *  @param st the state 
         */
        void setStateName(const string &st) {
            state = st;
        }
        /**
         *  Gets the zipcode  
         *  @return zipcode the zipcode 
         */
        const string &getZipcode() const {
            return zipcode;
        }
        /**
         *  Sets the zipcode  
         *  @param z the zipcode 
         */
        void setZipcode(const string &z) {
            zipcode = z;
        }
        /**
         *  Gets the phone number  
         *  @return phone_number the phone number 
         */
        const string &getPhoneNumber() const {
            return phone_number;
        }
        /**
         *  Sets the phone number  
         *  @return pn the phone number 
         */
        void setPhoneNumber(const string &pn) {
            phone_number = pn;
        }        
        /**
         * Prints the store name, street, state, zipcode, phone number
         */
        void toString() { 
            ostringstream os;
            os << setw(23) << store_name << endl
            << setw(26) << phone_number << endl
            << setw(20) << street
            << ", " << state
            << ", " << zipcode << endl
            << "---------------------------------------\n" << endl;
            cout << os.str();
        }
};
#endif
