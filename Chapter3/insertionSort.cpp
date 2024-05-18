#include <iostream>
using std::cin;
using std::cout;

int main()
{
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {6,1,-4,2,7,5,9,3,11,8};
    for(int i = 1;i < ARRAY_SIZE; i++)
    {
        for(int j = i; j > 0 && intArray[j-1] > intArray[j]; j--)
        {
            int temp = intArray[j-1];
            intArray[j-1] = intArray[j];
            intArray[j] = temp;
        }
    }
    for(int i = 0; i < ARRAY_SIZE; i++) cout << intArray[i] << ' ';
}
