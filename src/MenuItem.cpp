#include "headers/MenuItem.h"

#include <SFML/Graphics/Color.hpp>

#include "headers/Logger.h"
#include "headers/PfvConstants.h"

namespace pfv
{

MenuItem::MenuItem() : m_window(nullptr), m_isSelected(false)
{
    initMenuItem();
}

void MenuItem::initMenuItem()
{
    loadFont("resources/fonts/Emulogic-zrEw.ttf");
    setDefaultSettings();
}

void MenuItem::setDefaultSettings()
{
    m_menuItem.setCharacterSize(menu::FONT_SIZE);
    m_menuItem.setPosition(screen::WIDTH / 2.0f, screen::HEIGHT / 2.0f);
}

void MenuItem::loadFont(const std::filesystem::path &path)
{
    bool isFontLoadedSuccessfully = m_font.loadFromFile(path.string());

    if (!isFontLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load font from " << path.string() << "!");
        return;
    }

    m_menuItem.setFont(m_font);
}

void MenuItem::draw()
{
    m_window->draw(m_menuItem);
}

void MenuItem::move(float positionX, float positionY)
{
    m_menuItem.move(positionX, positionY);
}

bool MenuItem::isSelected() const
{
    return m_isSelected;
}

void MenuItem::setWindow(sf::RenderWindow *window)
{
    m_window = window;
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
