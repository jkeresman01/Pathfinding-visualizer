#include "headers/Global.h"
#include "headers/Menu.h"
#include "headers/MenuItem.h"
#include "headers/Logger.h"

#include <algorithm>

#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>

Menu::Menu() : m_window(nullptr)
{
    if(!m_soundBuffer.loadFromFile("./resources/images/maze_draw3.wav"))
    {
        LOG_ERROR("Sound effect can't be loaded from ./resources/images/maze_draw3.wav!");
    }

    m_sound.setBuffer(m_soundBuffer);
    m_background.setScale(gc::menu::BACKGROND_SCALE_X, gc::menu::BACKGROND_SCALE_Y);
    initilazeMenuItems();
}

void Menu::initilazeMenuItems()
{
    m_menuItems = new MenuItem[gc::menu::NUMBER_OF_OPTIONS];

    m_menuItems[gc::menu::MAZE_SOLVING].setText("Maze solving!");
    m_menuItems[gc::menu::MAZE_SOLVING].move(0, -gc::menu::SPACING_BETWEEN_ITEMS);
    m_menuItems[gc::menu::MAZE_SOLVING].setSelected(true);
    m_currentSelectedOption = gc::menu::MAZE_SOLVING;

    m_menuItems[gc::menu::WALL_BUILDING].setText("Wall building!");

    m_menuItems[gc::menu::EXIT].setText("Exit!");
    m_menuItems[gc::menu::EXIT].move(0, gc::menu::SPACING_BETWEEN_ITEMS);
}

Menu::~Menu()
{
    delete[] m_menuItems;
}

void Menu::draw()
{
    m_window->clear(sf::Color(3, 11, 28));
    m_background.draw();
    std::for_each(m_menuItems, m_menuItems + gc::menu::NUMBER_OF_OPTIONS, [](MenuItem &mi){mi.draw();});
    m_window->display();
}

void Menu::moveUp()
{
    if(m_currentSelectedOption > 0)
    {
        m_sound.play();
        m_menuItems[m_currentSelectedOption].setSelected(false);
        m_menuItems[--m_currentSelectedOption].setSelected(true);
    }
}

void Menu::moveDown()
{
    if(m_currentSelectedOption < gc::menu::NUMBER_OF_OPTIONS - 1)
    {
        m_sound.play();
        m_menuItems[m_currentSelectedOption].setSelected(false);
        m_menuItems[++m_currentSelectedOption].setSelected(true);
    }
}

int Menu::getSelectedItem() const
{
    return m_currentSelectedOption;
}

void Menu::setWindow(sf::RenderWindow *t_window)
{
    m_window = t_window;
    m_background.setWindow(t_window);
    std::for_each(m_menuItems, m_menuItems + gc::menu::NUMBER_OF_OPTIONS, [&t_window](MenuItem &mi){mi.setWindow(t_window);});
}
