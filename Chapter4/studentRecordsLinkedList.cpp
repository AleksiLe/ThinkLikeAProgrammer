#include <iostream>
using std::cin;
using std::cout;

struct listNode 
{
    int studentNum;
    int grade;
    listNode *next;
};
typedef listNode* studentCollection;

void removeRecord(studentCollection& sc, int studentNum)
{
    listNode *loopPtr = sc;
    listNode *prevPtr = NULL;
    while(loopPtr != NULL && loopPtr->studentNum != studentNum)
    {
        prevPtr = loopPtr;
        loopPtr = loopPtr->next;
    }
    if(loopPtr == NULL) return;
    if(prevPtr == NULL) sc = sc->next;
    else prevPtr->next = loopPtr->next;
    delete loopPtr;
}

void addRecord(studentCollection& sc, int studentNum, int grade)
{
    if(sc == NULL)
    {
        listNode *first = new listNode;
        first->studentNum = studentNum;
        first->grade = grade;
        first->next = NULL;
        sc = first;
    } else
    {
        listNode *newNode = new listNode;
        newNode->studentNum = studentNum;
        newNode->grade = grade;
        newNode->next = sc;
        sc = newNode;
    }
}

double getAverage(studentCollection sc)
{
    if(sc == NULL) return 0.0; // return 0.0 if the list is empty (no students in the list)
    int count = 0;
    int sum = 0;
    listNode *loopPtr = sc;
    while(loopPtr != NULL)
    {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    return (double)sum/count;
}

void deleteList(studentCollection& sc)
{
    while(sc != NULL)
    {
        listNode *temp = sc;
        sc = sc->next;
        delete temp;
    }
}

int main()
{
    studentCollection sc = NULL;
    addRecord(sc, 1, 10);
    addRecord(sc, 2, 13);
    addRecord(sc, 3, 11);
    cout << getAverage(sc) << '\n';
    removeRecord(sc, 2);
    cout << getAverage(sc) << '\n';
    deleteList(sc);
}