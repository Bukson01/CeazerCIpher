#include <iostream>
#include <string>

class CaesarCipher {
private:
    std::string symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    std::string getFunction() {
        // Get the function from the user: encrypt or decrypt.
        std::string response;
        while (true) {
            std::cout << "Do you want to (e)ncrypt or (d)ecrypt?" << std::endl;
            std::getline(std::cin, response);
            if (response[0] == 'e' || response[0] == 'E') {
                return "encrypt";
            } else if (response[0] == 'd' || response[0] == 'D') {
                return "decrypt";
            }
            std::cout << "Please enter the letter e or d." << std::endl;
        }
    }

    int getKey() {
        // Get the encryption/decryption key from the user.
        int maxKey = symbols.size() - 1;
        int key;
        while (true) {
            std::cout << "Please enter the key (0 to " << maxKey << ") to use." << std::endl;
            std::cin >> key;
            if (std::cin.fail() || key < 0 || key > maxKey) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                return key;
            }
        }
    }

    std::string processMessage(const std::string& message, const std::string& mode, int key) {
        // Encrypt or decrypt the message.
        std::string translated = "";
        for (char symbol : message) {
            char upperSymbol = std::toupper(symbol);
            if (symbols.find(upperSymbol) != std::string::npos) {
                int num = symbols.find(upperSymbol);
                if (mode == "encrypt") {
                    num = (num + key) % symbols.size();
                } else if (mode == "decrypt") {
                    num = (num - key + symbols.size()) % symbols.size();
                }
                translated += symbols[num];
            } else {
                translated += symbol;
            }
        }
        return translated;
    }

    void runCipher() {
        // Run the Caesar Cipher.
        std::cout << "Caesar Cipher, by Al Sweigart al@inventwithpython.com" << std::endl;
        std::cout << "The Caesar cipher encrypts letters by shifting them over by a" << std::endl;
        std::cout << "key number. For example, a key of 2 means the letter A is" << std::endl;
        std::cout << "encrypted into C, the letter B encrypted into D, and so on." << std::endl;
        std::cout << std::endl;

        // Get function, key, and message from the user
        std::string mode = getFunction();
        int key = getKey();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline character from buffer
        std::string message;
        std::cout << "Enter the message to " << mode << "." << std::endl;
        std::getline(std::cin, message);

        // Process the message
        std::string translated = processMessage(message, mode, key);

        // Display the result
        std::cout << translated << std::endl;

        // No clipboard functionality in C++
    }
};

int main() {
    CaesarCipher cipher;
    cipher.runCipher();
    return 0;
}
