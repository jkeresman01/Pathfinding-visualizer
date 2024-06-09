#include "headers/RecreatePath.h"
#include "headers/Grid.h"

#include<thread>
#include<chrono>

using namespace std::chrono_literals;

void recreatePath(Node *t_currentNode, Grid &t_grid, sf::RenderWindow *t_window, sf::Sound &sound)
{

    if(t_currentNode->getType() == gc::node::START)
    {
        return;
    }

    recreatePath(t_currentNode->getPredecessor(), t_grid, t_window, sound);
    t_currentNode->setType(gc::node::PATH);

    std::this_thread::sleep_for(0.7s);

    t_window->clear(sf::Color(3, 11, 28));
    sound.play();
    t_grid.draw();
    t_window->display();
}

