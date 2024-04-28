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
    vector<SpecialAbility> Specials; 
    int inventoryCount = 0;

public:
    Inventory(){}

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

    void displayWeapons()
    {
        cout << "=============List of Weapons=============" << endl;
        cout << weapon.GetName() << endl;
    }

    bool isEmpty(){
        return inventoryCount == 0;
    }

   void displaySpecials(){
        cout << "=============List of Special Abilities=============" << endl;
        for (int i = 0; i < Specials.size(); i++)
        {
            cout << Specials[i].GetName() << (Specials[i].used ? " avaliable": " ") << endl;
        }
        cout << endl;
    }

    void addSpecial(SpecialAbility s){
        if(isFull()) {
            cout<< "Inventory is now full!" << endl;
            return;
        }
        Specials.push_back(s);
        inventoryCount++;
    }

    Weapon getWeapon(){
        return weapon;
    }

    const vector<SpecialAbility>& getSpecials() const {
        return Specials;
    }

};
#endif