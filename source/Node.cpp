#include "headers/Node.h"
#include "headers/Global.h"

#include <utility>

Node::Node(){
    this->m_Node.setSize(sf::Vector2f(gc::node::HEIGHT, gc::node::WIDTH));
    this->m_Node.setOrigin(gc::node::ORIGIN_X, gc::node::ORIGIN_Y);
    setGridIndex(gc::node::START_INDEX_X, gc::node::START_INDEX_Y);
    setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y);
    setState(gc::node::State::NOT_VISITED);
}

void Node::draw(){
    this->m_Window->draw(m_Node);
}

bool Node::isVisited(){
    return this->m_IsVisited;
}

gc::node::State Node::getState(){
    return this->m_State;
}

std::pair<int, int> Node::getGridIndex(){
    return this->m_GridIndex;
}

void Node::setWindow(sf::RenderWindow* window){
    this->m_Window = window;
}

void Node::setGridIndex(float position_x, float position_y){
    this->m_GridIndex = std::make_pair(position_x, position_y);
}

void Node::setPosition(float position_x, float position_y){
    this->m_Node.setPosition(position_x, position_y);
}

void Node::setState(gc::node::State type){
    this->m_State = type;
    this->m_Node.setFillColor(sf::Color::White);

    if(m_State == gc::node::State::VISITED){
        this->m_IsVisited = true;
        this->m_Node.setFillColor(sf::Color::Green);
    }
}



