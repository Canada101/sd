#include "narrativeSuper.cpp"
#include <iostream>
using namespace std;

class CombatNarrative: public NarrativeSuper{
    public:
    int character;
    int characterHealth;
    int characterArmor;

    CombatNarrative(int characterType){
        character = characterType;
    }

    bool fightDragon(){
        int dragonHealth = 100;
        int choice = 0;
       
        bool won = false;
        while(1){
            cout << "Dragon's health is " + dragonHealth << endl;
            cout << "Your health is " + characterHealth << endl;

            cout << "Choose your next action:" << endl;
            cout << "1. Attack the dragon with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                cout << "Your blow lands! The dragon loses 25 health" << endl;
                dragonHealth-=25;
            }
            else if(choice==2){
                cout << "You patch up your wounds. You gain 25 health" << endl;
                if((characterHealth+25)<100){
                    characterHealth+=25;
                }
                else{
                    characterHealth = 100;
                }
            }
            else if(choice==3){
                cout << "You attempt to run away. The dragon attacks and you lose 20 health" << endl;
                characterHealth-=20;
            }

            if(characterHealth<=0){
                won = false;
                break;
            }
            else if(dragonHealth<=0){
                won = true;
                break;
            }

            return won;
        }
    }

    bool fightLakeMonster(){
        int lakeMonsterHealth = 150;
        int choice = 0;

        bool won = false;
        while(1){
            cout << "Lake monster's health is " + lakeMonsterHealth << endl;
            cout << "Your health is " + lakeMonsterHealth << endl;

            cout << "Choose your next action:" << endl;
            cout << "1. Attack the lake monster with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                cout << "Your blow lands! The lake monster loses 25 health" << endl;
                lakeMonsterHealth-=25;
            }
            else if(choice==2){
                cout << "You patch up your wounds. You gain 25 health" << endl;
                if((characterHealth+25)<100){
                    characterHealth+=25;
                }
                else{
                    characterHealth = 100;
                }
            }
            else if(choice==3){
                cout << "You attempt to run away. The lake monster attacks and you lose 25 health" << endl;
                characterHealth-=25;
            }

            if(characterHealth<=0){
                won = false;
                break;
            }
            else if(lakeMonsterHealth<=0){
                won = true;
                break;
            }

            return won;
        }
    }

    bool fightKing(){
        int kingHealth = 200;
        int choice = 0;
        
        bool won = false;
        while(1){
            cout << "The kings's health is " + kingHealth << endl;
            cout << "Your health is " + characterHealth << endl;

            cout << "Choose your next action:" << endl;
            cout << "1. Attack the lake monster with your weapon\n2. Heal yourself\n3. Hide" << endl;
            cin >> choice;
            if(choice==1){
                cout << "Your blow lands! The king loses 25 health" << endl;
                kingHealth-=25;
            }
            else if(choice==2){
                cout << "You patch up your wounds. You gain 25 health" << endl;
                if((characterHealth+25)<100){
                    characterHealth+=25;
                }
                else{
                    characterHealth = 100;
                }
            }
            else if(choice==3){
                cout << "You attempt to run away. The king attacks and you lose 25 health" << endl;
                characterHealth-=25;
            }

            if(characterHealth<=0){
                won = false;
                break;
            }
            else if(kingHealth<=0){
                won = true;
                break;
            }

            return won;
        }
    }
};