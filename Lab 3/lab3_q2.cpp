/*
 * Reversing and concatenating strings
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo-Shin
 * @version 1.0.0 
 */

#include <iostream>
#include <cstring>

using namespace std;

void reverse(char s[])
{
    string reverse;

    for (int i = strlen(s) - 1; i >= 0; i--) // i is set to string length to start from the end of the string and decrement to the first element
    {
        reverse = reverse + s[i]; // concatenating the reversed characters
        
    }
    cout << "Reverse String: " << reverse << endl;
}

void concat(const char a[], const char b[], char result[],int result_maxlength)
{
    int a_length = strlen(a) - 1;
    int remaining_size = result_maxlength - a_length;

    if (result_maxlength <= a_length) // do this if the max length given by user is less than or equal to the first character string's length
    {
        strncpy(result, a, result_maxlength); // copy contents from character string a into result
    }
    else // do this if the max length given by user is greater than or equal to the first character string's length
    {
        strncpy(result, a, a_length); // copy contents from character string a into result
        char temp[80]; // create temp character string to hold the remaining characters of character string b
        strncpy(temp, b, remaining_size); // copy contents from character string b into temp
        strcat(result, temp); // concatenate temp to result
    }
    
    cout << result << endl; 
}

int main() 
{
    char a[80]; // set character string a to hold 79 elements
    char b[80]; // set character string b to hold 79 elements
    int max_length; // max length for concatenating
    char result[80]; // character string that holds the result of concatenation

    cout << "Please enter the first string: " << endl; // asks user for character string a
    cin >> a;

    cout << "Please enter the second string: " << endl; // asks user for character string b
    cin >> b;

    cout << "Please enter the max length: " << endl; // asks user for max length for concatenation
    cin >> max_length;
    
    reverse(a); // use reverse function for character string a 
    reverse(b); // use reverse function for character string b

    concat(a, b, result, max_length); // use concatenation funciton for both character strings
    return 0;
}