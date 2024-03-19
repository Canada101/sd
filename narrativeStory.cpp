#include "narrativeSuper.cpp"
#include <iostream>
using namespace std;

class NarrativeStory: public NarrativeSuper
{

    public:
    int placeInStory;
    int playerC;
    NarrativeStory(int pNum)
    {
        playerC = pNum;
        placeInStory = 0;     
    }


    int getPlayerID() 
    {
        return playerC;
    };

    void storyJumpTo (int locationInStory)
    {
        placeInStory = locationInStory;
    };

    void moveThroughStory() 
    {
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
                cout << "You reached a forest.\nYou encountered a suspicious looking stranger in the forest." << endl;
                cout << "1. Ignore the stranger.\n2. Interact with the stranger.\n3. Attack the stranger.\n" << endl;
                placeInStory ++;
                break;
            }else if(placeInStory == 4){
                cout << "You passed the stranger and while walking, you found a map. The map has the location of a auspicious lake and its description says that bathing in the lake will give\nyou superpowers but there is skull sign drawn on the lake." << endl;
                cout << "With the greed of getting a super power, you are heading towards the direction of lake.\n" << endl;
                placeInStory ++;
            }else if(placeInStory == 5){
                cout << "You found the lake and also saw a danger sign on the entrance of the lake." << endl;
                cout << "You are feeling scared but you want to find out more about the lake.\nYou are looking around to see if you can find someone for more information on the lake." << endl;
                cout << "Far ahead, you spotted a man who seems to be a fisherman from the looks of his clothes and equipment.\n" << endl;
                cout << "1. Ignore the fisherman.\n2. Walk up to him and talk to him.\n3. Ambush him and collect his belongings if any.\n" << endl;
                placeInStory ++;
                break;
            }else if(placeInStory == 6){
                cout << "You ignored the fisherman.\nYou are confused whether to take the risk of diving in the lake to get the superpower or just pass the gate and head towards direction of\nthe tall gate in your sight." << endl;
                cout << "1. Head towards the gate.\n2. Dive in the lake.\n" << endl;
                placeInStory ++;
                break;
            }else if(placeInStory == 7){
                cout << "You reached the gate of capital of the city." << endl;
                cout << "At the entrance you were approached by a person who identifies himself to be a former knight." << endl;
                cout << "It seems he has some valuable information that can help you to enter the castle without getting compromised." << endl;
                cout << "1. Ignore him.\n2. Talk to him and find more information.\3. Kill the knight as you think it might be a trap to catch/kill you.\n" << endl;
                placeInStory ++;
                break;
            }else if(placeInStory == 8){
                cout << "You ignored him and decided to infiltrate the castle." << endl;
                cout << "1. Infiltrate the castle at night and catch the king offguard.\n2. Infiltrate now as you suspect your identity has been exposed by the former knight.\n" << endl; 
                placeInStory ++;
                break;
            }else if(placeInStory == 9){
                cout << "You decided to infiltrate the castle at night at minimum security." << endl;
                cout << "Its night time and you are getting ready for the infiltration and battle with the king." << endl;
                cout << "As the darkness of night approaches silently, you successfully reached outside of kings room by silently passing the guards throughtout the way." << endl;
                cout << "1. Silently try to crack the lock on the door while there is a possibility that you might be compromised by the guards on their rounds.\n2. Barge in the room forcefully and fight the king while the guards will be alerted.\n3. try to find the guard that has the key to the room.\n" << endl;
                placeInStory ++;  
                break;
            }else if(placeInStory == 10){
                cout << "Luckily, the lock was easy to break and you entered the king's room without being noticed by the guards." << endl;
                cout << "Unfortunately, the king is awake and he alerted the guardsof the castle." << endl;
                cout << "But it might take a while for the guards to reach the kings room and you have a chance at fighting the king." << endl;
                cout << "1. Fight the king.\n2. You think you will not win against the king and ask for forgiveness to spare you life.\n3. Try to escape the castle.\n4. To exit the terminal press any option except 1." << endl;
                placeInStory ++;
                break;
            }
        }   
    };

};