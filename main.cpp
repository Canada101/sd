#include <iostream>
#include "narrativeStory.cpp"
#include "Characters/Ranger.cpp"

using namespace std;

int main(){
    NarrativeSuper story;
    int player = story.startMenu();
    
    NarrativeStory mainStory(player);
    
    mainStory.moveThroughStory();
    return 0;
};