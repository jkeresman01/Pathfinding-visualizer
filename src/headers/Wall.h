#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace pfv
{

class Wall
{
  public:
    Wall();

    void render(sf::RenderWindow &window) const;
    void rotate(float rotationAngle);
    void move(float positionX, float positionY);

    bool isVisible() const;

    void setPosition(float positionX, float positionY);
    void setVisible(bool isVisible);

  private:
    sf::RectangleShape m_wall;
    bool m_isVisible;
};

} // namespace pfv
