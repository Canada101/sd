#include <iostream>
#include "narrativeStory.cpp"
#include "contextSwitcher.h"

using namespace std;

int main(){
    int player;
    cout<<"Welcome to the world of Warbles"<<endl<<"Choose a character for your adventure"<<endl<<"Option 1 Guardian "<<endl<<
    "Option 2 Ranger"<<endl<<"Option 3 Swordsman"<<endl<<"Option 4 Wizard"<<endl;
    cin >> player ;
    NarrativeStory mainStory(player);
 

    if (ContextSwitcher::getContext() == 1)
    {
        cout << "you are in the story" << endl;
    }else if (ContextSwitcher::getContext() == 2)
    {
        cout << "you are in combat" << endl;
    }else if (ContextSwitcher::getContext() == 3)
    {
        cout << "you are talking to someone" << endl;
    }
    mainStory.moveThroughStory();
        if (ContextSwitcher::getContext() == 1)
    {
        cout << "you are in the story" << endl;
    }else if (ContextSwitcher::getContext() == 2)
    {
        cout << "you are in combat" << endl;
    }else if (ContextSwitcher::getContext() == 3)
    {
        cout << "you are talking to someone" << endl;
    }
    mainStory.moveThroughStory();
            if (ContextSwitcher::getContext() == 1)
    {
        cout << "you are in the story" << endl;
    }else if (ContextSwitcher::getContext() == 2)
    {
        cout << "you are in combat" << endl;
    }else if (ContextSwitcher::getContext() == 3)
    {
        cout << "you are talking to someone" << endl;
    }
    mainStory.moveThroughStory();
    return 0;
};