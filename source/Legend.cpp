#include "headers/Legend.h"
#include "headers/Global.h"
#include "headers/Logger.h"

#include <algorithm>

#include <SFML/Graphics/Text.hpp>

Legend::Legend() : m_window(nullptr)
{
    if(!m_font.loadFromFile("./resources/fonts/Emulogic-zrEw.ttf"))
    {
        LOG_ERROR("Failed to load font from ./resources/fonts/Emulogic-zrEw.ttf");
    }

    initilazeLegendItems();
}

void Legend::initilazeLegendItems()
{
    m_items[gc::legend::ESC].setString("ESC - Menu");
    m_items[gc::legend::RESET].setString("R - Reset");
    m_items[gc::legend::DFS].setString("D - DFS");
    m_items[gc::legend::BFS].setString("B - BFS");
    m_items[gc::legend::DIJKSTRA].setString("J - Dijsktra");

    for(size_t i = 0; i < gc::legend::NUMBER_OF_ITEMS; ++i)
    {
        m_items[i].setFont(m_font);
        m_items[i].setCharacterSize(gc::legend::FONT_SIZE);
        m_items[i].setFillColor(sf::Color(204, 255, 229));
        m_items[i].setPosition(gc::legend::POSITION_X, gc::legend::POSITION_Y);
        m_items[i].move(0, i * gc::legend::ITEM_SPACING);
    }
}

void Legend::draw()
{
    std::for_each(m_items, m_items + gc::legend::NUMBER_OF_ITEMS, [this](sf::Text &item){ m_window->draw(item); });
}

void Legend::setWindow(sf::RenderWindow *t_window){
    m_window = t_window;
}
