#include "characterSuper.cpp"

class SwordsMan : public CharacterSuper{
public:
    SwordsMan(){
        speed = speed/2;
        strength = strength/2;
        addToInventory("Heaven Slasher");
        addToInventory("Manual");
        addSpecialAbility("Killer Move");
    }
};