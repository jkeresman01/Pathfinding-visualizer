#include "headers/MenuItem.h"                           

#include <SFML/Graphics/Color.hpp>

#include "headers/Logger.h"                           
#include "headers/PfvConstants.h"                           

namespace pfv
{

MenuItem::MenuItem() : m_window(nullptr)
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

void MenuItem::loadFont(const std::filesystem::path &t_path)
{
    if(!m_font.loadFromFile(t_path.string()))
    {
        LOG_ERROR("Failed to load font from " << t_path.string() << "!");
    }

    m_menuItem.setFont(m_font);
}

void MenuItem::draw()
{
    m_window->draw(m_menuItem);
}

void MenuItem::move(float t_positionX, float t_positionY)
{
    m_menuItem.move(t_positionX, t_positionY);
}

bool MenuItem::isSelected() const
{
   return m_isSelected; 
}
    
void MenuItem::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
}

void MenuItem::setText(const std::string &t_text)
{
    m_menuItem.setString(t_text);
    m_menuItem.setOrigin(m_menuItem.getGlobalBounds().width  / 2,
                         m_menuItem.getGlobalBounds().height / 2);
}

void MenuItem::setSelected(bool t_isSelected)
{
    m_isSelected = t_isSelected; 
    m_isSelected ? m_menuItem.setFillColor(sf::Color(51, 51, 255))
                 : m_menuItem.setFillColor(sf::Color(204, 255, 229));
}
    
} // pfv

