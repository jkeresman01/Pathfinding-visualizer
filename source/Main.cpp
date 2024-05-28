#include "headers/Global.h"
#include <SFML/Graphics.hpp>

int main(){
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(gc::SCREEN::WIDTH, gc::SCREEN::HEIGHT), "", sf::Style::Default);
    window.setPosition(sf::Vector2i(gc::SCREEN::POSITION_X, gc::SCREEN::POSITION_Y));
    window.setFramerateLimit(gc::FRAMES_PER_SECOND);

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
 
    return EXIT_SUCCESS;
}
