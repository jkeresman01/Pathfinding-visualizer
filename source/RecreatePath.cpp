#include "headers/RecreatePath.h"
#include "headers/Grid.h"

#include<thread>
#include<chrono>

using namespace std::chrono_literals;

void recreatePath(Node *t_currentNode, Grid &t_grid, sf::RenderWindow *t_window)
{

    if(t_currentNode->getType() == gc::node::START)
    {
        return;
    }

    recreatePath(t_currentNode->getPredecessor(), t_grid, t_window);
    t_currentNode->setType(gc::node::PATH);

    std::this_thread::sleep_for(120ms);

    t_window->clear(sf::Color(3, 11, 28));
    t_grid.draw();
    t_window->display();
}

