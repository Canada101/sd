#include <SFML/Graphics.hpp>
#include "menu.cpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 600), "DREAMY ADVENTURE");

    Texture backgroundImage;
    if (!backgroundImage.loadFromFile("background.jpg")) {
    }
    Sprite backgroundSprite(backgroundImage);

    Menu menu;

    while (window.isOpen()) {
        window.clear();
        window.draw(backgroundSprite);
        menu.handleEvents(window);
        menu.draw(window);
        window.display();
    }

    return 0;
}