#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Wall
{
    public:
        Wall();

        void draw();

        void rotate(float t_rotationAngle);
        void move(float t_positionX, float t_positionY);

        bool isVisible() const;

        void setWindow(sf::RenderWindow *t_window);
        void setPosition(float t_positionX, float t_positionY);
        void setVisible(bool t_isVisible);

    private:
        sf::RenderWindow *m_window;
        sf::RectangleShape m_wall;
        sf::Texture m_texture;

        bool m_isVisible;
};
