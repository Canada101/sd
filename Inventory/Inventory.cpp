#ifndef __INVENTORY
#define __INVENTORY
#include <iostream>
#include <vector>
#include <string>
#include "Weapon.cpp"

using namespace std;

class Inventory{
private:
    vector<Weapon> Weapons;
    //vector<string> SpecialAbilites; 
    int inventoryCount = 0;

public:
    void add(Weapon w){
        if(isFull()) {
            cout<< "Inventory is now full!" << endl;
            return;
        }
        Weapons.push_back(w);
        inventoryCount++;
    }

    void swapWeapons(Weapon w1, Weapon w2){
        for(int i = 0; i < Weapons.size(); i++){
            if (w1.GetName() == Weapons[i].GetName()){
                Weapons[i] = w2;
                w2.equipped = w1.equipped;
                return;
            }
        }
        cout<< "Couldn't find " << w1.GetName() << " to swap with!" << endl;
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
        for (int i = 0; i < Weapons.size(); i++)
        {
            cout << Weapons[i].GetName() << (Weapons[i].equipped ? " equipped": " ") << endl;
        }
    }

    void discardWeapon(Weapon w){
        for (vector<Weapon>::iterator i = Weapons.begin(); i != Weapons.end(); i++)
        {
            if(w.GetName() == i->GetName()){
                Weapons.erase(i);
                return;
            }
        }
        cout<< "Couldn't find " << w.GetName() << " to discard!" << endl;
    }

    bool isEmpty(){
        return inventoryCount == 0;
    }
};
#endif