#include "headers/RecreatePath.h"

void recreatePath(sf::RenderWindow *t_window,
                  Legend &t_legend,
                  Node *t_currentNode,
                  Grid &t_grid)
{
    if(t_currentNode->getType() == gc::node::START)
    {
        return;
    }

    recreatePath(t_window, t_legend, t_currentNode->getPredecessor(), t_grid);

    t_currentNode->setType(gc::node::PATH);

    t_window->clear(sf::Color(3, 11, 28));
    t_grid.draw();
    t_legend.draw();
    t_window->display();
}

