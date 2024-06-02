#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Wall{
    public:
        Wall();
        void draw();
        bool isVisible();
        void rotate(float t_angle);
        void move(float t_position_x, float t_position_y);
        void setWindow(sf::RenderWindow *t_window);
        void setPosition(float t_position_x, float t_position_y);
        void setOrigin(float t_origin_x, float t_origin_y);
        void setVisible(bool t_is_visible);

    private:
        sf::RenderWindow *m_Window;
        sf::RectangleShape m_Wall;
        sf::Texture m_Texture;
        bool m_IsVisible;
};
