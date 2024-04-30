#include <iostream>
#include <string>
#include <vector>
#include "Inventory/Weapon.cpp"
#include "Inventory/Inventory.cpp"
#include "Inventory/SpecialAbility.cpp"
using namespace std;

class CharacterSuper{
public:
    int health;
    int armor;
    int strength;
    int speed;
    Inventory inventory;

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

    Weapon getWeapon(){
        return inventory.getWeapon();
    }

    const vector<SpecialAbility> & getSpecials() const {
        return inventory.getSpecials();
    }

    void addSpecialAbility(SpecialAbility special){
        inventory.addSpecial(special);
    }

    string displayInventory(){
        string message;
        message = inventory.displayWeapons() + inventory.displaySpecials();
        return message;
    }

    void addWeapons(Weapon weapon){
        inventory.addWeapon(weapon);
    }


    Inventory getInventory(){
        return inventory;
    }

    string printStats(){
        string message;
        message = "Health: " + to_string(health) + "\nArmor: " + to_string(armor) + "\nStrength: " + to_string(strength) + "\nSpeed: " + to_string(speed);
        
        return message + displayInventory();
    }

    int getWeaponStrength(){
        return inventory.getWeaponStrength();
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

class Guardian: public CharacterSuper{
public:
    Guardian(){
        health = 100;
        armor = 75;
        strength = 100;
        speed = 25;
        inventory.addWeapon(Spear);
        inventory.addSpecial(Blocking);
    }
};

class Ranger: public CharacterSuper{
public:
    Ranger(){
        health = 100;
        armor = 50;
        strength = 25;
        speed = 100;
        inventory.addWeapon(BowandArrow);
        inventory.addSpecial(Stealth);
    }
};

class Swordsman: public CharacterSuper{
public:
    Swordsman(){
        health = 100;
        armor = 100;
        speed = 50;
        strength = 50;
        inventory.addWeapon(HeavenSlasher);
        inventory.addSpecial(KillerMove);
    }
};

class Wizard: public CharacterSuper{
public:
    Wizard(){
        health = 100;
        armor = 25;
        strength = 50;
        speed = 75;
        inventory.addWeapon(Wand);
        inventory.addSpecial(Fireball);
    }
};