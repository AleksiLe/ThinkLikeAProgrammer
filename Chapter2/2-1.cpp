#include <iostream>
using std::cin;
using std::cout;

int main()
{
   int counter = 8;
    while(counter > 1)
    {
        for(int i = 0; i < (8 - counter) / 2; i++)
        {
            cout << ' ';
        }
        for (int j = 0; j < counter; j++)
        {
            cout << '#';
        }
        cout << '\n';
        counter -= 2;
    }
    return 0;
}