#ifndef __INVENTORY
#define __INVENTORY
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.cpp"
#include "SpecialAbility.cpp"

using namespace std;

class Inventory{
private:
    Weapon weapon;
    vector<SpecialAbility> specials; 
    int inventoryCount;

public:
    Inventory(){
        inventoryCount = 0;
    }

    void addWeapon(Weapon w){
        weapon = w;
        inventoryCount++;
    }

    int getWeaponStrength(){
        return weapon.getStrength();
    }

    bool isFull(){
        if(inventoryCount == 4){
            return true;
        }else{
            return false;
        }
    }

    string displayWeapons(){
        string message;
        message = "\n=============List of Weapons=============\n" + weapon.getName();
        return message;
    }

    bool isEmpty(){
        return inventoryCount == 0;
    }

    string displaySpecials(){
        string message;
        message = "\n=============List of Special Abilities=============\n";
        for (int i = 0; i < specials.size(); i++){
            message += specials[i].getName() + (specials[i].used ? " avaliable": "|");
        }
        return message;
    }

    void addSpecial(SpecialAbility s){
        if(isFull()){
            cout<< "Inventory is now full!" << endl;
            return;
        }
        specials.push_back(s);
        inventoryCount++;
    }

    Weapon getWeapon(){
        return weapon;
    }

    const vector<SpecialAbility>& getSpecials() const {
        return specials;
    }

};
#endif