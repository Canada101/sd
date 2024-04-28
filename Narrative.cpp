#include <iostream>
#include "CombatNarrative.cpp"
#include "NPCNarrative.cpp"
using namespace std;

class Narrative{
    public:
    int placeInStory;
    CharacterSuper* character;

    Narrative(){
        character = chooseCharacter();
        placeInStory = 0;  
        moveThroughStory();   
    }

    CharacterSuper* chooseCharacter(){
        int choice;
        CharacterSuper* characterType;

        cout<<"Welcome to the world of Warbles\nChoose a character for your adventure:" << endl;
        cout << endl;
        cout << "Option 1 Guardian" << endl;
        Guardian guardian;
        guardian.printStats();
        cout << "Option 2 Ranger" << endl;
        Ranger ranger;
        ranger.printStats();
        cout << "Option 3 Swordsman" << endl;
        Swordsman swordsman;
        swordsman.printStats();
        cout << "Option 4 Wizard" << endl;
        Wizard wizard;
        wizard.printStats();
        cout << "Your Choice: ";
        cin >> choice;

        if(choice==1){
            characterType = new Guardian();
            cout << "\nYou chose the Guardian." << endl;
        }
        else if(choice==2){
            characterType = new Ranger();
            cout << "\nYou chose the Ranger." << endl;
        }
        else if(choice==3){
            characterType = new Swordsman();
            cout << "\nYou chose the Swordsman." << endl;
        }
        else if(choice==4){
            characterType = new Wizard();
            cout << "\nYou chose the Wizard." << endl;
        }
        
        return characterType;
    }

    void storyJumpTo (int locationInStory){
        placeInStory = locationInStory;
    }

    void moveThroughStory() {
        int choice;
        bool haveMap = false;
        bool haveOrb = false;
        CombatNarrative combatNarrative(character);
        NarrativeNPC npcNarrative;

        while(1){
            if (placeInStory == 0){
                cout << "The world of Wables is treacherous...\nCountless villains scheme and only the powerful may live as they please\nThe most powerful of all is the king, who uses his subjects as fodder for endless monsters.\n"<<endl;
                cout << endl;
                placeInStory ++;
            }else if(placeInStory == 1){
                cout << "You wake in a village near the castle.\nYou will face many difficulties throughtout your journey but your objective is to find the castle and kill the king.\n" << endl;
                cout << endl;
                placeInStory ++;
            }else if(placeInStory == 2){
                cout << "As you walk down the streets of the villiage, a strange noise sounds from the nearby forest." << endl;
                cout << "Your curious nature leads to to investigate the noise.\n" << endl;
                placeInStory ++;
            }else if(placeInStory == 3){
                cout << "As you enter the forest, you locate the source of the noise: a suspicious stranger calling for help." << endl;
                cout << "1. Ignore the stranger.\n2. Interact with the stranger.\n" << endl;
                cout << "Your Choice: ";
                cin >> choice;
                cout << endl;
                if(choice == 2){
                    npcNarrative.talkToWoodsCharacter();
                    cout << "\nAfter the interaction with the stranger, you feel a sense of responsibility to do what you can for the villiage, so you head forward to look for the dragon.\n";
                }
                cout << "\nWhile moving through the forest, you stumble upon the dragon, which readies iteself to attack.\n";
                cout << endl;
                bool killDragon = combatNarrative.fightDragon();
                if(killDragon == false){
                    break;
                }
                placeInStory ++;
            }else if(placeInStory == 4){
                cout << "\nAfter defeating the dragon, you continue on your way, until you notice a piece of paper on the ground." << endl;
                cout << "1. Pick up the paper.\n2. Ignore it." << endl;
                cout << "Your Choice: ";
                cin >> choice;
                if(choice == 1){
                    haveMap = true;
                    cout << "\nThe paper is a map that has the location of a auspicious lake, rumored to have special properties." << endl;
                    cout << "\nA handwritten note on the map warns that the lake contains severe danger" << endl;
                    cout << "Intrigued by the map, you follow the directions to head in the direction of the lake.\n" << endl;
                    character->addSpecialAbility(Map);
                }else{
                    cout << "\nYou ignored the paper and are heading in a random direction." << endl;
                    placeInStory = 7;
                }
                cout << "Do you want to take a look at your stats and inventory?" << endl;
                cout << "1.Yes\n2.No\n"<< endl;
                cout << "Your Choice : ";
                cin >> choice;
                if(choice == 1){
                    character->printStats();
                }
                placeInStory ++;
            }else if(placeInStory == 5){
                cout << "You arrive the lake and note a danger sign on the road." << endl;
                cout << "You tentatively look around for someone to talk to about the lake.\n" << endl;
                cout << "Far ahead, you spotted a fisherman.\n" << endl;
                cout << "1. Ignore the fisherman.\n2. Walk up to him and talk to him.\n" << endl;
                cout << "Your Choice : ";
                cin >> choice;
                if(choice == 2){
                    npcNarrative.talkToLakeCharacter();
                    cout << "\nAfter the interaction with the fisherman, you decide to confront the lake monster for the good of the community.\n" << endl;
                }
                cout << "The water suddenly draws back to reveal the lake monster ready to attack.\n" << endl;
                bool killLakeMonster = combatNarrative.fightLakeMonster();
                if(killLakeMonster == false){
                    break;
                }
                placeInStory ++;
            }else if(placeInStory == 6){
                cout << "\nAs a thank you for your service to the community, the fisherman tells you the local rumor of nearby treasure.\n" << endl;
                cout << "1. Head towards the treasure's location.\n2. Ignore it and head towards the gate of the city." << endl;
                cout << "Your Choice: ";
                cin >> choice;
                if(choice == 1){
                    cout << "\nYou find a closed cave with an imprint of a map on its entrance. Check your inventory and see if you have the map.\n" << endl;
                    character->printStats();
                    if(haveMap){
                        cout << "You use the map on the imprint to open the cave.\n" << endl;
                        cout << "Inside the cave, you find a orb which will increase you health by 50.\n" << endl;
                        cout << "1. Use the orb now\n2. Keep it in inventory.\n" << endl;
                        cout << "Your Choice: ";
                        cin >> choice;
                        if(choice == 1){
                            character->gainHealth(50);
                        }else{
                            character->addSpecialAbility(Orb);
                            character->printStats();
                            haveOrb = true;
                        }
                    }else{
                        cout << "\nUnfortunately you do not have a map and cannot open the cave.\n" << endl;
                    }
                    cout << "You now head to the city gate on your mission to confront the king.\n" << endl;

                }
                placeInStory ++;
            }else if(placeInStory == 7){
                cout << "You reach the city gates." << endl;
                cout << "At the entrance you are approached by a person who identifies himself as former knight." << endl;
                cout << "It seems he has some valuable information that can help you to enter the castle\n or advice regarding the fight against the king." << endl;
                cout << "1. Ignore him.\n2. Talk to him to get more information.\n" << endl;
                cout << "Your Choice: ";
                cin >> choice;
                if(choice == 2){
                    npcNarrative.talkToCastleCharacter();
                    cout << "\nAfter talking with the former knight, you feel more confident about fighting the king.\n" << endl;
                }
                cout << "\nYou check in to a nearby inn. In the room, you work on your plan to infiltrate the castle.\n" << endl;
                placeInStory ++;
            }else if(placeInStory == 8){
                cout << "You decided to infiltrate the castle at night for minimum security." << endl;
                cout << "As the darkness of night approaches silently, you successfully sneak into the castle and reached outside of king's room." << endl;
                if(haveOrb){
                    cout << "\nDo you want to use the orb you found in the cave?" << endl;
                    cout << "1.Yes\n2.No\n" << endl;
                    cout << "Your Choice: ";
                    cin >> choice;
                    if(choice == 1){
                        character->gainHealth(50);
                        character->printStats();
                    }
                }
                cout << "You are nervous but muster up the courage to open the door to the kings room." << endl;
                cout << "The king notices you enter and draws his sword.\n" << endl;
                bool killKing = combatNarrative.fightKing();
                if(killKing == false){
                    break;
                }
                placeInStory ++;  
            }else if(placeInStory == 9){
                cout << "You successfully defeat the king, freeing the land from his nefarious practices." << endl;
                cout << "In honor of your actions on your journey, the people appoint you the new king of the land." << endl;
                cout << "The End." << endl;
                break;
            }
        }   
    }
};