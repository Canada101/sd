#ifndef __CHARACTERSUPER
#define __CHARACTERSUPER
#include <iostream>
#include <string>
#include <vector>
#include "../Inventory/Weapon.cpp"
#include "../Inventory/Inventory.cpp"

using namespace std;

class CharacterSuper{
public:
    int health = 0;
    int armor = 0;
    int strength = 0;
    int speed = 0;
    Weapon weapon = Weapon(WeaponType::Knife);
    Inventory inventory = Inventory();

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

    Inventory getInventory(){
        return inventory;
    }

    void addToInventory(string item){

    }

    void loseHealth(int damage){
        health-=damage;
    }

    void gainHealth(int recovery){
        health+=recovery;
    }

    void setWeapon(Weapon weapon){
        this->weapon.equipped = false;
        this->weapon = weapon;
        this->weapon.equipped = true;
    }
};
#endif