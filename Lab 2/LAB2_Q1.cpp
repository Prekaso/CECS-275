/*
 * Adding each digit of number.
 * CECS 275 - Spring 2022 
 * @author Dongwoo Shin 
 * @author Dylan Dang 
 * @version 1.0.0 
 */
#include <iostream>
using namespace std;
 

int getSum(int n){
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

 

int main(){
    int number;
    while (true)
    {
        cout << " Enter  a positive number." << endl;
        cin >> number;
        if (number == 0) 
        {
            cout << "You have entered zero. Please try again!" << endl;
            continue;   
        }
        else if (number < 0)
        {
            cout << "You have entered a negative number. Please try again!" << endl;
            continue;
        }
        else
        {   
            cout << "You have entered " << number << "." << endl;
            cout << "The sum of the number " <<number <<" is " << getSum(number) << "."<< endl;

        }




    }
}