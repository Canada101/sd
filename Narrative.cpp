#include <iostream>
#include "CombatNarrative.cpp"
#include "NPCNarrative.cpp"
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

#define MAX_CHARACTER 4

class Narrative{
private:
    int placeInStory;
    bool haveMap;
    bool haveOrb;
    NarrativeNPC npcNarrative;
    CharacterSuper* character;
    Font font;
    Button characterChoice[MAX_CHARACTER];
    Text header;
    Text mess;
    Time time;

public:
    Narrative(){
        time = seconds(5);
        placeInStory = 0;  

        haveMap = false;
        haveOrb = false;       

        if (!font.loadFromFile("arial.ttf")) {
        }

        header.setFont(font);
        header.setFillColor(sf::Color::Blue);
        header.setString("Choose Your Character");
        header.setPosition(sf::Vector2f(50, 50));

        characterChoice[0] = Button(Vector2f(50, 200), 200, 50, font, "Guardian");

        characterChoice[1] = Button(Vector2f(50, 300), 200, 50, font, "Ranger");

        characterChoice[2] = Button(Vector2f(50, 400), 200, 50, font, "Swordsmen");

        characterChoice[3] = Button(Vector2f(50, 500), 200, 50, font, "Wizard");

        mess.setFont(font);
        mess.setFillColor(sf::Color::White);   
    }

    void drawCharacterMenu(RenderWindow &window){
        window.draw(header);
        for(int i = 0; i < MAX_CHARACTER; i++){
            characterChoice[i].drawButton(window);
        }
        
    }

    void handleEvents(RenderWindow &window){
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                        if(characterChoice[0].isClicked(mousePos)){
							while(window.isOpen()){    
                                character = new Guardian();
                                window.clear();
                                moveThroughStory(window);
                            }
						}else if(characterChoice[1].isClicked(mousePos)){
							while(window.isOpen()){
                                character = new Ranger();    
                                window.clear();
                                moveThroughStory(window);
                            }
						}else if(characterChoice[2].isClicked(mousePos)){
							while(window.isOpen()){    
                                character = new Swordsman();
							    window.clear();
                                moveThroughStory(window);
                            }
						}else if(characterChoice[3].isClicked(mousePos)){
							while(window.isOpen()){        
                                character = new Wizard();
                                window.clear();
                                moveThroughStory(window);
                            }
						}
                    }				
                    break;

                default:
                    break;
            }
        }
    }

    void storyJumpTo (int locationInStory){
        placeInStory = locationInStory;
    }

    void moveThroughStory(RenderWindow &window) {
       
        CombatNarrative combatNarrative(character);
       
      
        if (placeInStory == 0){
            Text context;
            context.setFont(font);
            context.setFillColor(sf::Color::White);
            context.setPosition(Vector2f(10, 50));
            context.setString("The world of Wables is treacherous...\nCountless villains scheme and only the powerful may live as they please\nYou stare at the large castle in the distance...\nA testament to the kings might the story progresses.\n");
            Text context2;
            context2.setFont(font);
            context2.setFillColor(sf::Color::White);
            context2.setPosition(Vector2f(10, 200));
            context2.setString("You woke in a village near the castle.\nYou will face many difficulties throughtout your journey\nbut find the castle and kill the king.\n");
            Text context3;
            context3.setFont(font);
            context3.setFillColor(sf::Color::White);
            context3.setPosition(Vector2f(10, 300));
            context3.setString("There is some noise coming from your right where there are trees.");
            Text context4;
            context4.setFont(font);
            context4.setFillColor(sf::Color::White);
            context4.setPosition(Vector2f(10, 400));
            context4.setString("You are getting curious and started heading towards the noise.\n");
            Text ps;
            ps.setFont(font);
            ps.setFillColor(Color::White);
            ps.setPosition(Vector2f(700, 550));
            ps.setString("Click to continue");
            
            window.draw(context);
            window.draw(context2);
            window.draw(context3);
            window.draw(context4);
            window.draw(ps);
            window.display();
                


            Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                            window.close();
                            break;
                    case sf::Event::MouseButtonPressed:
                        window.clear();
                        placeInStory++;
                }
            }

        }else if(placeInStory == 1){
            Text context;
            Button choice[2];
            context.setFont(font);
            context.setFillColor(sf::Color::White);
            context.setPosition(Vector2f(10, 50));
            context.setString("You reached a forest.\nYou encountered a suspicious looking stranger in the forest.\n");

            choice[0] = Button(Vector2f(50, 200), 400, 50, font, "Ignore the stranger");
            choice[1] = Button(Vector2f(50, 400), 400, 50, font, "Interact with the stranger");

            window.draw(context);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            window.display();
            


            Event event1;
            while (window.pollEvent(event1)) {
                switch (event1.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event1.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
						        Text ps2;
                                ps2.setFont(font);
                                ps2.setFillColor(sf::Color::White);
                                ps2.setPosition(Vector2f(10, 200));
                                ps2.setString("While moving through the forest, you found the dragon\nand the dragon is about to attack you.\n");
                                window.draw(ps2);
                                window.display();
                                sleep(time);
                                bool killDragon = combatNarrative.fightDragon(window);
                                placeInStory++;
					        }else if(choice[1].isClicked(mousePos)){
						        window.clear();
                                npcNarrative.talkToWoodsCharacter(window);
                                window.clear();
                                Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 100));
                                ps.setString("After the interaction with the strangers,\nyou feel a sense of responsibility as a hero and\nyou head forward to look for the dragon.\n");
                                Text ps2;
                                ps2.setFont(font);
                                ps2.setFillColor(sf::Color::White);
                                ps2.setPosition(Vector2f(10, 300));
                                ps2.setString("While moving through the forest, you found the dragon\nand the dragon is about to attack you.\n");
                                window.draw(ps);
                                window.draw(ps2);
                                window.display();
                                sleep(time);
                                bool killDragon = combatNarrative.fightDragon(window);
                                placeInStory++;
					        }
                        }				
                        break;

                    default:
                        break;
                }
            }
        }else if(placeInStory == 2){
            window.clear();
            Text context;
            context.setFont(font);
            context.setFillColor(sf::Color::White);
            context.setPosition(Vector2f(10, 100));
            context.setString("After defeating the dragon, you continue on your way,\nuntil you notice a piece of paper on the ground.");
            Button choice[2];
            choice[0] = Button(Vector2f(50,300), 300, 50, font, "Pick up the paper");
            choice[1] = Button(Vector2f(50,400), 200, 50, font, "Ignore it");

            window.draw(context);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            window.display();

            Event event2;
            while (window.pollEvent(event2)){
                switch (event2.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event2.mouseButton.button == Mouse::Left){
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
                                haveMap = true;
                                Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 100));
                                ps.setString("The paper is a map that has the location of a auspicious lake,\nrumored to have special properties.\nA handwritten note on the map warns\nthat the lake contains severe danger.\nIntrigued by the map, you follow the directions\nto head in the direction of the lake.");
                                character->addSpecialAbility(Map);
                                window.draw(ps);
                                window.display();
                                sleep(time);
                                sleep(time);

                                window.clear();
                                Text context2;
                                context2.setFont(font);
                                context2.setFillColor(sf::Color::White);
                                context2.setPosition(Vector2f(10, 100));
                                context2.setString("Do you want to take a look at your stats and inventory?");
                                Button option[2];
                                option[0] = Button(Vector2f(50, 250), 200, 50, font, "Yes");
                                option[1] = Button(Vector2f(50, 400), 200, 50, font, "No");

                                window.draw(context2);
                                option[0].drawButton(window);
                                option[1].drawButton(window);
                                window.display();

                                bool flag = true;
                                while(flag){
                                    Event event2_e;
                                    while (window.pollEvent(event2_e)){
                                        switch (event2_e.type){
                                            case Event::Closed:
                                                window.close();
                                                break;
                                            case Event::MouseButtonPressed:
                                                if(event2_e.mouseButton.button == Mouse::Left) {
                                                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                    if(option[0].isClicked(mousePos)){
                                                        window.clear();
                                                        Text ps;
                                                        ps.setFont(font);
                                                        ps.setFillColor(sf::Color::White);
                                                        ps.setPosition(Vector2f(10, 200));
                                                        ps.setString(character->printStats());
                                                        window.draw(ps);
                                                        window.display();
                                                        sleep(time);
                                                        placeInStory++;
                                                        flag = false;
                                                    }else if(option[1].isClicked(mousePos)){
                                                        window.clear();
                                                        placeInStory++;
                                                        flag = false;
                                                    }
                                                }				

                                            default:
                                                break;
                                        }
                                    }
                                }
					        }else if(choice[1].isClicked(mousePos)){
                                window.clear();
                                Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 200));
                                ps.setString("You ignored the paper and are heading in a random direction.");
                                window.draw(ps);
                                window.display();
                                sleep(time);
                                placeInStory++;
					        }
                        }		
                    default:
                        break;
                }
            }
            
                
        }else if(placeInStory == 3){
            Text context;
            context.setFont(font);
            context.setFillColor(sf::Color::White);
            context.setPosition(Vector2f(10, 100));
            context.setString("You arrive to the lake and note a danger sign on the road.");
            Text context2;
            context2.setFont(font);
            context2.setFillColor(sf::Color::White);
            context2.setPosition(Vector2f(10, 150));
            context2.setString("You tentatively look around for someone to talk to about the lake.");
            Text context3;
            context3.setFont(font);
            context3.setFillColor(sf::Color::White);
            context3.setPosition(Vector2f(10, 200));
            context3.setString("Far ahead, you spotted a fisherman.");
            Button choice[2];
            choice[0] = Button(Vector2f(50,300), 400, 50, font, "Ignore the fisherman");
            choice[1] = Button(Vector2f(50,400), 600, 50, font, "Walk up to him and talk to him");

            window.draw(context);
            window.draw(context2);
            window.draw(context3);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            window.display();
            

            Event event3;
            while (window.pollEvent(event3)){
                switch (event3.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event3.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
						        Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 200));
                                ps.setString("The water suddenly draws back to reveal the lake monster and\n the monster is trying to attack.");
                                window.draw(ps);
                                window.display();
                                sleep(time);
                                bool killLakeMonster = combatNarrative.fightLakeMonster(window);
                                placeInStory++;
					        }else if(choice[1].isClicked(mousePos)){
						        window.clear();
                                npcNarrative.talkToLakeCharacter(window);
                                window.clear();
                                Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 100));
                                ps.setString("After the interaction with the fisherman,\nyou decide to confront the lake monster for the good of the community.\n");
                                Text ps2;
                                ps2.setFont(font);
                                ps2.setFillColor(sf::Color::White);
                                ps2.setPosition(Vector2f(10, 300));
                                ps2.setString("The water suddenly draws back to reveal the lake monster and\n the monster is trying to attack.\n");
                                window.draw(ps);
                                window.draw(ps2);
                                window.display();
                                sleep(time);
                                sleep(time);
                                bool killLakeMonster = combatNarrative.fightLakeMonster(window);
                                placeInStory++;
					        }
                        }				
                        break;

                    default:
                        break;
                }
            }

        }else if(placeInStory == 4){
            window.clear();
            Text context;
            context.setFont(font);
            context.setFillColor(sf::Color::White);
            context.setPosition(Vector2f(10, 100));
            context.setString("As a thank you for your service to the community,\nthe fisherman tells you the local rumor of nearby treasure.");
            Button choice[2];
            choice[0] = Button(Vector2f(50,300), 500, 50, font, "Head towards the treasure's location");
            choice[1] = Button(Vector2f(50,400), 700, 50, font, "Ignore it and head towards the gate of the city");

            window.draw(context);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            window.display();

            Event event4;
            while (window.pollEvent(event4)){
                switch (event4.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event4.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
                                Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 200));
                                ps.setString("You find a closed cave with an imprint of a map on its entrance.");    
                                window.draw(ps);
                                window.display();
                                sleep(time);
                                sleep(time);
                                if(haveMap){
                                    window.clear();
                                    Text m;
                                    m.setFont(font);
                                    m.setFillColor(Color::White);
                                    m.setPosition(Vector2f(10,50));
                                    m.setString("You used the map which was found on the way\n to the lake, on the imprint to open the cave.");
                                    Text m1;
                                    m1.setFont(font);
                                    m1.setFillColor(Color::White);
                                    m1.setPosition(Vector2f(10,200));
                                    m1.setString("Inside the cave, you find a orb which will increase you health by 50.");
                                    Button option[2];
                                    option[0] = Button(Vector2f(50, 350), 400, 50, font, "Use the orb now");
                                    option[1] = Button(Vector2f(50, 450), 400, 50, font, "Keep the orb in inventory");

                                    window.draw(m);
                                    window.draw(m1);
                                    option[0].drawButton(window);
                                    option[1].drawButton(window);
                                    window.display();

                                    bool flag = true;
                                    while(flag){
                                        Event event4_e;
                                        while (window.pollEvent(event4_e)){
                                            switch (event4_e.type) {
                                                case Event::Closed:
                                                    window.close();
                                                    break;
                                                case Event::MouseButtonPressed:
                                                    if(event4_e.mouseButton.button == Mouse::Left) {
                                                        Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                        if(option[0].isClicked(mousePos)){
                                                            window.clear();
                                                            character->gainHealth(50);
                                                            Text m2;
                                                            m2.setFont(font);
                                                            m2.setFillColor(Color::White);
                                                            m2.setPosition(Vector2f(10,100));
                                                            m2.setString("You now head to the city gate on your mission to confront the king.");
                                                            window.draw(m2);
                                                            window.display();
                                                            sleep(time);
                                                            placeInStory++;
                                                            flag = false;
                                                        }else if(option[1].isClicked(mousePos)){
                                                            window.clear();
                                                            character->addSpecialAbility(Orb);
                                                            haveOrb = true;
                                                            Text m3;
                                                            m3.setFont(font);
                                                            m3.setFillColor(Color::White);
                                                            m3.setPosition(Vector2f(10, 100));
                                                            m3.setString(character->printStats());
                                                            window.draw(m3);
                                                            window.display();
                                                            sleep(time);
                                                            window.clear();
                                                            Text m4;
                                                            m4.setFont(font);
                                                            m4.setFillColor(Color::White);
                                                            m4.setPosition(Vector2f(10,100));
                                                            m4.setString("You now head to the city gate on your mission to confront the king.");
                                                            window.draw(m4);
                                                            window.display();
                                                            sleep(time);
                                                            placeInStory++;
                                                            flag = false;
                                                        }
                                                    }				

                                                default:
                                                    break;
                                            }
                                        }
                                    }
                                }else{
                                    window.clear();
                                    Text m5;
                                    m5.setFont(font);
                                    m5.setFillColor(Color::White);
                                    m5.setPosition(Vector2f(10, 150));
                                    m5.setString("Unfortunately you ignored the map on the way to the lake\n and cannot open the cave.");
                                    Text m6;
                                    m6.setFont(font);
                                    m6.setFillColor(Color::White);
                                    m6.setPosition(Vector2f(10,350));
                                    m6.setString("You now head to the city gate on your mission to confront the king.");

                                    window.draw(m5);
                                    window.draw(m6);
                                    window.display();
                                    sleep(time);
                                    placeInStory++;

                                }
					        }else if(choice[1].isClicked(mousePos)){
                                window.clear();
                                Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 200));
                                ps.setString("You now head to the city gate on your mission to confront the king.");
                                window.draw(ps);
                                window.display();
                                sleep(time);
                                placeInStory++;
					        }
                        }		
                    default:
                        break;
                }
            }
                            
        }else if(placeInStory == 5){
            window.clear();
            Text context;
            context.setFont(font);
            context.setFillColor(sf::Color::White);
            context.setPosition(Vector2f(10, 50));
            context.setString("You reach the city gates.");
            Text context2;
            context2.setFont(font);
            context2.setFillColor(sf::Color::White);
            context2.setPosition(Vector2f(10, 100));
            context2.setString("At the entrance you are approached by a person\nwho identifies himself as former knight.");
            Text context3;
            context3.setFont(font);
            context3.setFillColor(sf::Color::White);
            context3.setPosition(Vector2f(10, 200));
            context3.setString("It seems he has some valuable information\nthat can help you to enter the castle\n or advice regarding the fight against the king.");
            Button choice[2];
            choice[0] = Button(Vector2f(50,350), 400, 50, font, "Ignore him");
            choice[1] = Button(Vector2f(50,450), 600, 50, font, "Talk to him and get more information");

            window.draw(context);
            window.draw(context2);
            window.draw(context3);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            window.display();

            Event event5;
            while (window.pollEvent(event5)){
                switch (event5.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event5.mouseButton.button == Mouse::Left){
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
						        Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 200));
                                ps.setString("You check in to a nearby inn.\nIn the room, you work on your plan to infiltrate the castle.");
                                window.draw(ps);
                                window.display();
                                sleep(time);
                                placeInStory++;
					        }else if(choice[1].isClicked(mousePos)){
						        window.clear();
                                npcNarrative.talkToCastleCharacter(window);
                                sleep(time);
                            
                                window.clear();
                                Text ps;
                                ps.setFont(font);
                                ps.setFillColor(sf::Color::White);
                                ps.setPosition(Vector2f(10, 100));
                                ps.setString("You check in to a nearby inn.\nIn the room, you work on your plan to infiltrate the castle.");
                                window.draw(ps);
                                window.display();
                                sleep(time);
                                placeInStory++;
					        }
                        }				
                        break;

                    default:
                        break;
                }
            }

                
        }else if(placeInStory == 6){
            window.clear();
            Button option[2];
            Text context;
            context.setFont(font);
            context.setFillColor(sf::Color::White);
            context.setPosition(Vector2f(10, 100));
            context.setString("You decided to infiltrate the castle at night for minimum security");
            Text context2;
            context2.setFont(font);
            context2.setFillColor(sf::Color::White);
            context2.setPosition(Vector2f(10, 150));
            context2.setString("As the darkness of night approaches silently,\nyou successfully sneak into the castle and\nreached outside of king's room.");
            
            window.draw(context);
            window.draw(context2);

            if(haveOrb){
                Text context3;
                context3.setFont(font);
                context3.setFillColor(sf::Color::White);
                context3.setPosition(Vector2f(10, 300));
                context3.setString("Do you want to use the orb you found in the cave?");
                option[0] = Button(Vector2f(50,400), 200, 50, font, "Yes");
                option[1] = Button(Vector2f(50,500), 200, 50, font, "No");

                window.draw(context3);
                option[0].drawButton(window);
                option[1].drawButton(window);
            }

            window.display();

            bool flag = true;
            Event event6;
            while(flag & haveOrb){
                while (window.pollEvent(event6)){
                    switch (event6.type) {
                        case Event::Closed:
                            window.close();
                            break;
                        case Event::MouseButtonPressed:
                            if(event6.mouseButton.button == Mouse::Left){
                                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                if(option[0].isClicked(mousePos)){
                                    window.clear();
                                    character->gainHealth(50);
                                    Text ps;
                                    ps.setFont(font);
                                    ps.setFillColor(sf::Color::White);
                                    ps.setPosition(Vector2f(10, 200));
                                    ps.setString(character->printStats());
                                    window.draw(ps);
                                    window.display();
                                    sleep(time);
                                    flag = false;
                                }else if(option[1].isClicked(mousePos)){
                                    window.clear();
                                    flag = false;
                                }
                            }				
                            break;

                        default:
                            break;
                    }
                }
            }
            
            window.clear();
            Text context4;
            context4.setFont(font);
            context4.setFillColor(sf::Color::White);
            context4.setPosition(Vector2f(10, 200));
            context4.setString("You are nervous but\n you muster up the courage to open the door to the kings room.");
            Text context5;
            context5.setFont(font);
            context5.setFillColor(sf::Color::White);
            context5.setPosition(Vector2f(10, 350));
            context5.setString("The king notices you enter and draws his sword.");

            window.draw(context4);
            window.draw(context5);
            
            window.display();
            sleep(time);
            bool killKing = combatNarrative.fightKing(window);
            placeInStory++;
        }else if(placeInStory == 7){
            window.clear();
            Text context;
            context.setFont(font);
            context.setFillColor(sf::Color::White);
            context.setPosition(Vector2f(10, 50));
            context.setString("You successfully defeat the king,\nfreeing the land from his nefarious practices.");
            Text context2;
            context2.setFont(font);
            context2.setFillColor(sf::Color::White);
            context2.setPosition(Vector2f(10, 200));
            context2.setString("In honor of your actions on your journey,\nthe people appoint you the new king of the land.");
            Text context3;
            context3.setFont(font);
            context3.setFillColor(sf::Color::White);
            context3.setPosition(Vector2f(10, 500));
            context3.setString("THANK YOU FOR PLAYING");

            window.draw(context);
            window.draw(context2);
            window.draw(context3);
            window.display();
            sleep(time);
            sleep(time);
            window.close();
        }   
    }
};