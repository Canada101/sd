#include <iostream>
#include <string>
using namespace std;

class CharacterSuper{
public:
    int health;
    int armor;
    string inventory;

    int getHealth(){
        return health;
    }

    int getArmor(){
        return armor;
    }

    string getInventory(){
        return inventory;
    }

    void loseHealth(int damage){
        health-=damage;
    }

    void gainHealth(int recovery){
        health+=recovery;
    }
};

class Ranger: public CharacterSuper{
public:
    Ranger(){
        health = 100;
        armor = 50;
        inventory = "Bow and arrow";
    }
};

