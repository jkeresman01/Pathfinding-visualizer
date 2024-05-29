#include "headers/Tile.h"
#include "headers/Global.h"

Tile::Tile(sf::RenderWindow* window){
    this->m_Window = window;
    this->m_Tile.setSize(sf::Vector2f(gc::tile::HEIGHT, gc::tile::WIDTH));
    this->m_Tile.setOutlineColor(sf::Color::Black);
    this->m_Tile.setOutlineThickness(gc::tile::OUTLINE_THICKNESS);
    this->m_Tile.setPosition(gc::tile::START_POSITION_X, gc::tile::START_POSITION_X);
    this->m_Tile.setFillColor(sf::Color::White);
    this->m_Tile.setOrigin(gc::tile::ORIGIN_X, gc::tile::ORIGIN_Y);
    this->m_Type = gc::tile::EMPTY;
    this->m_isVisted = false;
}

void Tile::draw(){
    this->m_Window->draw(m_Tile);
}

void Tile::setPosition(float position_x, float position_y){
    this->m_Tile.setPosition(position_x, position_y);
}

gc::tile::Type Tile::getType(){
    return this->m_Type;
}

void Tile::setType(gc::tile::Type type){
    this->m_Type = type;
}

bool Tile::isVisited(){
    return this->m_isVisted;
}
