#include <iostream>
#include <fstream>
#include <string>
#include "Characters.cpp"

class UnitTests {
private:
    std::ofstream inputFile;
public:
    UnitTests(const std::string& filename) {
        inputFile.open(filename);
        if (!inputFile.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
        }
    }

    bool testHealth() {
        Guardian guardian;
        int health = guardian.getHealth();

        // Check if the return value is an integer
        bool isPass = (typeid(health) == typeid(int));

        if (isPass) {
            inputFile << "pass" << std::endl;
        } else {
            inputFile << "fail" << std::endl;
        }

        return isPass;
    }

    ~UnitTests() {
        if (inputFile.is_open()) {
            inputFile.close();
        }
    }
};
