#include "headers/Node.h"
#include "headers/Global.h"
#include "headers/Wall.h"

#include <algorithm>
#include <utility>

#include <SFML/Graphics/Color.hpp>

Node::Node()
{
    m_node.setSize(sf::Vector2f(gc::node::WIDTH, gc::node::HEIGHT));
    m_node.setOrigin(gc::node::ORIGIN_X, gc::node::ORIGIN_Y);
    m_walls = new Wall[gc::wall::WALL_COUNT];
    m_predecessor = nullptr;
    setWindow(nullptr);
    setType(gc::node::Type::EMPTY);
    setGridIndex(gc::node::START_INDEX_X, gc::node::START_INDEX_Y);
    setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y );
    setVisible(true);
}

Node::~Node()
{
    delete[] m_walls;
}

void Node::draw()
{
    m_window->draw(m_node);
    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT, [](Wall &w){ if(w.isVisible()){ w.draw(); }});
}

bool Node::isVisited() const
{
    return m_isVisited;
}

bool Node::isVisible() const
{
    return m_isVisible;
}

bool Node::isWallVisible(const gc::wall::Position t_wallPosition) const
{
    return m_walls[t_wallPosition].isVisible();
}

void Node::destroyWall(gc::wall::Position t_wallPosition)
{
    m_walls[t_wallPosition].setVisible(false);
}

void Node::destroyAllWalls()
{
    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT, [](Wall &wall){ wall.setVisible(false);});
}

void Node::recreateAllWalls()
{
    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT, [](Wall &wall){ wall.setVisible(true);});
}

gc::node::Type Node::getType() const
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

void Node::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT, [&t_window](Wall &w){ w.setWindow(t_window); });
}

void Node::setVisible(const bool t_isVisible)
{
    m_isVisible = t_isVisible;

    if(!m_isVisible)
    {
        m_node.setFillColor(sf::Color::Transparent);
        destroyAllWalls();
    }
    else 
    {
        recreateAllWalls();
    }
}

void Node::setOutline()
{
    m_node.setOutlineColor(sf::Color(sf::Color(204, 255, 229)));
    m_node.setOutlineThickness(gc::node::OUTLINE_THICKNESS);
}

void Node::setGridIndex(const float t_positionX, const float t_positionY)
{
    m_gridPosition = std::make_pair(t_positionX, t_positionY);
}

void Node::setVisited(const bool t_isVisited)
{
    m_isVisited = t_isVisited;
    m_isVisited ? m_node.setFillColor(sf::Color(51, 51, 255))
                : m_node.setFillColor(sf::Color::Transparent);
}

void Node::setPredecessor(Node* t_predecessor)
{
    m_predecessor = t_predecessor;
}

void Node::setPosition(const float t_positionX, const float t_positionY)
{
    m_node.setPosition(t_positionX, t_positionY);

    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT,
            [&t_positionX, &t_positionY](Wall &wall){ wall.setPosition(t_positionX, t_positionY);});

    m_walls[gc::wall::LEFT].rotate(gc::wall::LEFT_ROTATION_ANGLE);
    m_walls[gc::wall::RIGHT].rotate(gc::wall::RIGHT_ROTATION_ANGLE);
    m_walls[gc::wall::TOP].rotate(gc::wall::TOP_ROTATION_ANGLE);
    m_walls[gc::wall::BOTTOM].rotate(gc::wall::BOTTOM_ROTATION_ANGLE);
}

void Node::setType(const gc::node::Type t_type)
{
    m_type = t_type;

    if(m_type == gc::node::EMPTY)
    {
        m_node.setFillColor(sf::Color::Transparent);
    }

    if(m_type == gc::node::START)
    {
       m_node.setFillColor(sf::Color::Green);
    }

    if(m_type == gc::node::TARGET)
    {
       m_node.setFillColor(sf::Color::Cyan);
    }

    if(m_type == gc::node::PATH)
    {
        m_node.setFillColor(sf::Color::Green);
    }

    if(m_type == gc::node::WALL)
    {
        m_node.setFillColor(sf::Color(204, 255, 229));
    }
}



