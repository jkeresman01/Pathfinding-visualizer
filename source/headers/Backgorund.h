#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Background
{
    public:
        Background();
        void setImage(std::string t_path);
        void setWindow(sf::RenderWindow *t_window);
        void draw();

    private:
        sf::RenderWindow *m_window;;
        sf::Sprite m_background;
        sf::Texture m_texture;
        std::string m_path;
};
