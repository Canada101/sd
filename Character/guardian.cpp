#include "characterSuper.cpp"

class Guardian : public CharacterSuper{
public:

    Guardian(){
        armor = 2*armor;
        strength = 1.5*strength;
    }

};