#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ranger: public CharacterSuper{
public:
    Ranger(){
        health = 100;
        armor = 50;
        strength = 50;
        speed = 75;
        addToInventory("bow and arrow");
        addToInventory("knife");

    }
};