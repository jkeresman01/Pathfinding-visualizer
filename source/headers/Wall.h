#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Wall{
    private:
        sf::RenderWindow* m_Window;
        sf::RectangleShape m_Wall;
        sf::Texture m_Texture;
        bool m_IsVisible;
    
    public:
        Wall();
        void draw();
        bool isVisible();
        void rotate(float angle);
        void move(float position_x, float position_y);
        void setWindow(sf::RenderWindow* window);
        void setPosition(float position_x, float position_y);
        void setOrigin(float origin_x, float origin_y);
        void setVisible(bool is_visible);
};
