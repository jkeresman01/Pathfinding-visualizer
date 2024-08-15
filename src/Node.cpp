#include "headers/Node.h"

#include <algorithm>
#include <cstddef>
#include <utility>

#include <SFML/Graphics/Color.hpp>

#include "headers/PfvConstants.h"
#include "headers/Wall.h"

namespace pfv
{

Node::Node() : m_predecessor(nullptr), m_isVisited(false), m_distance(node::DEFAULT_DISTANCE_VALUE)
{
    m_walls = new Wall[wall::WALL_COUNT];

    m_node.setSize(sf::Vector2f(node::WIDTH, node::HEIGHT));
    m_node.setOutlineThickness(node::OUTLINE_THICKNESS);
    m_node.setOrigin(node::ORIGIN_X, node::ORIGIN_Y);

    setGridIndex(node::START_INDEX_X, node::START_INDEX_Y);
    setPosition(node::START_POSITION_X, node::START_POSITION_Y);
    setType(node::EMPTY);
    setVisited(false);
    setVisible(true);
}

Node::~Node()
{
    if (m_walls != nullptr)
    {
        delete[] m_walls;
    }
}

void Node::render(sf::RenderWindow &window) const
{
    window.draw(m_node);

    for (size_t i = 0; i < wall::WALL_COUNT; ++i)
    {
        if (m_walls[i].isVisible())
        {
            m_walls[i].render(window);
        }
    }
}
bool Node::isVisited() const
{
    return m_isVisited;
}

bool Node::isVisible() const
{
    return m_isVisible;
}

bool Node::isWallVisible(wall::Position wallPosition) const
{
    return m_walls[wallPosition].isVisible();
}

void Node::destroyWall(wall::Position wallPosition)
{
    m_walls[wallPosition].setVisible(false);
}

node::Type Node::getType() const
{
    return m_type;
}

std::pair<int, int> Node::getGridPosition() const
{
    return m_gridPosition;
}

Node *Node::getPredecessor() const
{
    return m_predecessor;
}

uint32_t Node::getDistance() const
{
    return m_distance;
}

void Node::setDistance(uint32_t distance)
{
    m_distance = distance;
}

void Node::setPredecessor(Node *predecessor)
{
    m_predecessor = predecessor;
}

void Node::setVisible(bool isVisible)
{
    m_isVisible = isVisible;
    m_isVisible ? createWalls() : destroyWalls();
}

void Node::destroyWalls()
{
    std::for_each(m_walls, m_walls + wall::WALL_COUNT, [](Wall &wall) { wall.setVisible(false); });
}

void Node::createWalls()
{
    std::for_each(m_walls, m_walls + wall::WALL_COUNT, [](Wall &wall) { wall.setVisible(true); });
}

void Node::setOutline(bool isOutlineVisible)
{
    isOutlineVisible ? m_node.setOutlineColor(sf::Color(204, 255, 229))
                     : m_node.setOutlineColor(sf::Color::Transparent);
}

void Node::setGridIndex(float positionX, float positionY)
{
    m_gridPosition = std::make_pair(positionX, positionY);
}

void Node::setVisited(bool isVisited)
{
    m_isVisited = isVisited;
    m_isVisited ? m_node.setFillColor(sf::Color(51, 51, 255))
                : m_node.setFillColor(sf::Color::Transparent);
}

void Node::setPosition(float positionX, float positionY)
{
    m_node.setPosition(positionX, positionY);

    std::for_each(m_walls, m_walls + wall::WALL_COUNT,
                  [&positionX, &positionY](Wall &wall) { wall.setPosition(positionX, positionY); });

    m_walls[wall::LEFT].rotate(wall::LEFT_ROTATION_ANGLE);
    m_walls[wall::RIGHT].rotate(wall::RIGHT_ROTATION_ANGLE);
    m_walls[wall::TOP].rotate(wall::TOP_ROTATION_ANGLE);
    m_walls[wall::BOTTOM].rotate(wall::BOTTOM_ROTATION_ANGLE);
}

void Node::setType(const node::Type &type)
{
    m_type = type;

    switch (m_type)
    {
    case node::START:
        m_node.setFillColor(sf::Color::Green);
        break;
    case node::TARGET:
        m_node.setFillColor(sf::Color::Cyan);
        break;
    case node::PATH:
        m_node.setFillColor(sf::Color(229, 204, 255));
        break;
    case node::WALL:
        m_node.setFillColor(sf::Color::Magenta);
        break;
    default:
        m_node.setFillColor(sf::Color::Transparent);
        break;
    }
}

} // namespace pfv
