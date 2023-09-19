






#include <iostream>
#include <string>
#include <unordered_map>

char translateChar(char inputChar, const std::unordered_map<char, char>& cipherTranslation) {
    char uppercaseInputChar = inputChar;
    if (inputChar >= 'a' && inputChar <= 'z') {
        uppercaseInputChar = inputChar - 'a' + 'A';
    }

    if (cipherTranslation.find(uppercaseInputChar) != cipherTranslation.end()) {
        char translatedChar = cipherTranslation.at(uppercaseInputChar);
        if (inputChar >= 'a' && inputChar <= 'z') {
            translatedChar = translatedChar - 'A' + 'a';
        }
        return translatedChar;
    }

    return inputChar; 
}

int main() {
    std::unordered_map<char, char> cipherTranslation = {
        {'A', 'V'},{'B', 'F'},{'C', 'X'},{'D', 'B'},{'E', 'L'},{'F', 'I'},{'G', 'T'},{'H', 'Z'},{'I', 'J'},{'J', 'R'},
        {'K', 'P'},{'L', 'H'}, {'M', 'D'}, {'N', 'K'}, {'O', 'N'},{'P', 'O'},{'Q', 'W'},{'R', 'S'},{'S', 'G'},
        {'T', 'U'},{'U', 'Y'},{'V', 'Q'},{'W', 'M'},{'X', 'A'},{'Y', 'C'},{'Z', 'E'}
    };

    std::string userInput;

    std::cout << "Input text to cypher: ";
    std::getline(std::cin, userInput);

    std::cout << "Encoded Message: ";
    for (char c : userInput) {
        char translatedChar = translateChar(c, cipherTranslation);
        std::cout << translatedChar;
    }
    std::cout << std::endl;

    return 0;
}
