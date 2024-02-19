#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CharacterSuper{
public:
    int health = 100;
    int armor = 100;
    int strength = 100;
    vector<string> inventory;

    int getHealth(){
        return health;
    }

    int getArmor(){
        return armor;
    }

    int getStrength(){
        return strength;
    }

    void getInventory(){
        for(int i = 0; i < inventory.size(); i++){
            cout << inventory[i] << endl;
        }
    }

    void addInventory(string item){
        inventory.push_back(item);
    }

    void loseHealth(int damage){
        health-=damage;
    }

    void gainHealth(int recovery){
        health+=recovery;
    }

    void loseArmor(int damage){
        armor -= damage;
    }

    void gainArmor(int recovery){
        armor += recovery;
    }

    void loseStrength(int damage){
        strength -= damage;
    }

    void gainStrength(int recovery){
        strength += recovery;
    }
};
