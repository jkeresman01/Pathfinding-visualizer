#include "headers/Wall.h"

#include "headers/PfvConstants.h"

namespace pfv
{

Wall::Wall() : m_window(nullptr), m_isVisible(true)
{
    m_wall.setSize(sf::Vector2f(wall::WIDTH, wall::HEIGHT));
    m_wall.setOrigin(wall::ORIGIN_X, wall::ORIGIN_Y);
    m_wall.setPosition(wall::START_POSITION_X, wall::START_POSITION_Y);
    m_wall.setFillColor(sf::Color(204, 255, 229));
}

void Wall::draw()
{
    m_window->draw(m_wall);
}

void Wall::rotate(float rotationAngle)
{
    m_wall.rotate(rotationAngle);
}

bool Wall::isVisible() const
{
    return m_isVisible;
}

void Wall::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

void Wall::setPosition(float positionX, float positionY)
{
    m_wall.setPosition(positionX, positionY);
}

void Wall::setVisible(bool isVisible)
{
    m_isVisible = isVisible;
}

} // namespace pfv
