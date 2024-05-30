#include "headers/Node.h"
#include "headers/Global.h"
#include <utility>
#include <iostream>


Node::Node(){
    this->m_Node.setSize(sf::Vector2f(gc::node::HEIGHT, gc::node::WIDTH));
    this->m_Node.setOutlineColor(sf::Color::Black);
    this->m_Node.setOutlineThickness(gc::node::OUTLINE_THICKNESS);
    this->m_Node.setOrigin(gc::node::ORIGIN_X, gc::node::ORIGIN_Y);
    setGridIndex(0, 0);
    setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y);
    setState(gc::node::State::NOT_VISITED);
}

void Node::draw(){
    this->m_Window->draw(m_Node);
}

bool Node::isVisited(){
    return this->m_State == gc::node::State::VISITED;
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

    if(m_State == gc::node::State::CURRENT){
        this->m_Node.setFillColor(sf::Color::Yellow);
    }

    if(m_State == gc::node::State::NOT_VISITED){
        this->m_Node.setFillColor(sf::Color::White);
    }

    if(m_State == gc::node::State::VISITED){
        std::cout << "Stavaljam green" << std::endl;
        this->m_Node.setFillColor(sf::Color::Green);
    }

}



