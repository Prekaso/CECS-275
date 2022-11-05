/*
 * Finding the most frequent substring in message
 * CECS 275 - Spring 2022 
 * @author Dylan Dang
 * @author Dongwoo-Shin
 * @version 1.0.0 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector <int> storeVal(string line) 
{
    vector <int> numbers;
    string character = "";
    int num;

    replace(line.begin(), line.end(), ',', ' '); // getting rid of commas separating the numbers
    
    for(int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ' && line[i+1] == ' ')
        {
            num = stoi(character); // converting the string number into an integer
            character = ""; // after converting, get rid of older string numbers inside
            numbers.push_back(num); // move the newly converted integer into the vector
        }
        else
        {
            character += line[i]; // get last integer in the string into the array
        }
    }
    numbers.push_back(stoi(character)); // converting into integer and then pushing last number in string into the vector

    return numbers;
}

void freqAndPrint(vector <int> numbers)
{
    int max = 0;
    int min;
    double average = 0.0; // set to double for decimals
    int counter = 0;
    int frequency = 0;

    sort(numbers.begin(), numbers.end()); // sorting the vector in ascending order

    for (int n : numbers)
    {
        if (n < min || min == -1) // finds the minimum value
        {
            min = n;
        }

        if (n > max)  // finds the maximum value  
        {
            max = n;
        }
        
        average += n; // sums the numbers and used for the average calculation below
        counter++; // keeps count of how many numbers are in the vector. Used in average calculation below.
    }

    average = average / counter;
    average = round(average*100)/100;

    fstream frequency_file;
    frequency_file.open("frequency.txt");
    

    if (frequency_file.is_open())
    { 
        for (int i = 0; i <= max; i++)
        {
            frequency_file << i << ": "; // print colons for formatting
            
            while (numbers[i] == i) // if element in vector is the same, increase frequency   // does not work as intended
            {
                frequency_file << "*"; // print * everytime there is an occurence of the same number
                frequency++;  // increment frequencyeverytime there is an occurence of the same number
                numbers[i]++; // increment to next element to check for occurences
            }
            frequency_file << "(" << frequency << ")"; // output frequency
            frequency = 0; // reset frequency after finish counting occurences of one number
            frequency_file << endl; // add new line
        }

        frequency_file << "There are " << counter << " " << "numbers." << endl;
        frequency_file << "The maximum is: " << max << "." << endl;
        frequency_file << "The minimum is: " << min << "." << endl;
        frequency_file << "The average is: " << average << "." << endl;
    }
    else
    {
        cout << "File doesn't exist." << endl; // executes if file does not exist
    }
}   

int main() 
{
    ifstream data_file;
    data_file.open("data.txt");

    string line;

    if (data_file.is_open())  // check if data file is open
    {
        while (getline(data_file, line)) // reading the line of the file
        {
            data_file >> line;  // copying contents into string line
        }
        data_file.close(); // close data file after reading all of the contents
    }
    else
    {
        cout << "File doesn't exist." << endl; // executes if file does not exist
    }

    vector <int> numbers = storeVal(line); // vector holds the contents in string line

    freqAndPrint(numbers);

    return 0;
}