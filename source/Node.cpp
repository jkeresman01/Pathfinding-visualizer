#include "headers/Node.h"

#include <algorithm>
#include <utility>

#include <SFML/Graphics/Color.hpp>

#include "headers/Global.h"
#include "headers/Wall.h"

namespace pfv
{

Node::Node() 
    : m_window(nullptr),
    m_predecessor(nullptr),
    m_distance(node::DEFAULT_DISTANCE_VALUE)
{
    m_walls = new Wall[wall::WALL_COUNT];

    m_node.setSize(sf::Vector2f(node::WIDTH, node::HEIGHT));
    m_node.setOutlineThickness(node::OUTLINE_THICKNESS);
    m_node.setOrigin(node::ORIGIN_X, node::ORIGIN_Y);

    setGridIndex(node::START_INDEX_X, node::START_INDEX_Y);
    setPosition(node::START_POSITION_X, node::START_POSITION_Y );
    setType(node::EMPTY);

    setVisible(true);
}

Node::~Node()
{
    delete[] m_walls;
}

void Node::draw()
{
    m_window->draw(m_node);
    drawWalls();
}

void Node::drawWalls()
{
    std::for_each(m_walls, m_walls + wall::WALL_COUNT,
            [](Wall &w){ if(w.isVisible()){ w.draw(); }});
}

bool Node::isVisited() const
{
    return m_isVisited;
}

bool Node::isVisible() const
{
    return m_isVisible;
}

bool Node::isWallVisible(wall::Position t_wallPosition) const
{
    return m_walls[t_wallPosition].isVisible();
}

void Node::destroyWall(wall::Position t_wallPosition)
{
    m_walls[t_wallPosition].setVisible(false);
}

void Node::destroyAllWalls()
{
    std::for_each(m_walls, m_walls + wall::WALL_COUNT,
            [](Wall &wall){ wall.setVisible(false); });
}

void Node::recreateAllWalls()
{
    std::for_each(m_walls, m_walls + wall::WALL_COUNT,
            [](Wall &wall){ wall.setVisible(true); });
}

node::Type Node::getType() const
{
    return m_type;
}

std::pair<int, int> Node::getGridPosition() const
{
    return m_gridPosition;
}

Node* Node::getPredecessor() const
{
    return m_predecessor;
}

uint32_t Node::getDistance() const
{
    return m_distance;
}

void Node::setDistance(uint32_t t_distance)
{
    m_distance = t_distance;
}

void Node::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
    setWindowWalls(t_window);
}

void Node::setWindowWalls(sf::RenderWindow *t_window)
{
    std::for_each(m_walls, m_walls + wall::WALL_COUNT,
            [&t_window](Wall &w){ w.setWindow(t_window); });
}

void Node::setVisible(bool t_isVisible)
{
    m_isVisible = t_isVisible;
    m_isVisible ? recreateAllWalls() : destroyAllWalls();
}

void Node::setOutline(bool t_isOutlineVisible)
{
    t_isOutlineVisible ? m_node.setOutlineColor(sf::Color(sf::Color(204, 255, 229)))
                       : m_node.setOutlineColor(sf::Color::Transparent);
}

void Node::setGridIndex(float t_positionX, float t_positionY)
{
    m_gridPosition = std::make_pair(t_positionX, t_positionY);
}

void Node::setVisited(bool t_isVisited)
{
    m_isVisited = t_isVisited;
    m_isVisited ? m_node.setFillColor(sf::Color(51, 51, 255))
                : m_node.setFillColor(sf::Color::Transparent);
}

void Node::setPredecessor(Node *t_predecessor)
{
    m_predecessor = t_predecessor;
}

void Node::setPosition(float t_positionX, float t_positionY)
{
    m_node.setPosition(t_positionX, t_positionY);
    setWallPosition(t_positionX, t_positionY);
}

void Node::setWallPosition(float t_positionX, float t_positionY)
{
    std::for_each(m_walls, m_walls + wall::WALL_COUNT,
            [&t_positionX, &t_positionY](Wall &wall){ wall.setPosition(t_positionX, t_positionY); });

    rotateWalls();
}

void Node::rotateWalls()
{
    m_walls[wall::LEFT].rotate(wall::LEFT_ROTATION_ANGLE);
    m_walls[wall::RIGHT].rotate(wall::RIGHT_ROTATION_ANGLE);
    m_walls[wall::TOP].rotate(wall::TOP_ROTATION_ANGLE);
    m_walls[wall::BOTTOM].rotate(wall::BOTTOM_ROTATION_ANGLE);
}

void Node::setType(node::Type t_type)
{
    m_type = t_type;

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
    
} // pfl

