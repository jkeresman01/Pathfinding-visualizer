#include "headers/Wall.h"
#include "headers/Global.h"
    
Wall::Wall(){
    this->m_Wall.setSize(sf::Vector2f(gc::wall::WIDTH, gc::wall::HEIGHT));
    this->m_Wall.setOrigin(gc::wall::ORIGIN_X, gc::wall::ORIGIN_Y);
    this->m_Wall.setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y);
    this->m_Wall.setFillColor(sf::Color(51, 51, 255));
    setVisible(true);
}

void Wall::draw(){
    this->m_Window->draw(m_Wall);
}
bool Wall::isVisible(){
    return this->m_IsVisible;
}

void Wall::setWindow(sf::RenderWindow* window){
    this->m_Window = window;
}

void Wall::setPosition(float postion_x, float position_y){
    this->m_Wall.setPosition(postion_x, position_y);
}

void Wall::setVisible(bool is_visible){
    this->m_IsVisible = is_visible;
}
