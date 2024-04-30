#include <iostream>
#include <string>
#include "Characters.cpp"
#include "SFML/Graphics.hpp"
#include "Button.cpp"
using namespace sf;
using namespace std;

class CombatNarrative{
    public:
    CharacterSuper* character;
    Text instruction[10];
    Button choice[3];
    Font font;
    Time time;

    CombatNarrative(CharacterSuper* characterType){
        time = seconds(2);

        if (!font.loadFromFile("arial.ttf")) {
        }

        character = characterType;
        for(int i = 0; i < 10; i++ ){
            instruction[i].setFont(font);
            instruction[i].setFillColor(sf::Color::White);
        }
    }

    bool fightDragon(RenderWindow &window){
        int dragonHealth = 100;
        
        bool won = false;
        while(1){
            window.clear();
            instruction[0].setPosition(Vector2f(10, 50));
            instruction[0].setString("Dragon's health is " + to_string(dragonHealth));
            instruction[1].setPosition(Vector2f(10, 150));
            instruction[1].setString("Your health is " + to_string(character->getHealth()));
            instruction[2].setPosition(Vector2f(10,200));
            instruction[2].setString("Choose your next action:");
            choice[0] = Button(Vector2f(50, 300), 600, 50, font, "Attack the dragon with your weapon");
            choice[1] = Button(Vector2f(50, 400), 300, 50, font, "Heal Yourself");
            choice[2] = Button(Vector2f(50, 500), 200, 50, font, "Hide");

            window.draw(instruction[0]);
            window.draw(instruction[1]);
            window.draw(instruction[2]);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            choice[2].drawButton(window);

            window.display();
           

            Event event;
            while (window.pollEvent(event)){
                switch (event.type){
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
                                int damageToDragon = (int)((25*(character->getStrength()/100.0))+(5*(character->getWeaponStrength()/100.0)));
                                dragonHealth-=damageToDragon;
                                instruction[3].setPosition(Vector2f(10,200));
                                instruction[3].setString("Your blow lands! The dragon loses " + to_string(damageToDragon) + " health.");
                                window.draw(instruction[3]);
                                window.display();
                                sleep(t);
					        }else if(choice[1].isClicked(mousePos)){
						        window.clear();
                                if((character->getHealth()+25)<100){
                                    character->gainHealth(25);
                                }else{
                                    character->maxHealth();
                                }
                                instruction[4].setPosition(Vector2f(10,200));
                                instruction[4].setString("You patch up your wounds. You gain 25 health");
                                window.draw(instruction[4]);
                                window.display();
                                sleep(time);
					        }else if(choice[2].isClicked(mousePos)){
                                window.clear();
                                int damageToCharacter = (int)(25*(1-(character->getArmor()/100.0)))+5;
                                character->loseHealth(damageToCharacter);
                                instruction[5].setPosition(Vector2f(10,200));
                                instruction[5].setString("You attempt to run away.\nThe dragon attacks and you lose " + to_string(damageToCharacter) + " health.");
                                window.draw(instruction[5]);
                                window.display();
                                sleep(time);
                            }
                        }				
                        break;

                    default:
                        break;
                }
            }

            if(character->getHealth()<=0){
                window.clear();
                won = false;
                instruction[6].setPosition(Vector2f(10,200));
                instruction[6].setString("The Dragon Killed You.\n\nGAME END\n");
                window.draw(instruction[6]);
                window.display();
                sleep(time);
                window.close();
               
            }else if(dragonHealth<=0){
                window.clear();
                won = true;
                instruction[7].setPosition(Vector2f(10, 200));
                instruction[7].setString("You defeat the dragon! Your armor has been increased by 10.");
                character->gainArmor(10);
                window.draw(instruction[7]);
                window.display();
                sleep(time);
                return won;
            }
        }
    }

    bool fightLakeMonster(RenderWindow &window){
        int lakeMonsterHealth = 150;

        bool won = false;
        while(1){
            window.clear();
            instruction[0].setPosition(Vector2f(10, 50));
            instruction[0].setString("Lake monster's health is " + to_string(lakeMonsterHealth));
            instruction[1].setPosition(Vector2f(10, 150));
            instruction[1].setString("Your health is " + to_string(character->getHealth()));
            instruction[2].setPosition(Vector2f(10,200));
            instruction[2].setString("Choose your next action:");
            choice[0] = Button(Vector2f(50, 300), 600, 50, font, "Attack the lake monster with your weapon");
            choice[1] = Button(Vector2f(50, 400), 300, 50, font, "Heal Yourself");
            choice[2] = Button(Vector2f(50, 500), 200, 50, font, "Hide");

            window.draw(instruction[0]);
            window.draw(instruction[1]);
            window.draw(instruction[2]);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            choice[2].drawButton(window);

            window.display();

            Event event;
            while (window.pollEvent(event)){
                switch (event.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
                                int damageToLakeMonster = (int)(25*(character->getStrength()/100.0))+(5*(character->getWeaponStrength()/100.0));
                                lakeMonsterHealth-=damageToLakeMonster;
                                instruction[3].setPosition(Vector2f(10,200));
                                instruction[3].setString("Your blow lands! The lake monster loses " + to_string(damageToLakeMonster) + " health.");
                                window.draw(instruction[3]);
                                window.display();
                                sleep(time);
					        }else if(choice[1].isClicked(mousePos)){
						        window.clear();
                                if((character->getHealth()+25)<100){
                                    character->gainHealth(25);
                                }else{
                                    character->maxHealth();
                                }
                                instruction[4].setPosition(Vector2f(10,200));
                                instruction[4].setString("You patch up your wounds. You gain 25 health");
                                window.draw(instruction[4]);
                                window.display();
                                sleep(time);
					        }else if(choice[2].isClicked(mousePos)){
                                window.clear();
                                character->loseHealth(25);
                                instruction[5].setPosition(Vector2f(10,200));
                                instruction[5].setString("You attempt to run away.\nThe dragon attacks and you lose 25 health.");
                                window.draw(instruction[5]);
                                window.display();
                                sleep(time);
                            }
                        }				
                        break;

                    default:
                        break;
                }
            }
            if(character->getHealth()<=0){
                window.clear();
                won = false;
                instruction[6].setPosition(Vector2f(10,200));
                instruction[6].setString("The Lake Monster Killed You.\n\nGAME END\n");
                window.draw(instruction[6]);
                window.display();
                sleep(time);
                window.close();
               
            }else if(lakeMonsterHealth<=0){
                window.clear();
                won = true;
                instruction[7].setPosition(Vector2f(10, 200));
                instruction[7].setString("You defeat the lake monster! Your strength has been increased.");
                character->gainArmor(10);
                window.draw(instruction[7]);
                window.display();
                sleep(time);
                return won;
            }

        }
    }
    
    bool fightKing(RenderWindow &window){
        int kingHealth = 200;
        bool won = false;

         while(1){
            window.clear();
            instruction[0].setPosition(Vector2f(10, 50));
            instruction[0].setString("The kings's health is " + to_string(kingHealth));
            instruction[1].setPosition(Vector2f(10, 150));
            instruction[1].setString("Your health is " + to_string(character->getHealth()));
            instruction[2].setPosition(Vector2f(10,200));
            instruction[2].setString("Choose your next action:");
            choice[0] = Button(Vector2f(50, 300), 600, 50, font, "Attack the king with your weapon");
            choice[1] = Button(Vector2f(50, 400), 300, 50, font, "Heal Yourself");
            choice[2] = Button(Vector2f(50, 500), 200, 50, font, "Hide");

            window.draw(instruction[0]);
            window.draw(instruction[1]);
            window.draw(instruction[2]);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            choice[2].drawButton(window);

            window.display();

            Event event;
            while (window.pollEvent(event)){
                switch (event.type){
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
                                int damageToKing = (int)(25*(character->getStrength()/100.0))+(5*(character->getWeaponStrength()/100.0));
                                kingHealth-=damageToKing;
                                instruction[3].setPosition(Vector2f(10,200));
                                instruction[3].setString("Your blow lands! The king loses " + to_string(damageToKing) + " health.");
                                window.draw(instruction[3]);
                                window.display();
                                sleep(time);
					        }else if(choice[1].isClicked(mousePos)){
						        window.clear();
                                if((character->getHealth()+25)<100){
                                    character->gainHealth(25);
                                }else{
                                    character->maxHealth();
                                }
                                instruction[4].setPosition(Vector2f(10,200));
                                instruction[4].setString("You patch up your wounds. You gain 25 health");
                                window.draw(instruction[4]);
                                window.display();
                                sleep(time);
					        }else if(choice[2].isClicked(mousePos)){
                                window.clear();
                                character->loseHealth(25);
                                instruction[5].setPosition(Vector2f(10,200));
                                instruction[5].setString("You attempt to run away.\nThe king attacks and you lose 25 health.");
                                window.draw(instruction[5]);
                                window.display();
                                sleep(time);
                            }
                        }				
                        break;

                    default:
                        break;
                }
            }
            if(character->getHealth()<=0){
                window.clear();
                won = false;
                instruction[6].setPosition(Vector2f(10,200));
                instruction[6].setString("The King Killed You.\nBetter Luck Next Time.\n\nGAME END\n");
                window.draw(instruction[6]);
                window.display();
                sleep(time);
                window.close();
               
            }else if(kingHealth<=0){
                window.clear();
                won = true;
                instruction[7].setPosition(Vector2f(10, 200));
                instruction[7].setString("You defeat the King! Your strength has been increased.");
                character->gainArmor(10);
                window.draw(instruction[7]);
                window.display();
                sleep(time);
                return won;
            }

        }
    }
};