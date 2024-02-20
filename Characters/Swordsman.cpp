#include "characterSuper.cpp"

class Swordsman : public CharacterSuper{
public:
    Swordsman(){
        armor = 100;
        speed = 50;
        strength = 50;
        addToInventory("Heaven Slasher");
        addToInventory("Manual");
        addSpecialAbility("Killer Move");
    }
};