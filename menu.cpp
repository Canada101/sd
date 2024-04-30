#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"
#include "Narrative.cpp"
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 2

class Menu{
private:
	int selectedItemIndex;
	Font font;
    Button menu[MAX_NUMBER_OF_ITEMS];
	Text header;

public:
    Menu(){
		if(!font.loadFromFile("arial.ttf")){

		}

		header.setFont(font);
		header.setFillColor(Color::Blue);
		header.setString("Welcome to the World of Adventure");
		header.setPosition(Vector2f(10, 50));

        
	    menu[0] = Button(Vector2f(20,250), 300, 50, font, "Start the Adventure");
	    
        menu[1] = Button(Vector2f(20, 450), 100, 50, font, "Exit");

	    selectedItemIndex = 0;
    }

    void draw(RenderWindow &window){
		window.draw(header);
	    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
		    menu[i].drawButton(window);
	    }
    }
    void handleEvents(RenderWindow &window){
        Event event;
        while (window.pollEvent(event)){
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == Mouse::Left){
                        Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                        if(menu[1].isClicked(mousePos)){
							window.close();
						}else if(menu[0].isClicked(mousePos)){
							while(window.isOpen()){
                                window.clear();
                                Narrative story;
                                story.handleEvents(window);
                                story.drawCharacterMenu(window);
                                window.display();
                            }
						}
                    }				
                    break;

                default:
                    break;
            }
        }
    }

    
};