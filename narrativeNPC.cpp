#include "narrativeSuper.cpp"
#include <iostream>
using namespace std;

class NarrativeNPC: public NarrativeSuper{
    public:
    int character;
    int characterHealth;
    int characterArmor;

    NarrativeNPC(int characterType){
        character = characterType;
    }

    void talkToWoodsCharacter(){
        int choice = 0;

        while(1){
            cout << "You have decided to interact with the stranger in the forest." << endl;
            cout << "He asks you where you are going." <<endl;
            cout << "1. Remain truthful, tell him you are seeking revenge against the king.\n2. Lie, state you are lost and trying to find your way to the market.\n3. Leave the conversation." << endl;
            cin >> choice;

            if(choice == 1){
                cout << "He seems shocked by your honesty. He offers to help. Do you accept?" << endl;
                cout << "1. Ask how he may help. 2. Say no and leave." << endl;
                cin >> choice;

                if(choice == 1){
                    cout << "It was a trick!\nAs you walk toward him, he pushes and threatens you to go back to your village.\nYou lose 25 armor." <<endl;
                    cout << "You quickly retreat and lose him in the forest." << endl;
                    characterArmor -= 25;
                    break;
                }else if(choice == 2){
                    cout << "You could see something was off about him.\nYou threaten him to stay out of your way and you continue walking down the path."<<endl;
                    break;
                }
            }else if(choice == 2){
                cout << "The stranger was wary of you at first, but brushed it off." <<endl;
                cout << "He offers you a small piece of armor, since the forest can be dangerous." << endl;
                cout << "1. Take the armor and say thank you.\n2. Take the armor from him and continue your way down the path.\n3. Say no and leave." << endl;
                cin >> choice;
                if(choice == 1){
                    cout << "The stranger appreciates your politeness and gives you the piece of armor.\nYou now have 10 extra armor." << endl;
                    characterArmor += 10;
                    break;
                }else if(choice == 2){
                    cout << "The stranger doesn't appreciate your rudeness.\nHe takes the armor away from your hands and pushes you.\nYou lose 25 armor."<<endl;
                    characterArmor -= 25;
                    break;
                }else if(choice == 3){
                    cout << "The stranger looks a little confused, but shrugs it off. You continue down the path."<<endl;
                    break;
                }
            }else if(choice == 3){
                cout << "You get a bad feeling about this stranger, and instead decide to continue down the path." << endl;
                break;
            }
        }
    }

    void talkToLakeCharacter(){
        int choice = 0;

        cout << "You have decided to speak to the fisherman. He notices you, and waves." << endl;
        cout << "1. Ask him if he's caught any big fish.\n2. Take his box of previously caught fish for replenishment.\n3. Leave." << endl;
        cin >> choice;

        while(1){
            if(choice == 1){
                cout << "The fisherman smiles and appreciates your politeness.\nHe says yes, and offers you the fish. Do you accept?" << endl;
                cout << "1. Accept the fish. 2. Say no thank you, and walk away." << endl;
                cin >> choice;

                if(choice == 1){
                    cout << "You take the fish and eat it.\n...\nThe fish was delicious! You have gained 10 health.\nYou continue down the path."<<endl;
                    characterHealth+=10;
                    break;
                }else if(choice == 2){
                    cout << "He seems offended, and as you walk away, he uses his rod to snatch a piece of your armor.\nYou have lost 25 armor."<<endl;
                    characterArmor -= 25;
                    break;
                }
            }else if(choice == 2){
                cout << "The fisherman is angry at what you've done! He trips you with his rod and begins to hit you.\nEventually, you break free and are able to retreat.\nYou have lost 45 health."<<endl;
                characterHealth -= 45;
                break;
            }else if(choice == 3){
                cout << "You felt wary of this fisherman and decide to continue on the path. He shrugs it off." << endl;
                break;
            }
        }
    }

    void talkToCastleCharacter(){
        int choice = 0;

        cout << "You have decided to talk to the former night and see what he has to say." << endl;
        cout << "1. Ask him about his experience as a knight.\n2. Threaten him to give you information.\n3. Leave the conversation." << endl;
        cin >> choice;

        while(1){
            if(choice == 1){
                cout << "The former knight tells you he was forced to resign from his position\nafter forgetting to light every lantern in the main room.\nIt may be valuable to know the king has a fear of the dark."<<endl;
                break;
            }else if(choice == 2){
                cout << "The former knight looks a bit offended at the threat, and pushes you into the castle gate.\nYou lose 10 armor."<<endl;
                cout << "After he feels satisfied with watching you appear fearful, he informs you to never\ntry to outrun the king. He will get you." << endl;
                characterArmor -= 10;
                break;
            }else if(choice == 3){
                cout << "The former knight admires your confidence to not acquire assistance. You continue down the path."<<endl;
                break;
            }
        }
    }

};