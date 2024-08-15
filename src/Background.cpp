#include "headers/Background.h"

#include "headers/PfvConstants.h"
#include "headers/ResourceManager.h"

namespace pfv
{

Background::Background(const std::filesystem::path &filepath)
{
    m_background.setTexture(ResourceManager::Instance().getTexture(filepath));
    m_background.setScale(menu::BACKGROND_SCALE_X, menu::BACKGROND_SCALE_Y);
}

void Background::render(sf::RenderWindow &window) const
{
    window.draw(m_background);
}

} // namespace pfv
