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
#include "Characters.cpp"
#include "Inventory/Inventory.cpp"


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
        bool isPassHealth = (typeid(health) == typeid(int));

        if (isPassHealth) {
            inputFile << "pass" << std::endl;
        } else {
            inputFile << "fail" << std::endl;
        }

        return isPassHealth;
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

    bool testCombat () {

    }

    ~UnitTests() {
        if (inputFile.is_open()) {
            inputFile.close();
        }
    }
};
