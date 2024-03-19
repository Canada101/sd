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
};

class Guardian: public CharacterSuper{
public:
    Guardian(){
        health = 100;
        armor = 75;
        strength = 100;
        speed = 25;
        addToInventory("spear");
        addToInventory("shield");
        addSpecialAbility("combat");
        addSpecialAbility("blocking");
    }
};

class Ranger: public CharacterSuper{
public:
    Ranger(){
        health = 100;
        armor = 50;
        strength = 25;
        speed = 100;
        addToInventory("bow and arrow");
        addToInventory("knife");
        addSpecialAbility("stealth");
        addSpecialAbility("language proficiency");
    }
};

class Swordsman: public CharacterSuper{
public:
    Swordsman(){
        health = 100;
        armor = 100;
        speed = 50;
        strength = 50;
        addToInventory("Heaven Slasher");
        addToInventory("Manual");
        addSpecialAbility("Killer Move");
    }
};

class Wizard: public CharacterSuper{
public:
    Wizard(){
        health = 100;
        armor = 25;
        strength = 50;
        speed = 75;
        addToInventory("wand");
        addToInventory("cloak");
        addSpecialAbility("fireball");
    }
};