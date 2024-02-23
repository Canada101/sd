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
                cout << "The world of Wables is treacherous...\nCountless villains scheme and only the powerful may live as they please\nYou stare at the large castle in the distance... A testament to the kings might the story progresses."<<endl;
            }else if(placeInStory == 1){
                break;
            };
            placeInStory ++;
        }   
    };

};