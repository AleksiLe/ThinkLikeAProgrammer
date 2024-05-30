#include <iostream>
using std::cin;
using std::cout;

struct listNode
{
    int value;
    listNode *next;
};
typedef listNode* numberCollection;

void addNumber(numberCollection& nc, int number)
{
    while(number != 0)
    {
        int digit = number % 10;
        if(nc == NULL)
        {
            listNode *first = new listNode;
            first->value = digit;
            first->next = NULL;
            nc = first;
        } else
        {
            listNode *newNode = new listNode;
            newNode->value = digit;
            newNode->next = nc;
            nc = newNode;
        }
            number /= 10;   
    }
}

void printNumberCollection(numberCollection nc)
{
    listNode *loopPtr = nc;
    while(loopPtr != NULL)
    {
        cout << loopPtr->value;
        loopPtr = loopPtr->next;
    }
    cout << '\n';
}

void deleteNumberCollection(numberCollection& nc)
{
    listNode *loopPtr = nc;
    while(loopPtr != NULL)
    {
        listNode *temp = loopPtr;
        loopPtr = loopPtr->next;
        delete temp;
    }
    nc = NULL;
}

int countNumberCollectionValue(numberCollection nc)
{
    int value = 0;
    listNode *loopPtr = nc;
    while(loopPtr != NULL)
    {
        value = value * 10 + loopPtr->value;
        loopPtr = loopPtr->next;
    }
    return value;
}

numberCollection sumNumberCollections(numberCollection nc1, numberCollection nc2)
{
    int sum = countNumberCollectionValue(nc1) + countNumberCollectionValue(nc2);
    numberCollection result = NULL;
    addNumber(result, sum);
    return result;
}

int main()
{
    numberCollection nc = NULL;
    int number;
    cout << "Enter a number: ";
    cin >> number;
    addNumber(nc, number);
    printNumberCollection(nc);
    numberCollection nc2 = NULL;
    addNumber(nc2, 1234);
    printNumberCollection(sumNumberCollections(nc, nc2));
    deleteNumberCollection(nc);
    return 0;
}