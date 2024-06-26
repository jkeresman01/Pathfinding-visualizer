#include "headers/Grid.h"

#include <algorithm>
#include <cmath>

#include <SFML/Window/Mouse.hpp>

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
    m_grid = new Node[gc::grid::ROWS * gc::grid::COLUMNS];

    for(size_t i = 0; i < gc::grid::ROWS; ++i)
    {
        for(size_t j = 0; j < gc::grid::COLUMNS; ++j)
        {
            m_grid[gc::grid::COLUMNS * i + j].setGridIndex(i, j);
            m_grid[gc::grid::COLUMNS * i + j].setPosition(
                    gc::node::START_POSITION_X + (j * gc::node::WIDTH), 
                    gc::node::START_POSITION_Y + (i * gc::node::HEIGHT));
        }
    } 
}

void Grid::restoreVisitedNodes()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n)
    { 
        n.setVisited(false);
        n.setType(gc::node::EMPTY);
    });
}

void Grid::draw()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS,
            [](Node &n){ n.draw(); });
}

void Grid::removeWalls()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS,
            [](Node &n) { n.setVisible(false); });
}

void Grid::resetDistanceValues()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS,
            [](Node &n) { n.setDistance(gc::node::DEFAULT_DISTANCE_VALUE); });
}

void Grid::createWalls()
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS,
            [](Node &n) { n.setVisible(true); });
}

void Grid::setOutline(bool t_isOutlineVisible)
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, 
            [&t_isOutlineVisible](Node &n) { n.setOutline(t_isOutlineVisible); });
}

void Grid::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
    setWindowNodes(t_window);
}

void Grid::setWindowNodes(sf::RenderWindow *t_window)
{
    std::for_each(m_grid, m_grid + gc::grid::ROWS * gc::grid::COLUMNS, 
        [&t_window](Node &n) { n.setWindow(t_window); });
}

Node* Grid::getNodeAtPosition(uint32_t t_positionX, uint32_t t_positionY)
{
    return &m_grid[gc::grid::COLUMNS * t_positionX + t_positionY];
}

Node* Grid::getSelectedNode()
{
    float mousePositionX = sf::Mouse::getPosition(*m_window).x - gc::node::WIDTH;
    float mousePositionY = sf::Mouse::getPosition(*m_window).y - gc::node::HEIGHT;

    uint32_t cellPostionX = std::floor(mousePositionX / gc::node::WIDTH);
    uint32_t cellPostionY = std::floor(mousePositionY / gc::node::HEIGHT);

    return getNodeAtPosition(cellPostionY, cellPostionX);
}
