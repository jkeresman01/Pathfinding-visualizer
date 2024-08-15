#include "headers/Wall.h"

#include "headers/PfvConstants.h"

namespace pfv
{

Wall::Wall()
{
    m_wall.setSize(sf::Vector2f(wall::WIDTH, wall::HEIGHT));
    m_wall.setOrigin(wall::ORIGIN_X, wall::ORIGIN_Y);
    m_wall.setPosition(wall::START_POSITION_X, wall::START_POSITION_Y);
    m_wall.setFillColor(sf::Color(204, 255, 229));

    setVisible(true);
}

void Wall::render(sf::RenderWindow &window) const
{
    window.draw(m_wall);
}

void Wall::rotate(float rotationAngle)
{
    m_wall.rotate(rotationAngle);
}

bool Wall::isVisible() const
{
    return m_isVisible;
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
