#include "headers/Background.h"

#include "headers/Logger.h"
#include "headers/PfvConstants.h"

namespace pfv
{

Background::Background()
{
    initBackground();
}

void Background::initBackground()
{
    setImage("resources/images/default_background.jpg");

    m_background.setScale(menu::BACKGROND_SCALE_X, menu::BACKGROND_SCALE_Y);
}

void Background::draw()
{
    m_window->draw(m_background);
}

void Background::setScale(float t_scaleX, float t_scaleY)
{
    m_background.setScale(t_scaleX, t_scaleY);
}

void Background::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

void Background::setImage(const std::filesystem::path &t_path)
{
    if(!m_texture.loadFromFile(t_path.string()))
    {
        LOG_ERROR("Failed to load texture from " << t_path.string() << "!");
    }

    m_background.setTexture(m_texture);
}
    
} // pfv

