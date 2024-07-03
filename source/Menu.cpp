#include "headers/Menu.h"

#include <algorithm>

#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>

#include "headers/Global.h"
#include "headers/Logger.h"
#include "headers/MenuItem.h"

Menu::Menu() : m_window(nullptr)
{
    initMenuItems();
}

Menu::~Menu()
{
    delete[] m_menuItems;
}

void Menu::loadSound(const std::filesystem::path &t_path)
{
    if(!m_soundBuffer.loadFromFile(t_path.string()))
    {
        LOG_ERROR("Failed to load sound effect from " << t_path.string() << "!");
    }

    m_soundEffect.setBuffer(m_soundBuffer);
}

void Menu::initMenuItems()
{
    m_menuItems = new MenuItem[gc::menu::NUMBER_OF_OPTIONS];

    m_menuItems[gc::menu::MAZE_SOLVING].setText("Maze solving!");
    m_menuItems[gc::menu::MAZE_SOLVING].move(0, -gc::menu::SPACING_BETWEEN_ITEMS);
    m_menuItems[gc::menu::MAZE_SOLVING].setSelected(true);
    m_selectedItem = gc::menu::MAZE_SOLVING;

    m_menuItems[gc::menu::WALL_BUILDING].setText("Wall building!");

    m_menuItems[gc::menu::EXIT].setText("Exit!");
    m_menuItems[gc::menu::EXIT].move(0, gc::menu::SPACING_BETWEEN_ITEMS);

    loadSound("resources/sound/menu_sound_effect.wav");
}

void Menu::draw()
{
    m_window->clear(sf::Color(3, 11, 28));
    m_background.draw();
    drawMenuItems();
    m_window->display();
}

void Menu::drawMenuItems()
{
    std::for_each(m_menuItems, m_menuItems + gc::menu::NUMBER_OF_OPTIONS,
            [](MenuItem &menuItem){ menuItem.draw(); });
}

void Menu::moveUp()
{
    if(m_selectedItem > 0)
    {
        m_soundEffect.play();
        m_menuItems[m_selectedItem].setSelected(false);
        m_menuItems[--m_selectedItem].setSelected(true);
    }
}

void Menu::moveDown()
{
    if(m_selectedItem < gc::menu::NUMBER_OF_OPTIONS - 1)
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

void Menu::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
    m_background.setWindow(t_window);
    setWindowMenuItems(t_window);
}

void Menu::setWindowMenuItems(sf::RenderWindow *t_window)
{
    std::for_each(m_menuItems, m_menuItems + gc::menu::NUMBER_OF_OPTIONS,
            [&t_window](MenuItem &menuItem){ menuItem.setWindow(t_window); });
}
