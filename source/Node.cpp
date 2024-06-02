#include "headers/Node.h"
#include "headers/Global.h"
#include "headers/Wall.h"

#include <algorithm>
#include <utility>

#include <SFML/Graphics/Color.hpp>

Node::Node(){
    this->m_Node.setSize(sf::Vector2f(gc::node::WIDTH, gc::node::HEIGHT));
    this->m_Node.setOrigin(gc::node::ORIGIN_X, gc::node::ORIGIN_Y);
    this->m_Walls = new Wall[gc::wall::WALL_COUNT];
    this->m_Predecessor = nullptr;
    setState(gc::node::State::EMPTY);
    setGridIndex(gc::node::START_INDEX_X, gc::node::START_INDEX_Y);
    setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y );
    setVisible(false);
}

Node::~Node(){
    delete[] m_Walls;
}

void Node::draw(){
    this->m_Window->draw(m_Node);
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT, [](Wall &w){ if(w.isVisible()){ w.draw(); }});
}

bool Node::isVisited(){
    return this->m_IsVisited;
}

bool Node::isVisible(){
    return this->m_IsVisible;
}

bool Node::isWallVisible(gc::wall::Position t_wall_position){
    return this->m_Walls[t_wall_position].isVisible();
}

void Node::destroyWall(gc::wall::Position t_wall_position){
    this->m_Walls[t_wall_position].setVisible(false);
}

void Node::destroyAllWalls(){
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT,[](Wall &wall){ wall.setVisible(false);});
}

void Node::recreateAllWalls(){
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT,[](Wall &wall){ wall.setVisible(true);});
}

gc::node::State Node::getState(){
    return this->m_State;
}

std::pair<int, int> Node::getGridIndex(){
    return this->m_GridIndex;
}

Node* Node::getPredecessor(){
    return this->m_Predecessor;
}

void Node::setWindow(sf::RenderWindow *t_window){
    this->m_Window = t_window;
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT, [&t_window](Wall &w){ w.setWindow(t_window);});
}

void Node::setVisible(bool t_is_visible){
    this->m_IsVisible = t_is_visible;
    if(!m_IsVisible){
        this->m_Node.setFillColor(sf::Color::Transparent);
        destroyAllWalls();
    }else {
        recreateAllWalls();
    }
}

void Node::setOutline(){
    this->m_Node.setOutlineColor(sf::Color::Red);
    this->m_Node.setOutlineThickness(gc::node::OUTLINE_THICKNESS);
}

void Node::setGridIndex(float t_position_x, float t_position_y){
    this->m_GridIndex = std::make_pair(t_position_x, t_position_y);
}

void Node::setVisited(bool t_is_visited){
    this->m_IsVisited = t_is_visited;
    m_IsVisited ? this->m_Node.setFillColor(sf::Color(204, 255, 229))
                : this->m_Node.setFillColor(sf::Color::Transparent);
}

void Node::setPredecessor(Node* t_predecessor){
    this->m_Predecessor = t_predecessor;
}

void Node::setPosition(float t_position_x, float t_position_y){
    this->m_Node.setPosition(t_position_x, t_position_y);
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT,
            [&t_position_x, &t_position_y](Wall &wall){ wall.setPosition(t_position_x, t_position_y);});

    this->m_Walls[gc::wall::LEFT].rotate(gc::wall::LEFT_ROTATION_ANGLE);
    this->m_Walls[gc::wall::RIGHT].rotate(gc::wall::RIGHT_ROTATION_ANGLE);
    this->m_Walls[gc::wall::TOP].rotate(gc::wall::TOP_ROTATION_ANGLE);
    this->m_Walls[gc::wall::BOTTOM].rotate(gc::wall::BOTTOM_ROTATION_ANGLE);
}

void Node::setState(gc::node::State t_type){
    this->m_State = t_type;

    if(m_State == gc::node::State::EMPTY){
        this->m_Node.setFillColor(sf::Color::Transparent);
    }

    if(m_State == gc::node::State::START){
       this->m_Node.setFillColor(sf::Color::Green);
    }

    if(m_State == gc::node::State::TARGET){
       this->m_Node.setFillColor(sf::Color::Cyan);
    }

    if(m_State == gc::node::State::PATH){
        this->m_Node.setFillColor(sf::Color::Green);
    }
    if(m_State == gc::node::State::WALL){
        this->m_Node.setFillColor(sf::Color(255, 153, 51));
    }
}



