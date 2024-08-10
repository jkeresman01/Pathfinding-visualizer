#include "headers/Background.h"

#include "headers/Logger.h"
#include "headers/PfvConstants.h"

namespace pfv
{

Background::Background() : m_window(nullptr)
{
    setImage("resources/images/default_background.jpg");
}

void Background::draw()
{
    m_window->draw(m_background);
}

void Background::setScale(float scaleX, float scaleY)
{
    m_background.setScale(scaleX, scaleY);
}

void Background::setWindow(sf::RenderWindow *window)
{
    m_window = window;
}

void Background::setImage(const std::filesystem::path &path)
{
    bool isTextureLoadedSuccessfully = m_texture.loadFromFile(path.string());

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load texture from " << path.string() << "!");
        return;
    }

    m_background.setTexture(m_texture);
    m_background.setScale(menu::BACKGROND_SCALE_X, menu::BACKGROND_SCALE_Y);
}

} // namespace pfv
