#include "headers/Node.h"
#include "headers/Global.h"
#include "headers/Wall.h"

#include <SFML/Graphics/Color.hpp>
#include <algorithm>
#include <utility>

Node::Node(){
    this->m_Node.setSize(sf::Vector2f(gc::node::WIDTH, gc::node::HEIGHT));
    this->m_Node.setOrigin(gc::node::ORIGIN_X, gc::node::ORIGIN_Y);
    this->m_Walls = new Wall[gc::wall::WALL_COUNT];
    this->m_Parent = nullptr;
    this->m_Child = nullptr;
    setState(gc::node::State::EMPTY);
    setGridIndex(gc::node::START_INDEX_X, gc::node::START_INDEX_Y);
    setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y );
    setVisible(true);
}

Node::~Node(){
    delete[] m_Walls;
}

void Node::draw(){
    this->m_Window->draw(m_Node);
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT, 
            [](Wall &w){ if(w.isVisible()){ w.draw();}});
}

bool Node::isVisited(){
    return this->m_IsVisited;
}

bool Node::isVisible(){
    return this->m_IsVisible;
}

void Node::setCoin(){
    this->m_Texture.loadFromFile("./resources/images/super_maio_coin.png");
    this->m_Node.setTexture(&m_Texture);
}

bool Node::isWallVisible(gc::wall::Position wall_position){
    return this->m_Walls[wall_position].isVisible();
}

void Node::destroyWall(gc::wall::Position wall_position){
    this->m_Walls[wall_position].setVisible(false);
}

void Node::destroyAllWalls(){
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT,[](Wall &wall){ wall.setVisible(false);});
}

gc::node::State Node::getState(){
    return this->m_State;
}

std::pair<int, int> Node::getGridIndex(){
    return this->m_GridIndex;
}

Node* Node::getParent(){
    return this->m_Parent;
}

Node* Node::getChild(){
    return this->m_Child;
}

void Node::setChild(Node* child){
    this->m_Child = child;
}

void Node::setWindow(sf::RenderWindow* window){
    this->m_Window = window;
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT, [&window](Wall &w){ w.setWindow(window);});
}

void Node::recreateAllWalls(){
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT,[](Wall &wall){ wall.setVisible(true);});
}

void Node::setVisible(bool is_visible){
    this->m_IsVisible = is_visible;
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

void Node::setGridIndex(float position_x, float position_y){
    this->m_GridIndex = std::make_pair(position_x, position_y);
}

void Node::setVisited(bool is_visited){
    this->m_IsVisited = is_visited;
    m_IsVisited ? this->m_Node.setFillColor(sf::Color(204, 255, 229))
                : this->m_Node.setFillColor(sf::Color::Transparent);
}

void Node::setParent(Node* parent){
    this->m_Parent = parent;
}

void Node::setPosition(float position_x, float position_y){
    this->m_Node.setPosition(position_x, position_y);
    std::for_each(m_Walls, m_Walls + gc::wall::WALL_COUNT,
            [&position_x, &position_y](Wall &wall){ wall.setPosition(position_x, position_y);});

    this->m_Walls[gc::wall::LEFT].rotate(gc::wall::LEFT_ROTATION_ANGLE);
    this->m_Walls[gc::wall::RIGHT].rotate(gc::wall::RIGHT_ROTATION_ANGLE);
    this->m_Walls[gc::wall::TOP].rotate(gc::wall::TOP_ROTATION_ANGLE);
    this->m_Walls[gc::wall::BOTTOM].rotate(gc::wall::BOTTOM_ROTATION_ANGLE);
}

void Node::setState(gc::node::State type){
    this->m_State = type;

    if(m_State == gc::node::State::EMPTY){
        this->m_Node.setFillColor(sf::Color::Transparent);
    }

    if(m_State == gc::node::State::START){
       this->m_Node.setFillColor(sf::Color::Green);
    }

    if(m_State == gc::node::State::TARGET){
       this->m_Node.setFillColor(sf::Color::Cyan);
    }

    if(m_State == gc::node::State::RECREATED_PATH){
       this->m_Node.setFillColor(sf::Color::Red);
    }

    if(m_State == gc::node::State::PATH){
        this->m_Node.setFillColor(sf::Color::Green);
    }
    if(m_State == gc::node::State::WALL){
        this->m_Node.setFillColor(sf::Color(255, 153, 51));
    }

}



