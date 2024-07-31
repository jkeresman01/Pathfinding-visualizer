#pragma once

#include <filesystem>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace pfv
{

class Background
{
  public:
    Background();

    void draw();

    void setImage(const std::filesystem::path &path);
    void setScale(float scaleX, float scaleY);
    void setWindow(sf::RenderWindow *window);

  private:
    sf::RenderWindow *m_window;
    ;
    sf::Sprite m_background;
    sf::Texture m_texture;
};

} // namespace pfv
