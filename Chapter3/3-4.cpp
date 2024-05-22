#include <iostream>
using std::cin;
using std::cout;

int main() //decoder
{
    std::string plainText = "HELLO WORLD!";
    std::string cipherText;
    const std::string alphabet = "ZMKXYABFCQGWITJNRLEVDOPUSH";
    cout << "Plaintext: " << plainText << '\n';
    for(char& c : plainText)
    {
        if (c - 64 < 0 || c - 64 > 26) cipherText += c;
        else
        {
            int index = alphabet.find(c);
            cipherText += 'A' + index;
        }
    }
    cout << "Ciphertext: " << cipherText << '\n';
}