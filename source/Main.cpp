#include "headers/Global.h"
#include "headers/Grid.h"

#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main(){

    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), "", sf::Style::Default);
    window.setPosition(sf::Vector2i(gc::screen::POSITION_X, gc::screen::POSITION_Y));
    window.setFramerateLimit(gc::tool::FRAMES_PER_SECOND);

    Grid grid(&window);

    sf::Clock clock;

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

            current_node = visited_nodes.top();

            auto neighbour = [&current_node, &grid](int x, int y){
                return grid.getNode(current_node->getGridIndex().first + x, current_node->getGridIndex().second + y);
            };

            std::vector<Node*> neighbours;
            if (current_node->getGridIndex().second > 0 && !neighbour(0, -1)->isVisited()){
                neighbours.push_back(neighbour(0, -1));
            }

            if (current_node->getGridIndex().first < gc::grid::ROWS - 1 && !neighbour(1, 0)->isVisited()){
                neighbours.push_back(neighbour(1, 0));
            }

            if (current_node->getGridIndex().second < gc::grid::COLUMNS - 1 && !neighbour(0, 1)->isVisited()){
                neighbours.push_back(neighbour(0, 1));
            }

            if (current_node->getGridIndex().first > 0 && !neighbour(-1, 0)->isVisited()){
                neighbours.push_back(neighbour(-1, 0));
            }


            if(neighbours.empty()){
                visited_nodes.pop();
            }else {
                Node* next_node = neighbours[rand() % neighbours.size()];
                next_node->setState(gc::node::State::VISITED);
                visited_nodes.push(next_node);
                visited_count++;
            }

            std::this_thread::sleep_for(40ms);
        }

        window.clear();
        grid.draw();
        window.display();
    }

    return EXIT_SUCCESS;
}
