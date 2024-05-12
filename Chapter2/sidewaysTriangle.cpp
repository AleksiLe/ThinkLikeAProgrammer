#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int value = 4;
    for(int i = -3; i < 4; i++)
    {
        for(int j = 0; j < (value - abs(i)); j++)
        {
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}