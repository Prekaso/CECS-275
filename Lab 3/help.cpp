//including the header files
#include<iostream>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

//implementing the parseString method to convert the line to vector<int>
vector<int> parseString(string line){
   //getting the size of the line, and declaring the variables
   int n = line.size(), num;

   //creating the vector array to store all the integers 
   vector<int> array;
   string word = "";
   //iterating to all the numbers storing to the vector
   for(int i = 0; i < n; i++){
      //if we got the space, than continue
      if(line[i] == ' ')
         continue;
      //if we got the sequence ', ' than break and word and store it into array
      if(line[i] == ',' && line[i+1] == ' '){
         //convert the  integer string to integer
         num = stoi(word);
         word = "";
         //pushing into array
         array.push_back(num);
      }else{
         //else storing into word
         word += line[i];
      }
   }
   //adding the last word to the array
   array.push_back(stoi(word));
   return array;
}

//implementing the calculate function, to print into the file
void calculate(vector<int> arr){
   int n = arr.size();
   //creating a variable map to get the frequency of the elements
   map<int, int> mp;
   for(int i = 0; i < n; i++){
      //if the element is not in the map, than store it with 1 frequency
      if(mp.find(arr[i]) == mp.end())
         mp[arr[i]] = 1;
      else
      //else increment the frequency
         mp[arr[i]] += 1;
   }
   //creating a file named frequency to store the results
   ofstream fout("frequency.txt");
   //checking if the file is opened or not
   if(fout){
      //iterating 1 to 50
      for(int i = 1; i <= 50; i++){
         fout << i << ":";
         //checking and pusing the count to the file
         if(mp.find(i) != mp.end()){
            int freq = mp[i];
            //storing the * variable into the file.
            for(int j = 0; j < freq; j++)
               fout << "*";
            //now fixing the frequency into the file
            fout << " (" << freq << ")" << endl;
         }else
            fout << " (0)" << endl;
      }
      //if the array size is one, than it executes the else statment
      if(arr.size() > 1)
      //print the count of the number into the file
         fout << "There are " << arr.size() << " numbers." << endl;
      else
         fout << "There is 1 number." << endl;
      
      //printing the max and min element to the file
      fout << "The maximum is " << *max_element(arr.begin(), arr.end()) << "." << endl;
      fout << "The minimum is " << *min_element(arr.begin(), arr.end()) << "." << endl;
   }else
      cout << "Error in creating file - frequency.txt";
}

//implementing the main function
int main(){
   //opening the file data.txt to get the input
   ifstream fin("data.txt");
   //checking if the file is opened or not
   if(fin){
      string line;
      //getting the input from the file
      getline(fin, line);
      //calling the parseString and calculate 
      vector<int> arr = parseString(line);
      calculate(arr);
   }else{
      cout << "data.txt -> Error in File Opening..";
   }
   return 0;
}