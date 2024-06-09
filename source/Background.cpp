#include "headers/Background.h"

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

void Background::setImage(std::string t_path)
{
    m_path = t_path;
    m_texture.loadFromFile(t_path);
    m_background.setTexture(m_texture);
}
