#include "headers/Global.h"
#include "headers/Grid.h"

#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), "", sf::Style::Default);
    window.setPosition(sf::Vector2i(gc::screen::POSITION_X, gc::screen::POSITION_Y));
    window.setFramerateLimit(gc::FRAMES_PER_SECOND);

    Grid grid(&window);

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        grid.draw();
        window.display();
    }
 
    return EXIT_SUCCESS;
}
