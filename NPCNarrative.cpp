#include <iostream>
using namespace std;

class NarrativeNPC{
    public:
    NarrativeNPC(){
    }

    void talkToWoodsCharacter(){
        int choice = 0;
        cout << "\nYou have decided to interact with the stranger in the forest." << endl;
        cout << "\nStranger: 'Greetings! What brings you here?'" << endl;
        cout << "1. I'm seeking adventure.\n2. I'm looking for my way to the castle...I want to speak to the King.\n3. Why are you here?" << endl;
        cin >> choice;

        while(1){
            if(choice == 1){
                cout << "Stranger: 'Adventure, you say? Well... I may have a favor to ask of you.\nYou see, there's been a horrific dragon terrorizing our villages for nearly a decade.\nThe King chooses not to do anything about it! But you, you seem brave...'" << endl;
                cout << "1. Tell me more about this dragon.\n2. Leave the conversation to look for the dragon." << endl;
                cin >> choice;

                if(choice == 1){
                    cout << "Stranger: 'The dragon is violent. Merciless. It has no regard for mere human beings.\nI'm not sure what kind of adventure you are seeking, but be careful of this creature.\nRemain aggressive, and you just may take it down once and for all...'" << endl;
                    break;
                }if(choice == 2){
                    break;
                }

            }else if(choice == 2){
                cout << "Stranger: 'That wretched King... He has never been of any help for our villages.\nA dragon has been terrorizing our villages for nearly a decade. And the King has been silent.'" << endl;
                cout << "1. Why hasn't the King done anything?\n2. Leave the conversation to look for the dragon." << endl;
                cin >> choice;

                if(choice == 1){
                    cout << "Stranger: 'The King only looks after himself and those close to him. He has no regards for us poor individuals in these villages.\nHe's been the worst King I've ever seen in my lifetime, and I've lived a very long life so far...'" << endl;
                    cout << "\nYou leave to help these villages and look for the dragon." << endl;
                    break;
                }else if(choice == 2){
                    break;
                }

            }else if(choice == 3){
                cout << "Stranger: 'I prefer to hide out in these trees from the violent dragon just further down this path.\nIt is the only way I feel safe.'" << endl;
                cout << "1. Tell me more about this dragon.\n2. Leave the conversation to look for the dragon." << endl;
                cin >> choice;

                if(choice == 1){
                    cout << "Stranger: 'The dragon is violent. It only knows terror and violence.\nHowever, it seems if you are able to defeat it... You do receive a reward in the end.'" << endl;
                    cout << "\nYou leave to look for the dragon." << endl;
                    break;
                }else if(choice == 2){
                    break;
                }

            }
        }
    }

    void talkToLakeCharacter(){
        int choice = 0;
        cout << "\nYou have decided to speak to the fisherman." << endl;
        cout << "\nFisherman: 'Hello, there! Come here to fish?'" << endl;
        cout << "1. I'm just passing through.\n2. Tell me about the lake." << endl;
        cin >> choice;

        while(1){
            if(choice == 1){
                cout << "Fisherman: 'I see. Well, be careful! There's been sightings of a huge lake monster, right along these paths.'" << endl;
                cout << "1. Why are you here, then?\n2. Leave the conversation and look for the lake monster." << endl;
                
                if(choice == 1){
                    cout << "Fisherman: 'I need to feed myself and my family somehow. The King has clearly shown he is nothing but\nuseless when it comes to our safety and basic needs.'" << endl;
                    cout << "You feel sorry for the fisherman, and continue to look for the lake monster." << endl;
                    break;
                }else if(choice == 2){
                    break;
                }

            }else if(choice == 2){
                cout << "Fisherman: 'It used to be a peaceful place...Unfortunately, it's been overrun by a giant lake monster, just further down this path.\nIt's affected people's nearby homes, and food supplies! The monster eats all the fish before we get to it!\nSadly, the King doesn't seem to care.'" << endl;
                cout << "1. Why do you think the King doesn't care?\n2. Leave the conversation and look for the lake monster." << endl;

                if(choice == 1){
                    cout << "Fisherman: 'He is simply downright selfish. But, it's alright, we make it work... I do hope you are brave enough to confront this creature.\nProvide us some peace.'" << endl;
                    cout << "You feel sorry for the fisherman, and continue to look for the lake monster." << endl;
                    break;
                }else if(choice == 2){
                    break;
                }

            }
        }
    }

    void talkToCastleCharacter(){
        int choice = 0;
        cout << "\nYou have decided to talk to the former night and see what he has to say." << endl;
        cout << "\nKnight: 'Why are you here?'" << endl;
        cout << "1. I'm here to fight the King once and for all.\n2. I should ask you the same question." << endl;
        cin >> choice;

        while(1){
            if(choice == 1){
                cout << "Knight: 'You're here to defeat the King!? Finally! Someone is brave enough to do so. Let me offer you some advice...'" << endl;
                cout << "1. I do not need advice. I will fight the King head-on.\n2. Tell me more." << endl;
                cin >> choice;

                if(choice == 1){
                    cout << "You leave before the former knight could say anything else." << endl;
                    break;
                }else if(choice == 2){
                    cout << "Knight: 'The King can be aggressive... You must match that energy. Whatever you do, do not try and run away.\nThe King is too quick, he will get you.'" << endl;
                    cout << "You leave more confident to confront the King." << endl;
                    break;
                }

            }else if(choice == 2){
                cout << "Knight: 'Clever. Truly, I have nowhere to go since the King banished me from my role as a Knight.\nHe's a horrible King, the worst these villages have ever had. He shows no mercy to the civilians that reside here.'" << endl;
                cout << "1. Do you have any advice for when I confront him?\n2. Leave and look for the King." << endl;
                cin >> choice;

                if(choice == 1){
                    cout << "Knight: 'The King can be aggressive. Whatever you do, do not try and run away.\nHe is quick, and he will get you.'" << endl;
                    cout << "You leave more confident to confront the King." << endl;
                    break;
                }else if(choice == 2){
                    break;
                }

            }
        }
    }

};