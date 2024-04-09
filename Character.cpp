#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CharacterSuper{
public:
    int health;
    int armor;
    int strength;
    int speed;
    vector<string> inventory;
    vector<string> specialAbilities;

    int getHealth(){
        return health;
    }

    void maxHealth(){
        health = 100;
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

    void printStats(){
        cout << "Armor: " + to_string(armor) << endl;
        cout << "Strength: " + to_string(strength) << endl;
        cout << "Speed: " + to_string(speed) << endl;
        
        cout << "Inventory: ";
        for(auto item: inventory){
            cout << item + " ";
        }
        cout << endl;

        cout << "Special Abilities: ";
        for(auto ability: specialAbilities){
            cout << ability + " ";
        }
        cout << endl;
        cout << endl;
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

    void gainStrength(int amountGained){
        if(strength+amountGained<100){
            strength+=amountGained;
        }
    }

    void gainArmor(int amountGained){
        if(armor+amountGained<100){
            armor+=amountGained;
        }
    }
};