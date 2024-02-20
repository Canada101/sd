#include <iostream>
#include <string>
#include <vector>
#include "characterSuper.cpp"
using namespace std;

class Ranger: public CharacterSuper{
public:
    Ranger(){
        armor = 50;
        strength = 25;
        speed = 100;
        addToInventory("bow and arrow");
        addToInventory("knife");
        addSpecialAbility("stealth");
        addSpecialAbility("laguage proficiency");
    }
};