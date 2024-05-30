#include "headers/Node.h"
#include "headers/Global.h"
#include "headers/Wall.h"

#include <algorithm>
#include <utility>

Node::Node(){
    this->m_Node.setSize(sf::Vector2f(gc::node::HEIGHT, gc::node::WIDTH));
    this->m_Node.setOrigin(gc::node::ORIGIN_X, gc::node::ORIGIN_Y);
    this->m_Walls = new Wall[gc::wall::WALL_COUNT];
    setGridIndex(gc::node::START_INDEX_X, gc::node::START_INDEX_Y);
    setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y );
    setState(gc::node::State::NOT_VISITED);
}

void Node::draw(){
    this->m_Window->draw(m_Node);
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT, 
            [](Wall &w){ if(w.isVisible()){ w.draw();}});
}

bool Node::isVisited(){
    return this->m_IsVisited;
}

void Node::destroyWall(gc::wall::Position wall_position){
    this->m_Walls[wall_position].setVisibility(false);
}

gc::node::State Node::getState(){
    return this->m_State;
}

std::pair<int, int> Node::getGridIndex(){
    return this->m_GridIndex;
}

void Node::setWindow(sf::RenderWindow* window){
    this->m_Window = window;
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT, [&window](Wall &w){ w.setWindow(window);});
}

void Node::setGridIndex(float position_x, float position_y){
    this->m_GridIndex = std::make_pair(position_x, position_y);
}

void Node::setPosition(float position_x, float position_y){
    this->m_Node.setPosition(position_x, position_y);
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT,
            [&position_x, &position_y](Wall &wall){ wall.setPosition(position_x, position_y);});

    this->m_Walls[gc::wall::LEFT].rotate(gc::wall::LEFT_ROTATION);
    this->m_Walls[gc::wall::RIGHT].rotate(gc::wall::RIGHT_ROTATION);
    this->m_Walls[gc::wall::TOP].rotate(gc::wall::TOP_ROTATION);
    this->m_Walls[gc::wall::BOTTOM].rotate(gc::wall::BOTTOM_ROTATION);
}

void Node::setState(gc::node::State type){
    this->m_State = type;
    this->m_Node.setFillColor(sf::Color::White);

    if(m_State == gc::node::State::VISITED){
        this->m_IsVisited = true;
        this->m_Node.setFillColor(sf::Color::Yellow);
    }
}



