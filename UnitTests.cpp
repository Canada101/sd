#include <iostream>
#include <fstream>
#include <string>
#include "Narrative.cpp"


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

        // Check if the Guardian's health is initially set to 100
        bool isPassHealth = (health == 100);

        if (isPassHealth) {
            inputFile << "pass" << std::endl;
        } else {
            inputFile << "fail" << std::endl;
        }

        return isPassHealth;
    }
    bool testArmor() {
        Guardian guardianTwo;
        int armor = guardianTwo.getArmor();

        // Check if the Guardian's armor is initially set to 75
        bool isPassArmor = (armor == 75);

        if (isPassArmor) {
            inputFile << "pass" << std::endl;
        } else {
            inputFile << "fail" << std::endl;
        }

        return isPassArmor;
    }
    bool testSpeed() {
        Guardian guardianThree;
        int speed = guardianThree.getSpeed();

        // Check if Guardian's speed is initially set to 25
        bool isPassSpeed = (speed == 25);

        if (isPassSpeed) {
            inputFile << "pass" << std::endl;
        } else {
            inputFile << "fail" << std::endl;
        }

        return isPassSpeed;
    }

    bool testInventory () {
        Inventory inv;
        bool full = inv.isFull();

        bool isPassInventory = (full == false);

        if (isPassInventory){
            inputFile << "pass" << std::endl;
        } else {
            inputFile << "fail" << std::endl;
        }
        return isPassInventory;

    }

    bool testInventoryTwo () {
        Inventory invTwo;
        bool empty = invTwo.isEmpty();
        bool isPassInventoryTwo = (empty == true);

        if (isPassInventoryTwo){
            inputFile << "pass" << std::endl;
        } else {
            inputFile << "fail" << std::endl;
        }
        
        return isPassInventoryTwo;

    }


    ~UnitTests() {
        if (inputFile.is_open()) {
            inputFile.close();
        }
    }
};
