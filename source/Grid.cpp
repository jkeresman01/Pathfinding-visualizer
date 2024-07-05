#include "headers/Grid.h"

#include <algorithm>
#include <cmath>

#include <SFML/Window/Mouse.hpp>

namespace pfv
{

Grid::Grid() : m_window(nullptr)
{
    initNodes();
}

Grid::~Grid()
{
    delete[] m_grid;
}

void Grid::initNodes()
{
    m_grid = new Node[grid::ROWS * grid::COLUMNS];

    for(size_t i = 0; i < grid::ROWS; ++i)
    {
        for(size_t j = 0; j < grid::COLUMNS; ++j)
        {
            m_grid[grid::COLUMNS * i + j].setGridIndex(i, j);
            m_grid[grid::COLUMNS * i + j].setPosition(
                    node::START_POSITION_X + (j * node::WIDTH), 
                    node::START_POSITION_Y + (i * node::HEIGHT));
        }
    } 
}

void Grid::restoreVisitedNodes()
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS, [](Node &n)
    { 
        n.setVisited(false);
        n.setType(node::EMPTY);
    });
}

void Grid::draw()
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS,
            [](Node &n){ n.draw(); });
}

void Grid::removeWalls()
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS,
            [](Node &n) { n.setVisible(false); });
}

void Grid::resetDistanceValues()
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS,
            [](Node &n) { n.setDistance(node::DEFAULT_DISTANCE_VALUE); });
}

void Grid::createWalls()
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS,
            [](Node &n) { n.setVisible(true); });
}

void Grid::setOutline(bool t_isOutlineVisible)
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS, 
            [&t_isOutlineVisible](Node &n) { n.setOutline(t_isOutlineVisible); });
}

void Grid::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
    setWindowNodes(t_window);
}

void Grid::setWindowNodes(sf::RenderWindow *t_window)
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS, 
        [&t_window](Node &n) { n.setWindow(t_window); });
}

Node* Grid::getNodeAtPosition(uint32_t t_positionX, uint32_t t_positionY)
{
    return &m_grid[grid::COLUMNS * t_positionX + t_positionY];
}

Node* Grid::getSelectedNode()
{
    float mousePositionX = sf::Mouse::getPosition(*m_window).x - node::WIDTH;
    float mousePositionY = sf::Mouse::getPosition(*m_window).y - node::HEIGHT;

    uint32_t cellPostionX = std::floor(mousePositionX / node::WIDTH);
    uint32_t cellPostionY = std::floor(mousePositionY / node::HEIGHT);

    return getNodeAtPosition(cellPostionY, cellPostionX);
}

} //grid
