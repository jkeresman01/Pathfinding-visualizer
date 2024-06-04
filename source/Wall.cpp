#include "headers/Wall.h"
#include "headers/Global.h"
    
Wall::Wall()
{
    this->m_wall.setSize(sf::Vector2f(gc::wall::WIDTH, gc::wall::HEIGHT));
    this->m_wall.setOrigin(gc::wall::ORIGIN_X, gc::wall::ORIGIN_Y);
    this->m_wall.setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y);
    this->m_wall.setFillColor(sf::Color(51, 51, 255));
    setVisible(true);
}

void Wall::draw()
{
    this->m_window->draw(m_wall);
}

void Wall::rotate(float t_rotationAngle)
{
    this->m_wall.rotate(t_rotationAngle);
}

bool Wall::isVisible()
{
    return this->m_isVisible;
}

void Wall::setWindow(sf::RenderWindow *t_window)
{
    this->m_window = t_window;
}

void Wall::setPosition(float t_positionX, float t_positionY)
{
    this->m_wall.setPosition(t_positionX, t_positionY);
}

void Wall::setVisible(bool t_isVisible)
{
    this->m_isVisible = t_isVisible;
}
