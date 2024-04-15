#ifndef __SPECIALABILITY
#define __SPECIALABILITY
#include <iostream>

using namespace std;

enum SpecialAbilities{Fireball, KillerMove, Stealth, Blocking};

class SpecialAbility
{
public:
    SpecialAbilities s;
    //int strength;
    string descripition;
    bool used; 

    SpecialAbility(SpecialAbilities sa) {
        this->s = sa;
        adjustSpecialAbilityStats(sa);
        used = false;
    };

    string GetName()
    {
        switch (s)
        {
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
        }
    }

    private:
        void adjustSpecialAbilityStats(SpecialAbilities sa)
        {
            switch (sa){
            case Fireball: descripition = "Produces a fireball from wand, dealing a large amount of damage";
            break;
            case KillerMove: descripition = "A killing move";
            break;
            case Stealth: descripition = "Sneak past any enemy";
            break;
            case Blocking: descripition = "Block any hit from an enemy";
            break;
            }
        }
};
#endif