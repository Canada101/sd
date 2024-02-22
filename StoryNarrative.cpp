#include <iostream>
using namespace std;

class StoryNarrative{
private:
    int startChoice;
    int charChoice;

public:
    void startMenu(){
        cout << "Welcome to the Game." << endl;
        cout << "1.New Game\n2.Load a Saved Game\n3.Exit" << endl;
        cin >> startChoice;
        if(startChoice == 1){
            cout << "Select a Character." << endl;
            cout << "1.Swordsman\n2.Wizard\n3.Ranger\n4.Guardian" << endl;
            cin >> charChoice;
            if(charChoice == 1){
                cout << "You are Swordsman." << endl;
            }else if(charChoice == 2){
                cout << "You are Wizard." << endl;
            }else if(charChoice == 3){
                cout << "You are Ranger." << endl;
            }else{
                cout << "You are Guardian." << endl;
            }
            
        } 
    }

};