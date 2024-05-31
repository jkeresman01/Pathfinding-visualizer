#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Background{
    private:
        sf::RenderWindow* m_Window;;
        sf::Sprite m_Background;
        sf::Texture m_Texture;
        std::string m_Path;

    public:
        Background();
        void setImage(std::string path);
        void setWindow(sf::RenderWindow* window);
        void draw();
};
