#include "headers/MenuItem.h"

#include <SFML/Graphics/Color.hpp>

#include "headers/PfvConstants.h"
#include "headers/ResourceManager.h"

namespace pfv
{

MenuItem::MenuItem() : m_isSelected(false)
{
    m_menuItem.setFont(ResourceManager::Instance().getFont("resources/fonts/Emulogic-zrEw.ttf"));
    m_menuItem.setCharacterSize(menu::FONT_SIZE);
    m_menuItem.setPosition(screen::WIDTH / 2.0f, screen::HEIGHT / 2.0f);
}

void MenuItem::render(sf::RenderWindow &window) const
{
    window.draw(m_menuItem);
}

void MenuItem::move(float positionX, float positionY)
{
    m_menuItem.move(positionX, positionY);
}

void MenuItem::setText(const std::string &text)
{
    m_menuItem.setString(text);
    m_menuItem.setOrigin(m_menuItem.getGlobalBounds().width / 2,
                         m_menuItem.getGlobalBounds().height / 2);
}

void MenuItem::setSelected(bool isSelected)
{
    m_isSelected = isSelected;
    m_isSelected ? m_menuItem.setFillColor(sf::Color(51, 51, 255))
                 : m_menuItem.setFillColor(sf::Color(204, 255, 229));
}

} // namespace pfv
