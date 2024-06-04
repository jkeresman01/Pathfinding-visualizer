#include "headers/Backgorund.h"

Background::Background()
{
    setImage("./resources/images/background_01.jpg");
    this->m_background.setScale(0.23, 0.23);
}

void Background::setWindow(sf::RenderWindow *t_window)
{
    this->m_window = t_window;
}

void Background::setImage(std::string t_path)
{
    this->m_path = t_path;
    this->m_texture.loadFromFile(t_path);
    this->m_background.setTexture(m_texture);
}

void Background::draw()
{
    this->m_window->draw(m_background);
}
