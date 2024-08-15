#include "headers/RecreatePath.h"

namespace pfv
{

void recreatePath(sf::RenderWindow &window, Legend &legend, Node *currentNode, Grid &grid)
{
    if (currentNode->getType() == node::START)
    {
        return;
    }

    recreatePath(window, legend, currentNode->getPredecessor(), grid);

    currentNode->setType(node::PATH);

    window.clear(sf::Color(3, 11, 28));
    grid.render(window);
    legend.render(window);
    window.display();
}

} // namespace pfv
