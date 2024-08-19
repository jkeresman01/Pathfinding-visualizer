#include "headers/Menu.h"

#include <algorithm>

#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>

#include "headers/MenuItem.h"
#include "headers/PfvConstants.h"
#include "headers/ResourceManager.h"

namespace pfv
{

Menu::Menu() : m_background("resources/images/default_background.jpg")
{
    m_menuItems = new MenuItem[menu::NUMBER_OF_OPTIONS];

    m_menuItems[menu::MAZE_SOLVING].setText("Maze solving!");
    m_menuItems[menu::MAZE_SOLVING].move(0, -menu::SPACING_BETWEEN_ITEMS);
    m_menuItems[menu::MAZE_SOLVING].setSelected(true);

    m_menuItems[menu::WALL_BUILDING].setText("Wall building!");

    m_menuItems[menu::EXIT].setText("Exit!");
    m_menuItems[menu::EXIT].move(0, menu::SPACING_BETWEEN_ITEMS);

    m_selectedItem = menu::MAZE_SOLVING;

    m_soundEffect.setBuffer(
        ResourceManager::Instance().getSoundBuffer("resources/sound/menu_sound_effect.wav"));
}

Menu::~Menu()
{
    if (m_menuItems != nullptr)
    {
        delete[] m_menuItems;
    }
}

void Menu::render(sf::RenderWindow &window) const
{
    window.clear(sf::Color(3, 11, 28));
    m_background.render(window);
    renderMenuItems(window);
    window.display();
}

void Menu::renderMenuItems(sf::RenderWindow &window) const
{
    std::for_each(m_menuItems, m_menuItems + menu::NUMBER_OF_OPTIONS,
                  [&window](const MenuItem &m) { m.render(window); });
}

void Menu::moveUp()
{
    if (m_selectedItem > 0)
    {
        m_soundEffect.play();
        m_menuItems[m_selectedItem].setSelected(false);
        m_menuItems[--m_selectedItem].setSelected(true);
    }
}

void Menu::moveDown()
{
    if (m_selectedItem < menu::NUMBER_OF_OPTIONS - 1)
    {
        m_soundEffect.play();
        m_menuItems[m_selectedItem].setSelected(false);
        m_menuItems[++m_selectedItem].setSelected(true);
    }
}

uint32_t Menu::getSelectedItem() const
{
    return m_selectedItem;
}

} // namespace pfv
