#include <iostream>
#include <string>
#include <vector>
#include "characterSuper.cpp"
using namespace std;

class Wizard: public CharacterSuper{
public:
    Wizard(){
        armor = 25;
        strength = 50;
        speed = 75;
        addToInventory("wand");
        addToInventory("cloak");
        addSpecialAbility("fireball");
    }
};