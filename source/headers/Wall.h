#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Wall{
    private:
        sf::RenderWindow* m_Window;
        sf::RectangleShape m_Wall;
        bool m_IsVisible;
    
    public:
        Wall();
        void setWindow(sf::RenderWindow* window);
        void setPosition(float position_x, float position_y);
        void setOrigin(float origin_x, float origin_y);
        void setVisibility(bool is_visible);
        bool isVisible();
        void rotate(float angle);
        void move(float position_x, float position_y);
        void draw();
};
