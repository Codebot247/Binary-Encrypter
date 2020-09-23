#include <iostream>
#include <bitset>
#include <string>
std::string textToBinary(std::string plainInput) {
    std::string binaryString = "";
    for (char& _char : plainInput) 
    {
        binaryString += std::bitset<8>(_char).to_string();
    }
    return binaryString;
}
int main()
{
    std::string plaintext = " ";
    std::string key = "";
    while (key.length() < plaintext.length())
    {
        std::cout << "Enter plaintext: ";
        std::getline(std::cin, plaintext);
        plaintext = textToBinary(plaintext);

        std::cout << "Enter key: ";
        std::getline(std::cin, key);
        key = textToBinary(key);
        if (key.length() < plaintext.length())
        {
            std::cout << "Invalid input somewhere, please make sure that the plaintext and key are equal length!" << std::endl;
        }
    }

    std::cout << "Plaintext: " <<plaintext << std::endl << "Key: " << key << std::endl;

    std::string encryptedText;
    for (int i = 0; i != plaintext.length(); i++)
    {
        if (plaintext[i] == key[i])
        {
            encryptedText += '0';
        }
        else
        {
            encryptedText += '1';
        }
    }
    
    std::cout << "Encrypted message: " << encryptedText;

    return 0;
}