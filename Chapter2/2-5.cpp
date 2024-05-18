#include <iostream>
using std::cin;
using std::cout;


int main() 
{
    char digit;
    bool multipleByThree = false;
    int sum = 0;
    cout << "Enter ISBN-13: ";
    digit = cin.get();
    while(digit != 10) 
    {
        if(multipleByThree)
        {
            sum += (digit - '0') * 3;
            multipleByThree = false;
        } else
        {
            sum += digit - '0';
            multipleByThree = true;
        }
        digit = cin.get();
    }
    cout << "remainder: " << sum % 10 << '\n';
    return 0;
}