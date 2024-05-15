#include <iostream>
using std::cin;
using std::cout;

int main()
{
   int counter = -7;
    while(counter < 8)
    {
        for(int i = 0; i < (abs(counter) + 1) / 2 - 1; i++)
        {
            cout << ' ';
        }
        for (int j = 0; j < 9 - abs(counter) ; j++)
        {
            cout << '#';
        }
        cout << '\n';
        counter += 2;
    }
    return 0;
}

/*   
    int counter = -6;
    while(counter < 7)
    {
        for(int i = 0; i < abs(counter) / 2; i++)
        {
            cout << ' ';
        }
        for (int j = 0; j < 8 - abs(counter); j++)
        {
            cout << '#';
        }
        cout << '\n';
        counter += 2;      
   ##
  ####
 ######
########
 ######
  ####
   ##
        */