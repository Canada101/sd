#include <iostream>
#include "narrativeStory.cpp"
#include "Characters/Ranger.cpp"


using namespace std;

int main(){
    int player;
    cout<<"Welcome to the world of Warbles"<<endl<<"Choose a character for your adventure"<<endl<<"Option 1 Guardian "<<endl<<
    "Option 2 Ranger"<<endl<<"Option 3 Swordsman"<<endl<<"Option 4 Wizard"<<endl;
    cin >> player ;
    NarrativeStory mainStory(player);
    
    mainStory.moveThroughStory();
    mainStory.moveThroughStory();
    return 0;
};