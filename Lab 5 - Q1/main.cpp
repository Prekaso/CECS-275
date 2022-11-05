#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
int main()
{
    cout << "---------------------------------------------------------------------------------" << endl;

    std::string str = Date::listAllDates(2000);
    std::cout<<str;    
    return 0;
}
