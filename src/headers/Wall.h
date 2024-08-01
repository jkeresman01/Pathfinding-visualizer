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

    void draw();

    void rotate(float rotationAngle);
    void move(float positionX, float positionY);

    bool isVisible() const;

    void setWindow(sf::RenderWindow *window);
    void setPosition(float positionX, float positionY);
    void setVisible(bool isVisible);

  private:
    sf::RenderWindow *m_window;
    sf::RectangleShape m_wall;
    sf::Texture m_texture;

    bool m_isVisible;
};

} // namespace pfv
