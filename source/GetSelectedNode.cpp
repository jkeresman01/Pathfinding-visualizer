#include "headers/GetSelectedNode.h"

#include "headers/Global.h"
#include <SFML/Window/Mouse.hpp>

#include <cmath>

Node* getSelectedNode(Grid &t_grid, sf::RenderWindow *t_window)
{
    float mousePositionX = sf::Mouse::getPosition(*t_window).x - gc::node::ORIGIN_X;
    float mousePositionY = sf::Mouse::getPosition(*t_window).y - gc::node::ORIGIN_Y;

    bool isMouseOnGrid = mousePositionX > gc::node::START_POSITION_X and mousePositionX < gc::node::START_POSITION_X * gc::node::WIDTH * gc::grid::COLUMNS and
                         mousePositionY > gc::node::START_POSITION_Y and mousePositionY < gc::node::HEIGHT * gc::grid::ROWS;                       

    if(isMouseOnGrid)
    {
        int cellPostionX = floor(mousePositionX / gc::node::WIDTH);
        int cellPostionY = floor(mousePositionY / gc::node::HEIGHT);

        Node* selectedNode = t_grid.getNodeAtPosition(cellPostionY, cellPostionX);

        return selectedNode;
    }

    return nullptr;
}
