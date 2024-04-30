#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Button{
public:

    Button(){};

    Button(Vector2f pos, float width, float height, Font& font, string mess){

        button.setPosition(pos);
        button.setSize(Vector2f(width, height));
        button.setFillColor(idleColor);
        button.setOutlineThickness(2); 
        button.setOutlineColor(Color(100, 100, 100)); 


        text.setFont(font);
        text.setString(mess);
        text.setFillColor(Color::Black); 

		float xPos = (pos.x + width / 2) - (text.getLocalBounds().width / 2);
		float yPos = (pos.y + height / 2.5) - (text.getLocalBounds().height / 2);
		text.setPosition(xPos, yPos);

    }

    void drawButton(RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }

    bool isClicked(Vector2f mousePos) {
        FloatRect buttonBounds = button.getGlobalBounds();
        return buttonBounds.contains(mousePos);
    }

private:
    RectangleShape button;
    Text text;
    Color idleColor = Color::White;
    Color hoverColor;
};