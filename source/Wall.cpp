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

void Wall::rotate(float angle){
    this->m_Wall.rotate(angle);
}

bool Wall::isVisible(){
    return this->m_IsVisible;
}

void Wall::setWindow(sf::RenderWindow *t_window){
    this->m_Window = t_window;
}

void Wall::setPosition(float t_postion_x, float t_position_y){
    this->m_Wall.setPosition(t_postion_x, t_position_y);
}

void Wall::setVisible(bool t_is_visible){
    this->m_IsVisible = t_is_visible;
}
