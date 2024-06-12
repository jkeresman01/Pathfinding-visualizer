#include "headers/Grid.h"

#include <algorithm>

#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>

Grid::Grid(sf::RenderWindow *t_window) : m_window(t_window)
{
    m_grid = new Node[gc::grid::ROWS * gc::grid::COLUMNS];
    initilazeNodes();
}

Grid::~Grid()
{
    delete[] m_grid;
}

void Grid::initilazeNodes()
{
    for(size_t i = 0; i < gc::grid::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::grid::COLUMNS; ++j)
        {
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
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n){ n.setVisited(false); });
}

void Grid::draw()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n){n.draw();});
}

void Grid::removeWalls()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n) { n.setVisible(true);});
}

Node* Grid::getNodeAtPosition(const int t_positionX, const int t_positionY)
{
    return &m_grid[gc::grid::COLUMNS * t_positionX + t_positionY];
}

