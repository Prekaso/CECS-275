/*
 * Barcode class header & implementation
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo Shin  
 * @version 1.1.0 
 */

#ifndef BARCODE_H
#define BARCODE_H

#include <iostream>
#include <io.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Barcode {
private:
    int returnval, str2int;
    wchar_t* c;
    wchar_t strU[100] = L"";

public:
    Barcode() {}
     /**
     * Prints the barcode using unicode
     * Unicode pattern is random
     */
    void printBarcode() { 
        // allow the use of Unicode
        _setmode(_fileno(stdout), 0x00020000);

         // make use of the computer's internal clock to generate random values
        srand (time(NULL));

        for (unsigned int i = 0; i < 12; i++) {
            // get random number 
            str2int = rand() % 10 ;

            // output different unicode values up to 12 times depending on random value
            switch (str2int) {
            case 0:
            c = wcscat(strU,L"\x2502\x2588\x2502");
            break;
            case 1:
            c = wcscat(strU,L"\x2588\x2502\x2588 ");
            break;
            case 2:
            c = wcscat(strU,L"\x2502\x2588\x2502");
            break;
            case 3:
            c = wcscat(strU,L"\x2588\x2588\x2502");
            break;
            case 4:
            c = wcscat(strU,L"\x2502\x2588 ");
            break;
            case 5:
            c = wcscat(strU,L"\x2588 \x2502");
            break;
            case 6:
            c = wcscat(strU,L"\x2502\x2502\x2502");
            break;
            case 7:
            c = wcscat(strU,L"\x2502 \x2588");
            break;
            case 8:
            c = wcscat(strU,L"\x2502 \x2502\x2588 ");
            break;
            case 9:
            c = wcscat(strU,L"\x2588\x2502\x2588 ");
            break;
            }
        }

        wcout << c <<endl;
        wcout << c <<endl;
        wcout << c <<endl;
    }
};
#endif

