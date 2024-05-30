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
        void isVisible();
        void rotate(float angle);
        void move(float position_x, float position_y);
        void draw();
};
