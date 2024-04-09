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
                cout << "The world of Wables is treacherous...\nCountless villains scheme and only the powerful may live as they please\nYou stare at the large castle in the distance... A testament to the kings might the story progresses.\n"<<endl;
                placeInStory ++;
            }else if(placeInStory == 1){
                cout << "You woke in a village near the castle.\nYou will face many difficulties throughtout your journey but find the castle and kill the king.\n" << endl;
                placeInStory ++;
            }else if(placeInStory == 2){
                cout << "There is some noise coming from your right where there are trees."<< endl;
                cout << "You are getting curious and started heading towards the noise.\n" << endl;
                placeInStory ++;
            }else if(placeInStory == 3){
                cout << "You reached a forest.\nYou encountered a suspicious looking stranger in the forest.\n" << endl;
                cout << "1. Ignore the stranger.\n2. Interact with the stranger.\n" << endl;
                cout << "Your Choice: ";
                cin >> choice;
                if(choice == 2){
                    npcNarrative.talkToWoodsCharacter();
                    cout << "\nAfter the interaction with the strangers, you feel a sense of responsibility as a hero and\nyou head forward to look for the dragon.\n";
                }
                cout << "\nWhile moving through the forest, you found the dragon and the dragon is about to attack you.\n";
                bool killDragon = combatNarrative.fightDragon();
                if(killDragon == false){
                    break;
                }
                placeInStory ++;
            }else if(placeInStory == 4){
                cout << "\nAfter defeating the dragon, while walking, you found a piece of paper on the ground." << endl;
                cout << "1. Pick up the paper.\n2. Ignore it." << endl;
                cout << "Your Choice: ";
                cin >> choice;
                if(choice == 1){
                    haveMap = true;
                    cout << "\nIts a map that has the location of a auspicious lake and its description says that bathing in the lake will give\nyou superpowers but there is skull sign drawn on the lake." << endl;
                    cout << "With the greed of getting a super power, you are heading towards the direction of lake.\n" << endl;
                    character->addToInventory("Map");
                }else{
                    cout << "\nYou ignored the paper and are heading in a random direction." << endl;
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
                cout << "You found the lake and also saw a danger sign on the entrance of the lake." << endl;
                cout << "You are feeling scared but you want to find out more about the lake.\nYou are looking around to see if you can find someone for more information on the lake." << endl;
                cout << "Far ahead, you spotted a man who seems to be a fisherman from the looks of his clothes and equipment.\n" << endl;
                cout << "1. Ignore the fisherman.\n2. Walk up to him and talk to him.\n" << endl;
                cout << "Your Choice : ";
                cin >> choice;
                if(choice == 2){
                    npcNarrative.talkToLakeCharacter();
                    cout << "\nAfter the interaction with the fisherman, you think that killing the lake monster is for the benefit of all\nand you start searching for the monster in the lake.\n" << endl;
                }
                cout << "\nYou are also thinking about the benefits of bathing in the lake after killing the lake monster." << endl;
                cout << "The water suddenly draws back and a lake monster appeared and is planning to attach you.\n" << endl;
                bool killLakeMonster = combatNarrative.fightLakeMonster();
                if(killLakeMonster == false){
                    break;
                }
                placeInStory ++;
            }else if(placeInStory == 6){
                cout << "\nAs a thank you, the fisherman showed you a way to find some treasure.\n" << endl;
                cout << "1. Head towards the treasure's location.\n2. Ignore it and head towards the gate of the city." << endl;
                cout << "Your Choice: ";
                cin >> choice;
                if(choice == 1){
                    cout << "\nYou found a closed cave with an imprint of a map on it entrance. Check inventory and see if you have the map.\n" << endl;
                    character->printStats();
                    if(haveMap){
                        cout << "You have the map and the cave opened when you placed the map on the imprint.\n" << endl;
                        cout << "You found a orb which will increase you health by 50.\n" << endl;
                        cout << "1. Use the orb now\n2. Keep it in inventory.\n" << endl;
                        cout << "Your Choice: ";
                        cin >> choice;
                        if(choice == 1){
                            character->gainHealth(50);
                        }else{
                            character->addToInventory("Orb");
                            character->printStats();
                            haveOrb = true;
                        }
                    }else{
                        cout << "\nUnfortunately you do not have a map and cannot open the cave.\n" << endl;
                    }
                    cout << "After visiting the cave, now you are headed towards the city gate.\n" << endl;

                }
                placeInStory ++;
            }else if(placeInStory == 7){
                cout << "You reached the gate of capital of the city." << endl;
                cout << "At the entrance you were approached by a person who identifies himself to be a former knight." << endl;
                cout << "It seems he has some valuable information that can help you to enter the castle without getting compromised\n or adive regarding the fight against the king.." << endl;
                cout << "1. Ignore him.\n2. Talk to him and find more information.\n" << endl;
                cout << "Your Choice: ";
                cin >> choice;
                if(choice == 2){
                    npcNarrative.talkToCastleCharacter();
                    cout << "\nAfter talking with the former knight, you feel more confident about fighting the king.\n" << endl;
                }
                cout << "\nYou are currently in an inn and are planning to infiltrate the castle at night.\n" << endl;
                placeInStory ++;
            }else if(placeInStory == 8){
                cout << "You decided to infiltrate the castle at night at minimum security." << endl;
                cout << "Its night time and you are getting ready for the infiltration and battle with the king." << endl;
                cout << "As the darkness of night approaches silently, you successfully infiltrated the castle and reached outside of kings room by silently passing the guards throughtout the way." << endl;
                if(haveOrb){
                    cout << "\nDo you want to use the orb you found in the cave?" << endl;
                    cout << "1.Yes\n2.No\n" << endl;
                    cout << "Your Choice: ";
                    cin >> choice;
                    if(choice == 1){
                        character->gainHealth(50);
                        character->removeFromInventory();
                        character->printStats();
                    }
                }
                cout << "You are nervous but mustered up the courage and opened the door to the kings room." << endl;
                cout << "The king notices you and draws his sword in order to prepare for a one on one fight.\n" << endl;
                bool killKing = combatNarrative.fightKing();
                if(killKing == false){
                    break;
                }
                placeInStory ++;  
            }else if(placeInStory == 9){
                cout << "You successfully defeat the king and took his power for yourself." << endl;
                cout << "Congratulations for killing the evil king and becoming a new righteous king loved by people." << endl;
                break;
            }
        }   
    }
};