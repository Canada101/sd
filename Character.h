#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CharacterSuper{
public:
    int health;
    int armor;
    int strength;
    int speed;
    vector<string> inventory;
    vector<string> specialAbilities;

    int getHealth(){
    }

    void maxHealth(){
    }

    int getArmor(){
    }

    int getStrength(){
    }

    int getSpeed(){
    }

    vector<string> getSpecialAbilities(){
    }

    void addSpecialAbility(string item){

    }

    vector<string> getInventory(){

    }

    void printStats(){
 
    }

    void addToInventory(string item){
    }

    void loseHealth(int damage){

    }

    void gainHealth(int recovery){

    }

    void gainStrength(int amountGained){

    }

    void gainArmor(int amountGained){

    }
};
