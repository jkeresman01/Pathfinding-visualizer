#include "headers/Background.h"

#include <iostream>

Background::Background()
{
    setImage("./resources/images/backgorund_09.jpg");
}

void Background::draw()
{
    m_window->draw(m_background);
}

void Background::setScale(const float t_scaleX, const float t_scaleY)
{
    m_background.setScale(t_scaleX, t_scaleY);
}

void Background::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

void Background::setImage(const std::string &t_path)
{
    if(!m_texture.loadFromFile(t_path))
    {
        std::cerr << "ERROR: Image can't be loaded from ./resources/images/backgorund_09.jpg" << t_path << "\n";
    }

    m_background.setTexture(m_texture);
}
