#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CharacterSuper{
public:
    int health = 100;
    int armor;
    int strength;
    int speed;
    vector<string> inventory;
    vector<string> specialAbilities;

    int getHealth(){
        return health;
    }

    int getArmor(){
        return armor;
    }

    int getStrength(){
        return strength;
    }

    int getSpeed(){
        return speed;
    }

    vector<string> getSpecialAbilities(){
        return specialAbilities;
    }

    void addSpecialAbility(string item){
        specialAbilities.push_back(item);
    }

    vector<string> getInventory(){
        return inventory;
    }

    void addToInventory(string item){
        inventory.push_back(item);
    }

    void loseHealth(int damage){
        health-=damage;
    }

    void gainHealth(int recovery){
        health+=recovery;
    }
};


