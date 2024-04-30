#include <iostream>
// #include "Button.cpp"
using namespace sf;
using namespace std;

class NarrativeNPC{
    public:
    Text instruction[10];
    Button choice[3];
    Font font;
    Time t;

    NarrativeNPC(){
        t = seconds(4);

        if (!font.loadFromFile("arial.ttf")) {
        }

        for(int i = 0; i < 10; i++ ){
            instruction[i].setFont(font);
            instruction[i].setFillColor(sf::Color::White);
        }
    }

    void talkToWoodsCharacter(RenderWindow &window){
        while (1){
            window.clear();
            instruction[0].setPosition(Vector2f(10,50));
            instruction[0].setString("You have decided to interact with the stranger in the forest.");
            instruction[1].setPosition(Vector2f(10,100));
            instruction[1].setString("Stranger: 'Greetings! What brings you here?'");
            choice[0] = Button(Vector2f(50, 200), 400, 50, font, "I'm seeking adventure");
            choice[1] = Button(Vector2f(50, 300), 900, 50, font, "I'm looking for my way to the castle...I want to speak to the King");
            choice[2] = Button(Vector2f(50, 400), 400, 50, font, "Why are you here?");

            window.draw(instruction[0]);
            window.draw(instruction[1]);
            choice[0].drawButton(window);
            choice[1].drawButton(window);
            choice[2].drawButton(window);

            window.display();
            

            Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
                                instruction[2].setPosition(Vector2f(10,50));
                                instruction[2].setString("Stranger: 'Adventure, you say? Well... I may have a favor to ask of you.\nYou see, there's been a horrific dragon terrorizing our villages\nfor nearly a decade.\nThe King chooses not to do anything about it! But you, you seem brave...'");
                                Button conv[2];
                                conv[0] = Button(Vector2f(50, 300), 450, 50, font, "Tell me more about this dragon");
                                conv[1] = Button(Vector2f(50, 400), 650, 50, font, "Leave the conversation to look for the dragon");
                                window.draw(instruction[2]);
                                conv[0].drawButton(window);
                                conv[1].drawButton(window);

                                window.display();
                                
                                
                                while(1){
                                    Event event2;
                                    while (window.pollEvent(event2)){
                                        switch(event2.type) {
                                            case Event::Closed:
                                                window.close();
                                                break;
                                            case Event::MouseButtonPressed:
                                                if(event2.mouseButton.button == Mouse::Left) {
                                                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                    if(conv[0].isClicked(mousePos)){
                                                        window.clear();
                                                        instruction[3].setPosition(Vector2f(10, 200));
                                                        instruction[3].setString("Stranger: 'The dragon is violent. Merciless.\nIt has no regard for mere human beings.\nI'm not sure what kind of adventure you are seeking,\nbut be careful of this creature.\nRemain aggressive, and you just may take it down once and for all...");
                                                        window.draw(instruction[3]);
                                                        window.display();
                                                        sleep(t);
                                                        return;
                                                    }else if(conv[1].isClicked(mousePos)){
                                                        return;
                                                    }
                                                }
                                                break;				

                                            default:
                                                break;
                                        }
                                    }
                                }

                            }else if(choice[1].isClicked(mousePos)){
                                window.clear();
                                instruction[4].setPosition(Vector2f(10,50));
                                instruction[4].setString("Stranger: 'That wretched King...\nHe has never been of any help for our villages.\nA dragon has been terrorizing our villages\nfor nearly a decade. And the King has been silent.'");
                                Button conv[2];
                                conv[0] = Button(Vector2f(50, 300), 500, 50, font, "Why hasn't the King done anything?");
                                conv[1] = Button(Vector2f(50, 400), 650, 50, font, "Leave the conversation to look for the dragon");
                                window.draw(instruction[4]);
                                conv[0].drawButton(window);
                                conv[1].drawButton(window);

                                window.display();
                                
                                
                                while(1){
                                    Event event2;
                                    while (window.pollEvent(event2)){
                                        switch(event2.type) {
                                            case Event::Closed:
                                                window.close();
                                                break;
                                            case Event::MouseButtonPressed:
                                                if(event2.mouseButton.button == Mouse::Left) {
                                                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                    if(conv[0].isClicked(mousePos)){
                                                        window.clear();
                                                        instruction[5].setPosition(Vector2f(10, 100));
                                                        instruction[5].setString("Stranger: 'The King only looks after himself and those close to him.\nHe has no regards for us poor individuals in these villages.\nHe's been the worst King I've ever seen in my lifetime,\nand I've lived a very long life so far...'");
                                                        instruction[6].setPosition(Vector2f(10,400));
                                                        instruction[6].setString("You leave to help these villages.");
                                                        window.draw(instruction[5]);
                                                        window.draw(instruction[6]);
                                                        window.display();
                                                        sleep(t);
                                                        return;
                                                    }else if(conv[1].isClicked(mousePos)){
                                                        return;
                                                    }
                                                }
                                                break;				

                                            default:
                                                break;
                                        }
                                    }
                                }

                            }else if(choice[2].isClicked(mousePos)){
                                window.clear();
                                instruction[7].setPosition(Vector2f(10,50));
                                instruction[7].setString("Stranger: 'I prefer to hide out in these trees from the violent dragon\njust further down this path.\nIt is the only way I feel safe.'");
                                Button conv[2];
                                conv[0] = Button(Vector2f(50, 300), 500, 50, font, "Tell me more about this dragon.");
                                conv[1] = Button(Vector2f(50, 400), 650, 50, font, "Leave the conversation to look for the dragon");
                                window.draw(instruction[7]);
                                conv[0].drawButton(window);
                                conv[1].drawButton(window);

                                window.display();
                                
                                
                                while(1){
                                    Event event2;
                                    while (window.pollEvent(event2)){
                                        switch(event2.type) {
                                            case Event::Closed:
                                                window.close();
                                                break;
                                            case Event::MouseButtonPressed:
                                                if(event2.mouseButton.button == Mouse::Left) {
                                                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                    if(conv[0].isClicked(mousePos)){
                                                        window.clear();
                                                        instruction[8].setPosition(Vector2f(10, 200));
                                                        instruction[8].setString("Stranger: 'The dragon is violent. It only knows terror and violence.\nHowever, it seems if you are able to defeat it...\nYou do receive a reward in the end.'");
                                                        instruction[9].setPosition(Vector2f(10,400));
                                                        instruction[9].setString("You leave to look for the dragon.");
                                                        window.draw(instruction[8]);
                                                        window.draw(instruction[9]);
                                                        window.display();
                                                        sleep(t);
                                                        return;
                                                    }else if(conv[1].isClicked(mousePos)){
                                                        return;
                                                    }
                                                }
                                                break;				

                                            default:
                                                break;
                                        }
                                    }
                                }
                            }
                        }				
                        break;

                    default:
                        break;
                }
            }
        }


    }


    void talkToLakeCharacter(RenderWindow &window){

        while (1){
            window.clear();
            instruction[0].setPosition(Vector2f(10,50));
            instruction[0].setString("You have decided to speak to the fisherman.");
            instruction[1].setPosition(Vector2f(10,100));
            instruction[1].setString("Fisherman: 'Hello, there! Come here to fish?'");
            choice[0] = Button(Vector2f(50, 200), 400, 50, font, "I'm just passing through.");
            choice[1] = Button(Vector2f(50, 300), 400, 50, font, "Tell me about the lake.");
            
            window.draw(instruction[0]);
            window.draw(instruction[1]);
            choice[0].drawButton(window);
            choice[1].drawButton(window);

            window.display();
            

            Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
                                instruction[2].setPosition(Vector2f(10,50));
                                instruction[2].setString("Fisherman: 'I see. Well, be careful!\nThere's been sightings of a huge lake monster, right along these paths.'");
                                Button conv[2];
                                conv[0] = Button(Vector2f(50, 300), 450, 50, font, " Why are you here, then?");
                                conv[1] = Button(Vector2f(50, 400), 750, 50, font, "Leave the conversation to look for the lake monster");
                                window.draw(instruction[2]);
                                conv[0].drawButton(window);
                                conv[1].drawButton(window);

                                window.display();
                                
                                
                                while(1){
                                    Event event2;
                                    while (window.pollEvent(event2)){
                                        switch(event2.type) {
                                            case Event::Closed:
                                                window.close();
                                                break;
                                            case Event::MouseButtonPressed:
                                                if(event2.mouseButton.button == Mouse::Left) {
                                                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                    if(conv[0].isClicked(mousePos)){
                                                        window.clear();
                                                        instruction[3].setPosition(Vector2f(10, 200));
                                                        instruction[3].setString("Fisherman: 'I need to feed myself and my family somehow.\nThe King has clearly shown he is nothing but\nuseless when it comes to our safety and basic needs.'\n\nYou feel sorry for the fisherman.");
                                                        window.draw(instruction[3]);
                                                        window.display();
                                                        sleep(t);
                                                        return;
                                                    }else if(conv[1].isClicked(mousePos)){
                                                        return;
                                                    }
                                                }
                                                break;				

                                            default:
                                                break;
                                        }
                                    }
                                }

                            }else if(choice[1].isClicked(mousePos)){
                                window.clear();
                                instruction[4].setPosition(Vector2f(10,50));
                                instruction[4].setString("Fisherman: 'It used to be a peaceful place...\nUnfortunately, it's been overrun by a giant lake monster,\njust further down this path.\nIt's affected people's nearby homes, and food supplies!\nThe monster eats all the fish before we get to it!\nSadly, the King doesn't seem to care.'");
                                Button conv[2];
                                conv[0] = Button(Vector2f(50, 300), 600, 50, font, "Why do you think the King doesn't care?");
                                conv[1] = Button(Vector2f(50, 400), 750, 50, font, "Leave the conversation and look for the lake monster");
                                window.draw(instruction[4]);
                                conv[0].drawButton(window);
                                conv[1].drawButton(window);

                                window.display();
                                
                                
                                while(1){
                                    Event event2;
                                    while (window.pollEvent(event2)){
                                        switch(event2.type) {
                                            case Event::Closed:
                                                window.close();
                                                break;
                                            case Event::MouseButtonPressed:
                                                if(event2.mouseButton.button == Mouse::Left) {
                                                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                    if(conv[0].isClicked(mousePos)){
                                                        window.clear();
                                                        instruction[5].setPosition(Vector2f(10, 100));
                                                        instruction[5].setString("Fisherman: 'He is simply downright selfish.\nBut, it's alright, we make it work...\nI do hope you are brave enough to confront this creature.\nProvide us some peace.'");
                                                        instruction[6].setPosition(Vector2f(10,400));
                                                        instruction[6].setString("You feel sorry for the fisherman");
                                                        window.draw(instruction[5]);
                                                        window.draw(instruction[6]);
                                                        window.display();
                                                        sleep(t);
                                                        return;
                                                    }else if(conv[1].isClicked(mousePos)){
                                                        return;
                                                    }
                                                }
                                                break;				

                                            default:
                                                break;
                                        }
                                    }
                                }

                            }
                        }				
                        break;

                    default:
                        break;
                }
            }
        }
    }

    void talkToCastleCharacter(RenderWindow &window){
         while (1){
            window.clear();
            instruction[0].setPosition(Vector2f(10,50));
            instruction[0].setString("You have decided to talk to the former night and see what he has to say.");
            instruction[1].setPosition(Vector2f(10,100));
            instruction[1].setString("Knight: 'Why are you here?'");
            choice[0] = Button(Vector2f(50, 200), 600, 50, font, "I'm here to fight the King once and for all");
            choice[1] = Button(Vector2f(50, 300), 500, 50, font, "I should ask you the same question.");
            
            window.draw(instruction[0]);
            window.draw(instruction[1]);
            choice[0].drawButton(window);
            choice[1].drawButton(window);

            window.display();
            

            Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                    case Event::Closed:
                        window.close();
                        break;
                    case Event::MouseButtonPressed:
                        if(event.mouseButton.button == Mouse::Left) {
                            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                            if(choice[0].isClicked(mousePos)){
                                window.clear();
                                instruction[2].setPosition(Vector2f(10,50));
                                instruction[2].setString("Knight: 'You're here to defeat the King!?\nFinally! Someone is brave enough to do so.\nLet me offer you some advice...'");
                                Button conv[2];
                                conv[0] = Button(Vector2f(50, 300), 800, 50, font, " I do not need advice. I will fight the King head-on");
                                conv[1] = Button(Vector2f(50, 400), 350, 50, font, "Tell me more.");
                                window.draw(instruction[2]);
                                conv[0].drawButton(window);
                                conv[1].drawButton(window);

                                window.display();
                                
                                
                                while(1){
                                    Event event2;
                                    while (window.pollEvent(event2)){
                                        switch(event2.type) {
                                            case Event::Closed:
                                                window.close();
                                                break;
                                            case Event::MouseButtonPressed:
                                                if(event2.mouseButton.button == Mouse::Left) {
                                                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                    if(conv[0].isClicked(mousePos)){
                                                        window.clear();
                                                        instruction[3].setPosition(Vector2f(10, 200));
                                                        instruction[3].setString("You leave before the former knight could say anything else");
                                                        window.draw(instruction[3]);
                                                        window.display();
                                                        sleep(t);
                                                        return;
                                                    }else if(conv[1].isClicked(mousePos)){
                                                        window.clear();
                                                        instruction[3].setPosition(Vector2f(10, 100));
                                                        instruction[3].setString("Knight: 'The King can be aggressive...\nYou must match that energy.\nWhatever you do, do not try and run away.\nThe King is too quick, he will get you.\n\nYou leave more confident.");
                                                        window.draw(instruction[3]);
                                                        window.display();
                                                        sleep(t);
                                                        return;
                                                    }
                                                }
                                                break;				

                                            default:
                                                break;
                                        }
                                    }
                                }

                            }else if(choice[1].isClicked(mousePos)){
                                window.clear();
                                instruction[4].setPosition(Vector2f(10,50));
                                instruction[4].setString("Knight: 'Clever.\nTruly, I have nowhere to go since the King banished me from my role as a\nKnight.\nHe's a horrible King, the worst these villages have ever had.\nHe shows no mercy to the civilians that reside here.'");
                                Button conv[2];
                                conv[0] = Button(Vector2f(50, 300), 750, 50, font, "Do you have any advice for when I confront him?");
                                conv[1] = Button(Vector2f(50, 400), 600, 50, font, "Leave and look for the King.");
                                window.draw(instruction[4]);
                                conv[0].drawButton(window);
                                conv[1].drawButton(window);

                                window.display();
                                
                                
                                while(1){
                                    Event event2;
                                    while (window.pollEvent(event2)){
                                        switch(event2.type) {
                                            case Event::Closed:
                                                window.close();
                                                break;
                                            case Event::MouseButtonPressed:
                                                if(event2.mouseButton.button == Mouse::Left) {
                                                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                                                    if(conv[0].isClicked(mousePos)){
                                                        window.clear();
                                                        instruction[5].setPosition(Vector2f(10, 100));
                                                        instruction[5].setString("Knight: 'The King can be aggressive.\nWhatever you do, do not try and run away.\nHe is quick, and he will get you.'");
                                                        instruction[6].setPosition(Vector2f(10,400));
                                                        instruction[6].setString("You leave more confident.");
                                                        window.draw(instruction[5]);
                                                        window.draw(instruction[6]);
                                                        window.display();
                                                        sleep(t);
                                                        return;
                                                    }else if(conv[1].isClicked(mousePos)){
                                                        return;
                                                    }
                                                }
                                                break;				

                                            default:
                                                break;
                                        }
                                    }
                                }

                            }
                        }				
                        break;

                    default:
                        break;
                }
            }
        }
    }
};