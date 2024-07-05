#include "headers/Legend.h"

#include <algorithm>

#include <SFML/Graphics/Text.hpp>

#include "headers/Global.h"
#include "headers/Logger.h"

namespace pfv
{
    
Legend::Legend() : m_window(nullptr)
{
    initLegendItems();
}

void Legend::initLegendItems()
{
    setTextLegendItems();
    setDefaultSettingsLegendItems();
    setColorLegendItems();
}

void Legend::setTextLegendItems()
{
    m_items[legend::EMPTY_START].setString("-------------");
    m_items[legend::ESC].setString("ESC - Menu");
    m_items[legend::RESET].setString("R - Reset");
    m_items[legend::DFS].setString("D - DFS");
    m_items[legend::BFS].setString("B - BFS");
    m_items[legend::DIJKSTRA].setString("J - Dijkstra");
    m_items[legend::EMPTY_MIDDLE].setString("-------------");
    m_items[legend::START].setString("o Start");
    m_items[legend::TARGET].setString("o Target");
    m_items[legend::WALL].setString("o Wall");
    m_items[legend::PATH].setString("o Path");
    m_items[legend::VISITED].setString("o Visited");
    m_items[legend::EMPTY_END].setString("-------------");
}

void Legend::setDefaultSettingsLegendItems()
{
    loadFont("resources/fonts/Emulogic-zrEw.ttf");

    for(size_t i = 0; i < legend::NUMBER_OF_ITEMS; ++i)
    {
        m_items[i].setFont(m_font);
        m_items[i].setCharacterSize(legend::FONT_SIZE);
        m_items[i].setFillColor(sf::Color(204, 255, 229));
        m_items[i].setPosition(legend::POSITION_X, legend::POSITION_Y);
        m_items[i].move(0, i * legend::ITEM_SPACING);
    }
}

void Legend::loadFont(const std::filesystem::path &t_path)
{
    if(!m_font.loadFromFile(t_path.string()))
    {
        LOG_ERROR("Failed to load font from " << t_path.string() << "!");
    }
}

void Legend::setColorLegendItems()
{
    m_items[legend::START].setFillColor(sf::Color::Green);
    m_items[legend::TARGET].setFillColor(sf::Color::Cyan);
    m_items[legend::WALL].setFillColor(sf::Color::Magenta);
    m_items[legend::PATH].setFillColor(sf::Color(229, 204, 255));
    m_items[legend::VISITED].setFillColor(sf::Color(51, 51, 254));
}

void Legend::draw()
{
    std::for_each(m_items, m_items + legend::NUMBER_OF_ITEMS,
            [this](sf::Text &item){ m_window->draw(item); });
}

void Legend::setWindow(sf::RenderWindow *t_window){
    m_window = t_window;
}

} // pfv

