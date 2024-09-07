#include "headers/Grid.h"

#include <algorithm>
#include <cmath>

#include <SFML/Window/Mouse.hpp>

namespace pfv
{

Grid::Grid()
{
    m_grid = new Node[grid::ROWS * grid::COLUMNS];

    for (size_t i = 0; i < grid::ROWS; ++i)
    {
        for (size_t j = 0; j < grid::COLUMNS; ++j)
        {
            float positionX = node::START_POSITION_X + (j * node::WIDTH);
            float positionY = node::START_POSITION_Y + (i * node::HEIGHT);

            m_grid[grid::COLUMNS * i + j].setGridIndex(i, j);
            m_grid[grid::COLUMNS * i + j].setPosition(positionX, positionY);
        }
    }
}

Grid::~Grid()
{
    delete[] m_grid;
}

void Grid::restoreVisitedNodes()
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS, [](Node &n) {
        n.setVisited(false);
        n.setType(node::EMPTY);
    });
}

void Grid::render(sf::RenderWindow &window) const
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS,
                  [&window](const Node &n) { n.render(window); });
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
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS, [](Node &n) { n.setVisible(true); });
}

void Grid::setOutline(bool isOutlineVisible)
{
    std::for_each(m_grid, m_grid + grid::ROWS * grid::COLUMNS,
                  [isOutlineVisible](Node &n) { n.setOutline(isOutlineVisible); });
}

Node *Grid::getNodeAtPosition(uint32_t positionX, uint32_t positionY) const
{
    return &m_grid[grid::COLUMNS * positionX + positionY];
}

Node *Grid::getSelectedNode(sf::RenderWindow &window) const
{
    float mousePositionX = sf::Mouse::getPosition(window).x - node::WIDTH;
    float mousePositionY = sf::Mouse::getPosition(window).y - node::HEIGHT;

    uint32_t cellPositionX = std::floor(mousePositionX / node::WIDTH);
    uint32_t cellPositionY = std::floor(mousePositionY / node::HEIGHT);

    return getNodeAtPosition(cellPositionY, cellPositionY);
}

} // namespace pfv
