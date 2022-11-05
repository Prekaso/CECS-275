/*
 * Reverse string recursion
 * CECS 275 - Spring 2022 
 * @author Dongwoo Shin 
 * @author Dylan Dang 
 * @version 1.0.0 
 */

#include <bits/stdc++.h>
using namespace std;

// Function to reverse a string
void reverseStr(string& str, int half)
{
    int n = str.length(); //count the number of the string.
    int i = 0;            
    string str_save;
    // Swap character starting from half and n-i-1(end of the string)
    str_save = str; //I made a copy of string to keep original string.
    while (half < n-i-1) // it will stop when half is same as n-i-1.
    {                   
        str[half] = str_save[n - i - 1 ];//first, I change half position of the string with end of sting from copied one. 
        str[n - i - 1] = str_save[half];//next, I change end of the string with half position of the string from copied one.
        half++;                          
        i++;
    }
}

 
int main(){
    string name;

    int number_of_string;
    int step = 1;
    while(true){
        cout << "Enter anything: ";
        cin >> name;
        number_of_string = name.length();
        int half = number_of_string/2;
        cout << "You entered: '" << name <<  "'"  << endl;
        while(half < number_of_string)
        { //we made a two possible cases, one is when the number of string is even, and the other is odd.
            if ( (0 < number_of_string) && (number_of_string < 4)) //In case of user input less then 3 number of string.
            { 
                reverseStr(name,half);//this function is swap the two position of the string.
                cout << "Step " <<step <<": "<< name << endl;
                half = number_of_string; // this will stop the while loop
            }
            else if (number_of_string%2 == 0)
                {
                    reverseStr(name,half); 
                    cout << "Step " <<step <<": "<< name << endl;
                    half = half + number_of_string/4; //after first step we need next half oposition so that it keeps the half of previous step.
                    step++;
                }
                else
                {
                    half = half +1; // we need to add 1 when the number of string is odd otherwise first half will be shorter then the rest.
                    reverseStr(name,half);//such as 1234567 => 1237654
                    cout << "Step " <<step <<": "<< name << endl;
                    half = half +1 + number_of_string/4;//same as the even but we need to substract 1 because we added 1 for the first swap.
                    step++;
                }
        }
        step = 1;    //reset the step for the next try.
    }
}
