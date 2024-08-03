#include "headers/Menu.h"

#include <algorithm>

#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>

#include "headers/Logger.h"
#include "headers/MenuItem.h"
#include "headers/PfvConstants.h"

namespace pfv
{

Menu::Menu() : m_window(nullptr)
{
    initMenuItems();
}

Menu::~Menu()
{
    delete[] m_menuItems;
}

void Menu::initMenuItems()
{
    initAllMenuOptions();
    loadSound("resources/sound/menu_sound_effect.wav");
    setDefaultSelectedOption();
}

void Menu::initAllMenuOptions()
{
    m_menuItems = new MenuItem[menu::NUMBER_OF_OPTIONS];

    initMazeSolvingOption();
    initWallBuildingOption();
    initExitOption();
}

void Menu::initMazeSolvingOption()
{
    m_menuItems[menu::MAZE_SOLVING].setText("Maze solving!");
    m_menuItems[menu::MAZE_SOLVING].move(0, -menu::SPACING_BETWEEN_ITEMS);
    m_menuItems[menu::MAZE_SOLVING].setSelected(true);
}

void Menu::initWallBuildingOption()
{
    m_menuItems[menu::WALL_BUILDING].setText("Wall building!");
}

void Menu::initExitOption()
{
    m_menuItems[menu::EXIT].setText("Exit!");
    m_menuItems[menu::EXIT].move(0, menu::SPACING_BETWEEN_ITEMS);
}

void Menu::setDefaultSelectedOption()
{
    m_selectedItem = menu::MAZE_SOLVING;
}

void Menu::loadSound(const std::filesystem::path &path)
{
    bool isSoundEffectLoadedSuccessfully = m_soundBuffer.loadFromFile(path.string()); 

    if (!isSoundEffectLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load sound effect from " << path.string() << "!");
        return;
    }

    m_soundEffect.setBuffer(m_soundBuffer);
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
    std::for_each(m_menuItems, m_menuItems + menu::NUMBER_OF_OPTIONS,
                  [](MenuItem &menuItem) { menuItem.draw(); });
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

void Menu::setWindow(sf::RenderWindow *window)
{
    m_window = window;
    m_background.setWindow(window);
    setWindowMenuItems(window);
}

void Menu::setWindowMenuItems(sf::RenderWindow *window)
{
    std::for_each(m_menuItems, m_menuItems + menu::NUMBER_OF_OPTIONS,
                  [&window](MenuItem &menuItem) { menuItem.setWindow(window); });
}

} // namespace pfv
