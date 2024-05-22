#include <iostream>
using std::cin;
using std::cout;

struct student{
    int id;
    int grade;
};


int main()
{
    srand(time(0));
    const int ARRAY_SIZE = 10;
    student students[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        students[i].id = 15 - i;
        students[i].grade = i + 1;
    }
    for(int i = 0; i < ARRAY_SIZE; i++) cout << students[i].id<< ' ';
    cout << '\n';
    for(int i = 1;i < ARRAY_SIZE; i++)
    {
        for(int j = i; j > 0 && students[j-1].id > students[j].id; j--)
        {
            student temp = students[j-1];
            students[j-1] = students[j];
            students[j] = temp;
        }
    }    
    for(int i = 0; i < ARRAY_SIZE; i++) cout << students[i].id << ' ';
    cout << '\n';
    for(int i = 0; i < ARRAY_SIZE; i++) cout << students[i].grade << ' ';
    cout << '\n';
    for(int i = 1;i < ARRAY_SIZE; i++)
    {
        for(int j = i; j > 0 && students[j-1].grade > students[j].grade; j--)
        {
            student temp = students[j-1];
            students[j-1] = students[j];
            students[j] = temp;
        }
    }
    
    for(int i = 0; i < ARRAY_SIZE; i++) cout << students[i].grade << ' ';
    cout << '\n';
}