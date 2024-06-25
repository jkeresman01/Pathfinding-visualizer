#pragma once

#include <filesystem>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Background
{
    public:
        Background();

        void draw();

        void setImage(const std::filesystem::path &t_path);
        void setScale(float t_scaleX, float t_scaleY);
        void setWindow(sf::RenderWindow *t_window);

    private:
        void initBackground();

    private:
        sf::RenderWindow *m_window;;
        sf::Sprite m_background;
        sf::Texture m_texture;
};
