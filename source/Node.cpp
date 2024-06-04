#include "headers/Node.h"
#include "headers/Global.h"
#include "headers/Wall.h"

#include <algorithm>
#include <utility>

#include <SFML/Graphics/Color.hpp>

Node::Node()
{
    this->m_node.setSize(sf::Vector2f(gc::node::WIDTH, gc::node::HEIGHT));
    this->m_node.setOrigin(gc::node::ORIGIN_X, gc::node::ORIGIN_Y);
    this->m_walls = new Wall[gc::wall::WALL_COUNT];
    this->m_predecessor = nullptr;
    setState(gc::node::State::EMPTY);
    setGridIndex(gc::node::START_INDEX_X, gc::node::START_INDEX_Y);
    setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y );
    setVisible(false);
}

Node::~Node()
{
    delete[] m_walls;
}

void Node::draw()
{
    this->m_window->draw(m_node);
    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT, [](Wall &w){ if(w.isVisible()){ w.draw(); }});
}

bool Node::isVisited()
{
    return this->m_isVisited;
}

bool Node::isVisible()
{
    return this->m_isVisible;
}

bool Node::isWallVisible(gc::wall::Position t_wallPosition)
{
    return this->m_walls[t_wallPosition].isVisible();
}

void Node::destroyWall(gc::wall::Position t_wallPosition)
{
    this->m_walls[t_wallPosition].setVisible(false);
}

void Node::destroyAllWalls()
{
    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT,[](Wall &wall){ wall.setVisible(false);});
}

void Node::recreateAllWalls(){
    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT,[](Wall &wall){ wall.setVisible(true);});
}

gc::node::State Node::getState(){
    return this->m_state;
}

std::pair<int, int> Node::getGridPosition(){
    return this->m_gridPosition;
}

Node* Node::getPredecessor()
{
    return this->m_predecessor;
}

void Node::setWindow(sf::RenderWindow *t_window)
{
    this->m_window = t_window;
    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT, [&t_window](Wall &w){ w.setWindow(t_window);});
}

void Node::setVisible(bool t_is_visible)
{
    this->m_isVisible = t_is_visible;

    if(!m_isVisible)
    {
        this->m_node.setFillColor(sf::Color::Transparent);
        destroyAllWalls();
    }
    else 
    {
        recreateAllWalls();
    }
}

void Node::setOutline()
{
    this->m_node.setOutlineColor(sf::Color::Red);
    this->m_node.setOutlineThickness(gc::node::OUTLINE_THICKNESS);
}

void Node::setGridIndex(float t_positionX, float t_positionY)
{
    this->m_gridPosition = std::make_pair(t_positionX, t_positionY);
}

void Node::setVisited(bool t_isVisited)
{
    this->m_isVisited = t_isVisited;
    m_isVisited ? this->m_node.setFillColor(sf::Color(204, 255, 229))
                : this->m_node.setFillColor(sf::Color::Transparent);
}

void Node::setPredecessor(Node* t_predecessor)
{
    this->m_predecessor = t_predecessor;
}

void Node::setPosition(float t_positionX, float t_positionY)
{
    this->m_node.setPosition(t_positionX, t_positionY);

    std::for_each(m_walls, m_walls + gc::wall::WALL_COUNT,
            [&t_positionX, &t_positionY](Wall &wall){ wall.setPosition(t_positionX, t_positionY);});

    this->m_walls[gc::wall::LEFT].rotate(gc::wall::LEFT_ROTATION_ANGLE);
    this->m_walls[gc::wall::RIGHT].rotate(gc::wall::RIGHT_ROTATION_ANGLE);
    this->m_walls[gc::wall::TOP].rotate(gc::wall::TOP_ROTATION_ANGLE);
    this->m_walls[gc::wall::BOTTOM].rotate(gc::wall::BOTTOM_ROTATION_ANGLE);
}

void Node::setState(gc::node::State t_type)
{
    this->m_state = t_type;

    if(m_state == gc::node::State::EMPTY)
    {
        this->m_node.setFillColor(sf::Color::Transparent);
    }

    if(m_state == gc::node::State::START)
    {
       this->m_node.setFillColor(sf::Color::Green);
    }

    if(m_state == gc::node::State::TARGET)
    {
       this->m_node.setFillColor(sf::Color::Cyan);
    }

    if(m_state == gc::node::State::PATH)
    {
        this->m_node.setFillColor(sf::Color::Green);
    }

    if(m_state == gc::node::State::WALL)
    {
        this->m_node.setFillColor(sf::Color(255, 153, 51));
    }
}



