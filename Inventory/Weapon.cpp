#ifndef __WEAPON
#define __WEAPON
#include <iostream>

using namespace std;

enum WeaponType{BowandArrow, Cloak, HeavenSlasher, Knife, Manual, Shield, Spear, Wand, Map, Orb};

class Weapon
{
public:
    WeaponType w;
    int strength;
    string rarity;
    bool equipped; 

    Weapon(WeaponType wt) {
        this->w = wt;
        adjustStats(wt);
        equipped = false;
    };

    string GetName()
    {
        switch (w)
        {
        case BowandArrow:
            return "Bow and Arrow";
            break;
        case Cloak:
            return "Cloak";
            break;
        case HeavenSlasher:
            return "Heaven Slasher";
            break;
        case Knife:
            return "Knife";
            break;
        case Manual:
            return "Manual";
            break;
        case Shield:
            return "Shield";
            break;
        case Spear:
            return "Spear";
            break;
        case Wand:
            return "Wand";
            break;
        case Map:
            return "Map";
            break;
        case Orb:
            return "Orb";
            break;
        }
    }

    private:
        void adjustStats(WeaponType wt)
        {
            switch (wt){
            case BowandArrow: strength = 35, rarity = "Common";
            break;
            case Cloak: strength = 35, rarity = "Rare";
            break;
            case HeavenSlasher: strength = 75, rarity = "Ultra Rare";
            break;
            case Knife: strength = 15, rarity = "Common";
            break;
            case Manual: strength = 50, rarity = "Uncommon";
            break;
            case Shield: strength = 75, rarity = "Rare";
            break;
            case Spear: strength = 25, rarity = "Common";
            break;
            case Wand: strength = 85, rarity = "Mythical";
            break;
            case Map: strength = 0, rarity = "Common";
            break;
            case Orb: strength = 0, rarity = "Common";
            }
        }
};
#endif