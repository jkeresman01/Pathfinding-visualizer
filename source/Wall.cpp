#include "headers/Wall.h"
#include "headers/Global.h"
    
Wall::Wall()
{
    m_wall.setSize(sf::Vector2f(gc::wall::WIDTH, gc::wall::HEIGHT));
    m_wall.setOrigin(gc::wall::ORIGIN_X, gc::wall::ORIGIN_Y);
    m_wall.setPosition(gc::node::START_POSITION_X, gc::node::START_POSITION_Y);
    m_wall.setFillColor(sf::Color(204, 255, 229));
    setWindow(nullptr);
    setVisible(true);
}

void Wall::draw()
{
    m_window->draw(m_wall);
}

void Wall::rotate(const float t_rotationAngle)
{
    m_wall.rotate(t_rotationAngle);
}

bool Wall::isVisible() const
{
    return m_isVisible;
}

void Wall::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

void Wall::setPosition(const float t_positionX, const float t_positionY)
{
    m_wall.setPosition(t_positionX, t_positionY);
}

void Wall::setVisible(const bool t_isVisible)
{
    m_isVisible = t_isVisible;
}
