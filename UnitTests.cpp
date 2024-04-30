/*
tests to run
character: getHealth
inventory: isfull
NPC narrative talktowoods character check output is correct for choice
narrative test character selection
combat narrative fight lake monster
*/


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

        // Check if the return value is an integer
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

        // Check if the return value is an integer
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

        // Check if the return value is an integer
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
