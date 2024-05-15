#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int counter = 0;
    bool multiplyByTen = false; //Keeps track of multiply
    char digit;
    char state = 'u'; //u for uppercase, l for lowercase, p for punctuation
    int modulo = 27;
    std::string message = "";
    cout << "Enter a decoded message: ";
    digit = cin.get();
    while(digit != 10)
    {
        //ask number until comma
        if(digit != 44)
        {
            counter = counter * 10 + (digit - '0');
        } else
        {
            //check action
            counter = counter % modulo;
            if(counter == 0)
            {
                if (state == 'u')
                {
                    state = 'l';
                } else if (state == 'l')
                {
                    state = 'p';
                    modulo = 9;
                } else
                {
                    state = 'u';
                    modulo = 27;
                }
            } else
            {
                if (state == 'u')
                {
                    message += char(counter + 64);
                } else if (state == 'l')
                {
                    message += char(counter + 96);
                } else
                {
                    switch(counter)
                    {
                        case 1:
                            message += '!';
                            break;
                        case 2:
                            message += '?';
                            break;
                        case 3:
                            message += ',';
                            break;
                        case 4:
                            message += '.';
                            break;
                        case 5:
                            message += ' ';
                            break;
                        case 6:
                            message += ';';
                            break;
                        case 7:
                            message += '"';
                            break;
                        case 8:
                            message += '\'';
                            break;
                    }
                }
            }
            //reset to start
            counter = 0;
        }
        digit = cin.get();

        
        
    }
    cout << message << "\n";
    return 0;
}