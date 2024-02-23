#include <iostream>
#include <string>
#include <vector>
#include "characterSuper.cpp"
using namespace std;

class Ranger: public CharacterSuper{
public:
    Ranger(){
        health = 100;
        armor = 50;
        strength = 25;
        speed = 100;
        addToInventory("bow and arrow");
        addToInventory("knife");
        addSpecialAbility("stealth");
        addSpecialAbility("language proficiency");
    }
};