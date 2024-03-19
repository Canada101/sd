#include <iostream>
#include "Characters.cpp"
using namespace std;

class CombatNarrative{
    public:
    CharacterSuper* character;

    CombatNarrative(CharacterSuper* characterType){
        character = characterType;
    }

    bool fightDragon(){
        int dragonHealth = 100;
        int choice = 0;
       
        bool won = false;
        while(1){
            cout << "Dragon's health is " + to_string(dragonHealth) << endl;
            cout << "Your health is " + to_string(character->getHealth()) << endl;

            cout << "Choose your next action:" << endl;
            cout << "1. Attack the dragon with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                cout << "Your blow lands! The dragon loses 25 health" << endl;
                dragonHealth-=25;
            }
            else if(choice==2){
                cout << "You patch up your wounds. You gain 25 health" << endl;
                if((character->getHealth() +25)<100){
                    character->gainHealth(25);
                }
                else{
                    character->maxHealth();
                }
            }
            else if(choice==3){
                cout << "You attempt to run away. The dragon attacks and you lose 20 health" << endl;
                character->loseHealth(20);
            }

            if(character->getHealth()<=0){
                won = false;
                cout << "You lost the battle" << endl;
                break;
            }
            else if(dragonHealth<=0){
                won = true;
                cout << "You defeat the dragon!" << endl;
                break;
            }
        }
        return won;
    }

    bool fightLakeMonster(){
        int lakeMonsterHealth = 150;
        int choice = 0;

        bool won = false;
        while(1){
            cout << "Lake monster's health is " + to_string(lakeMonsterHealth) << endl;
            cout << "Your health is " + to_string(lakeMonsterHealth) << endl;

            cout << "Choose your next action:" << endl;
            cout << "1. Attack the lake monster with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                cout << "Your blow lands! The lake monster loses 25 health" << endl;
                lakeMonsterHealth-=25;
            }
            else if(choice==2){
                cout << "You patch up your wounds. You gain 25 health" << endl;
                if((character->getHealth()+25)<100){
                    character->gainHealth(25);
                }
                else{
                    character->maxHealth();
                }
            }
            else if(choice==3){
                cout << "You attempt to run away. The lake monster attacks and you lose 25 health" << endl;
                character->loseHealth(25);
            }

            if(character->getHealth()<=0){
                won = false;
                cout << "You lost the battle" << endl;
                break;
            }
            else if(lakeMonsterHealth<=0){
                won = true;
                cout << "You defeated the lake monster!" << endl;
                break;
            }
        }
        return won;
    }

    bool fightKing(){
        int kingHealth = 200;
        int choice = 0;
        
        bool won = false;
        while(1){
            cout << "The kings's health is " + to_string(kingHealth) << endl;
            cout << "Your health is " + to_string(character->getHealth()) << endl;

            cout << "Choose your next action:" << endl;
            cout << "1. Attack the lake monster with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                cout << "Your blow lands! The king loses 25 health" << endl;
                kingHealth-=25;
            }
            else if(choice==2){
                cout << "You patch up your wounds. You gain 25 health" << endl;
                if((character->getHealth()+25)<100){
                    character->gainHealth(25);
                }
                else{
                    character->maxHealth();
                }
            }
            else if(choice==3){
                cout << "You attempt to run away. The king attacks and you lose 25 health" << endl;
                character->loseHealth(25);
            }

            if(character->getHealth()<=0){
                won = false;
                cout << "You lost the battle" << endl;
                break;
            }
            else if(kingHealth<=0){
                won = true;
                cout << "You defeated the king!" << endl;
                break;
            }
        }
        return won;
    }
};