#include <iostream>
using std::cin;
using std::cout;

bool isSorted(int array[], int size)
{
    for(int i = 1; i < size; i++)
    {
        if(array[i-1] > array[i]) return false;
    }
    return true;
}

int main()
{
    const int size = 10;
    int array[size];
    cout << "Enter 10 elements of the array: ";
    for(int i = 0; i < size; i++) cin >> array[i];
    if(isSorted(array, size)) cout << "The array is sorted.\n";
    else cout << "The array is not sorted.\n";
}