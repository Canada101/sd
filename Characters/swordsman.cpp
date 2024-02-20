#include "characterSuper.cpp"

class SwordsMan : public CharacterSuper{
public:
    SwordsMan(){
        armor = 100;
        speed = 50;
        strength = 50;
        addToInventory("Heaven Slasher");
        addToInventory("Manual");
        addSpecialAbility("Killer Move");
    }
};