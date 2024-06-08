#pragma once

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Mouse.hpp>

class Button
{
    public:
        Button(const std::string t_path);
        void draw();
        bool isPressed();
        void move(const float t_positionX, const float t_positionY);
        void setWindow(sf::RenderWindow *t_window);
        void setScale(const float scale);

    private:
        sf::RenderWindow *m_window;
        sf::Texture m_texture;
        sf::Sprite m_button;
        std::string m_path;
        float m_scaleFactor;

};
