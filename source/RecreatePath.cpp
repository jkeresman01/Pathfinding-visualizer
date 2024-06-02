#include "headers/RecreatePath.h"
#include "headers/Grid.h"

#include<thread>
#include<chrono>

using namespace std::chrono_literals;

void recreatePath(Node* node, Grid &grid, sf::RenderWindow* window){

    if(node->getState() == gc::node::State::START){
        return;
    }

    recreatePath(node->getPredecessor(),grid, window);
    node->setState(gc::node::PATH);

    std::this_thread::sleep_for(120ms);
    window->clear(sf::Color(3, 11, 28));
    grid.draw();
    window->display();
}

