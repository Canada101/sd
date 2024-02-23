#include <iostream>
#include <string>
#include <vector>
#include "characterSuper.cpp"
using namespace std;

class Wizard: public CharacterSuper{
public:
    Wizard(){
        health = 100;
        armor = 25;
        strength = 50;
        speed = 75;
        addToInventory("wand");
        addToInventory("cloak");
        addSpecialAbility("fireball");
    }
};