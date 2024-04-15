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

    const vector<Weapon> & getWeapons() const {
        return inventory.getWeapons();
    }

    const vector<SpecialAbility> & getSpecials() const {
        return inventory.getSpecials();
    }

    void addSpecialAbility(SpecialAbility special){
        inventory.addSpecial(special);
    }

    void displayInventory(){
        inventory.displayWeapons();
        inventory.displaySpecials();
    }

    void addWeapons(Weapon weapon){
        inventory.add(weapon);
    }


    Inventory getInventory(){
        return inventory;
    }

    void setWeapon(Weapon weapon){
    //     this->weapon.equipped = false;
    //     this->weapon = weapon;
    //     this->weapon.equipped = true;
    }

    void printStats(){
        cout << "Armor: " + to_string(armor) << endl;
        cout << "Strength: " + to_string(strength) << endl;
        cout << "Speed: " + to_string(speed) << endl;
        displayInventory();
    }

   void discardWeapon(Weapon weapon){
        inventory.discardWeapon(weapon);
   }

   bool WeaponsEmpty(){
    return inventory.isEmpty();
   }

   bool WeaponsFull(){
    return inventory.isFull();
   }

   void swapWeapons(Weapon w1, Weapon w2){
    inventory.swapWeapons(w1,w2);
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
        inventory.add(Spear);
        inventory.add(Shield);
        inventory.addSpecial(Blocking);
        // addSpecialAbility("blocking");
    }
};

class Ranger: public CharacterSuper{
public:
    Ranger(){
        health = 100;
        armor = 50;
        strength = 25;
        speed = 100;
        inventory.add(BowandArrow);
        inventory.add(Knife);
        inventory.addSpecial(Stealth);
        //addSpecialAbility("language proficiency");
    }
};

class Swordsman: public CharacterSuper{
public:
    Swordsman(){
        health = 100;
        armor = 100;
        speed = 50;
        strength = 50;
        inventory.add(HeavenSlasher);
        inventory.add(Manual);
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
        inventory.add(Wand);
        inventory.add(Cloak);
        inventory.addSpecial(Fireball);
    }
};