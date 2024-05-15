#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int emptySpacesTopDown = 12;
    int marks = 6;
    int marksMax = 8;
    bool second8marks = true;
    while(emptySpacesTopDown > -13)
    {
        //1, 2, 3, 3, 2, 1  -5 6-3 6-1 6-1 -3 -5
        for(int k = 0; k < (8 - abs(marks)) / 2 - 1; k++)
        {
            cout << ' ';
        }
        for(int i = 0; i < (8 - abs(marks)) / 2; i++)
        {
            cout << '#';
        }
        for(int j = 0; j < abs(emptySpacesTopDown); j++)
        {
            cout << ' ';
        }
        for(int l = 0; l < (8 - abs(marks)) / 2; l++)
        {
            cout << '#';
        }
        cout << '\n';
        if ((marks == 0) && (second8marks))
        {
            second8marks = false;
        } else
        {
            emptySpacesTopDown-=4;
            marks -= 2;
        }
        
    }
    return 0;
}
