#include "headers/Legend.h"
#include "headers/Global.h"
#include <SFML/Graphics/Text.hpp>
#include <algorithm>

Legend::Legend()
{
    m_font.loadFromFile("./resources/fonts/Emulogic-zrEw.ttf");
    initilazeLegendItems();
    setWindow(nullptr);
}

void Legend::initilazeLegendItems()
{
    m_items[gc::legend::RESET].setString("R - Reset");
    m_items[gc::legend::DFS].setString("D - DFS");
    m_items[gc::legend::BFS].setString("B - BFS");
    m_items[gc::legend::DIJKSTRA].setString("J - Dijsktra");

    std::for_each(m_items, m_items + gc::legend::NUMBER_OF_ITEMS, [this](sf::Text &item)
        {
            item.setFont(m_font);
            item.setCharacterSize(15);
            item.setOrigin(item.getGlobalBounds().width / 2, item.getGlobalBounds().height / 2);
            item.setPosition(gc::screen::WIDTH / 2.0f, gc::screen::HEIGHT / 2.0f);
        }
    );
}

void Legend::draw()
{
    std::for_each(m_items, m_items + gc::legend::NUMBER_OF_ITEMS, [](auto &i){ i.draw(); });
}

void Legend::move(const float t_positionX, const float t_positionY)
{

}

void Legend::setWindow(sf::RenderWindow *t_window){
    m_window = t_window;
}
