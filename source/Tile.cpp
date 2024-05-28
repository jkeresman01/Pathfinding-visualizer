#include "headers/Tile.h"
#include "headers/Global.h"

Tile::Tile(sf::RenderWindow* window){
    this->m_Window = window;
    this->m_Tile.setSize(sf::Vector2f(gc::TILE::HEIGHT, gc::TILE::WIDTH));
    this->m_Tile.setOutlineColor(sf::Color::Black);
    this->m_Tile.setOutlineThickness(gc::TILE::OUTLINE_THICKNESS);
    this->m_Tile.setPosition(gc::TILE::START_POSITION_X, gc::TILE::START_POSITION_X);
    this->m_Tile.setFillColor(sf::Color::White);
    this->m_Tile.setOrigin(gc::TILE::ORIGIN_X, gc::TILE::ORIGIN_Y);
    this->m_Type = gc::TILE::EMPTY;
    this->m_isVisted = false;
}

void Tile::draw(){
    this->m_Window->draw(m_Tile);
}

void Tile::setPosition(float position_x, float position_y){
    this->m_Tile.setPosition(position_x, position_y);
}

gc::TILE::TYPE Tile::getType(){
    return this->m_Type;
}

void Tile::setType(gc::TILE::TYPE type){
    this->m_Type = type;
}

bool Tile::isVisited(){
    return this->m_isVisted;
}
