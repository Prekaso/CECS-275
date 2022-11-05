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

using namespace std;

void freqSubstr(vector <string> &lines) 
{
    fstream result_file;
    result_file.open("result.txt");

    string num;
    int n;
    int max = 0;
    string output;
    string temp_str;
    string temp;

    for (auto &s : lines)
    {
        num = s.substr(0, 1);
        n = stoi(num);
        s = s.erase(0,2);
        int len = s.length();
        
        for (int i = 0; i <= len - n; i++)
        {
            temp = s.substr(i, n);
            int temp_count = 0;
            
            for (int j = i; j <= len - n; j++)
            {
                string temp2 = s.substr(j,n);
                if (s.substr(j,n) == temp)
                {
                    temp_count++;
                }
            }
            if (temp_count > max)
            {
                max = temp_count;
                output = temp;
            }
        }
        result_file << output << endl;
        max = 0;
    }
}

int main() 
{
    ifstream input_file;
    input_file.open("input.txt");

    fstream result_file;
    result_file.open("result.txt");

    string line;
    vector<string> lines;

    if (input_file.is_open()) 
    {
        
        while(getline(input_file, line))
        {   
            lines.push_back(line);
        }
    
        input_file.close();
    }

    freqSubstr(lines);

    return 0;
}