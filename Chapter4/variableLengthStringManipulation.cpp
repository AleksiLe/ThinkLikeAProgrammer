#include <iostream>
using std::cin;
using std::cout;

typedef char * arrayString;

int length(arrayString s)
{
    int length = 0;
    while(s[length] != 0)
    {
        length++;
    }
    return length;
}

char characterAt(const arrayString s, int position)
{
    return s[position];
}

void append(arrayString& s, char c)
{
    int oldLength = length(s);
    arrayString newS = new char[oldLength + 2];
    for(int i = 0; i < oldLength; i++)
    {
        newS[i] = s[i];
    }
    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s;
    s = newS;
}

void concatenate(arrayString& s1, arrayString& s2)
{
    int start = length(s1);
    int end = length(s2);
    arrayString newString = new char[end];
    for(int i = 0; i < start; i++) newString[i] = s1[i];
    for(int i = 0; i < end; i++) newString[i + start] = s2[i];
    delete[] s1;
    s1 = newString;
}

arrayString substring(arrayString s, int start, int length) //4-2
{
    arrayString substring = new char[length + 1];
    for(int i = 0; i < length; i++) substring[i] = s[i + start];
    substring[length + 1] = 0;
    return substring;
}

bool isSame(arrayString s1, arrayString s2)
{
    int len1 = length(s1);
    int len2 = length(s2);
    if(len1 != len2) return false;
    for(int i = 0; i < len1; i++)
    {
        if(s1[i] != s2[i]) return false;
    }
    return true;
}


void replaceString(arrayString& source, arrayString target, arrayString replace) //4-3
{
    int sourceLen = length(source);
    int targetLen = length(target);
    int replaceLen = length(replace);
    int diff = replaceLen - targetLen;
    int iter = 0;
    arrayString cut;
    while(source[iter] != 0)
    {
        arrayString cut = substring(source, iter, targetLen);
        if(isSame(cut, target))
        {
            arrayString newSource = new char[sourceLen + 1 + diff];
            for(int i = 0; i < iter; i++) 
            {
                cout << i << '\n';
                newSource[i] = source[i];
            }

            for(int i = 0; i < replaceLen; i++) 
            {
                newSource[i + iter] = replace[i];
            }
            for(int i = iter; i < sourceLen; i++) 
            {   
                newSource[i + replaceLen] = source[i + targetLen]; 
            }
            sourceLen += diff;
            iter += replaceLen;
            newSource[sourceLen + 1 + diff] = 0;
            delete[] source;
            source = newSource;
        } else
        {
            iter++;
        }
    } 
}

int main()
{
    arrayString greeting = new char[6];
    greeting[0] = 'H';
    greeting[1] = 'e';
    greeting[2] = 'l';
    greeting[3] = 'l';
    greeting[4] = 'o';
    greeting[5] = 0;
    cout << greeting << '\n';
    append(greeting, ' ');
    arrayString world = new char[6];
    world[0] = 'w';
    world[1] = 'o';
    world[2] = 'r';
    world[3] = 'l';
    world[4] = 'd';
    world[5] = 0;
    concatenate(greeting, world);
    cout << greeting << '\n';
    append(greeting, '!');
    cout << greeting << '\n';
    arrayString sub = substring(greeting, 6, 5);
    cout << sub << '\n';
    arrayString target = new char[3];
    target[0] = 'e';
    target[1] = 'l';
    target[2] = 0;
    arrayString replace = new char[2];
    replace[0] = 'a';
    //replace[1] = 'l';
    replace[1] = 0;
    replaceString(greeting, (arrayString)target, (arrayString)replace);
    cout << greeting << '\n';
    delete[] greeting;
    delete[] world;
    delete[] sub;
    return 0;
}