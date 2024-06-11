#include "headers/MenuItem.h"                           
#include "headers/Global.h"                           

#include <iostream>

#include <SFML/Graphics/Color.hpp>

MenuItem::MenuItem()
{
    if(!m_font.loadFromFile("./resources/fonts/Emulogic-zrEw.ttf"))
    {
        std::cerr << "Font can't be loaded from ./resources/fonts/Emulogic-zrEw.ttf" << "\n";
    }

    m_menuItem.setFont(m_font);
    m_menuItem.setCharacterSize(gc::menu::FONT_SIZE);
    m_menuItem.setPosition(gc::screen::WIDTH / 2.0f, gc::screen::HEIGHT / 2.0f);
    setWindow(nullptr);
}

void MenuItem::draw()
{
    m_window->draw(m_menuItem);
}

void MenuItem::move(const float t_positionX, const float t_positionY)
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

void MenuItem::setText(const std::string t_text)
{
    m_menuItem.setString(t_text);
    m_menuItem.setOrigin(m_menuItem.getGlobalBounds().width / 2, m_menuItem.getGlobalBounds().height / 2);
}

void MenuItem::setSelected(const bool t_isSelected)
{
    m_isSelected = t_isSelected; 
    m_isSelected ? m_menuItem.setFillColor(sf::Color(51, 51, 255))
                 : m_menuItem.setFillColor(sf::Color(204, 255, 229));
}

