#include <iostream>
#include <bitset>
#include <string>

// Turns the string into binary.
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
    std::string plaintext = " "; // Starting plaintext, this will be encrypted
    std::string key = "";        // The key to use during the encryption. Key must be equal length to plaintext.
    while (key.length() < plaintext.length())
    {
        std::cout << "Enter plaintext: ";
        std::getline(std::cin, plaintext);   // Gets plaintext
        plaintext = textToBinary(plaintext); // Converts plaintext to binary

        std::cout << "Enter key (Must be equal length to plaintext): ";
        std::getline(std::cin, key);  // Gets key
        key = textToBinary(key);  	  // Converts key to binary
        if (key.length() < plaintext.length())
        {
            std::cout << "Invalid input somewhere, please make sure that the plaintext and key are equal length!" << std::endl; // Displays if there is an invalid input in the plaintext or key
        }
    }

    std::cout << "Plaintext: " <<plaintext << std::endl; // Prints the plaintext
    std::cout << "Key: " << key << std::endl;  // Prints the key

    std::string encryptedText;

    for (int i = 0; i != plaintext.length(); i++) // Uses an XOR function to encrypt the binary 
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
    
    std::cout << "Encrypted message: " << encryptedText << std::endl << "PRESS ENTER TO EXIT"; // Displays the encrypted message, and then the exit dialogue

    getchar();

    return 0;
}