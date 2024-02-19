#include "characterSuper.cpp"

class SwordsMan : public CharacterSuper{
public:

    int speed;

    SwordsMan(){
        armor = 2*armor;
        strength = 2*strength;
        speed = 100;
    }

    int getSpeed(){
        return speed;
    }

    void loseSpeed(int damage){
        speed -= damage;
    }

    void gainSpeed(int recovery){
        speed += recovery;
    }
};