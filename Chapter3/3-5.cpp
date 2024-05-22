#include <iostream>
using std::cin;
using std::cout;

int main() //decoder
{
    std::string plainText;
    std::string cipherText = "ZSRRV LVQRU!";
    const std::string alphabet = "ZMKXYABFCQGWITJNRLEVDOPUSH";
    cout << "Ciphertext: " << cipherText << '\n';
    for(char& c : cipherText)
    {
        if (c - 64 < 0 || c - 64 > 26) plainText += c;
        else
        {
            int index = c - 'A';
            plainText += alphabet[index];
        }
    }
    cout << "Plaintext: " << plainText << '\n';
}