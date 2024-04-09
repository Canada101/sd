#include"Guardian.h" 

class Guardian: public CharacterSuper{
public:
    Guardian(){
        health = 100;
        armor = 75;
        strength = 100;
        speed = 25;
        addToInventory("spear");
        addToInventory("shield");
        addSpecialAbility("combat");
        addSpecialAbility("blocking");
    }
};