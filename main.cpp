#include <iostream>
#include "Characters/characterSuper.cpp"
#include "Characters/Ranger.cpp"
using namespace std;

int main(){
    Ranger ranger;
    cout << ranger.getSpeed() << endl;
    return 0;
}