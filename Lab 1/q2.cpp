/*
 * This C++ program takes an input between 0 & 1000000 non-inclusive
   and print a sequence of numbers base on the given recursive relation.
 * CECS 275 - Fall 2021 
 * @author Dylan Dang
 * @author Dong-woo Shin
 * @version 1.0.0 <----- Version
 *
 */

#include <iostream>

using namespace std;

int main() {
    while (true) {// using while loop, it will countinuously asks the user.
        int n; // number chosen by user input
        int counter = 1; // counts the number of integers
        cout << "Enter a number between 0 and 1000000 non-inclusive" << endl;
        cin >> n;
        cout << "n = " << n << "\n";
        cout << n;
        
        while (n > 1 ) { 
            if (n % 2 == 0) { // when user put even number.
                n = n / 2;
                cout << ", " << n;
                counter ++; // count will be increased every time until it goes out from the while loop.
            } 
            else {// when user put odd number.
                n = 3*n + 1;
                cout << ", " << n;
                counter ++;
            }
        }
        cout << "\nThere are " << counter << " numbers" << endl;
    }
}