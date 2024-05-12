#include <iostream>
using std::cin;
using std::cout;

int doupleDigitValue(int digit)
{
    int doubledDigit = digit * 2;
    int sum = 0;
    if(doubledDigit >= 10)
    {
        sum = 1 + doubledDigit % 10;
    }
    else
    {
        sum = doubledDigit;
    }
    return sum;
}

int main()
{
    char digit;
    int oddSum = 0;
    int evenSum = 0;
    int position = 1;
    cout << "Enter a digit: ";
    digit = cin.get();
    while(digit != 10)
    {
        if(position % 2 == 0)
        {
            evenSum += digit - '0';
            oddSum += doupleDigitValue(digit - '0');
        }
        else
        {
            oddSum += digit - '0';
            evenSum += doupleDigitValue(digit - '0');
        }
        digit = cin.get();
        position++;
    }
    cout << evenSum << " " << oddSum << "\n";
    if((position - 1) % 2 == 0)
    {
        if (evenSum % 10 == 0)
        {
            cout << "Checksum is valid.\n";
        }
        else
        {
            cout << "Checksum is invalid.\n";
        }
    }
    else
    {
        if (oddSum % 10 == 0)
        {
            cout << "Checksum is valid.\n";
        }
        else
        {
            cout << "Checksum is invalid.\n";
        }
    }
    return 0;
}