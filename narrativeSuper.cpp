#include <iostream>
using namespace std;

class NarrativeSuper{

public:
    NarrativeSuper(){

    };

    int startMenu(){
        int player;
        cout<<"Welcome to the world of Warbles\nChoose a character for your adventure\nOption 1 Guardian\nOption 2 Ranger\nOption 3 Swordsman\nOption 4 Wizard"<<endl;
        cin >> player ;
        return player;
    }

};