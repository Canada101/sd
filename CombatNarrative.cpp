#include <iostream>
#include <string>
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
            cout << endl;
            cout << "Dragon's health is " + to_string(dragonHealth) << endl;
            cout << "Your health is " + to_string(character->getHealth()) << endl;

            cout << "Choose your next action:" << endl;
            cout << "1. Attack the dragon with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                int damageToDragon = (int)(25*(character->getStrength()/100.0));
                cout << "Your blow lands! The dragon loses " + to_string(damageToDragon) + " health." << endl;
                dragonHealth-=damageToDragon;
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
                int damageToCharacter = (int)(25*(1-(character->getArmor()/100.0)))+5;
                cout << "You attempt to run away. The dragon attacks and you lose " + to_string(damageToCharacter) + " health." << endl;
                character->loseHealth(damageToCharacter);
            }

            if(character->getHealth()<=0){
                won = false;
                cout << "You lost the battle" << endl;
                break;
            }
            else if(dragonHealth<=0){
                won = true;
                cout << "You defeat the dragon! Your armor has been increased." << endl;
                character->gainArmor(10);
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
            cout << "Your health is " + to_string(character->getHealth()) << endl;

            cout << "Choose your next action:" << endl;
            cout << "1. Attack the lake monster with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                int damageToLakeMonster = (int)(25*(character->getStrength()/100.0));
                cout << "Your blow lands! The lake monster loses " + to_string(damageToLakeMonster) + " health." << endl;
                lakeMonsterHealth-=damageToLakeMonster;
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
                cout << "You defeated the lake monster! Your strength has been increased" << endl;
                character->gainStrength(10);
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
            cout << "1. Attack the king with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                int damageToKing = (int)(25*(character->getStrength()/100.0));
                cout << "Your blow lands! The king loses " + to_string(damageToKing) + " health." << endl;
                kingHealth-=damageToKing;
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