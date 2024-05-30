#include "headers/Global.h"
#include "headers/Grid.h"
#include "headers/RecursiveBacktracking.h"

#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <stack>
#include <thread>

using namespace std::chrono_literals;

int main(){

    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), "", sf::Style::Default);
    window.setPosition(sf::Vector2i(gc::screen::POSITION_X, gc::screen::POSITION_Y));
    window.setFramerateLimit(gc::tool::FRAMES_PER_SECOND);

    Grid grid(&window);

    std::stack<Node*> visited_nodes;
    Node* current_node = grid.getNode(2, 2);
    current_node->setState(gc::node::State::VISITED);
    visited_nodes.push(current_node);
    int visited_count = 1;

    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (visited_count < gc::grid::ROWS * gc::grid::COLUMNS) {
            drawMaze(grid, visited_nodes, visited_count);
        }

        std::this_thread::sleep_for(30ms);
        window.clear();
        grid.draw();
        window.display();
    }

    return EXIT_SUCCESS;
}
