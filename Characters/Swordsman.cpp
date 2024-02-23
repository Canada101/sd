#include "characterSuper.cpp"

class Swordsman : public CharacterSuper{
public:
    Swordsman(){
        health = 100;
        armor = 100;
        speed = 50;
        strength = 50;
        addToInventory("Heaven Slasher");
        addToInventory("Manual");
        addSpecialAbility("Killer Move");
    }
};
