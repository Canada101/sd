#include "narrativeSuper.cpp"
#include <iostream>
using namespace std;

class NarrativeStory 
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

    int storyJumpTo (int locationInStory)
    {
        placeInStory = locationInStory;
    };

    void moveThroughStory() 
    {
        if (placeInStory == 0)
        {
            cout << "The world of Wables is treacherous... " <<endl<<"Countless villains scheme and only the powerful may live as they please"<<endl<<"You stare at the large castle in the distance... A testament to the kings might"<<endl;

        } else if(placeInStory == 1)
        {
            cout << "the story progresses" << endl;
        };
     placeInStory ++;
    };

};