#ifndef __SPECIALABILITY
#define __SPECIALABILITY
#include <iostream>

using namespace std;

enum SpecialAbilities{Fireball, KillerMove, Stealth, Blocking, Map, Orb};

class SpecialAbility{
public:
    SpecialAbilities specialAbility;
    string description;
    bool used; 

    SpecialAbility(SpecialAbilities sa){
        this->specialAbility = sa;
        adjustSpecialAbilityStats(sa);
        used = false;
    };

    string getName(){
        switch (specialAbility){
        case Fireball:
            return "Fireball";
            break;
        case KillerMove:
            return "Killer Move";
            break;
        case Stealth:
            return "Stealth";
            break;
        case Blocking:
            return "Blocking";
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
        void adjustSpecialAbilityStats(SpecialAbilities sa){
            switch (sa){
            case Fireball: description = "Produces a fireball from wand, dealing a large amount of damage";
            break;
            case KillerMove: description = "A killing move";
            break;
            case Stealth: description = "Sneak past any enemy";
            break;
            case Blocking: description = "Block any hit from an enemy";
            break;
            case Map: description = "Lets you know where you are going";
            break;
            case Orb: description = "Has mysterious properties";
            }
        }
};
#endif