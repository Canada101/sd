#include <iostream>
#include "narrativeStory.cpp"
using namespace std;

class ContextSwitcher 
{
    public:
    //1 = main story 2 = npc dialogue 3 = combat
    int context;
    int input;
    ContextSwitcher()
    {
        input = 1;
        NarrativeSuper story;
        int player = story.startMenu();
    
        NarrativeStory mainStory(player);
        while(1){
            mainStory.moveThroughStory();
            cin >> input;
            if(input != 1){
                break;
            }
        }
    }; 
    int changeContext(int contextType)
    {

        return 0;
    };

};