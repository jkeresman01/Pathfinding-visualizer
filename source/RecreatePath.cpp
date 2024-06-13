#include "headers/RecreatePath.h"
#include "headers/Grid.h"

void recreatePath(Node *t_currentNode, Grid &t_grid, sf::RenderWindow *t_window)
{

    if(t_currentNode->getType() == gc::node::START)
    {
        return;
    }

    recreatePath(t_currentNode->getPredecessor(), t_grid, t_window);

    t_currentNode->setType(gc::node::PATH);

    t_window->clear(sf::Color(3, 11, 28));
    t_grid.draw();
    t_window->display();
}

