#include "headers/Grid.h"

#include <algorithm>

#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>

Grid::Grid(sf::RenderWindow *t_window)
{
    this->m_window = t_window;
    this->m_grid = new Node[gc::grid::ROWS * gc::grid::COLUMNS];
    initilazeNodes();
}

void Grid::initilazeNodes()
{
    for(int i = 0; i < gc::grid::ROWS; ++i){
        for(int j = 0; j < gc::grid::COLUMNS; ++j){
            m_grid[gc::grid::COLUMNS * i + j].setWindow(m_window);
            m_grid[gc::grid::COLUMNS * i + j].setGridIndex(i, j);
            m_grid[gc::grid::COLUMNS * i + j].setPosition(
                    gc::node::START_POSITION_X + (j * gc::node::WIDTH), 
                    gc::node::START_POSITION_Y + (i * gc::node::HEIGHT));
        }
    } 
}

void Grid::restoreVisitedNodes()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n){ n.setVisited(false);});
}

Grid::~Grid()
{
    delete[] m_grid;
}

void Grid::draw()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n){if(n.isVisible()) n.draw();});
}

void Grid::removeWalls()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n) {
            n.destroyAllWalls();
            n.setOutline();
    });
}

Node* Grid::getNodeAtPosition(int t_positionX, int t_positionY)
{
    return &m_grid[gc::grid::COLUMNS * t_positionX + t_positionY];
}

