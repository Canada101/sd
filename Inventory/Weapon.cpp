#ifndef __WEAPON
#define __WEAPON
#include <iostream>

using namespace std;

enum WeaponType{BowandArrow, HeavenSlasher, Spear, Wand};

class Weapon{
public:
    WeaponType weaponType;
    int strength;
    string rarity;
    bool equipped; 

    Weapon(){}

    Weapon(WeaponType type){
        this->weaponType = type;
        adjustStats(type);
        equipped = false;
    };

    string getName(){
        switch (weaponType){
        case BowandArrow:
            return "Bow and Arrow";
            break;
        case HeavenSlasher:
            return "Heaven Slasher";
            break;
        case Spear:
            return "Spear";
            break;
        case Wand:
            return "Wand";
            break;
        }
    }

    int getStrength(){
        return strength;
    }

    private:
        void adjustStats(WeaponType type){
            switch (type){
            case BowandArrow: strength = 35, rarity = "Common";
            break;
            case HeavenSlasher: strength = 75, rarity = "Ultra Rare";
            break;
            case Spear: strength = 25, rarity = "Common";
            break;
            case Wand: strength = 85, rarity = "Mythical";
            break;
            }
        }
};
#endif